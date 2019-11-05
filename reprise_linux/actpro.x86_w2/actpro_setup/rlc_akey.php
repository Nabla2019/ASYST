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

 	$Id: rlc_akey.php,v 1.20 2017/08/22 00:14:53 matt Exp $

 *****************************************************************************/

include "rlc_hostids.php";
include "rlc_defaults.php";
include "rlc_misc.php";

function display_form($sql, $who, $k, $edit, $def, $numkeys, $create, $error, $illegal)
{

	if ($def) 
	{
	    $sys = ""; $user = "";
	}
	else
	{
	    rlc_read_defaults($sql, $who, "keyd", $sys, $user);
	}

	if (!$create && !$def)
	{
		if ($error) $akey = $k['akey'];	  /* P419 - used to ref $key */
		else
		{
			$akey = $_POST['akey'];
			$k = rlc_mysql_read_key($sql, $akey);
		}
		if (!$k)
		{
			echo "<br><h2>Could not retrive activation key ".
			    "\"$akey\"</h2><h3>Activation key ptr is NULL</h3>";
			finish_page(0, 0, 0);
			return(1);
		}
	}
	if (!$def)
	{
	    $numproducts = rlc_mysql_read_products($sql, $products, $lictype,
						$license, $version, 
						$version_type, $active, 
						$obsolete, "", "", 1);
	    if ($numproducts == 0)
	    {
		echo "You must create a product definition before you can create an activation key.<br>";
		return(1);
	    }
	}
	$numcust = rlc_mysql_get_customers($sql, $contacts, "contact", "a", 
									""); 
	rlc_web_start_prompt();
	if ($error) rlc_web_error("");
	if (!$create && !$def) 
	{
		rlc_web_prompt_akey($akey, 0);
		rlc_web_prompt_active($k['active'], 1);
	}

	if ($def)
	{
	    rlc_web_tableheader();
	    rlc_web_row_start();
	    rlc_web_header_elem("<b>default</b>", "", "", "", "");    
	    rlc_web_header_elem("<b>invisible</b>", "", "", "", "");    
	    rlc_web_header_elem("<b>Activation Key Data</b>", "", "", "", "");
	    rlc_web_row_end();
	}

	rlc_get_defaults($edit, $def, $sys, $user, "type", $k, $val, $vis, $d);
	rlc_web_prompt_act_type($val, 1, $vis, $def, $d);

	/* No default for product name */
	if (!$def)
	    rlc_web_prompt_product_id($k['product_id'], $numproducts, 
	    				$products, $active, $obsolete, 0, 0, 1);

	rlc_get_defaults($edit, $def, $sys, $user, "count", $k, $val, $vis, $d);
	rlc_web_prompt_fulfills($val, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "rehosts", $k, $val, $vis, 
									$d);
	rlc_web_prompt_rehosts($val, 1, $vis, $def, $d);

	if ($create) 
	{
	    rlc_web_prompt_numkeys($numkeys);
	}

	rlc_get_defaults($edit, $def, $sys, $user, "sub_interval", $k, $val, 
								$vis, $d);
	rlc_web_prompt_sub_interval($val, 1, $vis, $def, $d);
	if ($error && array_key_exists('sub_interval', $illegal))
					rlc_web_error($illegal['sub_interval']);

	rlc_get_defaults($edit, $def, $sys, $user, "sub_window", $k, $val, 
								$vis, $d);
	rlc_web_prompt_sub_window($val, 1, $vis, $def, $d);
	if ($error && array_key_exists('sub_window', $illegal))
					rlc_web_error($illegal['sub_window']);

	rlc_get_defaults($edit, $def, $sys, $user, "lastdate", $k, $val, 
								$vis, $d);
	rlc_web_prompt_lastdate($val, 1, $vis, $def, $d);
	if ($error && array_key_exists('lastdate', $illegal))
					rlc_web_error($illegal['lastdate']);

	rlc_get_defaults($edit, $def, $sys, $user, "exp", $k, $val, $vis, $d);
	rlc_web_prompt_exp($val, 1, $vis, $def, $d);
	if ($error && array_key_exists('exp', $illegal))
						rlc_web_error($illegal['exp']);

	rlc_get_defaults($edit, $def, $sys, $user, "kver", $k, $val, $vis, $d);
	rlc_get_defaults($edit, $def, $sys, $user, "kver_type", $k, $val2, 
								$xx, $xxx);
	rlc_web_prompt_version($val, $val2, 1, 1, $vis, $def, $d);
	if ($error && array_key_exists('kver', $illegal))
						rlc_web_error($illegal['kver']);

	rlc_get_defaults($edit, $def, $sys, $user, "white", $k, $val,$vis, $d);
	rlc_web_prompt_white($val, 1, $vis, $def, $d);

	rlc_get_defaults($edit, $def, $sys, $user, "misc", $k, $val, $vis, $d);
	$misc = _misc_to_array($val);
	rlc_web_hidden("miscHidden", 0);
	rlc_web_prompt_misc($misc, $def==0, $vis, $def, $d);
	if ($error && array_key_exists('misc', $illegal))
						rlc_web_error($illegal['misc']);

	rlc_get_defaults($edit, $def, $sys, $user, "notes", $k, $val,$vis, $d);
	rlc_web_prompt_notes($val, 1, $vis, $def, $d);

	/* No default for this */
	if ($create) rlc_web_prompt_akey($k['akey'], 1);
	else if (!$def)	rlc_web_hidden("akey", $akey);

	/* No default for this */
	if (!$def)
	    rlc_web_prompt_customer($k['contact_id'], $contacts, 1);

	rlc_get_defaults($edit, $def, $sys, $user, "key_allowed_hostids", $k,
								$val, $vis, $d);
	rlc_prompt_hostids($val, 1, $vis, $def, $d);

	if (array_key_exists('kcreate', $k))
	    rlc_web_hidden("kcreate", $k['kcreate']);

	rlc_web_hidden("ash_sn", $k['ash_sn']);
	rlc_web_hidden("user_def", $k['user_def']);
	rlc_web_hidden("submit_form", "1");

/*
 *	Javascript code to make certain options appear and disappear,
 *	depending on the activation key type.
 */

	echo '<script type="text/javascript">';

	echo 'function rlcActFormSet(elem, what) {';
	echo '  for (var i = 0; i < elem.length; i++) {';
	echo '    elem[i].style.display = what; } }';

	echo ' function rlcActType(form) {';
	/*
	echo '  alert("rlcActType"); ';
	*/
	echo '  if (!form) { form = document.getElementById("akeyForm"); } ';
	echo '  var acttype = form.type[form.type.selectedIndex].value;';
	echo '  var subscription = document.getElementsByName("subscription");';
	echo '  var fulfill = document.getElementsByName("fulfill");';
	echo '	if (acttype==4) {';
	echo '    rlcActFormSet(subscription, ""); ';
	echo '    rlcActFormSet(fulfill, "none"); ';
	echo '  } else {';
	echo '    rlcActFormSet(subscription, "none"); ';
	echo '    rlcActFormSet(fulfill, ""); ';
	echo '  } }';
	echo "window.onload = rlcActType(this.form); ";
	echo '</script>'; 
	return(0);
}

function display_create_form($sql, $who, $key, $numkeys, $error, $illegal)
{
	rlc_web_title("Create Activation Key", "rlc_create_key.php", "id=akeyForm");
	if (!display_form($sql, $who, $key, false, false, $numkeys, true, 
							$error, $illegal))
	{
	    rlc_web_info("Click \"GENERATE Activation Key(s)\" below to create".
					" the activation key(s)");
	    rlc_web_hidden("active", 1);
	    finish_page_extra("GENERATE Activation Keys(s)", "CANCEL", 
					"rlc_show_key.php", 0, 0, 0, 0, "", "");
	}
}

function display_edit_form($sql, $who, $key, $error, $illegal, $xtra)
{
	rlc_web_title("Edit Activation Key", "rlc_edit_key.php", "id=akeyForm");
	if (!display_form($sql, $who, $key, true, false, 1, 0, $error,$illegal))
	{
		echo $xtra;
		rlc_web_info("Click \"Save Changes\" below to Edit ".
						"this activation key");
		finish_page_extra("Save Changes", "CANCEL", "rlc_show_key.php",
						0, 0, 0, 0, $xtra, "");
	}
}

function display_defaults_form($sql, $who, $k, $error, $illegal)
{
	if ($who == SYSTEM_DEFAULTS) 
	{
	    $title = "Set System-Wide Activation Key Defaults";
	    $info = " SYSTEM-wide";
	}
	else  
	{
	    $title = "Set Activation Key Defaults for user \"".$who."\"";
	    $info = " for user ".$who;
	}
	rlc_web_title($title, "rlc_akey_defaults.php", "id=akeyForm");
	$key = array();
	display_form($sql, $who, $k, false, true, 1, false, $error, $illegal);
	rlc_web_info("Click \"Save Changes\" below to set the activation key".
							" defaults".$info);
	if (array_key_exists("system_defaults", $_POST))
		rlc_web_hidden("system_defaults", 1);
	finish_page_extra("Save Changes", "CANCEL", "rlc_akey_defaults.php",
						0, 0, 0, 0, "", "");
}


/*
 *	Check an activation key for legal input.
 */

function rlc_check_akey($lastdate, $exp, $misc, $kver)
{
	$ilchar = " - the following 6 characters are illegal: [' ` \" > < &]";
	$nospace = " - no spaces allowed";

	$il = _rlm_illegal_char($lastdate, 0, 1, 1);
	$il2 = _check_exp($lastdate, 1);
	$ie = _rlm_illegal_char($exp, 0, 1, 1);
	$ie2 = _check_exp($exp, 2);
	$ia = _rlm_illegal_char($misc, 0, 0, 1);
	$iv = _rlm_illegal_char($kver, 1, 1, 1);

	if ($il) $illegal['lastdate'] = "Illegal character ".$ilchar.$nospace;
	if ($il2) $illegal['lastdate'] = "Illegal expiriation date format (dd-mmm-yyyy)";
	if ($ie) $illegal['exp'] = "Illegal character ".$ilchar.$nospace;
	if ($ie2) $illegal['exp'] = "Illegal expiriation date format (dd-mmm-yyyy or positive integer)";
	if ($ia) $illegal['misc'] = "Illegal character ".$ilchar;
	if ($iv) $illegal['kver'] = "Illegal character ".$ilchar;

	if ($il || $il2 || $ie || $ie2 || $ia || $iv)
	{
		/* finish_page(0, 0, 0); */
		return($illegal);
	}
	return(FALSE);
}
?>
