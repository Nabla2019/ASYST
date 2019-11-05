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

 	$Id: rlc_add_black.php,v 1.8 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_mysql.php";
include "login_session.php";

	rlc_web_header(RLC_MENU_ADMIN, $session);
	$newblack = strtolower($_POST['newblack']);
	rlc_web_title("Adding Blacklist Definition", "rlc_show_black.php");
	if (!$session->logged_in || !$session->isAdmin())
	{
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page("Back to BlackList", 0, 0);
	    return;
	}

/*
 *	Now write the list out.
 */
	if ($newblack == "")
	{
		echo "You must specify a non-empty blacklist definition<br><br>";
	}
	else
	{
		$sql = rlc_mysql_init($isv);
		rlc_mysql_add_black($sql, $newblack, 0);
		$res = rlc_mysql_add_audit($sql, $session->username, "add", 
						$newblack, "blacklist");
		rlc_mysql_close($sql);
		echo "Blacklist definition updated<br><br>";
	}
	finish_page("Back to BlackList", 0, 0);
?>
