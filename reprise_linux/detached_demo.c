/******************************************************************************

	    COPYRIGHT (c) 2005, 2017 by Reprise Software, Inc.
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
 *	Description: 	Example client for RLM Detached Demo(tm) capability
 *
 *	M. Christiano
 *	10/5/08
 *
 *	$Id: detached_demo.c,v 1.14 2017/02/15 19:28:54 matt Exp $
 */

#include "license.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT "abc"
#define VERSION "1.01"
//#define PRODUCT "rlmclient"

//static int checkstat(RLM_HANDLE, RLM_LICENSE, const char *);
static int installdemo(RLM_HANDLE, const char *, const char *);

void
CP(int *expDy, char *expDt, int *stat, char *errstring, char *prd, char *ver)
{
  RLM_HANDLE rh;
  RLM_LICENSE lic;
  int x;
  const char *product = PRODUCT;
  const char *version = VERSION;

	strcpy(ver, version);
	strcpy(prd, product);
/*
 *	NOTE that, unlike the case of activation, Detached Demo does not
 *	require a re-initialization of rlm.   Therefore, rlm_init() is 
 *	only called once.
 */
	rh = rlm_init(".", NULL, (char *) NULL);
	*stat = rlm_stat(rh);
	if (*stat && *stat != RLM_EH_READ_NOLICENSE)
	{
//		(void) printf("Error %d initializing license system\n", *stat);
//		exit(1);
  		rlm_errstring((RLM_LICENSE) NULL, rh, errstring);
  		return;
	}

/*
 *	First try the checkout.  If it succeeds, good.   If not,
 *	try to install the demo.
 */
	lic = rlm_checkout(rh, product, version, 1);

	*stat = rlm_license_stat(lic);

//	(void) printf("Detached Demo license %d\n", rlm_license_detached_demo(lic));

	if (*stat < 0)
	{
/*
 *		Didn't get the license.  Try a 2nd time to install a demo.
 */
	        if (lic) rlm_checkin(lic);
		*stat = installdemo(rh, product, version);
		if (*stat < 0) {
//		(void) printf("Error %d initializing license system\n", *stat);
			rlm_errstring((RLM_LICENSE) NULL, rh, errstring);
			return;
		}
		lic = rlm_checkout(rh, product, version, 1);
		*stat = rlm_license_stat(lic);
	}

	if (*stat == 0)
	{
/*
 *		We got the license
 */
//		(void) printf("Enter <CR> to continue: ");
//		x = fgetc(stdin);
                *expDy = rlm_license_exp_days(lic);
		strcpy(expDt, rlm_license_exp(lic));
//		(void) printf("experiation date: %s\n", expDt);
		if (lic) rlm_checkin(lic);
		rlm_close(rh);
	}
	else
	{
/*
 *		checkout and/or activation failed.
 */
//		(void) 
//		   printf("Unable to check out/install \"%s\" license\n",
//								PRODUCT);
                rlm_errstring(lic, rh, errstring);
	}
	return;
}
/*
static
int
checkstat(RLM_HANDLE rh, RLM_LICENSE lic, const char *name)
{
  int stat;
  char errstring[RLM_ERRSTRING_MAX];

	stat = rlm_license_stat(lic);
	if (stat == 0)
	    (void) printf("Checkout of %s license OK.\n", name);
	else
	{
	    (void) printf("Error checking out %s license\n", name);
	    (void) printf("%s\n", rlm_errstring(lic, rh, errstring));
	}
	return(stat);
}*/

static
int
installdemo(RLM_HANDLE rh, const char *name, const char *version)
{
  char license[RLM_MAX_LINE+1];
  int stat = RLM_EH_READ_NOLICENSE;	/* If they say NO, no license */

//	(void) printf("\nWould you like to install a 30-day demo license now? ");
//	fgets(license, RLM_MAX_LINE, stdin);
//	if (*license == 'y' || *license == 'Y')
//	{
/*
 *		Create the demo license.  Note that the hostid and expiration
 *		date do not matter, but must be present.   No signature
 *		is required.  All other parameters will be present in the
 *		demo license and can be retrieved by the rlm_license_xxx() 
 *		functions after the license is checked out.
 *
 *		Also note that you can ONLY check out the version contained
 *		in this license - this is not like a regular RLM license which
 *		allows lower-numbered versions to be checked out.
 */
                (void) printf("install demo\n");
		sprintf(license, "LICENSE %s %s %s 1-jan-2000 0 hostid=any",
							"demo", name, version);
/*
 *		Install the demo license
 */
	        stat = rlm_detached_demo( rh, 		/* RLM handle */
					  6, 		/* # days for demo */
			   (const char *) license); 	/* License string */

	        if (stat == 0)
	        {
//			printf("\nDemo license installation successful\n");
		}
		else
		{
		      char err[RLM_ERRSTRING_MAX+1];

//			  printf("\nError installing demo license\n");
//			  printf("%s\n", rlm_errstring(0, rh, err));
                          rlm_errstring(0, rh, err);
		}
//	}
	return(stat);
}
