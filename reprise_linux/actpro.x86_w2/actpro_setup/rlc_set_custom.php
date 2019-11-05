<?php
/*****************************************************************************

	    COPYRIGHT (c) 2010, 2017 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_set_custom.php,v 1.6 2017/03/07 01:02:41 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Set the customer list customization parameters
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("", "rlc_custom_cust.php");
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);
	for ($i=1; $i <= 10; $i++)
	{
	  $u[$i] = rlc_getpost("u".$i, "");
	  $un[$i] = rlc_getpost("u".$i."-num", 0);
	  if ($u[$i] != "")  rlc_mysql_write_setup($sql, 'u'.$i.'_def', $u[$i]);
	  else	 	     rlc_mysql_delete_setup($sql, 'u'.$i.'_def');
	  if ($un[$i] == 1)  rlc_mysql_write_setup($sql, 'u'.$i.'_numeric', 
	  							$un[$i]);
	  else	 	     rlc_mysql_delete_setup($sql, 'u'.$i.'_numeric');

	}

	echo '<pre>';
    	echo "<h4>Activation PRO customer list custom parameters saved.</h4>";
	echo "</pre>";
	rlc_mysql_close($sql);
	finish_page("BACK", 0, 0);
?>
