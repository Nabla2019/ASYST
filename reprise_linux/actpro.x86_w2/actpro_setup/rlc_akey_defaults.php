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

 	$Id: rlc_akey_defaults.php,v 1.8 2017/08/19 02:28:00 matt Exp $

 *****************************************************************************/

/*
 *	Edit product defaults.
 */

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include "login_session.php";
include "rlc_akey.php";

define ("UNSPECIFIED", "");

function set_defaults($cols)
{
	foreach ($cols as $col)
	{
	    $k[$col.'_inv'] = UNSPECIFIED;
	    $k[$col.'_def'] = UNSPECIFIED;
	}

	$k['active']    = 0;
	$k['count']     = 1;
	$k['numkeys']   = 1;
	$k['type']      = 0;
	$k['rehosts']   = 0;
	$k['lastdate']  = NULL;
	$k['exp']       = NULL;
	$k['kver']	= NULL;
	$k['kver_type'] = 0;
	$k['white']     = "";
	$k['misc']      = NULL;
	$k['notes']     = "";
	$k['key_allowed_hostids'] = 0;
	$k['sub_interval'] = RLM_ACT_SUBSCRIPTION_MONTH;
	$k['sub_window'] = 2;
	$k['ash_sn'] = 0;
	$k['user_def'] = NULL;
	return($k);
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
	}
	else
	{
	    $whichuser = $session->username;
	    rlc_web_header(RLC_MENU_PROFILE, $session);
	}
        if (!$session->logged_in)
	{
	    rlc_noview($session);
	    finish_page("Back", 0, 0);
	    return;
	}

/*
 *	cols has all the columns for the table.  primarycols has only the
 *	columns we use to set defaults - the other cols (e.g. kver_type
 * 	for "kver") are special-cased in the default writing routine.
 *	numkeys is special-cased as it's not actually in the table.
 */

	$cols = array("active", "count", "type", "rehosts", "lastdate", 
			     "exp", "kver", "kver_type", "white", "misc", 
			     "notes", "key_allowed_hostids", "numkeys",
			     "sub_interval", "sub_window");

	$primarycols = array("active", "count", "type", "rehosts", "lastdate", 
			     "exp", "kver", "white", "misc", "notes", 
			     "key_allowed_hostids", "numkeys",
			     "sub_interval", "sub_window");

	$sql = rlc_mysql_init($isv);
	if (!array_key_exists('submit_form', $_POST))
	{
	    $k = set_defaults($cols);
	    $k = rlc_mysql_read_table_defaults($sql, "keyd", $whichuser, $k, 1);
	    display_defaults_form($sql, $whichuser, $k, 0, 0);
	}
	else
	{
/*
 *	    Write out the defaults
 */
	    foreach ($cols as $col)
	    {
		$k[$col."_def"] = $k[$col."_inv"] = UNSPECIFIED;
		if (array_key_exists("DEFAULT_".$col, $_POST))
		    $k[$col."_def"]  = $_POST["DEFAULT_".$col];
		/*
		else
		    $k[$col."_def"]  = 0;
		*/

		if (array_key_exists("VISIBLE_".$col, $_POST))
		{
		    $x  = $_POST["VISIBLE_".$col];
		    if ($x == 1) 
		    {
		    	/* $k[$col."_def"] = 1;	/* If it's invisible, it has a
						   default */
		    	$k[$col."_inv"] = 1;
		    }
		    else	 
		    	$k[$col."_inv"] = 0;
		}
		/*
		else
		   $k[$col."_inv"] = 0;
		*/

		if ($col == "key_allowed_hostids")
	    	    $k['key_allowed_hostids'] = rlc_set_hostids($_POST);
		else if ($col == "misc")
		{
		    $misc = _values_to_misc();
	    	    $k['misc'] = $misc;
		}
		else
		{
		    if (array_key_exists($col, $_POST))
			$k[$col] = $_POST[$col];
		    else	
			$k[$col] = NULL;
		}
	    }

	    $illegal = rlc_check_akey($k['lastdate'], $k['exp'], $k['misc'],
	    							$k['kver']);
	    if ($illegal === FALSE)
	    {
/*
 *		Now write it out
 */
		rlc_web_title("Edit Activation Key Defaults", 
						"rlc_show_key.php");
		$errs = rlc_mysql_write_table_defaults($sql, "keyd", $whichuser,
							$primarycols, $k);
		if ($errs == 0)
		{
		    echo "Activation Key defaults updated<br>";
		    $res = rlc_mysql_add_audit($sql, $session->username,
						"defaults", $whichuser, "keyd");
		}
		else
		{
		    echo "Activation Key defaults not updated<br>";
		    echo "Error: ".mysqli_error($sql)."<br>";
		}

		finish_page("Show Activation Keys", 0, 0);
	    }
	    else
	    {
		display_defaults_form($sql, $whichuser, $k, 1, $illegal);
	    }
	}
	rlc_mysql_close($sql);
?>
