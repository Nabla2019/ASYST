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

 	$Id: rlc.php,v 1.45 2017/10/01 20:27:45 matt Exp $

 *****************************************************************************/

define("RLC_ACTPRO_VERSION", "12");
define("RLC_ACTPRO_REV", "3");
define("RLC_ACTPRO_BUILD", "3");
define("RLC_ACTPRO_PATCH", "0");
define("RLC_ACTPRO_DATE", "8-dec-2017");
define("RLC_DBDESC", "actpro.php");
define("RLC_DBDESC_OLD", "rlmact.mysql");

define ("RLC_ROWS_PER_PAGE",  20);	/* # of rows/page in default display */

define("AUTO_BL_NUMKEY", 40);		/* Auto-blacklist default parameters */
define("AUTO_BL_MAXSEC", 600);

define("DLCMDFILE", "tmp/dl_db.php");
/* For hostedactivation server stats */
define("COLOR_RED", "#ff0000");
define("COLOR_YELLOW", "#ffff00");
define("COLOR_GREEN", "#00ff00");


/*
 *      General Errors - returned by rlm_stat(license_handle)
  */
define("RLM_EH_ACT_BADSTAT",     -134); /* Bad status from activation binary */
define("RLM_EH_ACT_BADLICKEY",   -135); /* Bad license key in activation binary */
define("RLM_EH_BAD_HTTP",        -136);    /* Bad HTTP transaction */
define("RLM_ACT_ERR_FIRST",        1001);
define("RLM_ACT_BADPARAM",        -1001);
define("RLM_ACT_NO_KEY",          -1002);
define("RLM_ACT_NO_PROD",         -1003);      /* No product definition */
define("RLM_ACT_CANT_WRITE_KEYS", -1004);      /* Can't write keyf table */
define("RLM_ACT_KEY_USED",        -1005);      /* Activation key already used*/
define("RLM_ACT_BAD_HOSTID",      -1006);      /* Missing hostid */
define("RLM_ACT_BAD_HOSTID_TYPE", -1007);      /* Invalid hostid type */
define("RLM_ACT_BAD_HTTP",        -1008);      /* Bad HTTP transaction - UNUSED after v3.0BL4 */
define("RLM_ACT_CANTLOCK",        -1009);      /* Can't lock activation DB */
define("RLM_ACT_CANTREAD_DB",     -1010);      /* Can't read activation DB */
define("RLM_ACT_CANT_WRITE_FULFILL", -1011);   /* Can't write licf table */
define("RLM_ACT_CLIENT_TIME_BAD", -1012);      /* Clock incorrect on client */
define("RLM_ACT_BAD_REDIRECT",    -1013);      /* Bad redirect from server */
define("RLM_ACT_TOOMANY_HOSTID_CHANGES",  -1014);/* Too many hostid changes */
                                                /*  for Refresh activation */
define("RLM_ACT_BLACKLISTED",     -1015);      /* Domain on blacklist */
define("RLM_ACT_NOT_WHITELISTED", -1016);      /* Domain not on whitelist */
define("RLM_ACT_KEY_EXPIRED",     -1017);      /* Activation key expired */
define("RLM_ACT_NO_PERMISSION",   -1018);      /* HTTP request denied */
define("RLM_ACT_SERVER_ERROR",    -1019);      /* HTTP internal server error */
/*
 *	Internal errors in the php code
 */
define ("RLM_ACT_BAD_QUERY",	-2001);		/* Bad sql query */
define ("RLM_ACT_NO_ROWS",	-2002);		/* No rows found */

/*
 *	Activation Key types
 */
define("RLM_ACT_KEY_TYPE_MAX", "4");
define("RLM_ACT_KEY_TYPE_NORMAL", "0");
define("RLM_ACT_KEY_TYPE_REACTIVATE", "1");
define("RLM_ACT_KEY_TYPE_REFRESH", "2");
define("RLM_ACT_KEY_TYPE_NORMAL_REGEN", "3");
define("RLM_ACT_KEY_TYPE_SUBSCRIPTION", "4");

define("RLM_ACT_SUBSCRIPTION_MONTH", "-1");
define("RLM_ACT_SUBSCRIPTION_QUARTER", "-2");
define("RLM_ACT_SUBSCRIPTION_YEAR", "-3");

/*
 *	Tab definitions for the UI
 */
define("PRODUCTS_TAB", 1);
define("KEYS_TAB", 2);
define("FULFILLMENTS_TAB", 4);
define("CUSTOMERS_TAB", 8);
define("REPORTS_TAB", 16);
define("PROFILE_TAB", 32);
define("ALL_TABS", 63);

/*
 *	Flags for the delete and merge functions
 */
define("DELETE_MULTIPLE", "DeLeTe_MuLtIpLe");
define("DELETE_MULTIPLE_DOIT", "DeLeTe_MuLtIpLe_DoIt");
define("DELETE_ITEM", "D-");
define("MERGE_ITEM", "M-");
define("MERGE_CONTACTS", "MERGE-CONTACT");
define("MERGE_COMPANIES", "MERGE-COMPANY");

/*
 *	The username for system-wide defaults
 */

define("SYSTEM_DEFAULTS", "#SYS#");

function rlc_noview($session)
{
	if ($session->logged_in)
	{
	    rlc_web_info("You are not authorized to view or edit data.");
	}
	else
	{
	    rlc_web_info("You must log in to view or edit data.");
	}
}


function rlc_noadmin($session)
{
	if ($session->logged_in)
	{
	    rlc_web_info("You are not authorized to administer activation functions.");
	}
	else
	{
	    rlc_web_info("You must log in to administer activation functions.");
	}
}

/*
 *	Get a variable from the session
 */

function rlc_getvar($var, $def)
{
	if (isset($_SESSION[$var]))
		return $_SESSION[$var];
	else
		return $def;
}

function rlc_getpost($var, $def)
{
	if (isset($_POST[$var]))
		return $_POST[$var];
	else
		return $def;
}

function rlc_getinput($var, $def)
{
	if (isset($_POST[$var]))
	    return $_POST[$var];
	else if (isset($_GET[$var]))
	    return $_GET[$var];
	else
	    return $def;
}

/*
 *	Support routines for all the functions
 */

/*
 *	Check for illegal characters in product and version
 */

function _rlm_illegal_char($s, $version, $check_spaces, $check_quotes)
{
	$inquote=0;
	$p = 0;
	$len = strlen($s);
        while ($p < $len)
        {
		$c = $s[$p];
                if ($c == '"')
                {
                        if ($inquote) $inquote=0; else $inquote=1;
                }

		if ($version)
		{
			if (($c != '.') && !ctype_digit($c)) return(1);
		}
		else if (($check_spaces && !$inquote && ctype_space($c)) ||
                    ($check_quotes && (($c == '\'') || ($c == '`'))) ||
                    ($c == '>') ||
                    ($c == '<') ||
                    ($c == '&')    ) return(1);
                $p++;
        }
        if ($inquote) return(1);
        else         return(0);
}

function _check_exp($exp, $act_key)
{
	if ($act_key && ($exp == "")) return(0);
	$_valid_months = array("jan", "feb", "mar", "apr", "may", "jun", 
			"jul", "aug", "sep", "sept", "oct", "nov", "dec" );
	$temp = $exp;
	$p = 0;
	$m = $d = $y = -1;
	$num = 1;
	$day = $month = $ystring = "X";
	$len = strlen($temp);
        while ($p < $len)
        {
		if ($temp[$p] == '-') 
		{
			$num = 0;
			if ($d == -1) 
			{ 
				$day = substr($temp, 0, $p); 
				$d = $p; 
			}
			else if ($m == -1) 
			{ 
				$month = substr($temp, $d+1, $p-$d-1); 
				$m = $p; 
			}
			else if ($y == -1) 
			{ 
				return(-1);
			}
		}
		else if (!ctype_alnum($temp[$p])) return(-1);
		$p++;
	}	
	if ($num == 1) 
	{
		if ($act_key == 1) return(-1);
		if (!is_numeric($temp)) return(-1);
		$expdays = sscanf($temp, "%d");
		if ($expdays >= 0) return(0);
	}
	else if ($m != -1) 
	{
	    $ystring = substr($temp, $m+1);
	    sscanf($day, "%d", $monthday);
	    sscanf($ystring, "%d", $year);
/*
 *	    First, figure out if it is "normalized" format
 */
 	    if ($monthday > 50)	/* Normalized format yyyy-mm-dd */
	    {
	        /* year is monthday, day is year */
		$y = $monthday;
		$d = $year;
	        sscanf($month, "%d", $m);
		if ($y < 0 || $y >= 10000) return(-1);
		if ($m < 0 || $m > 12) return(-1);
		if (($d < 0) || ($d > 31)) return(-1);
	    }
	    else	/* standard RLM format dd-mmm-yyyy */
	    {
	        $whichmonth = array_search($month, $_valid_months);
		if ($year < 0 || $year >= 10000) return(-1);
		if (($monthday < 0) || ($monthday > 31)) return(-1);
		if ($whichmonth === FALSE) return(-1);
	    }
	    return(0);
	}
	return(-1);
}

function check_user($session) 
{ 
  	$perm['act_enabled'] = true; 
  	$perm['act_view_enabled'] = false; 
  	$perm['act_edit_enabled'] = false; 
  	$perm['act_portal_enabled'] = false; 		/* P425 */

	if (!$session->logged_in) return($perm);
	if ($session->userlevel == PORTAL_LEVEL) 	/* P425 */
	{
  	    $perm['act_portal_enabled'] = true; 
	    return($perm);
	}

	if ($session->canView())  $perm['act_view_enabled'] = true; 
	if ($session->canEdit())  $perm['act_edit_enabled'] = true; 

	return($perm);
}

define("RLC_ACTPRO_LT_ASH", 8);
define("RLC_ACTPRO_LT_ANH", 9);

function license_type($type)
{
	$lt = "Floating";
	if ($type == 1) $lt = "Nodelocked, Uncounted";
	else if ($type == 2) $lt = "Nodelocked, Counted";
	else if ($type == 3) $lt = "Single";
	else if ($type == 4) $lt = "Floating UPGRADE";
	else if ($type == 5) $lt = "NL, Uncounted UPGRADE";
	else if ($type == 7) $lt = "Single UPGRADE";
	else if ($type == 8) $lt = "Alternate Server Hostid";
	else if ($type == 9) $lt = "Alternate Nodelock Hostid";
	return($lt);
}

/*
 *	Format the server alternate hostid
 */
function ash_hostid_disp($ash_type, $ash_tolerance)
{
	if ($ash_type == 1) $str = "none:";
	else if ($ash_type == 2) $str = "startup:";
	else if ($ash_type == 3) $str = "daily:";
	else $str = "???:";
	$str .= $ash_tolerance;
	return($str);
}



function rlc_turn_off_warnings()
{
	$e = error_reporting();
	$new = $e & ~(E_WARNING | E_NOTICE);
	error_reporting($new);
	return($e);
}

/*
 *	Quote strings passed to html forms
 */

function _rlc_html_quote_string($in, &$out)
{
	$out = " ";
	$inlen = strlen($in);
	if ($inlen == 0)
	{
		$out = "";
		return;
	}
	$p = 0;  $q = 0;
	while ($p < $inlen)
	{
		if ($in[$p] == '"') 
		{
			$out[$q++] = '&';
			$out[$q++] = 'q';
			$out[$q++] = 'u';
			$out[$q++] = 'o';
			$out[$q++] = 't';
			$out[$q++] = ';';
			$p++;
		}
		else if ($in[$p] == '+') 
		{
			$out[$q++] = '%';
			$out[$q++] = '2';
			$out[$q++] = 'B';
			$p++;
		}
		else
			$out[$q++] = $in[$p++];
	}
}

function _rlc_sql_fmt($in, &$out)
{
	$out = " ";
	$inlen = strlen($in);
	if ($inlen == 0)
	{
		$out = "";
		return;
	}
	$p = 0;  $q = 0;
	while ($p < $inlen)
	{
		if ($in[$p] == '<') 
		{
			$p++;
			if (($p < $inlen) && $in[$p] == '<') 
			{
				$out[$q++] = '<';
				$p++;
			}
			else
				$out[$q++] = '\'';
		}
		else
			$out[$q++] = $in[$p++];
	}
}

function _rlc_remove_dot($in, &$out)
{
	$out = " ";
	$il = strlen($in);
	$p = 0;
	while ($p < $il)
	{
		if ($in[$p] == '.') $out[$p] = '-';
		else $out[$p] = $in[$p];
		$p++;
	}
}

/*
 *	Turn on warnings...
 */

	$_errrpt = error_reporting();
	$_errrpt = $_errrpt | (E_WARNING | E_NOTICE);
	error_reporting($_errrpt);

function rlc_get_isvname($session, &$isv, &$db, &$dbhost)
{

	$isv = $db = $dbhost = "";
	$e = rlc_turn_off_warnings();
	$data = file(RLC_DBDESC);
	error_reporting($e);
	if ($session->logged_in)
	{
	    if ($data[1] != "") $dbhost = rtrim($data[1]);
	    if ($data[3] != "") $db = rtrim($data[3]);
	}
	if ($data[6] != "") $isv = rtrim($data[6]);
}

/*
 *	Standard time display
 */

function rlc_get_timestr($what)
{
	$errlevel = rlc_turn_off_warnings();
	if (($what == NULL) || ($what == 0)) $timestr = "";
	else $timestr = date("Y-m-d H:i", $what);	
	return($timestr);
}

/*
 *	Debugging function to show form input fields
 *
function rlc_remove_bracket($in)
{
	$out = " ";
	$inlen = strlen($in);
	if ($inlen == 0)
	{
		$out = "";
		return ($out);
	}
	$p = 0;  $q = 0;
	while ($p < $inlen)
	{
		if ($in[$p] == '<') $out[$q++] = '[';
		else if ($in[$p] == '>') $out[$q++] = ']';
		else $out[$q++] = $in[$p];
		$p++;
	}
	return($out);
}
/**/

/* 
 * Refresh button for debugging 
 *

echo '<a href="javascript:document.location.reload();"';
echo 'ONMOUSEOVER="window.status=\'Refresh\'; return true"';
echo '<img src="images/refresh.jpg" alt="Refresh" ' ;
echo 'width="115" height="31" border="0" /></a>';
/* end refresh button */

include "rlc_web.php";
?>
