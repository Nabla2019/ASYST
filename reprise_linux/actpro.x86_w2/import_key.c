/*****************************************************************************

	    COPYRIGHT (c) 2009, 2017 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 *****************************************************************************/
/*	
 *	Description: 	import_key - Example program to import an activation 
 *					key into the activation PRO database.
 *
 *	Usage:	import_key activation-key product-id [-c count] [-t n|r]
 *				[-e key-exp-date] [-l lic-exp-date] 
 *				[-w whitelist] [-o other-params] [-n notes]
 *				[-z contact-id]
 *
 *	Return:		Activation key imported to database.
 *
 *	To compile/link:	(where "sql" is the directory where the
 *				 mysql connector kit is installed)
 *
 *				cc -c import_key.c -Isql/include
 *				cc -o import_key import_key.o \
 *					sql/lib/libmysqlclient.a -lm
 *
 *	M. Christiano
 *	1/30/12 
 *
 *	$Id: import_key.c,v 1.11 2017/02/15 19:28:54 matt Exp $
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifndef _WIN32
#include <unistd.h>
#include <sys/param.h>
#endif
#include "my_global.h"
#include "mysql.h"

/**********************************************************************/
/*
 *	Configuration Parameters
 */

#define ISVNAME "reprise"
/*
 *	You can get to the database either by creating a
 *	database description file named "isv.mysql" (where
 *	isv is your ISVNAME above), and putting the data
 *	into this file, or by hard-coding the parameters below.
 *
 *	To use the database description file, define USE_MYSQL_DESC_FILE below.
 */
#if 1
#define USE_MYSQL_DESC_FILE
#endif

#ifndef USE_MYSQL_DESC_FILE
#define SQLHOST "127.0.0.1"
#define	SQLPORT 3306
#define	DBNAME "RLM_Activation_Pro"
#define	DBUSER "root"
#define	DBPW   ""
#endif

/*
 *	Define PRINT_KEY_PARAMS to see the key parameters
 *	to be created.
 */
#if 0
#define PRINT_KEY_PARAMS
#endif

/**********************************************************************/

static MYSQL *init_mysql(char *isv, int exists, char *dbname);

#define RLM_ACT_MAX_KEY 60
#define RLM_ACT_MAX_MISC 255
#define RLM_ACT_MAX_WHITE 80
#define RLM_ACT_MAX_NOTES 100
#define RLM_MAX_EXP 11

/*
 *	Activation key parameters
 */

static char akey[RLM_ACT_MAX_KEY+1];
static int product_id = 0;
static int count = 1;
static int contact_id = 0;
static int type = 0;	/* 0 -> normal, 1 -> reactivate */
static char keyexp[RLM_MAX_EXP+1];
static char licexp[RLM_MAX_EXP+1];
static char white[RLM_ACT_MAX_WHITE+1];
static char misc[RLM_ACT_MAX_MISC+1];
static char notes[RLM_ACT_MAX_NOTES+1];

#define INSERT_KEYD "INSERT INTO keyd (akey, active, product_id, count, type, rehosts, lastdate, exp, white, misc, notes, contact_id) VALUES (\"%s\", %d, %d, %d, %d, %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d)"

static void quote_string(char *in, char *out);
static void create_key();
static void usage();
static void process_args(int argc, char *argv[]);


int
main(int argc, char *argv[])
{
	if (argc < 3)
	{
		usage(argv[0]);
		return(1);
	}

	printf("RLM activation database update.\n");
	printf("Copyright (C) 2009, 2017 Reprise Software, Inc.\n\n");
	process_args(argc, argv);
	printf("Creating activation key %s for product id %d\n", akey, 
								product_id);
#ifdef PRINT_KEY_PARAMS
	printf("  activation type:          %s\n", 
				type == 0 ? "normal" : "reactivate");
	printf("  fulfill count:            %d\n", count);
	printf("  key expiration date:      %s\n", keyexp[0] ? keyexp : "none");
	printf("  license expiration date:  %s\n", licexp[0] ? licexp : "none");
	printf("  whitelist:                %s\n", white[0] ? white: "none");
	printf("  other license parameters: %s\n", misc[0] ? misc : "none");
	printf("  notes:                    %s\n", notes[0] ? notes : "none");
#endif

	create_key();

	return(0);
}


static
void
create_key()
{
  int stat;
  MYSQL *sql;
  char temp[10000];
  char temp1[10000], temp2[1000];
  char database[200];
  char *isv = ISVNAME;

	sql = init_mysql(isv, 0, database);

	if (!sql)
	{
		printf("ERROR: Can't connect to MySQL database server\n");
		printf("SQL error: %s\n", mysql_error(sql));
		exit(1);
	}

	if ((stat = mysql_select_db(sql, (const char *)database)))
	{
		printf("Error %d selecting database %s\n%s\n", stat, database,
							mysql_error(sql));
		exit(1);
	}

/*
 *	Finally, populate the data
 */
	quote_string(misc, temp1);
	quote_string(notes, temp2);
	sprintf(temp, INSERT_KEYD, akey, 1 , product_id, 
					count, type, 0 /* # of rehosts */,
					keyexp, licexp, white, temp1, temp2, 
					contact_id);
	printf("Executing SQL command:\n%s\n", temp);
	if ((stat = mysql_query(sql, (const char *)temp)))
	{
		if (stat == 1)
		{
			printf("ERROR: activation key %s exists\n", akey);
			printf("Activation key (%s) ignored\n", akey);
			printf("Mysql error: %s\n", mysql_error(sql));
			exit(2);
		}
		else
		{
			printf("Error %d adding activation key row %d\n%s\n", 
					stat, count,  mysql_error(sql));
			exit(1);
		}
	}
	mysql_close(sql);
	printf("\nActivation key %s added to database for ISV %s\n", akey, isv);
}

#define COUNT_SWITCH        "-c"
#define TYPE_SWITCH         "-t"
#define KEY_EXP_SWITCH      "-e"
#define LIC_EXP_SWITCH      "-l"
#define WHITELIST_SWITCH    "-w"
#define OTHER_PARAMS_SWITCH "-o"
#define NOTES_SWITCH        "-n"
#define CONTACT_SWITCH      "-z"

static
void
usage(char *prog)
{
	printf("usage: %s activation-key product-id\n", prog);
	printf("               [%s count] [%s n|r] [%s key-exp-date]\n",
				  COUNT_SWITCH, TYPE_SWITCH, KEY_EXP_SWITCH);
	printf("               [%s lic-exp-date] [%s whitelist]\n",
					LIC_EXP_SWITCH, WHITELIST_SWITCH);
	printf("               [%s other-params] [%s notes]\n",
					OTHER_PARAMS_SWITCH, NOTES_SWITCH);
	printf("               [%s contact-id]\n",
					CONTACT_SWITCH);
	printf("\nYou must specify an activation key and a product id\n\n");
	printf("If omitted, the following parameters will have these values:\n");
	printf("    activation type: normal\n");
	printf("    fulfill count: 1\n");
	printf("    key expiration date: none\n");
	printf("    license expiration date: none specified\n");
	printf("    whitelist: none specified\n");
	printf("    other license parameters: none specified\n");
	printf("    notes: none\n");
	printf("    contact: none\n");
	printf("\n To determine the product ID for any product, hover over\n");
	printf(" the product name in the \"View Product Definitions\" list\n");
	printf(" in the RLM Activation Pro GUI, v9.3 or later\n");

}

static
void
process_args(int argc, char *argv[])
{
	if (argc < 3)
	{
		usage(argv[0]);
		return;
	}
	akey[0] = '\0';
	keyexp[0] = '\0';
	licexp[0] = '\0';
	white[0] = '\0';
	misc[0] = '\0';
	notes[0] = '\0';
	strncpy(akey, argv[1], RLM_ACT_MAX_KEY);
	product_id = atoi(argv[2]);
	if ((product_id == 0) || !akey[0])
	{
		usage(argv[0]);
		return;
	}
	while (argc > 2)
	{
		if (!strcmp(argv[1], COUNT_SWITCH)) 
		{
			count = atoi(argv[2]);
		}
		else if (!strcmp(argv[1], CONTACT_SWITCH)) 
		{
			contact_id = atoi(argv[2]);
		}
		else if (!strcmp(argv[1], TYPE_SWITCH))
		{
			if ((*argv[2] == 'r') || (*argv[2] == 'R')) type = 1;
		}
		else if (!strcmp(argv[1], KEY_EXP_SWITCH))
		{
			strncpy(keyexp, argv[2], RLM_MAX_EXP);
		}
		else if (!strcmp(argv[1], LIC_EXP_SWITCH))
		{
			strncpy(licexp, argv[2], RLM_MAX_EXP);
		}
		else if (!strcmp(argv[1], WHITELIST_SWITCH))
		{
			strncpy(white, argv[2], RLM_ACT_MAX_WHITE);
		}
		else if (!strcmp(argv[1], OTHER_PARAMS_SWITCH))
		{
			strncpy(misc, argv[2], RLM_ACT_MAX_MISC);
		}
		else if (!strcmp(argv[1], NOTES_SWITCH))
		{
			strncpy(notes, argv[2], RLM_ACT_MAX_NOTES);
		}
		argc -= 2;
		argv += 2;
	}
}



/*
 *	Quote the double-quotes in a string to pass to mysql
 */

static
void
quote_string(char *in, char *out)
{
  char *p, *q;

	*out = '\0';
	for (p=in, q=out; *p; )
	{
		if (*p == '"') *q++ = '\\';
		*q++ = *p++;
	}
	*q = '\0';
}

/*
 *	Strip the whitespace and newlines from the end
 *	of the lines in the ISV.mysql file
 */

static void strip_white(char *p, char *s)
{
	while ((p >= s) && (isspace(*p) || *p == '\n')) p--;
	*(p+1) = '\0';
}

/*
 *	Initialize the connection to the MYSQL database
 */

static
MYSQL *
init_mysql(char *isv, int exists, char *db)
{
  MYSQL *sqlinit, *sql;
  char *host;
  int port;
  char *getenv();
  char *dbuser;
  char *dbpw;
  char filename[MAXPATHLEN];
  int sqldebug = 0;
  FILE *f, *fopen();

/*
 *	Connect to the MySQL server
 */
	if (getenv("RLM_ACT_SQL_DEBUG")) sqldebug = 1;
	sqlinit = mysql_init((MYSQL *) NULL);
	db[0] = '\0';
	if (!sqlinit)
	{
		if (sqldebug) printf("ERROR: Can't initalize mysql\n");
		return(sqlinit);
	}
/*
 *	Locate the MySQL database
 */

#ifdef USE_MYSQL_DESC_FILE

	sprintf(filename, "%s.mysql", isv);
	if ((f = fopen(filename, "r")))
	{
	  char *p;
	  char _dbuser[100];
	  char _dbpw[100];
	  char _host[100];
	  char _ports[100];

		_host[0] = _ports[0] = '\0';

		fgets(_host, sizeof(_host)-1, f);
		host = _host;
		p = &_host[strlen(_host)-1];
		strip_white(p, host);

		fgets(_ports, sizeof(_ports), f);
		port = atoi(_ports);
		port = atoi(_ports);

		fgets(db, 199, f);
		if (*db == '\n') *db = '\0';
		p = &db[strlen(db)-1];
		strip_white(p, db);

		fgets(_dbuser, sizeof(_dbuser)-1, f);
		dbuser = _dbuser;
		p = &_dbuser[strlen(_dbuser)-1];
		strip_white(p, dbuser);

		fgets(_dbpw, sizeof(_dbpw), f);
		dbpw = _dbpw;
		p = &_dbpw[strlen(_dbpw)-1];
		strip_white(p, dbpw);
	}
	else
	{
		printf("ERROR: Cannot open database description file: %s\n",
								filename);
		exit(1);
	}

#else	/* Get the database info from the #defines above */

	host = SQLHOST;
	port = SQLPORT;
	strcpy(db, DBNAME);
	dbuser = DBUSER;
	dbpw = DBPW;

#endif

	printf("\nConnecting to database \"%s\"\n     on node \"%s\"\n", db, 
									host);
	sql = mysql_real_connect(sqlinit, (const char *) host, dbuser, dbpw, 
						exists ? (const char *) db :
							 (const char *) NULL, 
						port, NULL, 0);
	if (!sql)
	{

	    if (sqldebug)
	    {
		printf("ERROR: Can't connect to MySQL database server\n");
		printf("SQL error: %s\n", mysql_error(sqlinit));
		printf("rlm_act_mysql_init() parameters:\n");
		printf("host: \"%s\"\n", host);
		printf("port: \"%d\"\n", port);
		printf("db: \"%s\"\n", db);
		printf("dbuser: \"%s\"\n", dbuser); 
#if 0
		printf("dbpw: \"%s\"\n", dbpw); /* DON'T PRINT THIS! */
#endif
	    }
	}
	return(sql);
}
