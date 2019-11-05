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

 	$Id: rlc_del_cust.php,v 1.10 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_mysql.php";
include "login_session.php";


define("QUERY_CONTACT_COMPANY", "SELECT * FROM contact WHERE (company_id = %d)");

function _num_contact_customer($sql, $company_id)
{
	$temp = sprintf(QUERY_CONTACT_COMPANY, $company_id);
	$res = mysqli_query($sql, $temp);
	return(mysqli_num_rows($res));
}

/*
 *	Prompt to delete the contact.  If there are no
 *	contacts left for the company, then prompt to delete
 *	the company.
 */

	rlc_web_header(RLC_MENU_CUST, $session);

	if (!$session->canEdit())
        {
	    echo "You must log in to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	if (array_key_exists('contact_id', $_POST))
		$contact_id = $_POST['contact_id']; 
	else
		$contact_id = 0;
	if (array_key_exists('contact', $_POST))
	{
		$contact = $_POST['contact']; 
		$who = $contact;
	}
	else
	{
		$contact = "";
		$who = "(id: ".$contact_id.")";
	}
	_rlc_html_quote_string($contact, $contact_post);
	if (array_key_exists('company_id', $_POST))
		$company_id = $_POST['company_id']; 
	else
		$company_id = 0;
	if (array_key_exists('company', $_POST))
	{
		$company = $_POST['company']; 
		$comp = $company;
	}
	else
	{
		$company = "";
		$comp = "(id: ".$company.")";
	}
	_rlc_html_quote_string($company, $company_post);
	if (array_key_exists('phase', $_POST))
		$phase = $_POST['phase']; 
	else
		$phase = 0;

	$cols = array("contact", "title", "company", "phone", "email", "info");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);

	if ($phase == 0)
	{
		if ($contact_id == 0)
		{
			echo "<br><h2>No contact to delete - ID is NULL</h2>";
			echo $pxtra;
			finish_page(0, 0, 0);
		}
		rlc_web_title("Delete Customer Record", "rlc_del_cust.php");
		rlc_web_start_prompt();
	        echo "<h3>Delete customer contact record for <i>\"".$contact.
						"</i>\" - Are you sure?</h3>";
		rlc_web_hidden("contact_id", $contact_id);
		rlc_web_hidden("contact", $contact_post);
		rlc_web_hidden("company_id", $company_id);
		rlc_web_hidden("company", $company_post);
		rlc_web_hidden("phase", 1);
		echo $pxtra;
		finish_page_extra("Delete", "Cancel", "rlc_show_cust.php",
						0, 0, 0, 0, $pxtra, "");
	}
	else if ($phase == 1)
	{
 		$sql = rlc_mysql_init($isv);
		$res = rlc_mysql_del_contact($sql, $contact_id);

		if ($res)
		{
		    echo "Contact deleted<br>";
		    $res = rlc_mysql_add_audit($sql, $session->username,
					"delete", $who, "contact");
		}
		else
		{
		    echo "Contact not deleted<br>";
		    echo "Error: ".mysqli_error($sql)."<br>";
		}

		$numcontact = _num_contact_customer($sql, $company_id);
		rlc_mysql_close($sql);

		$next = "rlc_show_cust.php";
		$back = "Back to Customer List";
		if ($numcontact == 0) 
		{
			$next = "rlc_del_cust.php";
			$back = "Continue";
		}
		rlc_web_title("Deleting Customer Record", $next);
		echo $pxtra;
		echo "Contact Record \"$contact\" deleted<br><br>";
		rlc_web_hidden("phase", 2);
		rlc_web_hidden("company_id", $company_id);
		rlc_web_hidden("company", $company_post);
		finish_page($back, 0, 0);
	}
	else if ($phase == 2)
	{
		rlc_web_title("Delete Company  Record", "rlc_del_cust.php");
		rlc_web_start_prompt();
	        echo "<h3>There are no contacts associated with company <i>\"".
				$company.  "</i>\" - Delete company?</h3>";
		rlc_web_hidden("company_id", $company_id);
		rlc_web_hidden("company", $company_post);
		rlc_web_hidden("phase", 3);
		echo $pxtra;
		finish_page_extra("Delete", "Don't Delete", "rlc_show_cust.php",
						0, 0, 0, 0, $pxtra, "");
	}
	else if ($phase == 3)
	{
		rlc_web_title("Deleting Company Record", "rlc_show_cust.php");
 		$sql = rlc_mysql_init($isv);
		$res = rlc_mysql_del_company($sql, $company_id);
		if ($res)
		{
		    echo "Company Record \"$company\" deleted<br><br>";
		    $res = rlc_mysql_add_audit($sql, $session->username,
					"delete", $comp, "company");
		}
		else
		{
		    echo "Company not deleted<br>";
		    echo "Error: ".mysqli_error($sql)."<br>";
		}
		rlc_mysql_close($sql);

		echo $pxtra;
		finish_page("Back to Customer List", 0, 0);
	}
?>
