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

 	$Id: rlc_admin.php,v 1.7 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Administer the ActPro system
 */

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(0);

	$errlevel = rlc_turn_off_warnings();
	$files = glob("backups/*");
	foreach ($files as $file) 
	{
		chmod($file, 0777);
		unlink($file);
	}
	chmod(DLCMDFILE, 0777);
	unlink(DLCMDFILE);
	error_reporting($errlevel);
    }
    else
    {
/*
 *	Normal user.  Change password, etc.
 */
    }
?>
