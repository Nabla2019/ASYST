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

 	$Id: rlc_prod_defaults.php,v 1.12 2017/08/22 00:15:54 matt Exp $

 *****************************************************************************/

/*
 *	Edit product defaults.
 */

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include "login_session.php";
include "rlc_prod.php";

define ("UNSPECIFIED", "");

function set_defaults($cols)
{
	foreach ($cols as $col)
	{
	    $p[$col.'_inv'] = UNSPECIFIED;
	    $p[$col.'_def'] = UNSPECIFIED;
	}

	$p['issued']   = 0;
	$p['add_akey'] = 0;
	$p['add_cust'] = 0;
	$p['nlic']     = 1;
	$p['version_type'] = 0;
	$p['version'] = "1.0";
	$p['upgrade_version'] = "";
	$p['exp']             = "0";
	$p['issued']	      = 1;
	$p['lictype']         = 0;
	$p['misc']            = "";
	$p['generator']       = 0;
	$p['ash_type']        = 0;
	$p['ash_tolerance']   = 0;
	$p['prod_allowed_hostids'] = 0;
	$p['prod_id']	      = 0;
	$p['lictext']	      = "";
	return($p);
}

/*
 *	Figure out if this is a user or the system's defaults.
 */
	if (array_key_exists("system_defaults", $_POST))
	{
	    rlc_web_hidden("system_defaults", 1);
	    $whichuser = SYSTEM_DEFAULTS;
	    rlc_web_header(RLC_MENU_ADMIN, $session);
	    rlc_admin_menu(RLC_ADMIN_MENU_DB);
	    if (!$session->isAdmin())
            {
	        echo "You must log in as an administrator to do this.<br>";
	        finish_page(0, 0, 0);
	        return;
	    }
	}
	else
	{
	    $whichuser = $session->username;
	    rlc_web_header(RLC_MENU_PROFILE, $session);
	    if (!$session->canView())
            {
	        echo "You do not have permission to perform this operation.<br>";
	        finish_page(0, 0, 0);
	        return;
	    }
	}

/*
 *	cols has all the columns for the table.  primarycols has only the
 *	columns we use to set defaults - the other cols (e.g. version_type
 * 	for "version") are special-cased in the default writing routine.
 */
	$cols = array("version", "version_type", "upgrade_version",
			"lictype", "ash_type", "ash_tolerance", "add_cust",
			"add_akey", "issued", "nlic", "misc", "exp", 
			"generator", "lictext", "prod_allowed_hostids");

	$primarycols = array("version",  "upgrade_version",
			     "lictype", "ash_type", "add_cust", "add_akey", 
			     "issued", "nlic", "misc", "exp", "generator", 
			     "lictext", "prod_allowed_hostids");

	$sql = rlc_mysql_init($isv);
	if (!array_key_exists('submit_form', $_POST))
	{
	    $p = set_defaults($cols);
	    $p = rlc_mysql_read_table_defaults($sql, "prod", $whichuser, $p, 1);
	    display_defaults_form($sql, $whichuser, $p, 0, 0);
	}
	else
	{
/*
 *	    Write out the defaults
 */
	    foreach ($cols as $col)
	    {
		$p[$col."_def"] = $p[$col."_inv"] = UNSPECIFIED;
		if (array_key_exists("DEFAULT_".$col, $_POST))
		    $p[$col."_def"]  = $_POST["DEFAULT_".$col];
		/*
		else
		    $p[$col."_def"]  = 0;
		*/

		if (array_key_exists("VISIBLE_".$col, $_POST))
		{
		    $x  = $_POST["VISIBLE_".$col];
		    if ($x == 1) 
		    {
		    	/* $p[$col."_def"] = 1;	/* If it's invisible, it has a
						   default */
		    	$p[$col."_inv"] = 1;
		    }
		    else	 
		    	$p[$col."_inv"] = 0;
		}
		/*
		else
		   $p[$col."_inv"] = 0;
		*/

		if ($col == "prod_allowed_hostids")
	    	    $p['prod_allowed_hostids'] = rlc_set_hostids($_POST);
		else if ($col == "misc")
		{
		    $misc = _values_to_misc();
	    	    $p['misc'] = $misc;
		}
		else
		{
		    if (array_key_exists($col, $_POST))
			$p[$col] = $_POST[$col];
		    else	
			$p[$col] = 0;
		}
	    }

	    $illegal = rlc_check_product($p, 0);
	    if ($illegal === FALSE)
	    {
/*
 *		Now write it out
 */
		rlc_web_title("Edit Product Defaults", "rlc_show_prod.php");
		$errs = rlc_mysql_write_table_defaults($sql, "prod", $whichuser,
							$primarycols, $p);
		if ($errs == 0)
		{
		    echo "Product Definition defaults updated<br>";
		    $res = rlc_mysql_add_audit($sql, $session->username,
						"defaults", $whichuser, "prod");
		}
		else
		{
		    echo "Product Definition defaults not updated<br>";
		    echo "Error: ".mysqli_error($sql)."<br>";
		}

		finish_page("Show Product Definitions", 0, 0);
	    }
	    else
	    {
		display_defaults_form($sql, $whichuser, $p, 1,$illegal);
	    }
	}
	rlc_mysql_close($sql);
?>
