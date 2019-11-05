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

 	$Id: portal_show_key.php,v 1.35 2017/03/07 01:02:41 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "portal_mysql.php";
include 'login_session.php';

function make_key_extra($k, $extra)
{
	$r = $extra."<input type=hidden name=akey value=\"".$k['akey']."\">";
	return($r);
}


/*
 *	Get the selection data for the activation key list
 */

function get_selection_data($cols, $sel_data)
{
	$head = array("Activation Key", "Product Name", "Exp Date", 
			"Version", "Whitelist", "Extra Lic. Data", 
			"Notes", "Contact", "Email", "Company");

	rlc_web_browse_select("portal_show_key.php", $sel_data, $head, $cols);
}


/*
 *	Display all the activation keys
 */

	rlc_web_rpp("rlc-rpp-key");
	rlc_web_header(RLC_MENU_KEY, $session);
	$perm = check_user($session);
	rlc_web_title("Activation Keys", 0);

	if (!$perm['act_portal_enabled'])
	{
		rlc_noview($session);
		finish_page_extra(0, "Back", "rlc_info.php", 0, 0, 0, 0, "","");
		return;
	}
/*
 *	The admin tab sets delrevoked to allow deleting keys
 *	with no fulfillents but with revoked fulfillments.
 */
	$delrevoked = rlc_getinput("delrevoked", 0);

	$sql = portal_mysql_init($session->company_id, $isv);
	/* P343 - changed "customer" to "company" below */
	/* P379 - changed "exp" to "portal_keyd_$session->company_id.exp" below */
	$cols = array("portal_keyd_$session->company_id.akey", "name", "portal_keyd_$session->company_id.exp", "kver", "white", 
				"portal_keyd_$session->company_id.misc", "notes", "contact", "email",
				"company");
	if ($perm['act_edit_enabled'])
	    rlc_web_button("rlc_create_key.php", "Create New Activation Key", 
								"", 0);
/*
 *	Get selection criteria
 */
	$select_data = array("");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);

	if ($delrevoked == 1) 
	{
	    $pxtra .= rlc_web_hidden_string("delrevoked", $delrevoked);
	    $xtra .= "&delrevoked=1";
	}
	get_selection_data($cols, $select_data);

	$get = rlc_web_get_pagination($r1, $rpp, $tr, $sc, $sd, "rlc-rpp-key");

	$stat = portal_mysql_get_keys_with_contact($session->company_id, $sql, $keys, $sc, $sd, $select);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read activation keys, status: $stat<br>");
		finish_page_extra(0, "Back", "rlc_info.php", 0, 0, 0, 0, "","");
		portal_mysql_close($session->company_id, $sql);
		return;
	}

	if ($tr == 0)
	{
		$tr = mysqli_num_rows($keys);
	}

	if ($tr == 0)
	{
	    	echo "No activation keys to display<br>";
		finish_page(0, 0, 0);
		portal_mysql_close($session->company_id, $sql);
		return;
	}
	$first = 0;
	if ($r1 < 1) $r1 = 1;
	if ($r1 > 1)
	{
		mysqli_data_seek($keys, $r1-1);
		$first = $r1 - 1;
	}

/*
 *	Figure out if we have any REFRESH keys.  If not, don't display
 *	the # rehosts column.  Also, if we have any SUBSCRIPTION-NL keys,
 *	display the renewal period and grace days columns
 */
	$curkey = $firstkey = $r1 - 1;
	$lastkey = $firstkey + $rpp - 1;
	$refresh_keys = $subscrip_keys = 0;
	$rownum = $r1;

	while ($row = mysqli_fetch_array($keys, MYSQLI_ASSOC))
	{
	    if ($row['type'] == RLM_ACT_KEY_TYPE_REFRESH) 
	    	$refresh_keys = 1;
	    if ($row['type'] == RLM_ACT_KEY_TYPE_SUBSCRIPTION) 
	    	$subscrip_keys = 1;
	    if ($refresh_keys && $subscrip_keys) break;
	    $rownum++;
	    if ($rownum >= $lastkey) break;
	}
	$numdisp = 0;
	mysqli_data_seek($keys, $r1-1);
	$first = $r1 - 1;

	rlc_web_paginate("portal_show_key.php", $xtra, $pxtra, $rpp, $r1, -1, 
							$tr, $sc, $sd, "");

	rlc_web_form("rlc_del_key.php");
	rlc_web_tableheader();
	rlc_web_row_start();
	$sort = $xtra."&r1=".$r1."&rpp=".$rpp."&tr=".$tr;
	if ($perm['act_edit_enabled']) rlc_web_row_elem("");
	rlc_web_header_elem("Activation Key", $sort, "portal_keyd_$session->company_id.akey", $sc, $sd);
	rlc_web_header_elem("Enabled", $sort, "active", $sc, $sd);
	rlc_web_header_elem("Product", $sort, "name", $sc, $sd);
	rlc_web_header_elem("Count", $sort, "count", $sc, $sd);
	/* TODO: sort by # fulfilled */
	rlc_web_header_elem("# Fulfilled", $sort, "", $sc, $sd);
/* 
 *	It turns out the text of activtion type is ordered the same
 *	    as the value, so we got lucky!
 */
	rlc_web_header_elem("Type", $sort, "type", $sc, $sd);
	if ($refresh_keys)
	     rlc_web_header_elem("# rehosts allowed", $sort, "rehosts", $sc, 
	    								$sd);
	if ($subscrip_keys)
	{
	    rlc_web_header_elem("subscrip. interval", $sort, "sub_interval", 
	    							$sc, $sd);
	    rlc_web_header_elem("subscrip. window", $sort, "sub_window", $sc,
	    								$sd);
	}
	rlc_web_header_elem("# revoked", $sort, "num_revoked", $sc, $sd);
	rlc_web_header_elem("Last Date Valid", $sort, "lastdate", $sc, $sd);
	/* P379 - changed "exp" to "portal_keyd_$session->company_id.exp" below */
	rlc_web_header_elem("Exp", $sort, "portal_keyd_$session->company_id.exp", $sc, $sd);
	rlc_web_header_elem("Ver", $sort, "kver", $sc, $sd);
	rlc_web_header_elem("Whitelist", $sort, "white", $sc, $sd);
	rlc_web_header_elem("Other License Data", $sort, "misc", $sc, $sd);
	rlc_web_header_elem("Notes", $sort, "notes", $sc, $sd);
	rlc_web_header_elem("Contact", $sort, "contact", $sc, $sd);
	rlc_web_header_elem("Email", $sort, "email", $sc, $sd);
	rlc_web_header_elem("Company", $sort, "company", $sc, $sd);
	rlc_web_header_elem("Created", $sort, "kcreate", $sc, $sd);
	rlc_web_header_elem("SN", $sort, "ash_sn", $sc, $sd);
	rlc_web_button_invis();	/* To fix first edit icon */
	rlc_web_row_end();


	while ($row = mysqli_fetch_array($keys, MYSQLI_ASSOC))
	{
		if ($row['active']) 
		{
		    rlc_web_normal_bg();
		}
		else
		{
		    rlc_web_grey_bg();
		}

		rlc_web_row_start();

		$num = $row['num'];
		$rehosts = $row['rehosts'];
		$revoked = $row['num_revoked'];
/*
 *		Checkbox for delete, if appropriate
 */
		if ($perm['act_edit_enabled'])
		{
/*		
 *
 *		    V12.0 - allow deletion of keys with revoked licenses if
 *			called from the admin tab.
 */
		    if (($num <= 0) && ($delrevoked || ($revoked == 0)))
 		    	rlc_web_checkbox("", DELETE_ITEM.$numdisp, $row['akey'],
								 0, 1);
		    else
			rlc_web_row_elem("");
		}

		if ($row['name']) 
		{
			$info = "License: ".  $row['product'].
				", Version: ".  $row['version'].
				", Type: ".  license_type($row['lictype']);

	    		$product = "<abbr title=\"".$info.
					"\">".$row['name']."</abbr>";
		}
		else	$product = "???";

		rlc_web_row_elem($row['akey']);
		rlc_web_row_elem($row['active'] ? "yes" : "no");
		rlc_web_row_elem($product);
		rlc_web_row_elem_num($row['count']);
		rlc_web_row_elem_num($num);
 		$act_types = array("normal", "reactivate", "refresh", 
						"normal-regen", "subscription");
		rlc_web_row_elem_num($act_types[$row['type']]);
		if ($refresh_keys) rlc_web_row_elem_num($rehosts);
		if ($subscrip_keys)
		{
		    if ($row['type'] == RLM_ACT_KEY_TYPE_SUBSCRIPTION)
		    {
		        $interval = $row['sub_interval'];
			if ($interval == RLM_ACT_SUBSCRIPTION_MONTH) 
				$interval = "monthly";
			else if ($interval == RLM_ACT_SUBSCRIPTION_QUARTER) 
				$interval = "quarterly";
			else if ($interval == RLM_ACT_SUBSCRIPTION_YEAR) 
				$interval = "yearly";
			else	$interval = $interval . " days";
			rlc_web_row_elem($interval);
			rlc_web_row_elem($row['sub_window']." days");
		    }
		    else
		    {
			rlc_web_row_elem('');
			rlc_web_row_elem('');
		    }
		}
		rlc_web_row_elem_num($revoked);
		rlc_web_row_elem($row['lastdate']);
		if ($row['exp'] == "") $expdate = "";
		else if (strpos($row['exp'], '-'))
			$expdate = $row['exp'];
		else if (($row['exp'] == "0") || ($row['exp'] == "permanent"))
			$expdate = "permanent";
		else
			$expdate = $row['exp']. " days";
		rlc_web_row_elem($expdate);

		$version = "";
		if ($row['kver'] != "")
		{
		    if ($row['kver_type'] == 0)
			$version = $row['kver'];
		    else
			$version = "+ ".$row['kver']." mo.";
		}
		rlc_web_row_elem($version);

		rlc_web_row_elem($row['white']);
		rlc_web_row_elem($row['misc']);
		rlc_web_row_elem($row['notes']);
		if ($row['contact_id']) 
		{
			$info = "";
			/* $comma = ""; */

			$_contact = $row['contact'];
			$a = $row['email'];
			if ($a != "") $_contact .= " ". $a;

			$a = $row['title'];
			if ($a != "") { $info = $a; /* $comma = ", "; */ }

			if ($info != "")
	    		    $cust = "<abbr title=\"".$info.
						"\">".$_contact."</abbr>";
			else
			    $cust = $_contact;
			$email = $row['email'];
			$company = $row['company'];
		}
		else	
		{
		    $cust = $email = $company = "";
		}
		rlc_web_row_elem($cust);
		rlc_web_row_elem($email);
		rlc_web_row_elem($company);
		rlc_web_row_elem($row['kcreate']);
	   	rlc_web_row_elem($row['ash_sn']);
/*
 *		The edit/show/delete buttons
 */
		if ($perm['act_edit_enabled'])
		{
		    edit_button("rlc_edit_key.php",
						make_key_extra($row, $pxtra));
		}
		if ($num > 0)
		{
		    $extra = $pxtra.
			      rlc_web_hidden_string("akey", $row['akey']).
			      rlc_web_hidden_string("back", "portal_show_key.php");
		    rlc_show_button("portal_show_fulfill.php", $extra);
		}
/*
 *		    If none have been fulfilled and there were none revoked,
 *			(pre 11.3 - we checked rehosts, which is wrong)
 *		    then we can safely delete this activation key - nothing
 *		    refers to it.
 *
 *		    V12.0 - allow deletion of keys with revoked licenses if
 *			called from the admin tab.
 */
		if ($perm['act_edit_enabled'] && ($num <= 0) && 
					($delrevoked || ($revoked == 0)))
		{
		    rlc_web_delete_button("rlc_del_key.php", 
						make_key_extra($row, $pxtra));
		}
		rlc_web_row_end();
		$numdisp++;
		if ($numdisp >= $rpp) break;
		$curkey++;
	}
	
	rlc_web_table_end(0);
	mysqli_free_result($keys);
	portal_mysql_close($session->company_id, $sql);

/*
 *	The check all/clear all/delete buttons
 */
	if ($perm['act_edit_enabled'])
	{
	    rlc_web_del_multiple("rlc_del_key.php");
	}

	rlc_web_paginate("portal_show_key.php", $xtra, $pxtra, $rpp, $r1, 
					$r1 + $numdisp - 1, $tr, $sc, $sd, "");
	if ($perm['act_edit_enabled'])
	    finish_page(0, "Create New Activation Key", "rlc_create_key.php");
	else
	    finish_page(0, 0, 0);
?>
