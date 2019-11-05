#include "license.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef _WIN32
#include <sys/time.h>
#endif

#define URL "www.hostedactivation.com/issrs"
#define ISVNAME "issrs"

const char *product = "rs35";
const char *version = "3.50";

int main(int argc, char *argv[])
{
	RLM_HANDLE rh = (RLM_HANDLE) NULL;
	RLM_LICENSE lic = (RLM_LICENSE) NULL;
	RLM_ACT_HANDLE act_handle;

	char data[3*(RLM_MAX_LINE+1)];
	char okey[RLM_MAX_LINE+1];
	char akey[RLM_MAX_LINE+1];
	char verification[3*(RLM_MAX_LINE+1)];
	char err[RLM_ERRSTRING_MAX+1];
	FILE *f;
	int len;
	int stat;

	(void) printf("\n1. Revoke a license on a disconnected system (run this on the disconnected system; generate file verification)");
	(void) printf("\n2. Notify distributor the revoking action (run this on the internet-connected system; read file verification)");
	(void) printf("\n3. Get disconnected system information (run this on the disconnected system; generate file data)");
	(void) printf("\n4. Obtain a license for a disconnected system (run this on the internet-connected system; read file data)");
	(void) printf("\nEnter option 1, 2, 3, or 4:");
	fgets(okey, RLM_MAX_LINE, stdin);

	if (*okey == '1')
	{
		rh = rlm_init(".", argv[0], (char *) NULL);
		stat = rlm_act_revoke_disconn(rh, "", product, verification);
		
		if (stat == 0)
		{
			printf("License successfully revoked\n");
		}
		else
		{
			printf("\n");
			printf("Error %d requesting license revoke\n%s\n",
					stat,
					RLM_ACT_ERR(stat) ?
					rlm_act_errstring(stat) :
					rlm_errstring(0, rh, err));
			printf("\n");
			return(0);
		}

		f = fopen("verification", "w");
		if (f)
		{
			fprintf(f, "%s", verification);
			fclose(f);
			(void) printf("Revoke license successful, file \"%s\" written\n", "verification");
		}
		else
		{
			printf("Error writing verification file \"%s\"\n", "verification");
		}

		return(0);

	} else if (*okey == '2')
	{
		f = fopen("verification", "r");
		if (f)
		{
			fgets(verification, 3*RLM_MAX_LINE, f);
			len = ((int) strlen(verification)) - 1;
			if (verification[len] == '\n') verification[len] = '\0';
		}
		else
		{
			printf("Error reading file data");
			stat = -1;
			return (stat);
		}

		rh = rlm_init(".", argv[0], (char *) NULL);
		stat = rlm_act_revoke_disconn(rh, URL, verification, (char *) NULL);

		if (stat == 0)
		{
			printf("Notify distributor revoking action successfully\n");
		}
		else
		{
			printf("\n");
			printf("Error %d notify revoking action\n%s\n",
					stat,
					RLM_ACT_ERR(stat) ?
					rlm_act_errstring(stat) :
					rlm_errstring(0, rh, err));
			printf("\n");
		}

		return(0);

	} else if (*okey == '3')
	{
		rh = rlm_init(".", argv[0], (char *) NULL);
		act_handle = rlm_act_new_handle(rh);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_REHOST, (void *) 1);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_DISCONN, (void *) 1);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_PRODUCT, product);
		stat = rlm_activate(rh, URL, "", 0, data, act_handle);
		(void) rlm_act_destroy_handle(act_handle);

		if (stat != 0)
		{
		    printf("\n");
		    printf("Error %d requesting disconnected system information\n%s\n", 
					    stat, 
					    RLM_ACT_ERR(stat) ? 
						rlm_act_errstring(stat) : 
						rlm_errstring(0, rh, err));
		    printf("\n");
		    return(0);
		}

		f = fopen("data", "w");
		if (f)
		{
			fprintf(f, "%s", data);
			fclose(f);
			(void) printf("Obtain system information successful, file \"%s\" written\n", "data");
		//	break;
		}
		else
		{
			printf("Error writing disconnected system information file \"%s\"\n", "data");
			stat = -1;
		//	break;
		}
//		(void) printf("\n%s",data);
		return(0);
	} else if (*okey == '4')
	{
		char infor[3*(RLM_MAX_LINE+1)];
		char license[3*(RLM_MAX_LINE+1)];

/*		(void) printf("Enter disconnected system information for \"%s\": ", product);
	    	fgets(infor, RLM_MAX_LINE, stdin);
		len = ((int) strlen(infor)) - 1;
		if (infor[len] == '\n') infor[len] = '\0';
		*/

		f = fopen("data", "r");
		if (f)
		{
			fgets(infor, 3*RLM_MAX_LINE, f);
			len = ((int) strlen(infor)) - 1;
			if (infor[len] == '\n') infor[len] = '\0';
		}
		else
		{
			printf("Error reading file data");
			stat = -1;
			return (stat);
		}

		(void) printf("Enter Activation key for \"%s\": ", product);
	    	fgets(akey, RLM_MAX_LINE, stdin);
		len = ((int) strlen(akey)) - 1;
		if (akey[len] == '\n') akey[len] = '\0';

		rh = rlm_init(".", argv[0], (char *) NULL);
		act_handle =rlm_act_new_handle(rh);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_REHOST, (void *) 1);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_DISCONN, (void *) 1);
		stat = rlm_act_set_handle(act_handle, RLM_ACT_HANDLE_HOSTID_LIST, infor);
		stat = rlm_activate(rh, URL, akey, 0, license, act_handle);
		(void) rlm_act_destroy_handle(act_handle);

		if ((stat == 0) || (stat == 1))
		{
		  char name[100];
		  int try;

		  for (try=0; try<100; try++)
		  {
			sprintf(name, "a%d.lic", try);
			f = fopen(name, "r");
			if (f == (FILE *) NULL)
			{
			  struct tm *t;
#ifdef _WIN32
 			  time_t ltime;

				time(&ltime);
				t = localtime(&ltime);
#else
 			  struct timezone tz;
			  struct timeval tv;
			  time_t x;

				gettimeofday(&tv, &tz);
				x = tv.tv_sec;
				t = localtime((time_t *) &x);
#endif

				f = fopen(name, "w");
				if (f)
				{
				    fprintf(f, "This license created by RLM Internet Activation\n");
				    if (t)
		 		      fprintf(f, "Created on %02d/%02d/%04d at %02d:%02d\n", 
						t->tm_mon+1, t->tm_mday, 
						t->tm_year+1900, t->tm_hour, 
						t->tm_min);
	
				    fprintf(f, "\n%s\n", license);
				    fclose(f);
				    printf(
			"Activation successful, license file \"%s\" written\n",
				    				name);
				    break;
				}
				else
				{
				    printf(
					  "Error writing license file \"%s\"\n",
									name);
				    break;
				}
			}
		  }
		}
		else
		{
		    printf("\n");
		    switch(stat)
		    {
		      char err[RLM_ERRSTRING_MAX+1];

			case RLM_EH_CANTCONNECT_URL:
			  printf("You were unable to connect to %s.\n", URL);
			  printf("Please make sure that this system is able to\n");
			  printf("access the internet and try again.\n");
			  break;

			case RLM_ACT_NO_KEY_MATCH:
			  printf("The activation key you supplied (%s) was \n",
									akey);
			  printf("not found.  Please check the key and ensure\n");
			  printf("that you have entered it correctly.\n");
			  break;

			case RLM_ACT_KEY_USED:
			  printf("The activation key you supplied (%s)\n", akey);
			  printf("has already been used to activate a license.\n");
			  printf("Please check the key and ensure that you have entered it correctly.\n");
			  break;

			case RLM_EH_BAD_HTTP:
			  printf("Bad HTTP transaction\n%s\n",
						rlm_errstring(0, rh, err));
			  break;

			default:
			  printf("Error %d obtaining a license for the disconnected system.\n%s\n", 
					    stat, 
					    RLM_ACT_ERR(stat) ? 
						rlm_act_errstring(stat) : 
						rlm_errstring(0, rh, err));
			  break;

		    }
		    printf("\n");
		}
		return(0);
	} else
	{
		(void) printf("\nInvalid option");
		return(-1);
	}
}
