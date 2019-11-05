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

 	$Id: rlc_upload_cust.php,v 1.11 2017/06/20 02:44:39 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Upload the customer data - do the operation
 */

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    return;
	}
	$sql = rlc_mysql_init($isv);

	$errors = 0;
	echo '<pre>';
	if ($_FILES['custfile']['tmp_name'] ==  "")
	{
	    echo "Error - no upload file specified<br>";
	    return;
	}
	$data = file($_FILES['custfile']['tmp_name']);
	$sqlcmd = "";
	$count = 0;
/*
 *	OK, each line should be tab-separated data with the following
 *	fields (all fields must be present):
 *		contact name, contact type, title, phone, fax, email, info,
 *		company name, addr1, addr2, addr3, city, state, zip, country,
 *		notes, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10.
 */

define("CONTACT", 0);
define("CONTACT_TYPE", 1);
define("TITLE", 2);
define("PHONE", 3);
define("FAX", 4);
define("EMAIL", 5);
define("INFO", 6);

define("COMPANY", 7);
define("ADDR1", 8);
define("ADDR2", 9);
define("ADDR3", 10);
define("CITY", 11);
define("STATE", 12);
define("ZIP", 13);
define("COUNTRY", 14);
define("NOTES", 15);
define("USER", 16);

	$count = $errors = 0;
	$lineno = 0;
	foreach ($data as $line)
	{
	    $lineno++;
	    $sqlcmd .= $line;
	    $d = explode("	", $line, 27);
	    $num = count($d);
	    if ($num < (USER+9))
	    {
		echo "ERROR: input line $lineno has only $num elements.  Skipped<br>";
		$errors++;
		continue;
	    }
	    if ($d[CONTACT] == "")
	    {
		echo "ERROR: input line $lineno has no contact person.  Skipped<br>";
		$errors++;
		continue;
	    }
/*
 *	    Debug output.  Turned off.
 *
	    if (($errors == 0) && ($count == 0))
	    {
		echo "line is \"$line\"<br>";
		echo "exploded line is ";
		print_r($d);
		echo "<br>";
	    }
/***/
/*
 *	    First, see if this company is in the db.
 */
	    _rlc_act_quote_string(substr($d[COMPANY], 0, 60), $co);
	    _rlc_act_quote_string(substr($d[ADDR1], 0, 60), $addr1);
	    _rlc_act_quote_string(substr($d[ADDR2], 0, 60), $addr2);
	    _rlc_act_quote_string(substr($d[ADDR3], 0, 60), $addr3);
	    _rlc_act_quote_string(substr($d[CITY], 0, 60), $city);
	    _rlc_act_quote_string(substr($d[STATE], 0, 60), $state);
	    _rlc_act_quote_string(substr($d[ZIP], 0, 60), $zip);
	    _rlc_act_quote_string(substr($d[COUNTRY], 0, 60), $country);
	    $select = "where (company=\"".$co."\") and ".
				"(addr1=\"".$addr1."\") and ".
				"(addr2=\"".$addr2."\") and ".
				"(addr3=\"".$addr3."\") and ".
				"(city=\"".$city."\") and ".
				"(state=\"".$state."\") and ".
				"(zip=\"".$zip."\") and ".
				"(country=\"".$country."\")";

	    $r = rlc_mysql_get_companies($sql, $company, "", "", $select); 
	    if ($r == 0)
	    {
		$comp = mysqli_fetch_array($company, MYSQLI_ASSOC);
	    }
	    else
	    {
		$comp['company_id'] = 0;
	    }
	    $comp['company'] = $co;
	    $comp['addr1'] = $addr1;
	    $comp['addr2'] = $addr2;
	    $comp['addr3'] = $addr3;
	    $comp['city'] = $city;
	    $comp['state'] = $state;
	    $comp['zip'] = $zip;
	    $comp['country'] = $country;
	    _rlc_act_quote_string(substr($d[NOTES], 0, 255), $comp['c_notes']);
	    _rlc_act_quote_string(substr($d[USER], 0, 60),   $comp['u1']);
	    _rlc_act_quote_string(substr($d[USER+1], 0, 60), $comp['u2']);
	    _rlc_act_quote_string(substr($d[USER+2], 0, 60), $comp['u3']);
	    _rlc_act_quote_string(substr($d[USER+3], 0, 60), $comp['u4']);
	    _rlc_act_quote_string(substr($d[USER+4], 0, 60), $comp['u5']);
	    _rlc_act_quote_string(substr($d[USER+5], 0, 60), $comp['u6']);
	    _rlc_act_quote_string(substr($d[USER+6], 0, 60), $comp['u7']);
	    _rlc_act_quote_string(substr($d[USER+7], 0, 60), $comp['u8']);
	    _rlc_act_quote_string(substr($d[USER+8], 0, 60), $comp['u9']);
	    _rlc_act_quote_string(substr($d[USER+9], 0, 60), $comp['u10']);
	    /* echo "Company id after reading: ".$comp['company_id']."<br>"; */
	    $r = rlc_mysql_write_company($sql, $comp);
	    if (!$r)
	    {
		echo "<b>Error creating company record for $d[COMPANY]</b><br>";
		$errors++;
		continue;
	    }
/*
 *	    Read the record to get the company id
 */
	    $r = rlc_mysql_get_companies($sql, $company, "", "", $select); 
	    if ($r == 0)
	    {
	    	$comp = mysqli_fetch_array($company, MYSQLI_ASSOC);
	    }
	    else
	    {
		echo "<b>Error reading company record for ".$d[COMPANY].
							"</b><br>";
		$errors++;
		continue;
	    }
/*
 *	    Now, write the contact info.
 *	    First, see if this contact is in the db.
 */
	
	    _rlc_act_quote_string(substr($d[CONTACT], 0, 60), $pers);
	    _rlc_act_quote_string(substr($d[EMAIL], 0, 60), $email);
	    $select = "where (contact=\"".$pers."\") and ".
				"(email=\"".$email."\")";

	    $r = rlc_mysql_get_customers($sql, $contact, "", "", $select); 
	    if ($r == 0)
	    {
		echo "<b>Contact ".$d[CONTACT]." already in database.</b><br>";
		continue;
	    }
	    $person['contact'] = $pers;
	    _rlc_act_quote_string(substr($d[TITLE], 0, 60), $person['title']);
	    _rlc_act_quote_string(substr($d[CONTACT_TYPE], 0, 60), 
	    					$person['contact_type']);
	    _rlc_act_quote_string(substr($d[PHONE], 0, 60), $person['phone']);
	    _rlc_act_quote_string(substr($d[FAX], 0, 60), $person['fax']);
	    $person['email'] = $email;
	    _rlc_act_quote_string(substr($d[INFO], 0, 60), $person['info']);
	    $person['company_id'] = $comp['company_id'];
	    $person['contact_id'] = 0;
	    $person['ccreate'] = date("Y-m-d", time());	
	    $r = rlc_mysql_write_cust($sql, $person);
	    if (!$r)
	    {
		echo "<b>Error creating contact record for $d[CONTACT]</b><br>";
		$errors++;
		continue;
	    }
	    $count++;
	}

/*
 *	Delete the file
 */
	unlink($_FILES['custfile']['tmp_name']);
	echo "<br><b>Customer import complete, $count records imported, $errors errors.</b><br>";

	rlc_mysql_close($sql);
	finish_page_extra(0, "Back", "rlc_admin_db.php", 0, 0, 0, 0, "", "");
?>
