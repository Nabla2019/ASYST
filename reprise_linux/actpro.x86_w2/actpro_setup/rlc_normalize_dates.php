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

 	$Id: rlc_normalize_dates.php,v 1.4 2016/04/08 02:55:45 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include 'rlc_mysql.php';
include 'login_session.php';

define("READ_TEST", "SELECT orig FROM datetest");

function rlc_dbop($sql, $query, &$res)
{
	$res = mysqli_query($sql, $query);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$query."</i></b><br>";
		echo "MySQL error ".mysqli_error($sql)."<br>";
		return(1);
	}
	else return(0);
}

/*
 *	Convert a date from RLM format to "normalized" (sortable)
 */

function convert_date($old)
{
	list($day, $month, $year) = sscanf($old, "%d-%[^-]-%d");
	if (($day != "") && ($month != "") && ($year != "") &&
		($day < 32) && (($year < 100) || ($year > 1900)))
	{
	    if ($year == 0) return("permanent");
	    if ($year < 100) $year += 2000;
	    $d = sprintf("%02d", $day);
	    $month = strtolower($month);
	    switch ($month)
	    {
	      case 'jan': $m = "01"; break;
	      case 'feb': $m = "02"; break;
	      case 'mar': $m = "03"; break;
	      case 'apr': $m = "04"; break;
	      case 'may': $m = "05"; break;
	      case 'jun': $m = "06"; break;
	      case 'jul': $m = "07"; break;
	      case 'aug': $m = "08"; break;
	      case 'sep': $m = "09"; break;
	      case 'oct': $m = "10"; break;
	      case 'nov': $m = "11"; break;
	      case 'dec': $m = "12"; break;
	      default:  $m = $month; break;
	    }
	    $res = $year."-".$m."-".$d;
	    return($res);
	}
	return($old);
}
/*
 *	This is used to setup a test table.
 */
function setup_tests($sql)
{
/*******   Create the test data 
$months = array("jan", "Feb", "mAr", "apR", 
		"MAy", "JuN", "jUL", "AUG",
		"sep", "oct", "nov", "dec");

	$year = 0;
	$day = 0;
	foreach ($months as $month) 
	{
	    while ($day < 30)
	    {
	    	$year++;
		$day++;
		if (($month == "Feb") && ($day > 28)) break;
	        if ($year > 25) $year = 0;
		if ($year > 5) $y = $year+2000;
		else $y = $year;
	        $date =  "$day-$month-$y";
		$query = "INSERT INTO `datetest` (`orig`) VALUES ('$date');";
		$stat = mysqli_query($sql, $query);
		if (!$stat)
		{
			echo "Error inserting $date in datetest table<br>";
			echo mysqli_error($sql)."<br>";
			echo "query is $query<br>";
		}
	    }
	    $day = 0;
	}
	*****************/
}

$months = array("jan", "feb", "mar", "apr", 
		"may", "jun", "jul", "aug",
		"sep", "oct", "nov", "dec");

function process_test($sql)
{
	/**************   convert the test data 

define("READ_TEST", "SELECT orig FROM datetest");

	$stat = rlc_dbop($sql, READ_TEST, $res);
	if ($stat != 0)
	{
	    rlc_web_info("Can't read testdate table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($res);

	    if ($rows == 0)
	    {
	    	    echo "No dates in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$bad = 0;
		while ($row = mysqli_fetch_array($res, MYSQLI_ASSOC))
		{
		    if (!$row['orig']) 
		    {
		    	$bad++;
		    }
		    else
		    {
			$o = $row['orig'];
			$c = convert_date($o);
			echo "Replacing $o with $c<br>";
			$query = "update datetest set converted = '$c' where orig='$o'";
			rlc_dbop($sql, $query, $x);
		    }
		    $numdisp++;
		}
		echo "$numdisp dates converted, $bad bad dates<br>";
	    }
	}

	/**************/
}


define("READ_KEYD", "SELECT akey, exp, lastdate FROM keyd");
define("READ_PROD", "SELECT id, exp FROM prod");

/*
 *	Normalize all dates in the activation keys "exp" and "last date valid"
 *	columns.
 */
	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("Normalize Dates", "rlc_admin_db.php");

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);

	echo "<h4>Normalizing dates in activation keys table...</h4>";

	$stat = rlc_dbop($sql, READ_KEYD, $res);
	if ($stat != 0)
	{
	    rlc_web_info("Can't read keyd table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($res);

	    if ($rows == 0)
	    {
	    	    echo "No activation keys in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$missing = 0;
		while ($row = mysqli_fetch_array($res, MYSQLI_ASSOC))
		{
		    if (!$row['exp'] && !$row['lastdate']) 
		    {
		    	$missing++;
		    	continue;
		    }
		    else
		    {
			$a = $row['akey'];
			$oe = $row['exp'];
			$ol = $row['lastdate'];
			if ($oe) $ne = convert_date($oe);
			else $ne = "";
			if ($ol) $nl = convert_date($ol);
			else $nl = "";
			$query = "update keyd set exp='$ne', lastdate='$nl' where akey='$a'";
			/*** echo "query is $query<br>"; /**/
			rlc_dbop($sql, $query, $x);
		    }
		    $numdisp++;
		}
		echo "$numdisp dates converted, $missing keys with no dates<br>";
	    }
	}
	echo "<h4>Normalizing dates in product definition table...</h4>";

	$stat = rlc_dbop($sql, READ_PROD, $res);
	if ($stat != 0)
	{
	    rlc_web_info("Can't read prod table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($res);

	    if ($rows == 0)
	    {
	    	    echo "No product definitions in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$missing = 0;
		while ($row = mysqli_fetch_array($res, MYSQLI_ASSOC))
		{
		    if (!$row['exp'])
		    {
		    	$missing++;
		    	continue;
		    }
		    else
		    {
			$id = $row['id'];
			$oe = $row['exp'];
			$ne = convert_date($oe);
			$query = "update prod set exp='$ne' where id='$id'";
			rlc_dbop($sql, $query, $x);
		    }
		    $numdisp++;
		}
		echo "$numdisp dates converted, $missing products with no exp<br>";
	    }
	}

	rlc_mysql_close($sql);
	finish_page("BACK", 0, 0);

?>
