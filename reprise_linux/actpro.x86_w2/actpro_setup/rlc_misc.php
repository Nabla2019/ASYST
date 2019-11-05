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

 	$Id: rlc_misc.php,v 1.5 2017/10/08 17:31:04 matt Exp $

 *****************************************************************************/

/*
 *	Check to see if the last part of a string is a keyword.
 */
function check_for_keyword($input, $keywords)
{
	$last = strrchr($input, ' ');
    	if (stripos($keywords, substr($last, 1))) return($last);
	else return(FALSE);
}

/*
 *	Trim off leading and trailing quotes if there are no others.
 */
function set_val($val)
{
	if ((substr_count($val, '"') == 2) && (substr($val, 0, 1) == '"') &&
		substr($val, -1, 1) == '"') $val = substr($val, 1, -1);
	return($val);
}

function _misc_to_array($misc)
{
	$debug = false;	/* To turn on debugging */
	$values = array();
        $m = array( "client_cache", "customer", "disable", "hold", 
		    "min_checkout", "max_roam", "max_roam_count", 
		    "named_user", "options", "platforms", "replace", 
		    "soft_limit", "share", "user_based",
		    "host_based", "timezone", "min_timeout", "issuer");
	$keywords = implode($m);
	foreach ($m as $mval)
	{
	    $values[$mval] = "";
	}

	$misc2 = trim($misc);
	parse_str($misc2, $value);
	/* $strings = explode(" ", $misc); */
	$i = 0;
/*
 *	The state variable is:
 *	quoted list + new list *2 + in list * 4 + in quote * 8
 *
 *	inq - in a quote
 *	inl - in a list
 *	nl - new list
 *	ql - quoted list
 *
 *	Input string type:
 *	ist:
 *	  0 - no leading quote
 *	  1 - single leading quote
 *	  2 - double leading quote
 *
 */
	$inq = $inl = $nl = $ql = 0;
	$state = 0;
/*
 *	State definitions
 */
define ("IL", 8);
define ("IQ", 4);
define ("NL", 2);
define ("QL", 1);
define ("IL_QL", 9);
define ("IL_NL", 10);
define ("IL_NL_QL", 11);
define ("IL_IQ", 12);
define ("IL_IQ_QL", 13);
define ("IL_IQ_NL", 14);

/*
 *	state action table.  -1 indicates an error.
 *
 *	state	input string type
 *		   0		 1		 2
 *      -------------------------------------------------
 *	  0	kw=input	ERR		ERR
 *	 1-7		- invalid -
 *	  8	append val	append val	append val
 *	  9	append val	ERR		ERR
 *	  10	append val	append val	append val
 *	  11	append val	append val	ERR
 *	  12	append val	append val	ERR
 *	  13	append val	append val	append val
 *	  14	append val	append val	ERR
 *	  15		- invalid -
 *
 *	Note: in states 9, 10, 13, check the input for a trailing
 *		keyword, if so, save the value in the old keyword,
 *		then set the new keyword to the one found and set
 *		the next state to IL_NL (10).
 */

/*
 *	State transition table
 */
$nextstate = array (
	array(IL_NL, -1, -1),
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(0, 0, 0),		/* States 1-7 are invalid */
	array(IL, IL_IQ, IL_IQ_QL),	/* IL = 8 */
	array(IL_QL, -1, -1),		/* IL_QL = 9 */
	array(IL, IL_QL, IL_IQ_QL),	/* IL_NL = 10 */
	array(IL_QL, IL_IQ_QL, -1),	/* IL_NL_QL = 11 */
	array(IL_IQ, IL, -1),		/* IL_IQ = 12 */
	array(IL_IQ_QL, IL_QL, 0),	/* IL_IQ_QL = 13 */
	array(IL_IQ, IL, -1),		/* IL_IQ_NL = 14 */
	array(0, 0, 0)		/* State 15 is invalid */
	);

	$str = $misc;
	if ($debug) echo "long string: $str<br>";
	$pairs = explode("=", $str);
	while (array_key_exists($i, $pairs))
	{
	    if ($debug) 
	    { 
	    	echo "<br>list: $inl, quote: $inq, "; 
 		echo "pairs: "; 
		for ($j=$i; array_key_exists($j, $pairs); $j++) 
		    	echo $pairs[$j]." ";
		echo "<br>";
	    }
	    /* TODO: handle quoted double-quotes: \" */

	    $input = $pairs[$i];
	    if (($state & (IQ | QL)) && !($state & NL) ) $input = "=".$input;

 	    if (substr($input, 0, 2) == '""') $ist = 2;
	    else if (substr($input, 0, 1) == '"') $ist = 1;
	    else $ist = 0;

/*
 *	    Set the next state, and do the actions for this state.
 */
 	    if ($state < 0)
	    {
	    	/* ERROR - what to do? */
		if ($debug) echo "ERROR: bad state $state<br>";
		$state = 0;
	    }
	    $nstate = $nextstate[$state][$ist];
	    if ($debug) echo "state: $state, ist: $ist, next: $nstate, string: ".$input."<br>";
	    switch ($state)
	    {
	      case 0;
	        if ($ist == 0)
		{
		    $kw = $input;
		    if ($debug) echo "Setting keyword to $kw<br>";
		    $val = "";
		}
	      	break;

	      case IL:	/* 8 */
 	    	if (stripos($keywords, $input))
	    	{
	    	    $state = IL_NL;
		    if (($kw != "") && ($val != ""))
		    {
			$values[$kw] = set_val($val);
			$kw = $input;
		    	if ($debug) echo "Setting keyword to $kw<br>";
			$val = "";
		    }
		    $i++;
		    if (!array_key_exists($i, $pairs)) break;
	    	}
		else
		{
		    if ($ist < 2)
			$val .= $input;
		    else
		    	$val .= substr($input, 1);
		}
	      	break;

	      case IL_QL:	/* 9 */
	        if ($ist > 0) break;
 		$newkw = check_for_keyword($input, $keywords);
		if ($newkw)
		{
		    $newval = substr($input, 0, strlen($input)-strlen($newkw));
		    if ($kw != "")
		    {
			$values[$kw] = set_val($val.$newval);
			if ($debug) echo "setting $kw to $values[$kw]<br>";
			$kw = substr($newkw, 1);
		    	if ($debug) echo "Setting keyword to $kw<br>";
			$val = "";
		    }
		    $nstate = IL_NL;
		}
		else
		    $val .= $input;
	      	break;

	      case IL_NL:	/* 10 */

 		$newkw = check_for_keyword($input, $keywords);
		if ($newkw)
		{
		    $newval = substr($input, 0, strlen($input)-strlen($newkw));
		    if ($kw != "")
		    {
			$values[$kw] = set_val($val.$newval);
			if ($debug) echo "setting $kw to $values[$kw]<br>";
			$kw = substr($newkw, 1);
		    	if ($debug) echo "Setting keyword to $kw<br>";
			$val = "";
		    }
		    $nstate = IL_NL;
		}
		else
		    $val .= $input;
	      	break;

	      case IL_NL_QL:	/* 11 */
	        if ($ist < 2) $val .= $input;
	      	break;

	      case IL_IQ:	/* 12 */
	        if ($ist < 2) $val .= $input;
	      	break;

	      case IL_IQ_QL:	/* 13 */
 		$newkw = check_for_keyword($input, $keywords);
		if ($newkw)
		{
		    $newval = substr($input, 0, strlen($input)-strlen($newkw));
		    if ($kw != "")
		    {
			$values[$kw] = set_val($val.$newval);
			if ($debug) echo "setting $kw to $values[$kw]<br>";
			$kw = substr($newkw, 1);
		    	if ($debug) echo "Setting keyword to $kw<br>";
			$val = "";
		    }
		    $nstate = IL_NL;
		}
		else
		    $val .= $input;
	      	break;

	      case IL_IQ_NL:	/* 14 */
		if ($ist < 2) $val .= $input;
	      	break;

	      default;
	      	break;
	    }
	    $state = $nstate;
	    $i++;
	}
	if ($kw != "") $values[$kw] = set_val($val);
	if ($debug) echo "done, kw: '$kw', val: '".$values[$kw]."'<br>";

	return($values);
}

function _values_to_misc()
{
	$misc = "";

        $m = array( array("client_cache", 0), 
		    array("customer", 1),
		    array("hold", 0),
		    array("min_checkout", 0),
		    array("max_roam", 0),
		    array("max_roam_count", 0),
		    array("named_user", 0),
		    array("options", 1),
		    array("platforms", 1),
		    array("replace", 1),
		    array("soft_limit", 0),
		    array("share", 0),
		    array("user_based", 0),
		    array("host_based", 0),
		    array("timezone", 0),
		    array("min_timeout", 0),
		    array("issuer", 1) );
	foreach ($m as $mval)
	{
            $c = rlc_getpost($mval[0], "");
	    if ($c != "") 
	    {
	        if ($mval[1])
		{
		    /* no space - leave as-is */
		    if (!strpos($c, ' '))
			$misc .= " $mval[0]=$c";
		    /* double-quotes at each end - strip one */
		    else if ((substr($c, 0, 2) == '""') ||
		        (substr($c, -2, 2) == '""'))
			$misc .= " $mval[0]=".substr($c, 1, -1);
		    /* otherwise quote the whole thing */
		    else
			$misc .= " $mval[0]=\"$c\"";
		}
		else          
		    $misc .= " $mval[0]=$c";
	    }
	}
	/* Disable */
        $v = rlc_getpost("vm", "");
	if ($v == "y") $v = "vm";
        $t = rlc_getpost("TerminalServer", "");
	if ($t == "y") $t = "TerminalServer";
	$d = $v;
	if ($d == "") $d = $t; else $d .= " ".$t;
	$d = trim($d);
	if ($d != "") 
	{
	    $misc .= " disable=\"$d\"";
	}
	/* Platforms */
	$pl = array("x86_w", "x64_w", "x86_l", "x64_l", "x86_m", "x64_m",
		   "aarch64_l", "arm9_l", "hp_h", "hp64_h", "ibm_a", 
		   "ibm64_a", "ia64_h",
		   "ia64_l", "ppc_m", "ppc64_l", "sun_s", "sun64_s",
		   "x86_n", "x86_s", "x64_s", "xpi_l");
	$plats = "";
	foreach ($pl as $p)
	{
            $v = rlc_getpost($p, "");
	    if ($v == "y")
	    {
	    	if ($plats == "") $plats = $p;
		else $plats .= " $p";
	    }
	}
	if ($plats != "") 
	{
	    $misc .= " platforms=\"$plats\"";
	}

	/* Timezones */
	$timezones = array("UTC", "UTC-1", "UTC-2", "UTC-3", "UTC-4", "UTC-5",
		   "UTC-6", "UTC-7", "UTC-8", "UTC-9", "UTC-10", "UTC-11",
		   "UTC-12", "UTC-13", "UTC-14", "UTC-15", "UTC-16", "UTC-17",
		   "UTC-18", "UTC-19", "UTC-20", "UTC-21", "UTC-22", "UTC-23");
	$tz = 0;
	$i = 1;
	foreach ($timezones as $t)
	{
            $v = rlc_getpost($t, "");
	    if ($v == "y") $tz |= $i;
	    $i <<= 1;
	}
	if ($tz != 0) 
	{
	    $x = sprintf(" timezone=0x%x", $tz);
	    $misc .= " $x";
	}

	/* Share */
	$share = "";
        $v = rlc_getpost("user", "");
	if ($v == "y") $share .= "u";
        $v = rlc_getpost("host", "");
	if ($v == "y") $share .= "h";
        $v = rlc_getpost("isv-string", "");
	if ($v == "y") $share .= "i";
	if ($share != "") 
	{
	    $misc .= " share=$share";
	}

	$misc = trim($misc);
	return($misc);
}

/*
 *	Javascript code to make misc options appear and disappear.
 */

	echo '<script type="text/javascript">';

	echo 'function rlcMiscFormSet(elem, what) {';
	/* echo '  alert("rlcMiscFormSet, length: "+elem.length+", what: \""+what+"\""); '; */
	echo '  for (var i = 0; i < elem.length; i++) {';
	echo '    elem[i].style.display = what; } }';

	echo ' function rlcMiscOptions(form) {';
	/*
	echo '  alert("rlcMiscOptions"); ';
	*/
	echo '  if (!form) { form = document.getElementById("createProd"); } ';
	echo '  var hidden = form.miscHidden.value;';
	echo '  var miscdata = document.getElementsByName("miscdata");';
	echo '  var button = document.getElementById("showMiscButton");';
	/** echo '  alert("rlcMiscOptions, hidden: "+hidden); '; /**/
	echo '	if (hidden != 0) {';
	echo '    rlcMiscFormSet(miscdata, "");  form.miscHidden.value=0; ';
	echo '    button.value="Hide All Miscellanous Options"; ';
	echo '  } else {';
	echo '    rlcMiscFormSet(miscdata, "none"); form.miscHidden.value=1; ';
	echo '    button.value="Show All Miscellanous Options"; ';
	echo '  } }';
	echo "window.onload = rlcMiscOptions(this.form); ";
	echo '</script>'; 
?>
