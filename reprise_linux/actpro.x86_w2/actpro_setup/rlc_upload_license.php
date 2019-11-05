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

 	$Id: rlc_upload_license.php,v 1.5 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Upload the Activation PRO license - do the operation
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
	$lf = basename($_FILES['licensefile']['name']);
	/* $uploadfile = $uploaddir . basename($_FILES['licensefile']['name']); */
	$uploadfile = $uploaddir . "/". $isv . ".lic";

	echo '<pre>';
/*
	echo "moving uploaded file \"".$_FILES['licensefile']['tmp_name']. 
		"\" to \"" . $uploadfile."\"<br>";
*/
	if (move_uploaded_file($_FILES['licensefile']['tmp_name'], 
								$uploadfile)) 
	{
		chmod($uploadfile, 0600);
    		echo "<h4>Activation PRO license file successfully uploaded.</h4>";
		echo "License file: \"".$uploadfile."\"<br>";
	} 
	else 
	{
    		echo "<h4>Activation PRO license file upload failed.</h4>";
        	echo "<br>Error uploading license file \"".$lf."\"<br>";
		echo "Error: ".$_FILES['licensefile']['error']."<br>";
		if ($lf == "")
		{
			echo "<br>No license file specified.<br>";
		}
		/* echo 'Debugging info:<br>'; */
		/* print_r($_FILES); */
	}
	echo "</pre>";
?>
