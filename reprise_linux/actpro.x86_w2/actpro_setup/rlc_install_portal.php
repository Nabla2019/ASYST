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

 	$Id: rlc_install_portal.php,v 1.7 2017/07/31 19:23:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'rlc_setup.php';
include 'login_session.php';

function delete($file)
{
	chmod($file, 0777);
	unlink($file);
}

/*
 *	Install the portal software
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_PORTAL);
	rlc_web_title("", "rlc_admin_portal.php");
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);
	rlc_mysql_read_rlc_setup($sql, 'portal-name', $s);
	if (array_key_exists('portal-name', $s))
		$portal_name = $s['portal-name'];
	else
		$portal_name = "";
	rlc_mysql_read_rlc_setup($sql, 'portal-dir', $s);
	if (array_key_exists('portal-dir', $s))
		$portal_dir = $s['portal-dir'];
	else
		$portal_dir = "";
/*
 *	Set up the customer portal
 */
	if ($portal_dir != "")
	{
	    $actprodir = getcwd();
	    $portal = sprintf("%s/%s", $actprodir, $portal_dir);

	    $errlevel = rlc_turn_off_warnings();
	    $status = stat($portal);
	    error_reporting($errlevel);
	    if ($status)
	    {
 		echo "<br><b>\"$portal\" exists,</b> please delete before ".
			"attempting portal installation.<br><br>";
	    }
	    else
	    {
		echo "Setting up customer portal in \"".$portal_dir."\"<br>";
		mkdir($portal, 0755);
		chmod($portal, 0755);
	        $errlevel = rlc_turn_off_warnings();
	        $status = stat($actprodir."/portal.htaccess");
	        error_reporting($errlevel);
	        if ($status)
	        {
		    mycopy("$actprodir/portal.htaccess", "$portal/.htaccess");
	        }
		else
		{
		    mycopy("$actprodir/.htaccess", "$portal/");
		}
		$errlevel = rlc_turn_off_warnings();
		rmdir("$portal/images");
		error_reporting($errlevel);
		mkdir("$portal/images", 0755);
		chmod("$portal/images", 0755);
		mycopy("$actprodir/images/", "$portal/images/");
		chdir("portal_setup");
		echo "copying files from ".getcwd()."<br>";
		$files = glob("*");
		foreach ($files as $file) mycopy($file, "$portal/");
		chdir("..");
		mycopy("actpro.php", "$portal/");
		chmod("$portal/actpro.php", 0600);
    		echo "<h4>Activation PRO Portal set up in \"".
					$portal_dir."\".</h4>";
		echo "</pre>";
	    }
	}
	else
	{
    		echo "<h4>Activation PRO Portal directory not specified</h4>";
	}

	rlc_mysql_close($sql);
	finish_page("BACK", 0, 0);
?>
