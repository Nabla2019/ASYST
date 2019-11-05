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

 	$Id: setup.php,v 1.15 2017/06/24 03:19:18 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include 'rlc_mysql.php';


function is_installed()
{
	$errlevel = rlc_turn_off_warnings();
	$data = file("../actpro/actpro.php");
	error_reporting($errlevel);

	if ($data[0] != "") return(TRUE);
	return(FALSE);
}

/*
 *	Set up the files for RLM Activation Pro
 */

	$dbname = "RLM_Activation_Pro";

	rlc_setup_header("RLM Activation Pro Setup");

	$errlevel = rlc_turn_off_warnings();
	$data = file(RLC_SQL_DBDESC);
	error_reporting($errlevel);
	$dbhost = "localhost";
	$dbport = 3306;
	$dbuser = "sql";
	$dbpw = "sql";
	$isv = "";
	$admin = "admin";
	$adminpw = "admin";
	if ($data[1] != "") $dbhost = rtrim($data[1]);
	if ($data[2] != "") $dbport = rtrim($data[2]);
	if ($data[3] != "") $dbname = rtrim($data[3]);
	if ($data[4] != "") $dbuser = rtrim($data[4]);
	if ($data[5] != "") $dbpw = rtrim($data[5]);
	if ($data[6] != "") $isv = rtrim($data[6]);

	$usererr = $passerr = "";
	if (array_key_exists("admin", $_POST)) $admin = $_POST['admin'];
	if (array_key_exists("adminpw", $_POST)) $adminpw = $_POST['adminpw'];
	if (array_key_exists("dbhost", $_POST)) $dbhost = $_POST['dbhost'];
	if (array_key_exists("dbport", $_POST)) $dbport = $_POST['dbport'];
	if (array_key_exists("dbuser", $_POST)) $dbuser = $_POST['dbuser'];
	if (array_key_exists("dbpw", $_POST)) $dbpw = $_POST['dbpw'];
	if (array_key_exists("dbname", $_POST)) $dbname = $_POST['dbname'];
	$cgibin = "";
	if (array_key_exists("cgibin", $_POST)) $cgibin = $_POST['cgibin'];
	if (array_key_exists("isv", $_POST)) $isv = $_POST['isv'];
	if (array_key_exists("usererr", $_POST)) $usererr = $_POST['usererr'];
	if (array_key_exists("passerr", $_POST)) $passerr = $_POST['passerr'];

	if ($cgibin == "")
	{
/*
 *	    V12.2 - autodetect cgi-bin directory here.
 */
 	    if (file_exists("../../cgi-bin")) $cgibin = "../../cgi-bin";
	    else if (file_exists("../cgi-bin")) $cgibin = "../cgi-bin";
	    else if (file_exists("/usr/lib/cgi-bin")) /* Ubuntu default */
	    	$cgibin = "/usr/lib/cgi-bin";
	    else if (file_exists("../../../cgi-bin")) 
	    	$cgibin = "../../../cgi-bin";
	}
	$errors = 0;
	if (($usererr != "") || ($passerr != ""))
	{
            echo "<b><font color=\"#ff0000\">FORM has errors - please correct</font></b><br>";
	    $errors = 1;
	}
	if (array_key_exists("no_upgrade", $_POST)) $upgrade = 0;
	else $upgrade = 1;

	$errlevel = rlc_turn_off_warnings();
	$status = stat("../actpro");
	error_reporting($errlevel);

/*
 *	If the form has errors, they came from setup_doit.php, so we
 *	are overwriting.   We can skip this check...
 */
	if (($errors == 0) && $upgrade && $status)
	{
		$cwd = getcwd();
		rlc_web_title("", "setup.php");
		rlc_web_info("There is an installed version".
			" of RLM Activation Pro in:<br> <i>$cwd/../actpro".
			"</i>.<br>  Do you want to upgrade it?<br>");
		$extra = rlc_web_hidden_string("no_upgrade", "1");
		rlc_web_hidden("no_upgrade", "1");
		rlc_web_hidden("overwrite", "1");
		finish_page_extra("NO - Overwrite and Setup new Version", 0, 0, 
					"YES - Upgrade Installed version", 
					"upgrade.php", 0, 0, $extra, "");
	}
	else
	{
	    $ht = "&nbsp;&nbsp;&nbsp;&nbsp;";
	    rlc_web_title("", "setup_doit.php");
	    rlc_web_info("After you fill in this form and press \"Setup Activation Database\", your software will be copied and your Activation Pro database will be set up.<br><br>$ht You will want to change:<br>$ht $ht Database host: - to your database server name<br>$ht $ht Database user/password: - to your username/password for your MySQL database<br>$ht $ht ISV name: - to your RLM ISV name.<br><br>$ht The other parameters are probably fine as-is.");
	    if (array_key_exists('overwrite', $_POST))
	    {
		echo "<br><b>WARNING - YOU ARE ABOUT TO OVERWRITE ".
			"YOUR OLD INSTALLATION.  If you do not want ".
		        "to do this, select \"CANCEL\" below.</b><br><br>";
	    }
	    rlc_web_start_prompt();
	    echo "<tr><td><b><i>Database Setup</td></tr>";
	    echo "<tr><td>Database host:</td> <td><input type=text name=dbhost size=30 value=\"".$dbhost."\"></td></tr>";
	    echo "<tr><td>Database port:</td> <td><input type=text name=dbport size=10 value=\"".$dbport."\"></td></tr>";
	    echo "<tr><td>Database user:</td> <td><input type=text name=dbuser size=30 value=\"".$dbuser."\"></td></tr>";
	    echo "<tr><td>Database password:</td> <td><input type=text name=dbpw size=30 value=\"".$dbpw."\"></td></tr>";
	    echo "<tr><td>Database name:</td> <td><input type=text name=dbname size=30 value=\"".$dbname."\"></td><td>(No '.' or '-' characters)</td></tr>";
	    echo "<tr><td>webserver cgi-bin directory:</td> <td><input type=text name=cgibin size=30 value=\"".$cgibin."\"></td><td></td></tr>";
	    echo "<tr><td><b><i>ISV Setup</td></tr>";
	    echo "<tr><td>ISV name:</td> <td><input type=text name=isv size=10 value=\"".$isv."\"></td></tr>";
	    echo "<tr><td>Admin account name:</td> <td><input type=text name=admin size=30 value=\"".$admin."\"></td><td>";
	    if ($usererr != "")
       		echo "<b><font color=\"#ff0000\">".$usererr."</font></b>";
	    else if ($errors == 0)
	    	echo "MUST be lowercase letters and numbers only";
	    else
		echo "&nbsp;";
	    echo "</td></tr>";
	    echo "<tr><td>Admin account password:</td> <td><input type=text name=adminpw size=30 value=\"".$adminpw."\"></td><td>";
	    if ($passerr != "")
        	echo "<b><font color=\"#ff0000\">".$passerr."</font></b>";
	    else if ($errors == 0)
		echo "MUST be letters and numbers only";
	    else
		echo "&nbsp;";
	    echo "</td></tr>";

	    if (array_key_exists('overwrite', $_POST))
	    {
		echo "<tr><td><br><b>WARNING - YOU ARE ABOUT TO <br>".
				"OVERWRITE YOUR OLD INSTALLATION.<br>  If you ".
				"do not want to do this,<br>select \"CANCEL\" ".
				"below.</b></td></tr>";
	    }
	    if (array_key_exists("backto", $_POST)) 
	    {
		$backto = $_POST['backto'];
		rlc_web_hidden("backto", $backto);
	    }
	    finish_page("Setup Activation database", "CANCEL", "setup.php");
	}
?>
