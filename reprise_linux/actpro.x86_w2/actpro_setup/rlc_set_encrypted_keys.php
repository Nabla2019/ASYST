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

 	$Id: rlc_set_encrypted_keys.php,v 1.3 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Set the allow-non-encrypted parameter
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_GENERATOR);
	rlc_web_title("", "rlc_admin_generator.php");
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);
	if (array_key_exists('allow-non-encrypted', $_POST))
		$allow_non_encrypted = $_POST['allow-non-encrypted'];
	else
        	$allow_non_encrypted = '0';

	rlc_mysql_write_setup($sql, 'allow-non-encrypted',$allow_non_encrypted);
	echo '<pre>';
    	echo "<h4>Activation PRO encrypted requests setting saved.</h4>";
	echo "</pre>";
	rlc_mysql_close($sql);
	finish_page("BACK", 0, 0);
?>
