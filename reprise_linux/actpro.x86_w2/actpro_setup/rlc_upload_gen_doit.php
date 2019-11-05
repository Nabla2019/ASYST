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

 	$Id: rlc_upload_gen_doit.php,v 1.5 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'login_session.php';

/*
 *	Upload the license generator - do the operation
 */

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    return;
	}

	$uploaddir = '../cgi-bin/';
	$uploadfile = $uploaddir . basename($_FILES['generatorfile']['name']);

	echo '<pre>';
	/* echo "moving uploaded file ".$_FILES['generatorfile']['tmp_name']. 
		" to " . $uploadfile."<br>"; */
	if (move_uploaded_file($_FILES['generatorfile']['tmp_name'], 
								$uploadfile)) 
	{
		chmod($uploadfile, 0600);
    		echo "<h4>Generator settings were successfully uploaded.</h4>";
		echo "Generator settings file: ".$uploadfile."<br>";
	} 
	else 
	{
        	echo "Error uploading license generator settings<br>";
		echo 'Debugging info:<br>';
		print_r($_FILES);
	}
	echo "</pre>";
?>
