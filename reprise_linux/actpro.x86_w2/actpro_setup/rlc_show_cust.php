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

 	$Id: rlc_show_cust.php,v 1.17 2017/03/07 01:02:41 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';

define("QUERY_KEY_CONTACT", "SELECT * FROM keyd WHERE (contact_id = %d)");

function _num_keys_contact($sql, $contact_id)
{
	$temp = sprintf(QUERY_KEY_CONTACT, $contact_id);
	$res = mysqli_query($sql, $temp);
	return(mysqli_num_rows($res));
}

function _quotit($in)
{
	_rlc_html_quote_string($in, $c1);
	$out = "\"".$c1."\"";
	return($out);
}

function make_cust_extra_edit($p, $select)
{
	$contact = _quotit($p['contact']);
	$contact_type = _quotit($p['contact_type']);
	$company = _quotit($p['company']);
	$title = _quotit($p['title']);
	$phone = _quotit($p['phone']);
	$fax = _quotit($p['fax']);
	$email = _quotit($p['email']);
	$info = _quotit($p['info']);
	$ccreate = _quotit($p['ccreate']);
	$addr1 = _quotit($p['addr1']);
	$addr2 = _quotit($p['addr2']);
	$addr3 = _quotit($p['addr3']);
	$city = _quotit($p['city']);
	$state = _quotit($p['state']);
	$zip = _quotit($p['zip']);
	$country = _quotit($p['country']);
	$c_notes = _quotit($p['c_notes']);
	$u1 = _quotit($p['u1']);
	$u2 = _quotit($p['u2']);
	$u3 = _quotit($p['u3']);
	$u4 = _quotit($p['u4']);
	$u5 = _quotit($p['u5']);
	$u6 = _quotit($p['u6']);
	$u7 = _quotit($p['u7']);
	$u8 = _quotit($p['u8']);
	$u9 = _quotit($p['u9']);
	$u10 = _quotit($p['u10']);

	$r = $select.
	     "<input type=hidden name=contact_id value=".$p['contact_id'].">
	      <input type=hidden name=contact value=".$contact.">
	      <input type=hidden name=contact_type value=".$contact_type.">
	      <input type=hidden name=company_id value=".$p['company_id'].">
	      <input type=hidden name=company value=".$company.">
	      <input type=hidden name=title value=".$title.">
	      <input type=hidden name=phone value=".$phone.">
	      <input type=hidden name=fax value=".$fax.">
	      <input type=hidden name=email value=".$email.">
	      <input type=hidden name=info value=".$info.">
	      <input type=hidden name=ccreate value=".$ccreate.">
	      <input type=hidden name=addr1 value=".$addr1.">
	      <input type=hidden name=addr2 value=".$addr2.">
	      <input type=hidden name=addr3 value=".$addr3.">
	      <input type=hidden name=city value=".$city.">
	      <input type=hidden name=state value=".$state.">
	      <input type=hidden name=zip value=".$zip.">
	      <input type=hidden name=country value=".$country.">
	      <input type=hidden name=u1 value=".$u1.">
	      <input type=hidden name=u2 value=".$u2.">
	      <input type=hidden name=u3 value=".$u3.">
	      <input type=hidden name=u4 value=".$u4.">
	      <input type=hidden name=u5 value=".$u5.">
	      <input type=hidden name=u6 value=".$u6.">
	      <input type=hidden name=u7 value=".$u7.">
	      <input type=hidden name=u8 value=".$u8.">
	      <input type=hidden name=u9 value=".$u9.">
	      <input type=hidden name=u10 value=".$u10.">
	      <input type=hidden name=c_notes value=".$c_notes.">";
	return($r);
}

function make_cust_extra($p, $select)
{
	_rlc_html_quote_string($p['contact'], $c1);
	$contact = "\"".$c1."\"";
	_rlc_html_quote_string($p['company'], $c2);
	$company = "\"".$c2."\"";

	$r = $select.
	     "<input type=hidden name=contact_id value=".$p['contact_id'].">
	      <input type=hidden name=contact value=".$contact.">
	      <input type=hidden name=company_id value=".$p['company_id'].">
	      <input type=hidden name=company value=".$company.">";
	return($r);
}

/*
 *	Get the selection data for the product list
 */

function get_selection_data($cols, $sel_data)
{
	$head = array("Name", "Contact Type", "Title", "Company", "Phone", "Email", "Info");
	rlc_web_browse_select("rlc_show_cust.php", $sel_data, $head, $cols);
}


/*
 *	Customer browser - outputs a list of customers
 */
	
	rlc_web_rpp("rlc-rpp-cust");
	rlc_web_header(RLC_MENU_CUST, $session);
	$sql = rlc_mysql_init($isv);
	$perm = check_user($session);

	if (!$perm['act_view_enabled'])
	{
	    rlc_noview($session);
	    finish_page(0, 0, 0);
	    return;	/* Fix P280 */
	}
/*
 *		Get selection criteria
 */
	rlc_web_title("Customers", "rlc_show_cust.php");
/*
 *	The pagination code needs this for the first button to work.
 */
	echo "<form method='get' action='rlc_show_cust.php'></form>";
	if ($perm['act_edit_enabled'])
		rlc_web_button("rlc_add_cust.php", "Add Customer", "", 0);

	$select_data = array("");
  	$cols = array("contact", "contact_type", "title", "company", "phone", 
							"email", "info");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);

	get_selection_data($cols, $select_data);

	$get = rlc_web_get_pagination($r1, $rpp, $tr, $sc, $sd, "rlc-rpp-cust");

	$active = $count = 0;
	$sql = rlc_mysql_init($isv);
	for ($i=1; $i<=10; $i++)
	{
	    rlc_mysql_read_rlc_setup($sql, "u".$i."_def", $u);
	    rlc_mysql_read_rlc_setup($sql, "u".$i."_numeric", $u);
	}

	$stat = rlc_mysql_get_customers($sql, $cust, $sc, $sd, $select);

	if ($stat != 0)
	{
	    if ($stat == -2)
		$tmp = sprintf("No customer data found (status: %s)<br>", 
									$stat);
	    else
		$tmp = sprintf("Cannot read customer data, status: %s<br>",
									$stat);
	    rlc_web_info($tmp);
	    finish_page(0, 0, 0);
	    rlc_mysql_close($sql);
	    return;
	}

	if ($tr == 0)
	{
	        $tr = mysqli_num_rows($cust);
	}
	if ($r1 > 1)
	{
		mysqli_data_seek($cust, $r1-1);
	}

	echo "<br>";
	rlc_web_paginate("rlc_show_cust.php", $xtra, $pxtra, $rpp, $r1, -1,
						      $tr, $sc, $sd, "");
	rlc_web_form("rlc_merge_cust.php");
	rlc_web_tableheader();
	rlc_web_row_start();
	$sort = $xtra."&r1=".$r1."&rpp=".$rpp."&tr=".$tr;
	if ($perm['act_edit_enabled']) rlc_web_row_elem("");
	rlc_web_header_elem("Name", $sort, "contact", $sc, $sd);
	rlc_web_header_elem("Contact Type", $sort, "contact_type", $sc, $sd);
	rlc_web_header_elem("Title", $sort, "title", $sc, $sd);
	rlc_web_header_elem("Company", $sort, "company", $sc, $sd);
	rlc_web_header_elem("Phone", $sort, "phone", $sc, $sd);
	rlc_web_header_elem("Fax", $sort, "fax", $sc, $sd);
	rlc_web_header_elem("Email", $sort, "email", $sc, $sd);
	rlc_web_header_elem("Info", $sort, "info", $sc, $sd);
	rlc_web_header_elem("Address", $sort, "state", $sc, $sd);
	rlc_web_header_elem("Notes", $sort, "c_notes", $sc, $sd);
	for ($i=1; $i<=10; $i++)
	{
	    $u[$i] = 0;
	    if (array_key_exists('u'.$i.'_def', $u))
	    {
		$u[$i] = 1;
		$n = 0;
		if (array_key_exists('u'.$i.'_numeric', $u)) 
			$n = $u['u'.$i.'_numeric'];
		rlc_web_header_elem($u['u'.$i.'_def'], $sort, "u".$i, $sc, $sd,
									$n);
	    }
	}
	rlc_web_header_elem("Created", $sort, "ccreate", $sc, $sd);
	dummy_edit_button("rlc_add_cust.php", ""); /* To make 1st button work */
	rlc_web_row_end();
	$numdisp = 0;

	while ($row = mysqli_fetch_array($cust, MYSQLI_ASSOC))
	{
		$count++;
		rlc_web_row_start();

		$contact_id = "Contact ID: ".$row['contact_id'];
		$contact_name = "<abbr title=\"".$contact_id."\">".
						$row['contact']."</abbr>";
/*
 *		Checkbox for merge, if appropriate
 */
 		if ($perm['act_edit_enabled'])
		{
		    rlc_web_checkbox("", MERGE_ITEM.$numdisp, 
		    				$row['contact_id'], 0, 1);
		}
		rlc_web_row_elem($contact_name);
		rlc_web_row_elem($row['contact_type']);
		rlc_web_row_elem($row['title']);
		rlc_web_row_elem($row['company']);
		rlc_web_row_elem($row['phone']);
		rlc_web_row_elem($row['fax']);
		rlc_web_row_elem($row['email']);
		rlc_web_row_elem($row['info']);
		$addrfields = array("addr1", "addr2", "addr3", "city", "state",
					"zip", "country");
		$address = "";
		$addcomma = false;
		foreach ($addrfields as $field)
		{
			if ($addcomma) $address .= ", ";
			$addcomma = false;
			if ($row[$field] != "") 
			{
				$address .= $row[$field];
				$addcomma = true;
			}
		}
		rlc_web_row_elem($address);
		rlc_web_row_elem($row['c_notes']);
		for ($i=1; $i<=10; $i++)
		{
		    if ($u[$i]) rlc_web_row_elem($row['u'.$i]);
		}
		rlc_web_row_elem($row['ccreate']);

/*
 *		The edit/show/delete buttons
 */
		if ($perm['act_edit_enabled'])
		{
			$x = rlc_web_hidden_string("edit_customer", 1).$pxtra;
			edit_button("rlc_add_cust.php", 
						make_cust_extra_edit($row, $x));
 
/*
 *			Figure out how many activation keys there are for
 *			this product to see if we can delete it....
 */
			$numkeys = _num_keys_contact($sql, $row['contact_id']);
			if ($numkeys == 0)
			{
		    		rlc_web_delete_button("rlc_del_cust.php", 
						make_cust_extra($row, $pxtra));
			}
		}
		rlc_web_row_end();
		$numdisp++;
		if ($numdisp >= $rpp) break;
	}
	rlc_web_table_end();
	mysqli_free_result($cust);
	if ($perm['act_edit_enabled'])
	{
	    rlc_web_sel_multiple("rlc_merge_cust.php");
	}

	rlc_web_paginate("rlc_show_cust.php", $xtra, $pxtra, $rpp, $r1, 
							$r1 + $numdisp - 1,
						      $tr, $sc, $sd, "");
	rlc_mysql_close($sql);
	finish_page(0, "Add Customer", "rlc_add_cust.php");
?>
