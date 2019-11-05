/******************************************************************************

	    COPYRIGHT (c) 2007-2017 by Reprise Software, Inc.
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
 *	Description:	License to use RLM
 *
 *	Replace the RLM license on the four lines after:
 *
 *		#define RLM_LICENSE_TO_RUN	\
 *
 *	with the license you received from Reprise Software.
 *
 *	M. Christiano
 *	4/20/07
 *
 */

#ifdef RLM_LICENSE_TO_RUN
#undef RLM_LICENSE_TO_RUN
#endif

/* ISV:  issrs */

#define RLM_LICENSE_TO_RUN \
  "  platforms=\"x86_w x86_l x86_m\" \
  sig=\"c2J251nzkpjCYerIahoWe92QIfNR+S~K0icYquw80qGQ376oPeJj7V~PoGQQ\""

#define RLM_ISV_NAME "issrs"

  /* License Key Checksum: 5f00f4  */
  /*  End of License keys for RLM v12 for ISV issrs  */
