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

 	$Id: rlc_prompts.php,v 1.44 2017/10/08 17:31:04 matt Exp $

 *****************************************************************************/


/*
 *	Prompts for the RLC web forms
 */

/*
 *	Function to put a prompt into a table for default definitions.
 */

function _def_table($def, $vis, $d, $what)
{
	if ($def && ($vis < 2))
	{
	    rlc_web_row_start();
	    if (($d == NULL) || ($d == "")) $d = 0;
	    if (($vis == NULL) || ($vis == "")) $vis = 0;
	    rlc_web_checkbox("", "DEFAULT.$what", 1, $d, 1);
	    rlc_web_checkbox("", "VISIBLE.$what", 1, $vis, 1);
	    echo "<td>";
	    rlc_web_tableheader_blank();
	}
}

function _def_table_end($def)
{
	if ($def) 
	{
	    echo "</td>";
	    rlc_web_table_end();
	    echo "</td>";
	    rlc_web_row_end();
	}
}

function
rlc_web_prompt($label, $var, $varname, $size)
{
	echo "<tr><td>$label: </td> <td><input type=text name=$varname size=$size value=\"$var\"></td></tr>";
}

function
rlc_web_prompt_header($label)
{
	echo "<tr><td><b>$label</b></td></tr>";
}


function
rlc_web_error($text)
{
	if ($text == "") $err = "* Form has errors - see below *";
	else		 $err = $text;
	echo "<tr><td> </td><td class=error>$err</td></tr>";
}

function
_rlc_web_prompt_any($what, $val, $prompt, $p1, $p2, $vis, $def, $d)
{
	_def_table($def, $vis, $d, $what);
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($prompt)
		echo $p1;
	    else
		rlc_web_show_var($p2, $val);

	    _def_table_end($def);
	}
	else
	    rlc_web_hidden($what, $val);
}

function
rlc_web_prompt_akey($akey, $prompt)
{
	if ($prompt)
	    echo "<tr><td><b>Optional</b>: Activation Key to use (rlc will generate if not specified): </td> <td><input type=text name=akey size=30 value=\"$akey\"> <ht><b> [40 characters maximum]</b></td></tr>";
	else
	    rlc_web_show_var("Activation Key", $akey);
}

function
_rlc_lines($in)
{
	$p = $res = 0;
	$inlen = strlen($in);
	while ($p < $inlen)
	{
	    if ($in[$p] == "\n") $res++;
	    $p++;
	}
	return($res+1);
}

function
rlc_prompt_lictext($lictext, $prompt=1, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "lictext");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    $lines = _rlc_lines($lictext);
	    _rlc_html_quote_string($lictext, $reallictext);
	    if ($prompt)
	    {
		echo "<tr><td><abbr title=\"This field contains text that will be placed at the beginning of a fulfilled license.  As such, you probably want a pound sign (#) at the beginning of each line. (Max length: 1024 bytes)\"><b>Optional: </b><i>Text to prepend to license:</i></abbr> </td> <td><textarea  cols=64 rows=$lines name=lictext>$reallictext</textarea></td></tr>";
	    }
	    else
		rlc_web_show_var("Text to prepend to License", $reallictext);
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("lictext", $lictext);

}

/***
function
OLD_rlc_web_prompt_misc($misc, $prompt=1, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "misc");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    _rlc_html_quote_string($misc, $realmisc);

	    if ($prompt)
	    {
		echo "<tr><td><abbr title=\"This field must contain valid RLM license file syntax, e.g.:\nclient_cache=n\ndisable=TerminalServer\nhold=30\nmin_checkout=60\nmax_roam_count=7\nmax_roam=30\nnamed_user=n\noptions=<quote>list of options<quote>\nplatforms=<quote>x86_w x64_w<quote>\nreplace=abc\nsoft_limit=3\nshare=uh\nuser_based\nhost_based=3\ntimezone=1E0\nmin_timeout=240\nissuer=<quote>abc corp<quote>\"><b>Optional: </b><i>Other RLM keyword=value pairs:</i></abbr> </td> <td><input type=text name=misc size=64 value=\"$realmisc\"></td></tr>";
	    }
	    else
		rlc_web_show_var("Other License Parameters", $realmisc);
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("misc", $misc);

}
***/

function
rlc_web_prompt_misc($misc, $prompt=1, $vis, $def, $d)
{

    $m = array( array( "client_cache", "client_cache (sec, 0-1000)", 6),
		array( "customer", "customer (string, 64 characters max)", 64),
		array( "hold", "hold (min, 0-1000)", 6),
		array( "min_checkout", "min_checkout (sec, 0-10000)", 6),
		array( "max_roam", "max_roam (sec, 0-10000)", 6),
		array( "max_roam_count", "max_roam_count (sec, 0-10000)", 6),
		array( "named_user", "named_user (sec, 0-10000)", 6),
		array( "options", "options (string, 64 char max)", 64),
		array( "replace", "replace (list of licenses)", 32),
		array( "soft_limit", "soft_limit (count, 0-N)", 6),
		array( "user_based", "user_based (count, 0-N)", 6),
		array( "host_based", "host_based (count, 0-N)", 6),
		array( "min_timeout", "min_timeout (sec, 0-10000)", 6),
		array( "issuer", "issuer (string, 32-char max)", 32) );

	if ($prompt)
	{
	    echo "<tr><td colspan=2><hr></td></tr>";
	    rlc_web_clickbutton("Hide Miscellaneous Options", 
	 				"rlcMiscOptions(this.form)", 1, 
					"showMiscButton");
	}
	else
	{
	    echo "<tr><td></td><td></td><td><strong>Miscellaneous Options</strong>".
	    				"</td></td></td></tr>";
	}

	_def_table($def, $vis, $d, "misc");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    echo '<div name=misc_vals>';
	    foreach ($m as $mval)
	    {
	        _rlc_html_quote_string($misc[$mval[0]], $realmisc);
		echo "<tr><td name=miscdata><i>$mval[1]:</i></td><td name=miscdata><input type=text name=$mval[0] size=$mval[2] value=\"$realmisc\"></td></tr>";
	    }

	    $disabled = " ".$misc['disable'];
	    $name = "name=miscdata";
	    echo "<tr><td $name>Disable:</i></td>";
	    echo "<td $name colspan=3><table><tr>";
	    rlc_hostid_checkbox("", "vm", stripos($disabled, "vm"), 1, $name);
	    rlc_hostid_checkbox("", "TerminalServer", 
	    			stripos($disabled, "terminalserver"), 1, $name);
	    echo "</tr></table></td></tr>";

	    $plats = " ".$misc['platforms'];
	    echo "<tr><td $name>Allowed platforms:</i></td>";
	    echo "<td $name colspan=3><table>";
	    echo "<tr>";
	    rlc_hostid_checkbox("", "x86_w", strpos($plats, "x86_w"), 1, $name);
	    rlc_hostid_checkbox("", "x64_w", strpos($plats, "x64_w"), 1, $name);
	    rlc_hostid_checkbox("", "x86_l", strpos($plats, "x86_l"), 1, $name);
	    rlc_hostid_checkbox("", "x64_l", strpos($plats, "x64_l"), 1, $name);
	    rlc_hostid_checkbox("", "x86_m", strpos($plats, "x86_m"), 1, $name);
	    rlc_hostid_checkbox("", "x64_m", strpos($plats, "x64_m"), 1, $name);
	    echo "</tr><tr>";
	    rlc_hostid_checkbox("", "aarch64_l", strpos($plats, "aarch64_l"), 1, $name);
	    rlc_hostid_checkbox("", "arm9_l", strpos($plats, "arm9_l"), 1, $name);
	    rlc_hostid_checkbox("", "hp_h", strpos($plats, "hp_h"), 1, $name);
	    rlc_hostid_checkbox("", "hp64_h", strpos($plats, "hp64_h"), 1, $name);
	    rlc_hostid_checkbox("", "ibm_a", strpos($plats, "ibm_a"), 1, $name);
	    rlc_hostid_checkbox("", "ibm64_a", strpos($plats, "ibm64_a"),1, $name);
	    rlc_hostid_checkbox("", "ia64_h", strpos($plats, "ia64_h"), 1, $name);
	    rlc_hostid_checkbox("", "ia64_l", strpos($plats, "ia64_l"), 1, $name);
	    echo "</tr><tr>";
	    rlc_hostid_checkbox("", "ppc_m", strpos($plats, "ppc_m"), 1, $name);
	    rlc_hostid_checkbox("", "ppc64_l", strpos($plats, "ppc64_l"),1, $name);
	    rlc_hostid_checkbox("", "sun_s", strpos($plats, "sun_s"), 1, $name);
	    rlc_hostid_checkbox("", "sun64_s", strpos($plats, "sun64_s"),1, $name);
	    rlc_hostid_checkbox("", "x86_n", strpos($plats, "x86_n"), 1, $name);
	    rlc_hostid_checkbox("", "x86_s", strpos($plats, "x86_s"), 1, $name);
	    rlc_hostid_checkbox("", "x64_s", strpos($plats, "x64_s"), 1, $name);
	    rlc_hostid_checkbox("", "xpi_l", strpos($plats, "xpi_l"),1, $name);
	    echo "</tr></table></td></tr>";

	    $tz = hexdec($misc['timezone']);
	    echo "<tr><td $name>Allowed timezones:</i></td>";
	    echo "<td $name colspan=3><table>";
	    echo "<tr>";
	    rlc_hostid_checkbox("", "UTC", $tz & 0x1, 1, $name);
	    rlc_hostid_checkbox("", "UTC-1 (EGT)", $tz&0x2, 1, $name, "UTC-1");
	    rlc_hostid_checkbox("", "UTC-2 (GST)", $tz&0x4, 1, $name, "UTC-2");
	    rlc_hostid_checkbox("", "UTC-3 (ADT)", $tz&0x8, 1, $name, "UTC-3");
	    rlc_hostid_checkbox("", "UTC-4 (AMT)", $tz&0x10, 1,$name, "UTC-4");
	    rlc_hostid_checkbox("", "UTC-5 (EST)", $tz&0x20, 1,$name, "UTC-5");
	    rlc_hostid_checkbox("", "UTC-6 (CST)", $tz&0x40, 1,$name, "UTC-6");
	    rlc_hostid_checkbox("", "UTC-7 (MST)", $tz&0x80, 1,$name, "UTC-7");
	    echo "</tr><tr>";
	    rlc_hostid_checkbox("", "UTC-8 (PST)", $tz&0x100,1, $name, "UTC-8");
	    rlc_hostid_checkbox("", "UTC-9 (AKST)", $tz&0x200, 1,$name,"UTC-9");
	    rlc_hostid_checkbox("", "UTC-10 (CKT)", $tz&0x400,1,$name,"UTC-10");
	    rlc_hostid_checkbox("", "UTC-11 (SST)", $tz&0x800,1,$name,"UTC-11");
	    rlc_hostid_checkbox("", "UTC-12 (BIT)",$tz& 0x1000,1,$name,"UTC-12");
	    rlc_hostid_checkbox("", "UTC-13 (NFT)",$tz&0x2000,1,$name,"UTC-13");
	    rlc_hostid_checkbox("","UTC-14 (ACST)",$tz&0x4000,1,$name,"UTC-14");
	    rlc_hostid_checkbox("","UTC-15 (JST)",$tz&0x8000,1,$name,"UTC-15");
	    echo "</tr><tr>";
	    rlc_hostid_checkbox("","UTC-16 (CST)",$tz&0x10000,1,$name,"UTC-16");
	    rlc_hostid_checkbox("","UTC-17 (CXT)",$tz&0x20000,1,$name,"UTC-17");
	    rlc_hostid_checkbox("","UTC-18 (BST)",$tz&0x40000,1,$name,"UTC-18");
	    rlc_hostid_checkbox("","UTC-19 (PKT)", $tz&0x80000,1,$name,"UTC-19");
	    rlc_hostid_checkbox("","UTC-20 (GST)",$tz&0x100000,1,$name,"UTC-20");
	    rlc_hostid_checkbox("","UTC-21 (MSK)",$tz&0x200000,1,$name,"UTC-21");
	    rlc_hostid_checkbox("","UTC-22 (EET)",$tz&0x400000,1,$name,"UTC-22");
	    rlc_hostid_checkbox("","UTC-23 (CET)",$tz&0x800000, 1, $name,"UTC-23");
	    echo "</tr></table></td></tr>";

	    $share = " ".$misc['share'];
	    echo "<tr><td $name>Share by (all checked must match):</i></td>";
	    echo "<td $name colspan=3><table><tr>";
	    rlc_hostid_checkbox("", "user", stripos($share, "u"), 1, $name);
	    rlc_hostid_checkbox("", "host", stripos($share, "h"), 1, $name);
	    rlc_hostid_checkbox("", "isv-string", stripos($share, "i"), 1, 
	    								$name);
	    echo "</tr></table></td></tr>";
	    echo "</div>";
	    echo "<tr><td colspan=2><hr></td></tr>";

	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("misc", $misc);

}

function
rlc_web_prompt_notes($notes, $prompt=1, $vis, $def, $d)
{
	$p1 = "<tr><td><b>Optional</b>: Notes: </td> <td><input type=text name=notes size=64 value=\"".$notes."\"></td></tr>";
	$p2 = "Notes";
	_rlc_web_prompt_any("notes", $notes, $prompt, $p1, $p2, $vis, $def, $d);
}

function rlc_web_prompt_act_type($type, $prompt, $vis, $def, $d)
{
	$act_types = array("Normal", "ReActivate", "Refresh (deprecated)", "Normal-Regen",
				"Subscription");

	_def_table($def, $vis, $d, "type");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($prompt)
	    {
		echo "<tr><td>Activation Key Type: </td> <td>".
			"<select id=type onchange=rlcActType(this.form) ".
			"name=type>";
		for ($i=0; $i<=RLM_ACT_KEY_TYPE_MAX; $i++)
	        {
	        	if ($i == $type)  $selected = " selected=\"selected\"";
			else              $selected = "";
			echo "<option value=".$i." ".$selected.">".
						$act_types[$i]."</option>";
		}
		echo "</td></tr></select>";
	    }
	    else
	    {
		rlc_web_show_var("Activation Type", $act_types[$type]);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("type", $type);
}

function
rlc_web_prompt_fulfills($count, $prompt, $vis, $def, $d)
{
	$p1 = "<tr><td name=fulfill># of fulfillments for each Activation key (0 for no limit): </td> <td name=fulfill><input type=text name=count size=10 value=\"$count\"></td></tr>";
	$p2 = "# of fulfillments for activation key";
	_rlc_web_prompt_any("count", $count, $prompt, $p1, $p2, $vis, $def, $d);
}

function
rlc_web_prompt_generator($generator, $prompt=1, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "generator");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($prompt)
		echo "<tr><td>License Generator Algorithm: </td> <td><input type=text name=generator size=10 value=\"$generator\"> <b>[=0: RLM standard algorithm, !=0: ISV-defined]</b></td></tr>";
	    else
		rlc_web_show_var("License Generator algorighm", $generator);

	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("generator", $generator);

}

function
rlc_web_prompt_rehosts($rehosts, $prompt, $vis, $def, $d)
{
	$p1 = "<tr><td># of rehosts allowed [0-9999, 0 for unlimited]: </td> <td><input type=text name=rehosts size=10 value=\"$rehosts\"></td></tr>";
	$p2 = "# of rehosts allowed";
	_rlc_web_prompt_any("rehosts", $rehosts, $prompt, $p1, $p2, $vis, $def,
									$d);
}

function rlc_web_prompt_report_type($type, $report_types)
{
	echo "<table><tr><td>Activation Report: </td> <td><select name=report_type>";
	for ($i=0; $i<count($report_types); $i++)
	{
	    if ($i == $type)  $selected = " selected=\"selected\"";
	    else              $selected = "";
	    echo "<option value=\"".$report_types[$i]."\" ".$selected.">".
					$report_types[$i]."</option>";
	}
	echo "</td></tr><tr><td>Report Output:</td><td>";
	echo "<input type=radio name=rep_output value=0 checked=true>HTML to browser&nbsp&nbsp&nbsp";
	echo "<input type=radio name=rep_output value=9>tab-delimited (file)&nbsp&nbsp&nbsp";
	echo "<input type=radio name=rep_output value=44>comma-delmited (file)&nbsp&nbsp";
	echo "</td></tr>";
	echo "</td></tr></select>";
}
function
rlc_web_prompt_white($white, $prompt, $vis, $def, $d)
{
	$p1 = "<tr><td><b>Optional</b>: Allowed domains (whitelist - 64 bytes max): </td> <td><input type=text name=white size=64 value=\"$white\"></td></tr>";
	$p2 = "Allowed domains";
	_rlc_web_prompt_any("white", $white, $prompt, $p1, $p2, $vis, $def, $d);

}

function
rlc_web_prompt_lastdate($lastdate, $prompt, $vis, $def, $d)
{
	$p1 =  "<tr><td><b>Optional</b>: Activation key expiration date: </td> <td><input type=text name=lastdate size=10 value=\"$lastdate\"></td></tr>";
	$p2 = "Activation key expiration date";
	_rlc_web_prompt_any("lastdate", $lastdate, $prompt, $p1, $p2, $vis, 
								$def, $d);
}

function rlc_web_prompt_lictype($type, $prompt, $vis, $def, $d)
{
/*
 *	0: floating	  4: floating upgrade
 *	1: NL, uncounted  5: NL, uncounted upgrade
 *	2/6: reserved for NL, counted
 *	3: single         7: single upgrade
 *	8: alternate server hostid
 *	9: alternate nodelock hostid
 */
	_def_table($def, $vis, $d, "lictype");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    $check0 = $check1 = $check3 = $check4 = $check5 = $check7 = 
	    	$check8 = $check9 = "";
	    if ($type == 0)      $check0=" checked=true"; 
	    else if ($type == 3) $check3=" checked=true"; 
	    else if ($type == 4) $check4=" checked=true"; 
	    else if ($type == 5) $check5=" checked=true"; 
	    else if ($type == 7) $check7=" checked=true"; 
	    else if ($type == 8) $check8=" checked=true"; 
	    else if ($type == 9) $check9=" checked=true"; 
	    else		 $check1=" checked=true"; 

	    if ($prompt)
	    {
		echo "<tr><td>License Type:</td><td>";
		echo "<table><tr><td>";
		echo "<input type=radio name=lictype value=1$check1>Nodelocked, Uncounted</td><td>";
		echo "<input type=radio name=lictype value=3$check3>Single</td><td>";
		echo "<input type=radio name=lictype value=0$check0>Floating</td></tr><tr><td>";
		echo "<input type=radio name=lictype value=5$check5>NL, Uncounted UPGRADE</td><td>";
		echo "<input type=radio name=lictype value=7$check7>Single UPGRADE</td><td>";
		echo "<input type=radio name=lictype value=4$check4>Floating UPGRADE</td></tr>";
		echo "<tr><td><input type=radio name=lictype value=8$check8>Alternate Server Hostid</td>";
		echo "<td><input type=radio name=lictype value=9$check9>Alternate Nodelock Hostid</td>";
		echo "</table></td></tr>";
	    }
	    else
	    {
		$lictype = license_type($type);
		rlc_web_show_var("License Type", $lictype);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("lictype", $type);
}

function rlc_web_prompt_active($active, $prompt, $vis=0, $def=0, $d=0)
{
	_def_table($def, $vis, $d, "obsolete");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($active == 1) $check=" checked=true"; else $check = "";

	    if ($prompt)
    		echo "<tr><td><abbr title=\"No activations allowed if disabled\"><i>Enabled? (yes if checked)</i>: </abbr></td><td><input type=checkbox name=active value=1$check></td></tr>";
	    else
	    {
		if ($active == 1) $act = "Yes"; else $act = "No";
		rlc_web_show_var("Active?", $act);
	    }
	}
	else
	    rlc_web_hidden("active", $active);
}

function rlc_web_prompt_obsolete($obsolete, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "obsolete");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($obsolete == 1) $check=" checked=true"; else $check = "";

	    if ($prompt)
		echo "<tr><td><abbr title=\"Activations allowed but no new activation keys can be created if obsolete\"><i>Obsolete? (yes if checked)</i>: </abbr></td><td><input type=checkbox name=obsolete value=1$check></td></tr>";

	    else
	    {
		if ($obsolete == 1) $obs = "Yes"; else $obs = "No";
		rlc_web_show_var("Obsolete?", $obs);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("obsolete", $obsolete);
}


function rlc_web_prompt_add_akey($add_akey, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "add_akey");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    $check0 = $check1 = $check2 = "";
/*
*	0: none	 
*	1: include akey
*	2: include akey and without akey
*/
    
	    if ($add_akey == 1)	 $check1=" checked=true"; 
	    else if ($add_akey == 2) $check2=" checked=true"; 
	    else		         $check0=" checked=true"; 

	    if ($prompt)
	    {
	 	echo "<tr><td><abbr title=\"The akey= attribute was added in RLM v11.0.  If you deliver software built with pre-v11, the software won't recognize the akey= license attribute, and the license will be invalid.  By selecting 2 licenses (3rd choice), ActPro will generate one license with the akey= attribute and a 2nd license without the akey= attribute which will be usable by your pre-v11 applications.  Note that a second license will NEVER be generated for any counted license type, since this would yield extra licenses.\">Include Activation Key in License:</abbr></td><td>";
		echo "<table><tr><td>";
		echo "<input type=radio name=add_akey value=0$check0>No&nbsp</td><td>";
		echo "<input type=radio name=add_akey value=1$check1>Yes&nbsp</td><td>";
		echo "<input type=radio name=add_akey value=2$check2>2 licenses: one with and one without</td></tr><tr><td>";
		echo "</table></td></tr>";

	    }
	    else
	    {
		$lictype = license_type($type);
		rlc_web_show_var("License Type", $lictype);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("add_akey", $add_akey);
}

function
rlc_web_prompt_ash_hostid($ash_type, $ash_tolerance, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "ash_type");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    $none = $startup = $daily = "";
	    if ($ash_type == 1) $none = "checked=true";
	    else if ($ash_type == 2) $startup = "checked=true";
	    else if ($ash_type == 3) $daily = "checked=true";
	    else  $none = "checked=true";

	    if ($prompt)
	    {
		echo "<tr><td>";
		echo "<b>Optional:</b> Alternate Server Hostid parameters";
		echo ": </td><td><table><tr>";

		echo "<td>Activation Server Check: </td>";
		echo "<td><input type=radio name=ash_type value=1 $none>None&nbsp&nbsp&nbsp</td>";
		echo "<td><input type=radio name=ash_type value=2 $startup>At Startup&nbsp&nbsp&nbsp</td>";
		echo "<td><input type=radio name=ash_type value=3 $daily>Daily&nbsp&nbsp&nbsp</td>";
	        echo "<td>Check failure tolerance: </td>";
	        echo "<td><input type=text name=ash_tolerance size=2 value=\"$ash_tolerance\"> </td>";
		echo "</tr></table></td></tr>";
	    }
	    else
	    {
		if ($ash_type == 1) 
		    echo("Alternate Server Hostid, No checks");
    		else if ($ash_type == 2) 
		    echo("Alternate Server Hostid, checked at startup");
  		else if ($ash_type == 3)  
		    echo("Alternate Server Hostid, checked every night");
	    }
	    _def_table_end($def);
	}
	else
	{
	    rlc_web_hidden("ash_type", $ash_type);
	    rlc_web_hidden("ash_tolerance", $ash_tolerance);
	}
}

function
rlc_web_prompt_issued($issued, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "issued");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($issued == 1) $check=" checked=true"; else $check = "";
	    if ($prompt)
	    {
		echo "<tr><td>Create issued=today? (yes if checked): </td>";
		rlc_web_checkbox("", "issued", 1, $issued, 1);
		echo "</tr>";
	    }
	    else
	    {
		if ($issued == 1) $iss = "yes"; else $iss = "no";
		rlc_web_show_var("Create issued=today?", $iss);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("issued", $issued);
}

function
rlc_web_prompt_custeq($customer, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "add_cust");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($customer == 1) $check=" checked=true"; else $check = "";
	    if ($prompt)
	    {
		echo "<tr><td>Create customer= in license? (yes if checked): </td>";
		rlc_web_checkbox("", "add_cust", 1, $customer, 1);
		echo "</tr>";
	    }
	    else
	    {
		if ($customer == 1) $cust = "yes"; else $cust = "no";
		rlc_web_show_var("Create customer= in license?", $cust);
	    }
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("add_cust", $customer);
}

function
rlc_web_prompt_nlic($nlic, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "nlic");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    echo "<tr><td># of licenses to create per activation [1-9999]: </td> <td><input type=text name=nlic size=10 value=\"$nlic\"><ht><b> [only used for floating licenses - multiplies requested count]</b></td></tr>";
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("nlic", $nlic);
}

function
rlc_web_prompt_numkeys($numkeys)
{
	echo "<tr><td># of Activation keys to create [1-9999]: </td> <td><input type=text name=numkeys size=10 value=\"$numkeys\"></td></tr>";
}

function
rlc_web_prompt_prod_name($product_name, $prompt)
{
	if ($prompt)
	    echo "<tr><td>Name of this product definition: </td> <td><input type=text name=name size=30 value=\"$product_name\"></td></tr>";
	else
	    rlc_web_show_var("Product Definition Name", $product_name);

}

function
rlc_web_prompt_prod_license($product, $prompt)
{
	if ($prompt)
	    echo "<tr><td>Product Name (in generated license): </td> <td><input type=text name=product size=30 value=\"$product\"></td></tr>";
	else
	    rlc_web_show_var("Product Name", $product);
}

function
rlc_web_prompt_customer($contact_id, $customers, $prompt)
{
	if ($prompt) 
	{
	    echo "<tr><td><b>Optional:</b> Contact Person: </td> <td><select name=contact_id>";
	    if ($contact_id == 0) $selected = " selected=\"selected\"";
	    else $selected = "";
	    echo "<option value=0".$selected.">-None-</option>";
	}

	while ($row = mysqli_fetch_array($customers))
	{
	    $id = $row['contact_id'];
	    if ($row['contact'] == "") continue; 
	    $name = $row['contact'];
	    if ($row['company'] != "") $name .= " - ".$row['company'];

	    if ($contact_id == $id) 
	    {
		if ($prompt)
			$selected = " selected=\"selected\"";
		else
		{
			rlc_web_show_var("Contact", $name);
			return;
		}
	    }
	    else	       
	    {
		$selected = "";
	    }
	    if ($prompt) 
		echo "<option value=".$id.$selected.">".$name."</option>";
	}
	if ($prompt) echo "</td></tr>";
}

function
rlc_web_prompt_company($company_id, $companies, $prompt)
{
	if ($prompt) 
	{
	    echo "<tr><td>Company: </td> <td><select name=company_id>";
	    if ($company_id == 0) $selected = " selected=\"selected\"";
	    else $selected = "";
	    echo "<option value=0".$selected.">-None-</option>";
	}

	while ($row = mysqli_fetch_array($companies))
	{
	    $id = $row['company_id'];
	    $name = $row['company'];
	    if ($row['addr1'] != "") $name .= ", ";
	    $name .= $row['addr1'];
	    if ($row['city'] != "") $name .= ", ";
	    $name .= $row['city'];
	    if ($row['state'] != "") $name .= ", ";
	    $name .= $row['state'];

	    if ($company_id == $id) 
	    {
		if ($prompt)
			$selected = " selected=\"selected\"";
		else
		{
			rlc_web_show_var("Company", $name);
			return;
		}
	    }
	    else	       
	    {
		$selected = "";
	    }
	    if ($prompt) 
		echo "<option value=".$id.$selected.">".$name."</option>";
	}
	if ($prompt) echo "</td></tr>";
}

function
rlc_web_prompt_contact($contacts, $cid=0)
{
	echo "<tr><td>Contact: </td> <td><select name=contact_id>";
	if ($cid == 0) $sel = "selected=selected";
	else $sel = "";
	echo "<option value=0 $sel>-None-</option>";

	while ($row = mysqli_fetch_array($contacts))
	{
	    $id = $row['contact_id'];
	    $name = $row['contact'];
	    if ($row['email'] != "") $name .= ", ";
	    $name .= $row['email'];

	    if ($cid == $id) $sel = "selected=selected";
	    else $sel = "";

	    echo "<option value=".$id." $sel>".$name."</option>";
	}
	echo "</td></tr>";
}

function
rlc_web_prompt_product_id($product_id, $numproducts, $products, $active, 
					$obsolete, $include_all, 
					$include_act_obs, $prompt)
{
	asort($products);			/* New in 12.0 */
	$keys = array_keys($products);

	if ($prompt)
	{
	    echo "<tr><td>Product Name: </td> <td><select name=product_id>";
	    if ($include_all)
	    {
		echo "<option value=*all*>*ALL PRODUCTS*</option>";
	    }
	    foreach ($keys as $key)
	    {
		if ($product_id == $key) 
		{
		    $selected = " selected=\"selected\"";
		}
		else	       
		{
		    $selected = "";
		}

		$inact = "";
		if (!$active[$key]) 
		{
		    if ($include_act_obs) $inact = " (<i>inactive</i>)";
		    else continue;
		}
		if ($obsolete[$key]) 
		{
		    if ($include_act_obs) $obs = " (<i>obsolete</i>)";
		    else continue;
		}

		echo "<option value=".$key.$selected.">".$products[$key].$inact.
							$obs."</option>";
	    }
	}
	else
	{
	    rlc_web_show_var("Product ID", $product_id);
	}
}

function
rlc_web_prompt_contact_id($contacts, $whatdisp)
{
	$first = true;
	echo "<tr><td>Which $whatdisp will remain: </td><td>".
						"<select name=survivor>";
	while ($contact = current($contacts))
	{
	    if ($first)
	    {
		$selected = " selected=\"selected\"";
		$first = false;
	    }
	    else	       
	    {
		$selected = "";
	    }

	    echo "<option value=".key($contacts).$selected.">".$contact."</option>";
	    next($contacts);
	}
}

function
rlc_web_prompt_contact_type($types, $thistype)
{
	echo "<tr><td>Contact Type: </td> <td><select name=contact_type>";
	if ($thistype == "") $selected = " selected=\"selected\"";
	else $selected = "";
	echo "<option value=\"\"".$selected.">-none-</option>";
	while ($row = mysqli_fetch_array($types, MYSQLI_ASSOC))
	{
	    $type = $row['contact_type'];
	    if ($type == $thistype) 
	    {
		$selected = " selected=\"selected\"";
	    }
	    else	       
	    {
		$selected = "";
	    }
	    echo "<option value=".$type.$selected.">".$type."</option>";
	}
}

function
rlc_web_prompt_sub_interval($interval, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, $interval);
	$val = "";
	$normal_check = $month_check = $quarter_check = $year_check = "";
	if ($interval == RLM_ACT_SUBSCRIPTION_MONTH)
	    $month_check = "checked=true";
	else if ($interval == RLM_ACT_SUBSCRIPTION_QUARTER)
	    $quarter_check = "checked=true";
	else if ($interval == RLM_ACT_SUBSCRIPTION_YEAR)
	    $year_check = "checked=true";
	else
	{
	    $normal_check = "checked=true";
	    $val = $interval;
	}
	if (($vis == 0) || ($def && ($vis < 2)))
	{

	    if ($prompt)
	    {
		echo "<tr><td name=subscription>";
		$abbrev = "Subscription interval can be either one month, one quarter, one year, or a specified # of days";
    		echo "<abbr title=\"$abbrev\"><i>Subscription Interval:</i></abbr>";
		echo "</td><td name=subscription><table><tr>";
		echo "<td><input type=radio name=sub_interval value=".
			RLM_ACT_SUBSCRIPTION_MONTH." $month_check>Monthly</td>";
		echo "<td><input type=radio name=sub_interval value=".
			RLM_ACT_SUBSCRIPTION_QUARTER." $quarter_check>Quarterly</td>";
		echo "<td><input type=radio name=sub_interval value=".
			RLM_ACT_SUBSCRIPTION_YEAR." $year_check>Yearly</td>";
		echo "<td><input type=radio name=sub_interval value=0 $normal_check># days:&nbsp</td>";
		echo "<td><input type=text name=sub_interval_val size=5 
						value=\"$val\"> </td>";
		echo "</tr></table></td></tr>";
	    }
	    else
	    {
		if ($interval == RLM_ACT_SUBSCRIPTION_MONTH)
		    rlc_web_show_var("Subscription Interval", "1 month");
	    	else if ($interval == RLM_ACT_SUBSCRIPTION_QUARTER)
		    rlc_web_show_var("Subscription Interval", "1 quarter");
	    	else if ($interval == RLM_ACT_SUBSCRIPTION_YEAR)
		    rlc_web_show_var("Subscription Interval", "1 year");
		else
		    rlc_web_show_var("Subscription Interval", $val);
	    }
	    _def_table_end($def);
	}
	else
	{
	    rlc_web_hidden("sub_interval", $interval);
	}
}

function
rlc_web_prompt_sub_window($window, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "sub_window");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    echo "<tr><td name=subscription>Subscription Renewal Window: </td> <td name=subscription><input type=text name=sub_window size=5 value=\"$window\"> <ht><b>(# of days before expiration when the license can be re-activated)</b></td>";
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("sub_window", $window);
}

function
rlc_web_prompt_version($ver, $ver_type, $prompt, $key=0, $vis, $def, $d)
{
	if ($key) $keyword = "kver";
	else      $keyword = "version";

	_def_table($def, $vis, $d, $keyword);
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($ver_type == 0)
	    {
		$normal_check = "checked=true";
		$db_check = "";
	    }
	    else
	    {
		$db_check = "checked=true";
		$normal_check = "";
	    }

	    if ($prompt)
	    {
		echo "<tr><td>";
		$abbrev = "Normal versions are in integer or floating-point number format,\ne.g. 1, 1.2, 10.7, 9.333\ndate-based versions are an integer number of months from activation,\nso a date-based version of 10 activated in January, 2016\nwould have a version number of 2016.11";
		if ($key)
		{
		    $keytype = "kver_type";
    		    echo "<abbr title=\"$abbrev\"><b>Optional:</b><i> Product Version (Overrides Product Definition):</i></abbr>";
		}
		else      
		{
		    $keytype = "version_type";
    		    echo "<abbr title=\"$abbrev\"><i>Product Version (in generated license):</i></abbr>";
		}
		echo "</td><td><table><tr>";
		echo "<td><input type=text name=$keyword size=10 value=\"$ver\"> </td>";
		echo "<td><input type=radio name=$keytype value=0 $normal_check>Normal&nbsp</td>";
		echo "<td><input type=radio name=$keytype value=1 $db_check>Date-Based</td>";
		echo "</tr></table></td></tr>";
	    }
	    else
	    {
		if ($ver_type == 0)
		    rlc_web_show_var("Product Version", $ver);
		else
		    rlc_web_show_var_trailing("Product Version (date-based)", 
				" months after activation", $ver);
	    }
	    _def_table_end($def);
	}
	else
	{
	    rlc_web_hidden($keyword, $ver);
	    rlc_web_hidden($keyword."_type", $ver_type);
	}
}

function
rlc_web_prompt_upgrade($upgrade_version, $prompt, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "upgrade_version");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($prompt)
		echo "<tr><td><b>Optional: </b>Upgrade from Version: </td> <td><input type=text name=upgrade_version size=10 value=\"$upgrade_version\"></td></tr>";
	    else
		rlc_web_show_var("Upgrade from Version", $upgrade_version);
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("upgrade_version", $upgrade_version);
}

function
rlc_web_prompt_exp($exp, $optional, $vis, $def, $d)
{
	_def_table($def, $vis, $d, "exp");
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    if ($optional) 
	    {
		$opt = "<b>Optional: </b>";
		$opt2 = "(Overrides Product Definition)";
	    }
	    else	       
	    {
		$opt = "";
		$opt2 = "";
	    }
	    echo "<tr><td>$opt License expiration date: $opt2</td> <td><input type=text name=exp size=10 value=\"$exp\"> <ht><b>[0=permanent, number=# of days, string=fixed date]</b></td>";
	    _def_table_end($def);
	}
	else
	    rlc_web_hidden("exp", $exp);
}

function rlc_prompt_hostids($val, $akey=0, $vis, $def, $d)
{
	if ($akey) $keyword = "key_allowed_hostids";
	else $keyword = "prod_allowed_hostids";
	_def_table($def, $vis, $d, $keyword);
	if (($vis == 0) || ($def && ($vis < 2)))
	{
	    echo "<tr><td colspan=3><table>";
	    if ($akey) $x = " or any specified hostids in the product definition";
	    else $x = "";
	    echo "<tr><td><abbr title=\"Checking any of the selections below will override the settings from the rlm_isv_cfg_actpro_allowed_hostids() call in rlm_isv_config.c$x\"><b>Optional: </b><i>Allowed hostid types:</i> </abbr></td></td></tr>";
	    echo "<tr><td>(if any specified, overrides default";
	    if ($akey) echo " and product definition";
	    echo ")</td></tr>";

	    echo "<tr><td></td>";
	    rlc_hostid_checkbox("", "rehostable", $val & ACTPRO_ALLOW_REHOST,1);
	    rlc_hostid_checkbox("", "isv-defined", $val & ACTPRO_ALLOW_ISV, 1);
	    rlc_hostid_checkbox("", "isv-string", $val & ACTPRO_ALLOW_ISVDEF,1);
	    rlc_hostid_checkbox("", "rlmid", $val & ACTPRO_ALLOW_RLMID, 1);
	    rlc_hostid_checkbox("", "ethernetMACaddr", $val & ACTPRO_ALLOW_ETHER
									, 1);
	    echo "</tr><tr><td></td>";
	    rlc_hostid_checkbox("", "32-bit", $val & ACTPRO_ALLOW_32, 1);
	    rlc_hostid_checkbox("", "diskSerial#", $val & ACTPRO_ALLOW_DISKSN, 1);
	    rlc_hostid_checkbox("", "IPaddress", $val & ACTPRO_ALLOW_IP, 1);
	    rlc_hostid_checkbox("", "UUID", $val & ACTPRO_ALLOW_UUID, 1);
	    rlc_hostid_checkbox("", "Alternate Server/Nodelock", 
	    					$val & ACTPRO_ALLOW_ASH, 1);
	    echo "</tr><tr><td></td>";
	    rlc_hostid_checkbox("", "username", $val & ACTPRO_ALLOW_USER, 1);
	    rlc_hostid_checkbox("", "hostname", $val & ACTPRO_ALLOW_HOST, 1);
	    rlc_hostid_checkbox("", "serial#", $val & ACTPRO_ALLOW_SN, 1);
	    rlc_hostid_checkbox("", "string", $val & ACTPRO_ALLOW_STRING, 1);
	    rlc_hostid_checkbox("", "demo", $val & ACTPRO_ALLOW_DEMO, 1);
	    echo "</tr><tr><td></td>";
	    rlc_hostid_checkbox("", "any", $val & ACTPRO_ALLOW_ANY, 1);
	    echo "</tr></table></td></tr>";
	    _def_table_end($def);
	}
	else
	{
	    rlc_web_hidden("rehostable", $val & ACTPRO_ALLOW_REHOST ? "y" : "");
	    rlc_web_hidden("isv-defined", $val & ACTPRO_ALLOW_ISV ? "y" : "");
	    rlc_web_hidden("rlmid", $val & ACTPRO_ALLOW_RLMID ? "y" : "");
	    rlc_web_hidden("ethernetMACaddr", $val & ACTPRO_ALLOW_ETHER ? "y" : 
	    								"");
	    rlc_web_hidden("32-bit", $val & ACTPRO_ALLOW_32 ? "y" : "");
	    rlc_web_hidden("diskSerial#", $val & ACTPRO_ALLOW_DISKSN ? "y" :"");
	    rlc_web_hidden("IPaddress", $val & ACTPRO_ALLOW_IP ? "y" : "");
	    rlc_web_hidden("username", $val & ACTPRO_ALLOW_USER ? "y" : "");
	    rlc_web_hidden("hostname", $val & ACTPRO_ALLOW_HOST ? "y" : "");
	    rlc_web_hidden("serial#", $val & ACTPRO_ALLOW_SN ? "y" : "");
	    rlc_web_hidden("string", $val & ACTPRO_ALLOW_STRING ? "y" : "");
	    rlc_web_hidden("demo", $val & ACTPRO_ALLOW_DEMO ? "y" : "");
	    rlc_web_hidden("any", $val & ACTPRO_ALLOW_ANY ? "y" : "");
	}
}
?>
