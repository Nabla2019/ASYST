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

 	$Id: setup_finish.php,v 1.7 2017/05/10 02:37:53 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'rlc_setup.php';

function delete($file)
{
	chmod($file, 0777);
	unlink($file);
}

/*
 *	We submitted the form - clear out the actpro_setup directory and start
 *	rlc now.
 */

	error_reporting(E_ERROR | E_PARSE);

	rlc_setup_header("Cleaning up RLM Activation PRO install directory ...");

	if (array_key_exists("backto", $_POST))
	{
		$next = $_POST['backto'];
		if (array_key_exists("backtotext", $_POST))
		{
			$nexttext = $_POST['backtotext'];
		}
		else
		{
			$nexttext = "Continue";
		}
	}
	else
	{
		$next = "index.php";
		$nexttext = "Done - Start RLC";
	}
	$isv = rlc_getpost("isv", "");

	rlc_web_title("", $next);

/*
 *	Now remove the actpro_setup
 */
	$files = glob("../actpro_setup/images/*");
	foreach ($files as $file) delete($file);
	rmdir("../actpro_setup/images");

	$files = glob("../actpro_setup/portal_setup/images/*");
	foreach ($files as $file) delete($file);
	rmdir("../actpro_setup/portal_setup/images");

	$files = glob("../actpro_setup/portal_setup/*");
	foreach ($files as $file) delete($file);
	rmdir("../actpro_setup/portal_setup");

	$files = glob("../actpro_setup/*");
	foreach ($files as $file) delete($file);
	rmdir("../actpro_setup");

	chmod("../actpro/portal_setup", 0700);

	rlc_web_hidden("phase", 4);
	rlc_web_hidden("isv", $isv);
	finish_page($nexttext, 0, 0);
?>
