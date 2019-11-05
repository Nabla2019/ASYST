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

 	$Id: rlc_setup_doit.php,v 1.8 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	We submitted the form - create the ACTIVAION Server URL.
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("Setup Database", "rlc_admin_db.php");
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$url = $_POST['actserverurl'];
	rlc_web_title("Setting up Activation Server URL", "rlc_info.php");
	$sql = rlc_mysql_init($isv);
	rlc_mysql_write_setup($sql, "url", $url);
	rlc_mysql_close($sql);
	echo "Activation server URL saved";
	finish_page("BACK", 0, 0);
?>
