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

 	$Id: rlc_upload_logo.php,v 1.8 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'login_session.php';
include 'rlc_mysql.php';

/*
 *	Upload the portal logo - do the operation
 */

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    return;
	}
	$sql = rlc_mysql_init($isv);
	rlc_mysql_read_rlc_setup($sql, 'portal-dir', $s);
	if (array_key_exists('portal-dir', $s))
	    $portal_dir = $s['portal-dir'];
	else
	    $portal_dir = ".";
	rlc_mysql_close($sql);

	$uploadfile = "$portal_dir/images/portallogo.gif";

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_PORTAL);
	rlc_web_title("", "rlc_admin_portal.php");

	echo '<pre>';
	/* echo "moving uploaded file ".$_FILES['portal-logo']['tmp_name']. 
		" to " . $uploadfile."<br>"; /**/

	if (move_uploaded_file($_FILES['portal-logo']['tmp_name'], $uploadfile)) 
	{
		chmod($uploadfile, 0644);
    		echo "<h4>Portal logo was successfully uploaded.</h4>";
	} 
	else 
	{
    		echo "<h4>Portal logo upload failed.</h4>";
		echo "<br>uploadfile: ".$uploadfile."<br>";
        	echo "<br>Error uploading portal logo<br>";
		echo "Error: ".$_FILES['portal-logo']['error']."<br>";

		/* echo 'Debugging info:<br>'; */
		/* print_r($_FILES); */
	}
	echo "</pre>";
	finish_page("BACK", 0, 0);
?>
