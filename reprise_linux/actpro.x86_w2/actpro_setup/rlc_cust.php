<?php
/*****************************************************************************

	    COPYRIGHT (c) 2007, 2016 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_cust.php,v 1.9 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

function display_form($sql, $who, $contact, $company, $create)
{
	$sql = rlc_mysql_init($isv);
	rlc_mysql_get_companies($sql, $companies, "company", "a", ""); 
	rlc_mysql_read_rlc_setup($sql, "u1_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u2_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u3_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u4_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u5_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u6_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u7_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u8_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u9_def", $u);
	rlc_mysql_read_rlc_setup($sql, "u10_def", $u);
	rlc_mysql_get_contact_types($sql, $contact_types);
	rlc_mysql_close($sql);

	echo "<table border=1><tr><td>";
/*
 *	Next, the company form
 */
 	rlc_web_title("Company Info", "rlc_add_cust.php");
	rlc_web_start_prompt();
	rlc_web_prompt("Company", $company['company'], "company", 30);
	rlc_web_prompt("Addr line 1", $company['addr1'], "addr1", 30);
	rlc_web_prompt("Addr line 2", $company['addr2'], "addr2", 30);
	rlc_web_prompt("Addr line 3", $company['addr3'], "addr3", 30);
	rlc_web_prompt("City", $company['city'], "city", 30);
	rlc_web_prompt("State", $company['state'], "state", 30);
	rlc_web_prompt("ZIP/Postal code", $company['zip'], "zip", 30);
	rlc_web_prompt("Country", $company['country'], "country", 30);
	rlc_web_prompt("Notes", $company['c_notes'], "c_notes", 30);
	rlc_web_hidden("company_id", $company['company_id']);
	rlc_web_hidden("submit_form_company", "1");
	if (array_key_exists('u1_def', $u))
	    rlc_web_prompt($u['u1_def'], $company['u1'], "u1", 30);
	if (array_key_exists('u2_def', $u))
	    rlc_web_prompt($u['u2_def'], $company['u2'], "u2", 30);
	if (array_key_exists('u3_def', $u))
	    rlc_web_prompt($u['u3_def'], $company['u3'], "u3", 30);
	if (array_key_exists('u4_def', $u))
	    rlc_web_prompt($u['u4_def'], $company['u4'], "u4", 30);
	if (array_key_exists('u5_def', $u))
	    rlc_web_prompt($u['u5_def'], $company['u5'], "u5", 30);
	if (array_key_exists('u6_def', $u))
	    rlc_web_prompt($u['u6_def'], $company['u6'], "u6", 30);
	if (array_key_exists('u7_def', $u))
	    rlc_web_prompt($u['u7_def'], $company['u7'], "u7", 30);
	if (array_key_exists('u8_def', $u))
	    rlc_web_prompt($u['u8_def'], $company['u8'], "u8", 30);
	if (array_key_exists('u9_def', $u))
	    rlc_web_prompt($u['u9_def'], $company['u9'], "u9", 30);
	if (array_key_exists('u10_def', $u))
	    rlc_web_prompt($u['u10_def'], $company['u10'], "u10", 30);

	if ($create)
		finish_form("Add Company Info", "");
	else
	{
		rlc_web_hidden("edit_customer", 1);
		finish_form("Update Company Info", "");
	}

	echo "</td><td>";

/*
 *	Next, the create contact person form.
 */
 	rlc_web_title("Contact Person Info", "rlc_add_cust.php");
	rlc_web_start_prompt();
	rlc_web_prompt("Contact Person", $contact['contact'], "contact", 30);
	rlc_web_prompt_contact_type($contact_types, $contact['contact_type']);
	rlc_web_prompt("Title", $contact['title'], "title", 30);
	rlc_web_prompt("Phone", $contact['phone'], "phone", 30);
	rlc_web_prompt("Fax", $contact['fax'], "fax", 30);
	rlc_web_prompt("Email", $contact['email'], "email", 30);
	rlc_web_prompt("Other Info", $contact['info'], "info", 30);
	rlc_web_prompt_company($contact['company_id'], $companies, 1);
	echo "<tr><td>&nbsp;</td></tr>";
	rlc_web_hidden("submit_form_contact", "1");
	rlc_web_hidden("contact_id", $contact['contact_id']);
	if ($create)
		finish_form("Add Contact Person Info", "");
	else
	{
		rlc_web_hidden("ccreate", $contact['ccreate']);
		rlc_web_hidden("edit_customer", 1);
		finish_form("Update Contact Person Info", "");
	}

	echo "</td></table>";

	return(0);
}

function display_create_form($sql, $who, $contact, $company, $xtra)
{
	rlc_web_title("Add New Customer", "rlc_add_cust.php");
	rlc_web_info("Click \"ADD Company Info\" or ".
			"\"Add Contact Person Info\"".
			" below to create the company or contact person<br>".
			"record.  If you are adding a completely new customer,".
			" add the company first, then add the contact person.");
	display_form($sql, $who, $contact, $company, 1);
	echo $xtra;
	finish_page_extra(0, "Return to Customer List", "rlc_show_cust.php", 
						0, 0, 0, 0, $xtra, "");
}

function display_edit_form($sql, $who, $contact, $company, $xtra)
{
	rlc_web_title("Edit Customer Data", "rlc_add_cust.php");
	rlc_web_info("Click \"Update\" to update either the company".
			" or contact person info below.<br>");
	display_form($sql, $who, $contact, $company, 0);
	echo $xtra;
	finish_page_extra(0, "Return to Customer List", "rlc_show_cust.php", 
						0, 0, 0, 0, $xtra, "");
}

?>
