<?php
/*****************************************************************************

	    COPYRIGHT (c) 2010, 2016 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_set_auto_black.php,v 1.8 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Set the automatic blacklist parameters
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_BLACKLIST);
	rlc_web_title("", "rlc_admin_black.php");
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);
	if (array_key_exists('numkey', $_POST))
		$numkey = $_POST['numkey'];
	else
        	$numkey = AUTO_BL_NUMKEY;
	if (array_key_exists('maxsec', $_POST))
		$maxsec = $_POST['maxsec'];
	else
        	$maxsec = AUTO_BL_MAXSEC;

	rlc_mysql_write_setup($sql, 'auto-bl-numkey', $numkey);
	rlc_mysql_write_setup($sql, 'auto-bl-maxsec', $maxsec);
	echo '<pre>';
    	echo "<h4>Activation PRO auto-blacklist parameters saved.</h4>";
	echo "</pre>";
	rlc_mysql_close($sql);
	finish_page("BACK", 0, 0);
?>
