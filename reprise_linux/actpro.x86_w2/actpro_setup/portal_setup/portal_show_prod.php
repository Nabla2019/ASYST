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

 	$Id: portal_show_prod.php,v 1.24 2017/05/02 01:11:46 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "portal_mysql.php";
include "login_session.php";

function make_prod_extra($p, $extra)
{
	$r = $extra."<input type=hidden name=id value=".$p['id'].">
	      <input type=hidden name=active value=".$p['active'].">
	      <input type=hidden name=obsolete value=".$p['obsolete'].">
	      <input type=hidden name=name value=\"".$p['name']."\">
	      <input type=hidden name=version value=".$p['version'].">
	      <input type=hidden name=version_type value=".$p['version_type'].">
	      <input type=hidden name=upgrade_version value=".$p['upgrade_version'].">
	      <input type=hidden name=exp value=".$p['exp'].">
	      <input type=hidden name=lictype value=".$p['lictype'].">
	      <input type=hidden name=issued value=".$p['issued'].">
	      <input type=hidden name=add_cust value=".$p['add_cust'].">
	      <input type=hidden name=add_akey value=".$p['add_akey'].">
	      <input type=hidden name=product value=".$p['product'].">
	      <input type=hidden name=misc value=\"".$p['misc']."\">
	      <input type=hidden name=pcreate value=\"".$p['pcreate']."\">
	      <input type=hidden name=prod_id value=".$p['prod_id'].">";
	return($r);
}

function make_prod_del($p, $x)
{
	$r = "<input type=hidden name=";
	$r .= DELETE_ITEM.$x;
	$r .= " value=".$p['id'].">";
	return($r);
}

/*
 *	Get the selection data for the product list
 */


function get_selection_data($cols, $sel_data)
{
	$head = array("Product Name", "License Name", "Version", 
		"Upgrade Version", "Exp Date", "Extra License Data");
	rlc_web_browse_select("portal_show_prod.php", $sel_data, $head, $cols);
}

function clone_product($sql, $session, $prod_id, $product, $select)
{
	echo "Cloning product... to $product<br>";
	$stat = portal_mysql_get_products($session->company_id, $sql, $prods, "", "", $select);

	if ($stat != 0)
	{
		$tmp = sprintf("Cannot read product definitions, status: %s<br>"
								, $stat);
		rlc_web_info($tmp."Product not copied<br>");
		finish_page(0, 0, 0);
		portal_mysql_close($session->company_id, $sql);
		return;
	}

/*
 *	First, get the primary product and clone it.
 */
	while ($row = mysqli_fetch_array($prods, MYSQLI_ASSOC))
	{
		$pid = $row['prod_id'];
		if (!$pid) 
		{
		    $pid = $row['id'];
		    $row['id'] = 0;
		    $row['name'] = $product;
		    $res = rlc_mysql_write_prod($sql, $row, $clonepid);
		    if ($res)
		    {
			$res = rlc_mysql_add_audit($sql, $session->username,
						"clone", $row['name'], "prod");
		    }
		    else
		    {
			echo "Error cloning product: ".mysqli_error($sql)."<br>";
		    }
		    break;
		}
		else continue;
	}
	mysqli_data_seek($prods, 0);
/*
 *	Now, all the other licenses.
 */
	while ($row = mysqli_fetch_array($prods, MYSQLI_ASSOC))
	{
		$pid = $row['prod_id'];
		if (!$pid) continue;
		else
		{
		    $row['id'] = 0;
		    $row['prod_id'] = $clonepid;
		    $row['name'] = $product;
		    $res = rlc_mysql_write_prod($sql, $row, $unused);
		    if ($res)
		    {
			$res = rlc_mysql_add_audit($sql, $session->username,
						"clone", $row['name'], "prod");
		    }
		    else
		    {
			echo "Error cloning product: ".mysqli_error($sql)."<br>";
		    }
		}
	}
	mysqli_free_result($prods);
	return($clonepid);
}


/*
 *	Product browser - outputs a list of products
 */
	
	rlc_web_rpp("rlc-rpp-pro");
	rlc_web_header(RLC_MENU_PROD, $session);
	$perm = check_user($session);

	$prod_id = rlc_getinput('view_one_prod', 0);
	$cloneproduct = rlc_getinput('cloneproduct', 0);
	if ($cloneproduct)
	{
	    $product = rlc_getinput('view_name', "");
	    $prod_id = $cloneproduct;
	    $product .="_COPY";
	    $title = "Product Definition Created for Product \"".$product."\"";
	    $oneproduct = 1;
	}
	else if ($prod_id)
	{
	    $product = rlc_getinput('view_name', "");
	    $title = "Product Definition for Product \"".$product."\"";
	    $oneproduct = 1;
	}
	else
	{
	    $title = "Product Definitions";
	    $oneproduct = 0;
	}

	rlc_web_title($title, "portal_show_prod.php");

	if (!$perm['act_portal_enabled'])
	{
	    rlc_noview($session);
	    finish_page(0, 0, 0);
	    return;
	}

/*
 *	The pagination code needs this for the first edit button to work.
 */
	echo "<form method='get' action='portal_show_prod.php'></form>";

	if ($oneproduct) 
	{
	    if ($perm['act_edit_enabled'])
		rlc_web_info("All enabled licenses below will be created when product \"$product\" is activated.<br>Press \"Add New License to this product\" below to add additional licenses to this<br>product definition or click the edit icon to edit the definition of an individual license.");
	    else
		rlc_web_info("All licenses below will be created when product \"$product\" is activated.");
	}
	else if ($cloneproduct) 
	{
	    rlc_web_info($product."_COPY created.<br>You can now edit the product definition for this product.");
	}
	else
	{
	    if ($perm['act_edit_enabled'])
	    {
		rlc_web_button("rlc_create_prod.php", "Add New Product", "", 0);
	    }
	    rlc_web_info("The list below displays the <i><b>Primary License</b></i> for each product definition.<br>If the <i>License Name</i> has a trailing \"...\", this is a multiple-license product defintion.<br>When you click the show/edit icon, you will see the full list of licenses for that product definition.");
	}

	$sql = portal_mysql_init($session->company_id, $isv);
/*
 *	Get selection criteria
 */
	$select_data = array("");
	$cols = array("name", "product", "version", "upgrade_version", "exp",
								"misc");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);
	if ($oneproduct || $cloneproduct)
	{
	    if ($select)
	        $select = $select."AND ((id = $prod_id) OR (prod_id = $prod_id))";
	    else
	        $select = "WHERE (id = $prod_id) OR (prod_id = $prod_id)";
	    $xtra = "view_one_prod=$prod_id&view_name=$product";
	    $pxtra = rlc_web_hidden_string("view_one_prod", $prod_id).
			    rlc_web_hidden_string("view_name", $product);

	
	}
	else
	{
	    if ($select)
	    	$select = $select." AND ((prod_id is NULL) OR (prod_id = 0))";
	    else
		$select = "WHERE ((prod_id is NULL) OR (prod_id = 0))";
	    get_selection_data($cols, $select_data);
	}

	if ($cloneproduct) 
	{
	    $pid = clone_product($sql, $session, $prod_id, $product, $select);
	    $prod_id = $pid;
/*
 *	    reset the select criteria
 */
	    $select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);
	    if ($select)
	        $select = $select."AND ((id = $pid) OR (prod_id = $pid))";
	    else
	        $select = "WHERE (id = $pid) OR (prod_id = $pid)";
	    $xtra = "view_one_prod=$pid&view_name=$product";
	    $pxtra = rlc_web_hidden_string("view_one_prod", $pid).
			    rlc_web_hidden_string("view_name", $product);
	}

	$get = rlc_web_get_pagination($r1, $rpp, $tr, $sc, $sd, "rlc-rpp-pro");

	$active = $obsolete = $count = 0;

	$stat = portal_mysql_get_products($session->company_id, $sql, $prods, $sc, $sd, $select);

	if ($stat != 0)
	{
		$tmp = sprintf("Cannot read product definitions, status: %s<br>"
								, $stat);
		rlc_web_info($tmp);
		finish_page(0, 0, 0);
		portal_mysql_close($session->company_id, $sql);
		return;
	}

	if ($tr == 0)
	{
	        $tr = mysqli_num_rows($prods);
	}
	$first = 0;
	if ($r1 > 1)
	{
		mysqli_data_seek($prods, $r1-1);
		$first = $r1-1;
	}
/*
 *	Figure out if there are any alternate hostids.
 */
	$server_alt = $nck = 0;
	while ($row = mysqli_fetch_array($prods, MYSQLI_ASSOC))
	{
	    if ($row['lictype'] == RLC_ACTPRO_LT_ASH)
	    {
		$server_alt = 1;
		break;
	    }
	    $nck++;
	    if ($nck >= $rpp) break;
	}
	mysqli_data_seek($prods, $first);

	rlc_web_paginate("portal_show_prod.php", $xtra, $pxtra, $rpp, $r1, -1, 
							$tr, $sc, $sd, "");
	rlc_web_form("rlc_del_prod.php");
	rlc_web_tableheader();
	rlc_web_row_start();
	$sort = $xtra."&r1=".$r1."&rpp=".$rpp."&tr=".$tr;
	if ($perm['act_edit_enabled']) rlc_web_row_elem("");
	if (!$oneproduct)
	    rlc_web_header_elem("Product Name", $sort, "name", $sc, $sd);
	rlc_web_header_elem("License Name", $sort, "product", $sc, $sd);
	rlc_web_header_elem("Version", $sort, "version", $sc, $sd);
	rlc_web_header_elem("Upgrade Version", $sort, "upgrade_version",
								$sc, $sd);
	rlc_web_header_elem("Expiration", $sort, "exp", $sc, $sd);
	rlc_web_header_elem("License Type", $sort, "lictype", $sc, $sd);
	rlc_web_header_elem("# lic", $sort, "nlic", $sc, $sd);
	rlc_web_header_elem("Issued", $sort, "issued", $sc, $sd);
	rlc_web_header_elem("cust=", $sort, "add_cust", $sc, $sd);
	rlc_web_header_elem("key", $sort, "add_akey", $sc, $sd);
	rlc_web_header_elem("Other License Data", $sort, "misc", $sc, $sd);
	if ($server_alt)
	   rlc_web_header_elem("Alt Server Hostid", $sort, "ash_sn", $sc, $sd);
	rlc_web_header_elem("Enabled", $sort, "active", $sc, $sd);
	rlc_web_header_elem("Obsolete", $sort, "obsolete", $sc, $sd);
	rlc_web_header_elem("Created", $sort, "pcreate", $sc, $sd);
	rlc_web_button_invis();	/* To fix first edit icon */
	rlc_web_row_end();
	$numdisp = 0;
	$numcheckboxes = 0;

	while ($row = mysqli_fetch_array($prods, MYSQLI_ASSOC))
	{
		if ($numdisp == 0) $firstprod = $row;
		if (!$row['active']) 
		{
		    rlc_web_grey_bg();
		}
		else if ($row['obsolete']) 
		{
		    rlc_web_light_grey_bg();
		    $obsolete++;
		}
		else
		{
		    rlc_web_normal_bg();
		    $active++;
		}

		$count++;
		rlc_web_row_start();

		$multi = 0;
		if (!$oneproduct)
		{
		    $pid = "Product ID: ".$row['id'];
		    $prod_name = "<abbr title=\"".$pid."\">".$row['name'].
								"</abbr>";
/*
 *		    Figure out if this is a single-license definition or not.
 */
		    $stat = portal_mysql_get_products($session->company_id, $sql, $thisprod, "", "", 
						"where prod_id = ".$row['id']);
		    if (mysqli_num_rows($thisprod) > 0) $multi = 1;
		    mysqli_free_result($thisprod);
		}
/*
 *		Checkbox for delete, if appropriate
 */
		if ($perm['act_edit_enabled'])
		{
		    /* No DEL checkbox on multi-license products */
		    if (!$multi)
		    {
			$numkeys = rlc_mysql_num_keys_and_fulfill($sql, 
						$row['id']);	/* P433 */
			if (!(($oneproduct) && ($row['prod_id'] == 0))
				&& ($numkeys == 0))
			{
			    rlc_web_checkbox("", DELETE_ITEM.$numdisp, 
							$row['id'], 0, 1);
			    $numcheckboxes++;
			}
			else rlc_web_row_elem("");
		    }
		    else rlc_web_row_elem("");
		}

		if (!$oneproduct) rlc_web_row_elem($prod_name);
		$license_name = $row['product'];
		if ($multi) $license_name = $license_name." ...";
		rlc_web_row_elem($license_name);

		if ($row['version_type'] == 0)
			$version = $row['version'];
		else
			$version = "+ ".$row['version']." mo.";
		rlc_web_row_elem($version);

		rlc_web_row_elem($row['upgrade_version']);
		if (strpos($row['exp'], '-'))
			$expdate = $row['exp'];
		else if (($row['exp'] == "0") || ($row['exp'] == "permanent"))
			$expdate = "permanent";
		else
			$expdate = $row['exp']. " days";
		rlc_web_row_elem($expdate);
		$lt = license_type($row['lictype']);
		rlc_web_row_elem($lt);
		rlc_web_row_elem($row['nlic']);
		rlc_web_row_elem($row['issued'] ? "yes" : "no");
		rlc_web_row_elem($row['add_cust'] ? "yes" : "no");
		$kd = "no";
		if ($row['add_akey'] == 1) $kd = "yes";
		if ($row['add_akey'] == 2) $kd = "both";
		rlc_web_row_elem($kd);
		rlc_web_row_elem($row['misc']);
		if ($server_alt)
		{
	    	    if ($row['lictype'] == RLC_ACTPRO_LT_ASH)
	   		rlc_web_row_elem(ash_hostid_disp($row['ash_type'], 
					$row['ash_tolerance']));
		    else
			rlc_web_row_elem(" ");
		}
		rlc_web_row_elem($row['active'] ? "yes" : "no");
		rlc_web_row_elem($row['obsolete'] ? "yes" : "no");
		rlc_web_row_elem($row['pcreate']);
/*
 *		The buttons
 */
		if ($oneproduct)
		{
		    $pextra = $pxtra.
			    rlc_web_hidden_string("view_one_prod", $prod_id).
			    rlc_web_hidden_string("view_name", $row['name']);
		    if ($perm['act_edit_enabled'])
			edit_button("rlc_edit_prod.php", 
						make_prod_extra($row, $pextra));
		}
		else
		{
		    $pid = $row['prod_id'];
		    if (!$pid) $pid = $row['id'];
		    $pextra = $pxtra.
			    rlc_web_hidden_string("view_one_prod", $pid).
			    rlc_web_hidden_string("view_name", $row['name']);
		    if ($perm['act_edit_enabled'])
			edit_button("portal_show_prod.php", 
						make_prod_extra($row, $pextra));
		    else if ($multi)
			rlc_show_button("portal_show_prod.php", 
						make_prod_extra($row, $pextra));
		}
/*
 *		Figure out how many activation keys there are for
 *		this product to see if we can delete it....
 */
		if (($oneproduct) && ($row['prod_id'] == 0))
		{
		    if ($perm['act_edit_enabled']) rlc_web_row_elem("&nbsp");
		    rlc_web_row_elem("<i>Primary License</i>");
		}
		else if ($perm['act_edit_enabled'])
		{
		    if (!$multi)  /* No DEL button on multi-license products */
		    {
			$numkeys = rlc_mysql_num_keys_and_fulfill($sql, 
						$row['id']);	/* P433 */
			if ($numkeys == 0)
			{
			    if ($oneproduct)
				$extra = 
			       rlc_web_hidden_string("view_one_prod", $prod_id).
			       rlc_web_hidden_string("view_name", $product);
			    else
				$extra = "";
			    rlc_web_delete_button("rlc_del_prod.php", 
					make_prod_del($row, $numdisp, $extra));
			}
		    }
		}
		rlc_web_row_end();
		$numdisp++;
		if ($numdisp >= $rpp) break;
	}
	rlc_web_table_end(0);
	mysqli_free_result($prods);
	portal_mysql_close($session->company_id, $sql);

/*
 *	The check all/clear all/delete buttons
 */
	if ($perm['act_edit_enabled'] && ($numcheckboxes > 0))
	{
	    $tip = "<i>Note: A product cannot be deleted if there are either activation keys or fulfillments which reference it.</i>";
	    rlc_web_del_multiple("rlc_del_prod.php", $tip);
	}

	rlc_web_paginate("portal_show_prod.php", $xtra, $pxtra, $rpp, $r1, 
							$r1 + $numdisp - 1,
						      $tr, $sc, $sd, "");
	if ($oneproduct)
	{
	    $xtra = make_prod_extra($firstprod, 
			rlc_web_hidden_string("view_one_prod", $prod_id));
	    $xtra2 = $pxtra.make_prod_extra($firstprod, 
			rlc_web_hidden_string("cloneproduct", $prod_id));
	    if ($perm['act_edit_enabled'])
	    {
	        if ($cloneproduct) finish_page_extra(0, 0, 0,
			"View Complete Product list", "portal_show_prod.php",
			"Add New License to this product", 
			"rlc_create_prod.php", "", $xtra);
		else finish_page_extra(0, 
			"Copy (clone) this product", "portal_show_prod.php", 
			"View Complete Product list", "portal_show_prod.php",
			"Add New License to this product", 
			"rlc_create_prod.php", "", $xtra, $xtra2);
	    }
	    else
		finish_page_extra(0, 0, 0, "View Complete Product list", 
			"portal_show_prod.php",
			0, "", "", $xtra);
	}
	else
	{
	    if ($perm['act_edit_enabled'])
		finish_page(0, "Add New Product", "rlc_create_prod.php");
	    else
		finish_page(0, 0, 0);
	}
?>
