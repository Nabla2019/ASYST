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

 	$Id: rlc_upload_gen.php,v 1.6 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Upload the license generator - do the operation
 */

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    return;
	}

	$sql = rlc_mysql_init($isv);
	rlc_mysql_read_rlc_setup($sql, 'cgi-bin', $s);
	if (array_key_exists('cgi-bin', $s))
		$uploaddir = $s['cgi-bin'];
	else
		$uploaddir = '../../cgi-bin';
	rlc_mysql_close($sql);
	$gen = $isv.".gen";
	$uploadfile = $uploaddir . "/" . $isv . ".gen";

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("Upload Generator Settings", "rlc_admin_db.php");

	echo '<pre>';
	/* echo "moving uploaded file ".$_FILES['generatorfile']['tmp_name']. 
		" to " . $uploadfile."<br>"; /**/
	if (move_uploaded_file($_FILES['generatorfile']['tmp_name'], 
								$uploadfile)) 
	{
		chmod($uploadfile, 0600);
    		echo "<h4>Generator settings were successfully uploaded.</h4>";
		echo "Generator settings file: ".$uploadfile."<br>";
	} 
	else 
	{
    		echo "<h4>Generator settings upload failed.</h4>";
		echo "<br>uploadfile: ".$uploadfile."<br>";
        	echo "<br>Error uploading license generator settings \"".$gen.
				"\"<br>";
		echo "Error: ".$_FILES['generatorfile']['error']."<br>";
		if ($gen == "")
		{
			echo "<br>No generator file specified.<br>";
		}

		/* echo 'Debugging info:<br>'; */
		/* print_r($_FILES); */
	}
	echo "</pre>";
	finish_page("BACK", 0, 0);
?>
