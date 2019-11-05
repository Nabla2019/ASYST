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

 	$Id: rlc_show_fulfill.php,v 1.25 2016/10/14 17:39:34 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';

/*
 *	Get the selection data for the fulfillment list
 */

function get_selection_data($cols, $sel_data)
{
	$head = array("Product Name", "Activation Key", "License Hostid", 
			"License Expiration", "Activated From", 
			"First Fulfill", "Last Check", "Company", 
			"Logged Data");
	rlc_web_browse_select("rlc_show_fulfill.php", $sel_data, $head, $cols);
}


	rlc_web_rpp("rlc-rpp-ful");
	rlc_web_header(RLC_MENU_FULFILL, $session);
	$perm = check_user($session);

	$back = rlc_getinput('back', "rlc_show_fulfill.php");

	if ($back == "rlc_show_fulfill.php") $backtxt = "";
	else				     $backtxt = "Back";

	rlc_web_title("Activation Fulfillments", $back);

	if (!$perm['act_view_enabled'])
	{
		rlc_noview($session);
		finish_page(0, 0, 0);
		return;
	}

	$cols = array("name", "licf.akey", "license_hostid", "expdate", 
					"remote_host", "time", 
					"last_check", "company", "log");

	$akey = rlc_getinput('akey', "");

	if ($akey != "")
/*
 *	This handles the case where akey was passed in - it has to
 *	match exactly.
 */
	{
	    $select = " WHERE licf.akey = '".$akey."'";
	    $extra = "akey=".$akey."&";
	    $pextra = "<input type=hidden name=akey value='".$akey."'>".
			  "<input type=hidden name=r-akey value=1>";
	    echo "</form>";	/* P416 - get rid of the "show" form */
	}
	else
	{

	    $select_data = array("");
	    $select = rlc_web_get_select($cols, $select_data, $extra, $pextra);
	    get_selection_data($cols, $select_data);
	}

	$extra .= "back=".$back."&";
	$pextra .= rlc_web_hidden_string('back', $back);
	$get = rlc_web_get_pagination($r1, $rpp, $tr, $sc, $sd, "rlc-rpp-ful");

	$sql = rlc_mysql_init($isv);
	$numrec = 0;

	$stat = rlc_mysql_get_fulfillments($sql, $select, $fulfill, $sc, $sd);
	if ($stat != 0)
	{
	    echo "No fulfillments to display ";
	    if ($akey != "") echo "for activation key <b>".$akey. "</b>";
	    if ($backtxt != "")
		finish_page_extra("", "", 0, $backtxt, $back, 0, 0, $pextra,
									"");
	    rlc_mysql_close($sql);
	    return;
	}

	if ($tr == 0)
	{
	    $tr = mysqli_num_rows($fulfill);
        }
	if ($r1 > 1)
	{
	    mysqli_data_seek($fulfill, $r1-1);
	}

	rlc_web_paginate("rlc_show_fulfill.php", $extra, $pextra, $rpp, 
						$r1, -1, $tr, $sc, $sd, "");
	rlc_web_form("rlc_del_fulfill.php");
	rlc_web_tableheader();
	rlc_web_row_start();
	$sort = $extra."&r1=".$r1."&rpp=".$rpp."&tr=".$tr;
	if ($perm['act_edit_enabled']) rlc_web_row_elem("");
	rlc_web_header_elem("Product Name", $sort, "name", $sc, $sd);
	rlc_web_header_elem("Activation key", $sort, "licf.akey", $sc, $sd);
	rlc_web_header_elem("Hostid", $sort, "license_hostid", $sc, $sd);
	rlc_web_header_elem("License Exp", $sort, "expdate", $sc, $sd);
	rlc_web_header_elem("Count", $sort, "licf.count", $sc, $sd);
	rlc_web_header_elem("Activated from", $sort, "remote_host", $sc, $sd);
	rlc_web_header_elem("First Fulfill", $sort, "time", $sc, $sd);
	rlc_web_header_elem("Last Fulfill", $sort, "last_fulfill", $sc, $sd);
	rlc_web_header_elem("# fulfills", $sort, "num_fulfills", $sc, $sd);
	rlc_web_header_elem("Last Check", $sort, "last_check", $sc, $sd);
	rlc_web_header_elem("Company", $sort, "company", $sc, $sd);
	rlc_web_header_elem("Notes", $sort, "notes", $sc, $sd);
	rlc_web_header_elem("Logged Data", $sort, "log", $sc, $sd);
	rlc_web_row_end();
	$numdisp = 0;
	while ($row = mysqli_fetch_array($fulfill, MYSQLI_ASSOC))
	{
	    	$numrec++;
	    	rlc_web_row_start();
/*
 *		Checkbox for delete
 */
	        if ($perm['act_edit_enabled'])
			rlc_web_checkbox("", DELETE_ITEM.$numdisp, $row['id'], 
								0, 1);
	    	$product = $row['name'];
		if (!$row['active']) $product = $product." (<i>inactive</i>)";
		if ($row['obsolete']) $product = $product." (<i>obsolete</i>)";
	    	rlc_web_row_elem_bold($product);
	    	rlc_web_row_elem($row['akey']);
	    	rlc_web_row_elem($row['license_hostid']);
	    	rlc_web_row_elem($row['expdate']);
	    	rlc_web_row_elem_num($row['count']);
	    	rlc_web_row_elem($row['remote_host']);
		$timestr = rlc_get_timestr($row['time']);
	    	rlc_web_row_elem($timestr);

		$timestr = rlc_get_timestr($row['last_fulfill']);
	    	rlc_web_row_elem($timestr);

	    	rlc_web_row_elem_num($row['num_fulfills']);

		$timestr = rlc_get_timestr($row['last_check']);
	    	rlc_web_row_elem($timestr);
	    	rlc_web_row_elem($row['company']);
	    	rlc_web_row_elem($row['notes']);
	    	rlc_web_row_elem($row['log']);
		$bxtra = $pextra.
			 rlc_web_hidden_string("fulfill_id", $row['id']).
			 rlc_web_hidden_string("license_hostid",
							$row['license_hostid']).
			 rlc_web_hidden_string("akey", $row['akey']).
			 rlc_web_hidden_string("lictype", $row['lictype']).
			 rlc_web_hidden_string("hostname", $row['hostname']);
		echo "<form></form>";	/* Shouldn't need this. arg.  */
		rlc_show_button('rlc_show_lic.php', $bxtra);
	        if ($perm['act_edit_enabled'])
	        {
		    $cxtra = $pextra.  
			rlc_web_hidden_string(DELETE_ITEM.$numdisp, $row['id']);
	            rlc_web_delete_button("rlc_del_fulfill.php", $cxtra);
		}
		rlc_web_row_end();
		$numdisp++;
		if ($numdisp >= $rpp) break;
	}
	rlc_web_table_end(0);
	mysqli_free_result($fulfill);
	rlc_mysql_close($sql);

/*
 *	The check all/clear all/delete buttons
 */
	if ($perm['act_edit_enabled'])
	{
	    rlc_web_del_multiple("rlc_del_fulfill.php");
	}
		
	rlc_web_paginate("rlc_show_fulfill.php", $extra, $pextra, $rpp, 
							$r1, $r1 + $numdisp - 1,
						     $tr, $sc, $sd, "");
	if ($backtxt != "")
		finish_page_extra("", "", 0, $backtxt, $back, 0, 0, $pextra,
									"");
	else
		finish_page(0, 0, 0);
?>
