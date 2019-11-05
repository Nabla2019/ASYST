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

 	$Id: upgrade.php,v 1.34 2017/10/01 20:27:45 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include 'rlc_mysql.php';
include 'rlc_setup.php';
include 'upgrade_db.php';

function v12_upgrade($isv)
{
	rlc_upgrade_12_0BL1_to_12_0BL2($isv);
	rlc_upgrade_12_0BL2_to_12_1BL1($isv);
	rlc_upgrade_12_1BL1_to_12_2BL2($isv);
	rlc_upgrade_12_2BL2_to_12_3BL1($isv);
}

function v11_upgrade($isv)
{
	rlc_upgrade_11_0_to_11_1($isv);
	rlc_upgrade_11_1BL1_to_11_1BL2($isv);
	rlc_upgrade_11_1BL2_to_11_2BL1($isv);
	rlc_upgrade_11_2BL1_to_11_2BL2($isv);
	rlc_upgrade_11_2BL2_to_11_3BL1($isv);
	rlc_upgrade_11_3BL1_to_12_0BL1($isv);
}

/*
 *	Check to see if there is an existing ActPro installation, and
 *	attempt to upgrade it if it's there.
 */

	$thisver = 12;
	$thisrev = 3;
	$thisbuild = 3;
	$newver = "$thisver.$thisrev"."BL$thisbuild";

	rlc_setup_header("RLM Activation Pro Upgrade");


/*
 *	We have something to upgrade.
 */
	if (array_key_exists('phase', $_POST)) $phase = $_POST['phase'];
	else $phase = 1;

	rlc_web_start_prompt();
	if ($phase == 1)
	{
	    $errlevel = rlc_turn_off_warnings();

/*
	    $status = stat("../actpro/actpro.php");
	    if ($status) 
	    {
		chmod("./actpro.php", 0777);
		unlink("./actpro.php"); 
		copy("../actpro/actpro.php", "./actpro.php");
		$offset = 1;
		$writenew = false;
		$data = file("actpro.php");
	    }
	    if (!$status) $status = stat("../actpro/rlmact.mysql");
	    if ($status)
	    {
		chmod("./rlmact.mysql", 0777);
		unlink("./rlmact.mysql"); 
		$offset = 0;
		$writenew = true;
		$data = file("../actpro/rlmact.mysql");
	    }
*/
            $status = stat("../actpro/actpro.php");
            if ($status)
            {
                chmod("./actpro.php", 0777);
                unlink("./actpro.php");
                copy("../actpro/actpro.php", "./actpro.php");
                $offset = 1;
                $writenew = false;
                $data = file("actpro.php");
            }
            else
            {
                $status = stat("../actpro/rlmact.mysql");
                if ($status)
                {
                    chmod("./rlmact.mysql", 0777);
                    unlink("./rlmact.mysql");
                    $offset = 0;
                    $writenew = true;
                    $data = file("../actpro/rlmact.mysql");
                }
            }


	    chmod("backups", 0700);		/* Fix for P432 */
	    error_reporting($errlevel);

	    if ($data[0] != "") 
	    {
		$actpro_there = TRUE;
		$dbhost = rtrim($data[$offset]);
		if ($data[$offset+1] != "") $dbport = rtrim($data[$offset+1]);
		if ($data[$offset+2] != "") $dbname = rtrim($data[$offset+2]);
		if ($data[$offset+3] != "") $dbuser = rtrim($data[$offset+3]);
		if ($data[$offset+4] != "") $dbpw = rtrim($data[$offset+4]);
		if ($data[$offset+5] != "") $isv = rtrim($data[$offset+5]);
	    }
	    else
	    {
		$actpro_there = FALSE;
	    }

	    if ($writenew && $actpro_there)
	    {
 		$f = fopen(RLC_SQL_DBDESC, "w");
		if ($f)
		{
		    fwrite($f, "<"."? php exit(); ?".">\n");
		    fwrite($f, $dbhost."\n");
		    fwrite($f, $dbport."\n");
		    fwrite($f, $dbname."\n");
		    fwrite($f, $dbuser."\n");
		    fwrite($f, $dbpw."\n");
		    fwrite($f, $isv."\n");
		    fclose($f);
		}
		else
		{
		   echo "Could not create ".RLC_SQL_DBDESC." database file";
		}
	    }
	    if (!$actpro_there)
	    {
		rlc_web_title( "Upgrade RLM Activation Pro (upgrade failed)", 
							"setup.php");
		rlc_web_info("I can't read your database ".
					"settings from ../actpro/rlmact.mysql".
					"<br>Make sure this file exists, that".
					" it is readable, and isn't corrupted".
					", then re-start the setup procedure."
					."<br>Database upgrade cannot be done".
					" at this time.");
		rlc_web_hidden("no_upgrade", 1);
		finish_page("Return to Setup", 0, 0);
	    }
	    else
	    {
		$sql = rlc_mysql_init($isv);
		rlc_mysql_read_rlc_setup($sql, 'actpro_version', $v);
		rlc_mysql_read_rlc_setup($sql, 'actpro_rev', $v);
		rlc_mysql_read_rlc_setup($sql, 'actpro_build', $v);
		rlc_mysql_read_rlc_setup($sql, 'actpro_patch', $v);
		rlc_mysql_read_rlc_setup($sql, 'url', $v);
		if (array_key_exists('actpro_version', $v))
		{
		    $ver = $v['actpro_version'];
		    if ($v['actpro_patch'] >= 1)
			$version = $v['actpro_version'].".". 
							$v['actpro_rev']."BL".
			   				$v['actpro_build']."-p".
			   				$v['actpro_patch'];
		    else
			$version = $v['actpro_version'].".".
			   				$v['actpro_rev']."BL".
			   				$v['actpro_build'];
		}
		else
		{
		    $ver = '9';
		    $version = "9.1BL3";
		}
				
		if (array_key_exists('actpro_rev', $v))
		{
		    $rev = $v['actpro_rev'];
		}
		else
		{
		    $rev = '1';
		}

		if (array_key_exists('actpro_build', $v))
		{
		    $build = $v['actpro_build'];
		}
		else
		{
		    $build = '1';
		}

		rlc_mysql_close($sql);
		$upgrade = true;
		if (($ver >= $thisver) && ($rev >= $thisrev) &&
						($build >= $thisbuild))
		{
		    $upgrade = false;	
		}

		if ($upgrade)
		{
		    rlc_web_title("Upgrade RLM Activation Pro (step 1)", 
							"upgrade.php");
		    rlc_web_hidden("phase", 2);
		}
		else
		{
		    rlc_web_title( "Upgrade RLM Activation Pro (step 1)", 
							"setup_doit.php");
		    rlc_web_hidden("no_upgrade", 1);
		}
		echo "New Activation Pro version (to be installed): ".
						$newver.  "<br>";
		echo "Installed Activation Pro version: ".$version.  "<br>";
		echo "Database location: ".$dbport."@".$dbhost.", user: ".
								$dbuser."<br>";
		if (!$upgrade)
		{
		    echo "<br><b>Your database has already been ".
					"upgraded to v$ver.$rev - no upgrade ".
					"can be done.</b><br>";
		}
		rlc_web_hidden("dbhost", $dbhost);
		rlc_web_hidden("dbport", $dbport);
		rlc_web_hidden("dbname", $dbname);
		rlc_web_hidden("dbuser", $dbuser);
		rlc_web_hidden("dbpw", $dbpw);
		if ($upgrade)
		    finish_page("Next->Backup Installation", 
							"CANCEL", "setup.php");
	    }
	}
	else if ($phase == 2)
	{
		rlc_web_title("Upgrade RLM Activation Pro (step 2 - backup)", 
							"upgrade.php");
		if (array_key_exists('dbhost', $_POST)) 
			$dbhost = $_POST['dbhost'];
		else	$dbhost = "";
		if (array_key_exists('dbport', $_POST)) 
			$dbport = $_POST['dbport'];
		else	$dbport = "0";
		if (array_key_exists('dbname', $_POST)) 
			$dbname = $_POST['dbname'];
		else	$dbname = "";
		if (array_key_exists('dbuser', $_POST)) 
			$dbuser = $_POST['dbuser'];
		else	$dbuser = "";
		if (array_key_exists('dbpw', $_POST)) 
			$dbpw = $_POST['dbpw'];
		else	$dbpw = "";

		$ht = "&nbsp;&nbsp;&nbsp;&nbsp;";
		rlc_web_hidden("phase", 3);
		rlc_web_info("In this step, we will back up your existing".
			" Activation Pro software.<br><br>Leave the checkbox ".
			"checked if you want to back up your software.".
			"<br>Uncheck the box if you don't want a backup of".
			" your existing installation software.".
			"<br><br>Reprise Software STRONGLY RECOMMENDS".
			" that you back up your database before you continue.".
			"<br><br>To back up your database:<br><br>".
			"$ht Run phpMyAdmin on your database machine<br>".
			"$ht Select your database from the left-hand column<br>"
			."$ht Select \"Export\" from the tabs at the top<br>".
			"$ht In the Export tab, press \"Go\" near the bottom ".
					"right<br>".
			"$ht Save the file when prompted by your browser.");
		rlc_web_start_prompt();
		$date = date("jMY"); 
		$backupdir = "../actpro.$date";
		rlc_web_checkbox("Backup old ActPro code to directory $backupdir? ",
				"backup_code", 1, 1, 1);
		rlc_web_hidden("backup_directory", $backupdir);
		rlc_web_hidden("dbhost", $dbhost);
		rlc_web_hidden("dbport", $dbport);
		rlc_web_hidden("dbname", $dbname);
		rlc_web_hidden("dbuser", $dbuser);
		rlc_web_hidden("dbpw", $dbpw);
		finish_page("Next->", "CANCEL", "setup.php");
	}
	else if ($phase == 3)
	{
		rlc_web_title("Upgrade RLM Activation Pro (step 3 - upgrade DB)"
							, "upgrade.php");

		rlc_web_info("When you press \"Next->Upgrade Database\" below".
			" your existing RLM Activation Pro database will".
			" be upgraded to RLM v$thisver.$thisrev".
			"BL$thisbuild<br><br>".
			"Choose \"CANCEL\" if you do not want to upgrade".
			" your database.");
		if (array_key_exists('backup_code', $_POST)) 
			$backup_code = $_POST['backup_code'];
		else
			$backup_code = 0;

		if (array_key_exists('backup_directory', $_POST)) 
			$backup_directory = $_POST['backup_directory'];
		else
			$backup_directory = "../backup";

		if (array_key_exists('dbhost', $_POST)) 
			$dbhost = $_POST['dbhost'];
		else	$dbhost = "";
		if (array_key_exists('dbport', $_POST)) 
			$dbport = $_POST['dbport'];
		else	$dbport = "0";
		if (array_key_exists('dbname', $_POST)) 
			$dbname = $_POST['dbname'];
		else	$dbname = "";
		if (array_key_exists('dbuser', $_POST)) 
			$dbuser = $_POST['dbuser'];
		else	$dbuser = "";
		if (array_key_exists('dbpw', $_POST)) 
			$dbpw = $_POST['dbpw'];
		else	$dbpw = "";
		rlc_web_hidden("dbhost", $dbhost);
		rlc_web_hidden("dbport", $dbport);
		rlc_web_hidden("dbname", $dbname);
		rlc_web_hidden("dbuser", $dbuser);
		rlc_web_hidden("dbpw", $dbpw);

/*
 *		Copy the .htaccess file from the running system
 *		so that it will be there on the new system. (v11.1)
 */
		mycopy("../actpro/.htaccess", ".");

		if ($backup_code)
		{
			echo "Backing up actpro directory to <i><b>".
					"$backup_directory</i></b> ...";
			mycopy("../actpro", $backup_directory);
			echo " success<br>";
		}
		rlc_web_hidden("phase", 4);
		finish_page("Next->Upgrade Database", "CANCEL", "setup.php");
	}
	else if ($phase == 4)
	{
		rlc_web_title("Upgrade RLM Activation Pro (step 4 - install new software)", 
							"setup_doit.php");

		rlc_web_info("When you press \"Next->Install New ActPro ".
			"software\" below,".
			" the directory <i>../actpro</i> will be removed and".
			" replaced with the new Activation Pro software.<br>".
			"<br>Choose \"CANCEL\" if you do not want to replace".
			" the Actpro software.");
		$sql = rlc_mysql_init($isv);
		if (!$sql) echo "sql init failed<br>";
		rlc_mysql_read_rlc_setup($sql, 'actpro_version', $v);
		rlc_mysql_read_rlc_setup($sql, 'actpro_rev', $v);
		rlc_mysql_read_rlc_setup($sql, 'actpro_build', $v);
		rlc_mysql_close($sql);
		if (array_key_exists('actpro_version', $v))
		{
			$ver = $v['actpro_version'];
			$rev = $v['actpro_rev'];
		}
		else
		{
			$ver = 9;
			$rev = 1;
			$build = 1;
		}

		if (array_key_exists('actpro_build', $v))
		{
			$build = $v['actpro_build'];
		}
		else
		{
			$build = 1;
		}

		if (array_key_exists('backup_directory', $_POST)) 
			$backup_directory = $_POST['backup_directory'];
		else
			$backup_directory = "../backup";

		if (array_key_exists('dbhost', $_POST)) 
			$dbhost = $_POST['dbhost'];
		else	$dbhost = "";
		if (array_key_exists('dbport', $_POST)) 
			$dbport = $_POST['dbport'];
		else	$dbport = "0";
		if (array_key_exists('dbname', $_POST)) 
			$dbname = $_POST['dbname'];
		else	$dbname = "";
		if (array_key_exists('dbuser', $_POST)) 
			$dbuser = $_POST['dbuser'];
		else	$dbuser = "";
		if (array_key_exists('dbpw', $_POST)) 
			$dbpw = $_POST['dbpw'];
		else	$dbpw = "";
		rlc_web_hidden("dbhost", $dbhost);
		rlc_web_hidden("dbport", $dbport);
		rlc_web_hidden("dbname", $dbname);
		rlc_web_hidden("dbuser", $dbuser);
		rlc_web_hidden("dbpw", $dbpw);

		if ($ver == "") { $ver = 9;  $rev = 1; $build = 1; }
		echo "Upgrading from Activation Pro version $ver.$rev<br>";
/*
 *		Run the appropriate upgrade(s).
 */
		if ($ver == 12)
		{
 		    if ($rev < 1) 
		    {
			rlc_upgrade_12_0BL1_to_12_0BL2($isv);
			rlc_upgrade_12_0BL2_to_12_1BL1($isv);
		    	rlc_upgrade_12_1BL1_to_12_2BL2($isv);
		    	rlc_upgrade_12_2BL2_to_12_3BL1($isv);
		    }
		    else if ($rev < 2)
		    {
		    	rlc_upgrade_12_1BL1_to_12_2BL2($isv);
		    	rlc_upgrade_12_2BL2_to_12_3BL1($isv);
		    }
		    else if ($rev < 3)
		    {
		    	rlc_upgrade_12_2BL2_to_12_3BL1($isv);
		    }
		}
		else if ($ver == 11)
		{
 		    if ($rev < 1) rlc_upgrade_11_0_to_11_1($isv);
		    if ($rev < 2) 
		    {
			if (($build < 2) || ($rev < 1)) 
			    rlc_upgrade_11_1BL1_to_11_1BL2($isv);
		        rlc_upgrade_11_1BL2_to_11_2BL1($isv);
		    }
		    if ($rev < 3)
		    {
		        rlc_upgrade_11_2BL1_to_11_2BL2($isv);
		    
		        rlc_upgrade_11_2BL2_to_11_3BL1($isv); /* upgrade BL0 */
		    }
		    rlc_upgrade_11_3BL1_to_12_0BL1($isv);
		    v12_upgrade($isv);
		}
		else if ($ver == 10)
		{
 		    if ($rev < 1) rlc_upgrade_10_0_to_10_1($isv);
 		    rlc_upgrade_10_1_to_11_0($isv);
		    v11_upgrade($isv);
		    v12_upgrade($isv);
		}
		else if ($ver == 9)
		{
 		    if ($rev < 2) rlc_upgrade_9_1_to_9_2($isv);
		    if ($rev < 3) rlc_upgrade_9_2_to_9_3($isv);
		    if ($rev < 4) rlc_upgrade_9_3_to_9_4($isv);
		    rlc_upgrade_9_4_to_10_0($isv);
		    rlc_upgrade_10_0_to_10_1($isv);
		    rlc_upgrade_10_1_to_11_0($isv);
		    v11_upgrade($isv);
		    v12_upgrade($isv);
		}
		else
		{
		    echo "Installed version ($ver) can't be upgraded<br>";
		}
		rlc_web_hidden("isv", $isv);
		rlc_web_hidden("db_upgrade", 1);
		finish_page("Next->Install New ActPro software", "CANCEL", 
								"setup.php");
	}
?>
