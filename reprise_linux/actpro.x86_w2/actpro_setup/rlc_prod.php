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

 	$Id: rlc_prod.php,v 1.24 2017/08/22 00:15:09 matt Exp $

 *****************************************************************************/

include "rlc_hostids.php";
include "rlc_defaults.php";
include "rlc_misc.php";

/*
 *	edit = 1 if we are editing
 *	def = 1 if we are setting defaults
 */
function display_form($sql, $who, $p, $edit, $def, $error, $illegal, $one_prod)
{
	if ($def) 
	{
	    $sys = ""; $user = "";
	}
	else
	{
	    rlc_read_defaults($sql, $who, "prod", $sys, $user);
	}

	rlc_web_start_prompt();
	if (!array_key_exists('id', $p)) $p['id'] = 0;
	if ($error) rlc_web_error("");

/*
 *	the product name and license name don't have defaults
 */
	if (!$def)
	{
	    rlc_web_prompt_prod_name($p['name'], 1);
	    if ($error && array_key_exists('name', $illegal))
					rlc_web_error($illegal['name']);
	    rlc_web_prompt_prod_license($p['product'], 1);
	    if ($error && array_key_exists('product', $illegal))
					rlc_web_error($illegal['product']);
	}

	if ($def) 
	{
	    rlc_web_tableheader();
	    rlc_web_row_start();
	    rlc_web_header_elem("default", "", "", "", "");    
	    rlc_web_header_elem("invisible", "", "", "", "");    
	    rlc_web_header_elem("Product Definition Data", "", "", "", "");    
	    rlc_web_row_end();
	    
	}

	rlc_get_defaults($edit, $def, $sys, $user, "version", $p, $value, 
	    							$vis, $d);
	rlc_get_defaults($edit, $def, $sys, $user, "version_type", $p, $vtype, 
								$xx, $xxx);
	rlc_web_prompt_version($value, $vtype, 1, 0, $vis, $def, $d);
	if ($error && array_key_exists('version', $illegal))
					rlc_web_error($illegal['version']);

	rlc_get_defaults($edit, $def, $sys, $user, "upgrade_version", $p, 
							$value, $vis, $d);
	rlc_web_prompt_upgrade($value, 1, $vis, $def, $d);
	if ($error && array_key_exists('upgrade_version', $illegal))
				rlc_web_error($illegal['upgrade_version']);

	if ($edit) 
	{
	    rlc_get_defaults($edit, $def, $sys, $user, "active", $p, 
							$value, $vis, $d);
	    rlc_web_prompt_active($value, 1, $vis, $def, $d);
	}
/*
 *	Only allow editing obsolete on primary products
 */
	if ($edit && ($p['prod_id'] == 0)) 
	{
	    rlc_get_defaults($edit, $def, $sys, $user, "obsolete", $p, 
							$value, $vis, $d);
	    rlc_web_prompt_obsolete($value, 1, $vis, $def, $d);
	}

	rlc_get_defaults($edit, $def, $sys, $user, "lictype", $p, $value, 
								$vis, $d);
	rlc_web_prompt_lictype($value, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "ash_type", $p, $value1, 
								$vis, $d);
	rlc_get_defaults($edit, $def, $sys, $user, "ash_tolerance", $p, $value2,
								$vis2, $d2);
	rlc_web_prompt_ash_hostid($value1, $value2, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "issued", $p, $value, $vis, 
									$d);
	rlc_web_prompt_issued($value, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "add_cust", $p, $value, $vis,
									$d);
	rlc_web_prompt_custeq($value, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "add_akey", $p, $value,
								$vis, $d);
	rlc_web_prompt_add_akey($value, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "nlic", $p, $value, $vis,$d);
	rlc_web_prompt_nlic($value, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "exp", $p, $value, $vis, $d);
	rlc_web_prompt_exp($value, 0, $vis, $def, $d);
	if ($error && array_key_exists('exp', $illegal))
					rlc_web_error($illegal['exp']);

	rlc_get_defaults($edit, $def, $sys, $user, "generator", $p, $value, 
								$vis, $d);
	rlc_web_prompt_generator($value, 1, $vis, $def, $d);

	if (!$def)
	{
	    rlc_web_hidden("prod_id", $p['prod_id']);
	    if ($one_prod) rlc_web_hidden("view_one_prod", $p['prod_id']);
	}

	if ($p['prod_id'] == 0)
	{
	    rlc_get_defaults($edit, $def, $sys, $user, "lictext", $p, 
							$value, $vis, $d);
	    rlc_prompt_lictext($value, 1, $vis, $def, $d);
	}

	rlc_get_defaults($edit, $def, $sys, $user, "prod_allowed_hostids", $p, 
							$value, $vis, $d);
	rlc_prompt_hostids($value, 0, $vis, $def, $d);

/*
 *	Finally, the list of miscellanous options
 */
	rlc_get_defaults($edit, $def, $sys, $user, "misc", $p, $value, $vis,$d);
	$misc = _misc_to_array($value);
	rlc_web_hidden("miscHidden", 0);
	rlc_web_prompt_misc($misc, $def==0, $vis, $def, $d);
	if ($error && array_key_exists('misc', $illegal))
					rlc_web_error($illegal['misc']);


	if ($edit) rlc_web_hidden("pcreate", $p['pcreate']);
	rlc_web_hidden("submit_form", 1);
	rlc_web_hidden("id", $p['id']);
	if ($def) 
	{
	    rlc_web_table_end();
	}
	return(0);
}

function display_create_form($sql, $who, $p, $error, $illegal, $xtra, $one_prod,
					$header="Create Product Definition")
{
	rlc_web_title($header, "rlc_create_prod.php", "id=createProd");
	display_form($sql, $who, $p, false, false, $error, $illegal, $one_prod);
	rlc_web_info("Click \"CREATE Product Definition\" below to create ".
					"this product definition record");
	rlc_web_hidden("active", 1);
	rlc_web_hidden("obsolete", 0);
	finish_page_extra("CREATE Product Definition", "CANCEL", 
				"rlc_show_prod.php", 0, 0, 0, 0, $xtra, "");
}

function display_edit_form($sql, $who, $p, $error, $illegal, $xtra, $one_prod)
{
	rlc_web_title("Edit Product Definition", "rlc_edit_prod.php", 
							"id=createProd");
	display_form($sql, $who, $p, true, false, $error, $illegal, $one_prod);
	echo $xtra;
	rlc_web_info("Click \"Save Changes\" below to Edit this product ".
							"definition record");
	finish_page_extra("Save Changes", "CANCEL", "rlc_show_prod.php",
						0, 0, 0, 0, $xtra, "");
}

function display_defaults_form($sql, $who, $p, $error, $illegal)
{
	if ($who == SYSTEM_DEFAULTS) 
	{
	    $title = "Set System-Wide Product Definition Defaults";
	    $info = " SYSTEM-wide";
	}
	else  
	{
	    $title = "Set Product Definition Defaults for user \"".$who."\"";
	    $info = " for user ".$who;
	}
	rlc_web_title($title, "rlc_prod_defaults.php");
	display_form($sql, $who, $p, false, true, $error, $illegal, 0);
	rlc_web_info("Click \"Save Changes\" below to set the product defaults".
								$info);
	if (array_key_exists("system_defaults", $_POST))
		rlc_web_hidden("system_defaults", 1);
	finish_page_extra("Save Changes", "CANCEL", "rlc_prod_defaults.php",
						0, 0, 0, 0, "", "");
}

/*
 *	Check a product defintion for legal input.
 */
function rlc_check_product($p, $edit)
{
	$ilchar = " - the following 6 characters are illegal: [' ` \" > < &]";
	$nospace = " - no spaces allowed";
 	$err = 0;

	if ($edit)
	{
	    if (($p['name'] == "") || ctype_space($p['name']))
	    {
		$illegal['name'] = "Missing product definition name";
		$err++;
	    }
	    if (($p['product'] == "") || ctype_space($p['product']))
            {
                $illegal['product'] = "Missing product name";
		$err++;
            }
	    else if (_rlm_illegal_char($p['product'], 0, 1, 1))
	    {
		$illegal['product'] = "Illegal character".$ilchar.$nospace; 
		$err++;
	    }
	}
	if (($p['version'] == "") || ctype_space($p['version']))
        {
            $illegal['version'] = "Missing product version";
	    $err++;
        }
	else if (_rlm_illegal_char($p['version'], 1, 1, 1))
	{
		$illegal['version'] ="Illegal character (numbers and '.' only)";
		$err++;
	}
	if (_rlm_illegal_char($p['upgrade_version'], 1, 1, 1))
	{
		$illegal['upgrade_version'] ="Illegal character (numbers and '.' only)";
		$err++;
	}
	if (($p['exp'] == "") || ctype_space($p['exp']))
        {
                $illegal['exp'] = "Missing product expiration";
		$err++;
        }
	else if (_check_exp($p['exp'], 0))
	{
		$illegal['exp'] = "Illegal expiriation date format (dd-mmm-yyyy or positive integer)";
		$err++;
	}
	if (_rlm_illegal_char($p['misc'], 0, 0, 1))
	{
		$illegal['misc'] = "Illegal character ".$ilchar;
		$err++;
	}
	if ($err == 0) return(FALSE); else return($illegal);
}
?>
