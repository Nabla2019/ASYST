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

 	$Id: rlc_defaults.php,v 1.13 2017/08/21 21:12:59 matt Exp $

 *****************************************************************************/

/*
 *	Process defaults for product and akey editing
 */

define ("QUERY_DEFAULTS", "SELECT * from defaults where (user=\"%s\" AND tab=\"%s\")");

/*
 *	Read all the defaults for later.
 */
function rlc_read_defaults($sql, $who, $tab, &$sys, &$user)
{
	if ($who == SYSTEM_DEFAULTS) $user = NULL;
	else
	{
	    $temp = sprintf(QUERY_DEFAULTS, $who, $tab);
	    $user = mysqli_query($sql, $temp);
	    if (!$user) echo "Error on $who defaults: ".mysqli_error($sql)."<br>";
	}

	$temp = sprintf(QUERY_DEFAULTS, SYSTEM_DEFAULTS, $tab);
	$sys = mysqli_query($sql, $temp);
	if (!$sys) echo "Error on sys defaults: ".mysqli_error($sql)."<br>";
}

function rlc_default($defaults, $what, &$default, &$invis)
{
	$default = /*false; */"";
	$invis = 0;
	while ($row = mysqli_fetch_array($defaults))
	{
	    if (array_key_exists('col', $row) && ($row['col'] == $what))
	    {
		$default = $row['value'];
		$invis = $row['invis'];
	    }
	}
	mysqli_data_seek($defaults, 0);
}

/*
 *	Get the default data for one item.
 */
function rlc_get_defaults($edit, $set, $sys, $user, $what, $input, &$val, &$inv,
									&$d)
{
	if ($set)
	{
	    $inv = $input[$what."_inv"];
	    $val = $input[$what];
	    $d = $input[$what."_def"];
	}
	else
	{
	    rlc_default($sys, $what, $def, $invs);
	    rlc_default($user, $what, $defu, $invu);
	    if (array_key_exists($what, $input))
	    	$val = $input[$what];
	    else
	    	$val = "";
	    if (!$edit)
	    {
		if ($defu != "") $val = $defu; else if ($def != "") $val = $def;
	    }
	    if ($invs || $invu) $inv = 1; else $inv = 0;
	/**
	    echo "default for $what is $val, (inv: $inv) input is \"".$input[$what]."\"<br>";
	/**/
	}
}

/*
 *	read_table_defaults() - used only for reading and updating
 *	the default values, not for reading defaults when building
 *	the form.
 *
 *	include_sys is used so that the system defaults are included
 *	when the form is presented, but not when the defaults are read
 *	for re-writing them (unless we are re-writing the system defaults).
 */
function rlc_mysql_read_table_defaults($sql, $table, $who, $p, $include_sys)
{
	rlc_read_defaults($sql, $who, $table, $sys, $user);
	if ($who == SYSTEM_DEFAULTS) $do_system = true; else $do_system = false;
/*
 *	First, read all the system defaults.
 */
	while ($row = mysqli_fetch_array($sys))
	{
	    if (array_key_exists('col', $row))
	    {
		$c = $row['col'];
		$cd = $c."_def";
		$cv = $c."_inv";
		$cid = $c."_id";
		$p[$c] = $row['value'];
		if ($do_system)
		{
		    $p[$cd] = 1;
		    $p[$cv] = $row['invis'];
		    $p[$cid] = $row['id'];
		}
		else if ($include_sys)
		{
		    if ($row['invis']) $p[$cv] = 2;	/* Flag as unsettable */
		}
	    }
	}
	mysqli_data_seek($sys, 0);
/*
 *	Next, update with the user's defaults.
 */
	if (!$do_system)
	{
	    while ($row = mysqli_fetch_array($user))
	    {
		if (array_key_exists('col', $row))
		{
		    $c = $row['col'];
		    $cd = $c."_def";
		    $cv = $c."_inv";
		    $cid = $c."_id";
/*
 *		    If the row is already invisible from a system-wide
 *		    default, we don't use the user's default.
 */
		    if (!array_key_exists($cv, $p) || $p[$cv] != 2)
		    {
	    		$p[$c] = $row['value'];
			$p[$cd] = 1;
			$p[$cv] = $row['invis'];
			$p[$cid] = $row['id'];
			/*
			echo "Setting $c user default to ($cd)".$p[$c].
		    			", vis: ($cv)".$p[$cv]."<br>";
			*/
		    }
		}
	    }
	    mysqli_data_seek($user, 0);
	}
	return($p);
}

define ("WRITE_DEFAULT", "REPLACE INTO defaults (id, user, tab, col, value, invis) VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d)");
define ("WRITE_DEFAULT_NOID", "REPLACE INTO defaults (user, tab, col, value, invis) VALUES (\"%s\", \"%s\", \"%s\", \"%s\", %d)");
define ("REMOVE_DEFAULT", "DELETE FROM defaults where (id=%d AND user=\"%s\" AND tab=\"%s\" AND col=\"%s\")");

define("DEFAULT", "DEFAULT");
define("VISIBLE", "VISIBLE");

/*
 *	Write a default entry
 */
function _write_def($sql, $old_def, $who, $col, $p, $table, $errs)
{
	_rlc_act_quote_string($p[$col], $val);
	if (array_key_exists($col."_id", $old_def))
	    $temp = sprintf(WRITE_DEFAULT, $old_def[$col."_id"], $who, 
							$table, $col, $val,
							$p[$col."_inv"]);
	else
	    $temp = sprintf(WRITE_DEFAULT_NOID, $who, $table, $col, $val,
							$p[$col."_inv"]);
	/** echo "Adding $col to defaults, val: ".$p[$col].", query: $temp<br>";
									/**/
	$res = mysqli_query($sql, $temp);
	if (!$res) $errs++;
	return($errs);
}

/*
 *	Remove a default entry
 */
function _remove_def($sql, $old_def, $who, $col, $table, $errs)
{
	$temp = sprintf(REMOVE_DEFAULT, $old_def[$col."_id"], $who,
		    					$table, $col);
	/** echo "Removing $col from defaults, query: $temp<br>"; /**/
	$res = mysqli_query($sql, $temp);
	if (!$res) $errs++;
	return($errs);
}

function rlc_mysql_write_table_defaults($sql, $table, $who, $cols, $p)
{
	$errs = 0;
	$odef = array();
	$old_def = rlc_mysql_read_table_defaults($sql, $table, $who, $odef, 0);
	/** echo "old defaults for $who:<br>"; print_r($old_def); 
							echo "<br>"; /**/
	/** echo "new defaults:<br>"; print_r($p); echo "<br>"; /**/
	/** echo "new defaults columns:<br>"; print_r($cols); echo "<br>"; /**/
	foreach ($cols as $col)
	{
/*
 *	    First, add the new ones.
 */
	    if (($p[$col."_def"] != "") ||
	        ($p[$col."_inv"] != ""))
	    {
	    	$errs = _write_def($sql, $old_def, $who, $col, $p, $table,
									$errs);
/*
 *		Special-case the multi-column defaults
 */
 		if ($col == "ash_type")
		    $errs = _write_def($sql, $old_def, $who, "ash_tolerance",
		    					$p, $table, $errs);
 		else if ($col == "kver")
		    $errs = _write_def($sql, $old_def, $who, "kver_type",
		    					$p, $table, $errs);
 		else if ($col == "version")
		    $errs = _write_def($sql, $old_def, $who, "version_type",
		    					$p, $table, $errs);
	    }
	    else
	    {
		if ((array_key_exists($col."_inv", $old_def) &&
		      ($old_def[$col."_inv"] != "")) ||
		    (array_key_exists($col."_def", $old_def) &&
		      ($old_def[$col."_def"] != "")))
		{
		    /**
		    if (array_key_exists($col."_inv", $old_def) &&
		      ($old_def[$col."_inv"] != ""))
		      	echo "$col._inv:".$old_def[$col."_inv"]."<br>";
		    if (array_key_exists($col."_def", $old_def) &&
		      ($old_def[$col."_def"] != ""))
		      	echo "$col._def:".$old_def[$col."_def"]."<br>";
		    /**/

/*
 *		    If it is in the old defaults, but not the new, remove it.
 */
		    $errs = _remove_def($sql, $old_def, $who, $col, $table,
		    							$errs);
/*
 *		    Special-case the multi-column defaults
 */
		    if ($col == "ash_type")
			$errs = _remove_def($sql, $old_def, $who, 
						"ash_tolerance", $table, $errs);
		    else if ($col == "kver")
			$errs = _remove_def($sql, $old_def, $who, 
						"kver_type", $table, $errs);
		    else if ($col == "version")
			$errs = _remove_def($sql, $old_def, $who, 
						"version_type", $table, $errs);
		}
	    }
	}
	return($errs);
}
?>
