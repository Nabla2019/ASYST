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

 	$Id: rlc_edit_prod.php,v 1.22 2017/08/19 02:27:25 matt Exp $

 *****************************************************************************/

/*
 *	Edit product.  Including enable/disable.
 */

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include "login_session.php";
include "rlc_prod.php";

/*
 *	Create the form
 */
	rlc_web_header(RLC_MENU_PROD, $session);
	if (!$session->canEdit())
        {
	    echo "You do not have permission to perform this operation.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	if (array_key_exists('id', $_POST)) $id = $_POST['id'];
	else 				    $id = 0;

	if (array_key_exists("view_name", $_POST))
		$name = $_POST['view_name'];
	else
		$name = "";
	$pxtra = "";

        if (array_key_exists("view_one_prod", $_POST))
	{
		$view_one_prod = $_POST['view_one_prod'];
		$oneprod = 1;
		$pxtra = rlc_web_hidden_string("view_name", $name).
			 rlc_web_hidden_string("view_one_prod", $view_one_prod);
	}
	else	$oneprod = 0;


	$sql = rlc_mysql_init($isv);
	if (!array_key_exists('submit_form', $_POST))
	{
		$p = rlc_mysql_read_prod($sql, $id);
		if (!$p)
		{
			echo "<br><h2>Could not retrive product</h2>".
					"<h3>Product ptr is NULL</h3>";
			echo $pxtra;
			rlc_web_hidden("view_name", $name);
			finish_page(0, 0, 0);
		}
		else
		{
			rlc_web_hidden("view_name", $name);
			display_edit_form($sql, $session->username, $p, 0, 0, 
							$pxtra, $oneprod);
		}
	}
	else
	{
/*
 *		Write out the product
 */
		if (array_key_exists('active', $_POST))
			$p['active']  = $_POST['active'];
		else
			$p['active']  = 0;
		if (array_key_exists('obsolete', $_POST))
			$p['obsolete']  = $_POST['obsolete'];
		else
			$p['obsolete']  = 0;
		$p['issued'] = rlc_getpost("issued", 0);
		$p['add_cust'] = rlc_getpost("add_cust", 0);
		if (array_key_exists('add_akey', $_POST)) 
		    $p['add_akey']    = $_POST['add_akey'];
		else
		    $p['add_akey']    = 0;
		if (array_key_exists('nlic', $_POST)) 
		    $p['nlic']        = $_POST['nlic'];
		else
		    $p['nlic']        = 1;
		$p['name']            = $_POST['name'];
		$p['version_type']    = $_POST['version_type'];
		$p['version']	      = $_POST['version'];
		$p['upgrade_version'] = $_POST['upgrade_version'];
		$p['exp']             = strtolower($_POST['exp']);
		$p['lictype']         = $_POST['lictype'];
		$p['product']         = $_POST['product'];
		$misc		      = _values_to_misc();
		$p['misc']            = $misc;
		$p['generator']       = $_POST['generator'];
		$p['id']	      = $id;
		$p['prod_id']	      = $_POST['prod_id'];
		$p['pcreate']	      = $_POST['pcreate'];
		if (array_key_exists('ash_type', $_POST))
		    $p['ash_type']    = $_POST['ash_type'];
		else
		    $p['ash_type']    = 0;

		if (array_key_exists('ash_tolerance', $_POST))
		    $p['ash_tolerance']    = $_POST['ash_tolerance'];
		else
		    $p['ash_tolerance']    = 0;

		$p['prod_allowed_hostids'] = rlc_set_hostids($_POST);
		if (array_key_exists('lictext', $_POST)) 
		    $p['lictext']      = $_POST['lictext'];
		else
		    $p['lictext']      = "";

		$illegal = rlc_check_product($p, 1);
		if ($illegal === FALSE)
		{
/*
 *			Now write it out
 */
			rlc_web_title("Edit Product Definition", 
							"rlc_show_prod.php");
 			if ($p['product'] == "") $p['product'] = $p['name'];
			$res = rlc_mysql_write_prod($sql, $p, $unused);


			if ($res)
			{
			    if ($p['prod_id'] == 0) $idtoupdate = $p['id'];
			    else		    $idtoupdate = $p['prod_id'];
			    $res = rlc_mysql_update_prod_name($sql, $p['name'], 
								$idtoupdate);
			    echo "Product Definition updated<br>";
			    $res = rlc_mysql_add_audit($sql, $session->username,
						"edit", $p['name'], "prod");
			}
			else
			{
			    echo "Product Definition not updated<br>";
			    echo "Error: ".mysqli_error($sql)."<br>";
			}

			echo $pxtra;
			rlc_web_hidden("view_name", $p['name']);
			finish_page("Show Product Definition", 0, 0);
		}
		else
		{
			display_edit_form($sql, $session->username, $p, 1, 
						$illegal, $pxtra, $oneprod);
		}
	}
	rlc_mysql_close($sql);
?>
