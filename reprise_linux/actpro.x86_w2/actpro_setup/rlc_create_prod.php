<?php
/*****************************************************************************

	    COPYRIGHT (c) 2007, 2017 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_create_prod.php,v 1.22 2017/08/22 00:16:26 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include "rlc_mysql.php";
include 'login_session.php';
include "rlc_prod.php";

/*
 *	Create a new product definition
 */

	$perm = check_user($session);
	if (array_key_exists('name', $_POST))
	    $p['name'] = $_POST['name'];
	else
	    $p['name'] = "";

	$pxtra = "";
        if (array_key_exists("view_one_prod", $_POST))
	{
	    $view_one_prod = $p['prod_id'] = $_POST['view_one_prod'];
	    $newlicense = 1;
	    $header = "Create New License for Product \"".$p['name']."\"";
	    $button = "Back to ".$p['name']." Definition";
	    $pxtra = rlc_web_hidden_string("view_one_prod", $view_one_prod).
				rlc_web_hidden_string("view_name", $p['name']);
	}
	else
	{
	    $p['prod_id'] = 0;
	    $newlicense = 0;
	    $header = "Create Product Definition";
	    $button = "Back to List";
	}


	rlc_web_header(RLC_MENU_PROD, $session);

	if (!$perm['act_edit_enabled'])
	{
		rlc_web_title($header, 0);
		rlc_noadmin($session);
		finish_page(0, 0, 0);
	}
	else
	{
		$sql = rlc_mysql_init($isv);
		if (!array_key_exists('submit_form', $_POST))
		{
/*
 *		    If this is a follow-on product, pick up some
 *		    of the data here as defaults
 */
		    if (array_key_exists('lictype', $_POST))
			$p['lictype'] = $_POST['lictype'];
		    else
			$p['lictype'] = 1; /* Default to NL, uncounted */

		    if (array_key_exists('version', $_POST))
			$p['version'] = $_POST['version'];
		    else
			$p['version'] = "1.0";

		    if (array_key_exists('version_type', $_POST))
			$p['version_type'] = $_POST['version_type'];
		    else
			$p['version_type'] = 0;

		    if (array_key_exists('exp', $_POST))
			$p['exp'] = $_POST['exp'];
		    else
			$p['exp'] = 0;


		    $p['product'] = "";

		    if (array_key_exists('upgrade_version', $_POST))
			$p['upgrade_version'] = $_POST['upgrade_version'];
		    else
			$p['upgrade_version'] = "";

		    $p['issued'] = rlc_getpost("issued", 1);  /* 1 is default */
		    $p['add_cust'] = rlc_getpost("add_cust", 0);
		    $p['add_akey'] = rlc_getpost("add_akey", 0);

		    if (array_key_exists('nlic', $_POST))
			$p['nlic'] = $_POST['nlic'];
		    else
			$p['nlic'] = 1;

		    $misc = _values_to_misc();
		    $p['misc'] = $misc;

		    if (array_key_exists('generator', $_POST))
			$p['generator'] = $_POST['generator'];
		    else
			$p['generator'] = 0;

		    $p['prod_allowed_hostids'] = rlc_set_hostids($_POST);

		    if (array_key_exists('ash_type', $_POST))
			$p['ash_type'] = $_POST['ash_type'];
		    else
			$p['ash_type'] = 0;

		    if (array_key_exists('ash_tolerance', $_POST))
			$p['ash_tolerance'] = $_POST['ash_tolerance'];
		    else
			$p['ash_tolerance'] = 0;

		    if (array_key_exists('lictext', $_POST))
			$p['lictext'] = $_POST['lictext'];
		    else
			$p['lictext'] = "";

		    display_create_form($sql, $session->username, $p, 0, 0, 
		    				$pxtra, $newlicense, $header);
		}
		else
		{
/*
 *		    Write out the product
 */
 /***
		    if (array_key_exists('id', $_POST))
			$p['id']           = $_POST['id'];
		    else 
 ***/
			$p['id']           = 0;
		    $p['name']             = $_POST['name'];
		    $p['product']          = $_POST['product'];
		    $p['version_type']     = $_POST['version_type'];
		    $p['version'] 	   = $_POST['version'];
		    $p['upgrade_version']  = $_POST['upgrade_version'];
		    $p['lictype']          = $_POST['lictype'];
		    $p['issued'] = rlc_getpost("issued", 0);
		    					/* not present here 
							   means unchecked */
		    $p['add_cust'] = rlc_getpost("add_cust", 0);

		    if (array_key_exists('nlic', $_POST))
		    	$p['nlic']       = $_POST['nlic'];
		    else
		    	$p['nlic']       = 1;
		    if (array_key_exists('add_akey', $_POST))
			$p['add_akey'] = $_POST['add_akey'];
		    else
			$p['add_akey'] = 0;

		    $misc = _values_to_misc();
		    $p['misc'] 		   = $misc;
		    $p['generator']        = $_POST['generator'];
		    $p['exp']              = strtolower($_POST['exp']);
		    $p['active'] = 1;
		    $p['obsolete'] = 0;
		    $p['prod_allowed_hostids'] = rlc_set_hostids($_POST);
		    $p['pcreate'] = date("Y-m-d", time());	
		    $p['ash_type']         = $_POST['ash_type'];
		    $p['ash_tolerance']    = $_POST['ash_tolerance'];
		    $p['lictext']          = $_POST['lictext'];

		    $illegal = rlc_check_product($p, 1);

		    if ($illegal === FALSE)
		    {
		        rlc_web_title($header, "rlc_show_prod.php");
			if ($p['product'] == "") $p['product'] = $p['name'];
			$res = rlc_mysql_write_prod($sql, $p, $unused);
			if ($res)
			{
			    echo "Product record written<br>";
			    $res = rlc_mysql_add_audit($sql, $session->username,
						"add", $p['name'], "prod");
			}
			else
			{
			    echo "Product record not written<br>";
			    echo "Error: ".mysqli_error($sql)."<br>";
			}

			echo "Product definition record created<br><br>";
			if ($newlicense)
			{
			    rlc_web_hidden("view_one_prod", $p['prod_id']);
			    rlc_web_hidden("view_name", $p['name']);
			}
			else
			    echo $pxtra;

		        finish_page($button, 0, 0);
		    }
		    else
		    {
		        display_create_form($sql, $session->username, $p, 1, 
					$illegal, $pxtra, $newlicense, $header);
		    }
		}
		rlc_mysql_close($sql);
	}
?>
