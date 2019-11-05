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

 	$Id: rlc_debuglog.php,v 1.17 2016/12/07 04:12:01 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';


define("GET_DEBUGLOG", "SELECT * FROM `debuglog`");
define("GET_DLOG_SELECT", "SELECT * FROM `debuglog` where `logdata` REGEXP \"%s\"");

function rlc_get_dlog($sql, $sel, &$res)
{
	if ($sel == "")
	    $temp = GET_DEBUGLOG;
	else
	    $temp = sprintf(GET_DLOG_SELECT, $sel);

	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		echo "MySQL error ".mysqli_error($sql)."<br>";
		return(1);
	}
	else return(0);
}

function rlc_del_debuglog_doit($sql, $cleardate)
{
	if ($cleardate == "all")
	    $q = sprintf("DELETE FROM debuglog where 1");
	else
	    $q = sprintf("DELETE FROM debuglog where date < %d", $cleardate);
	mysqli_query($sql, $q);
	if ($cleardate == "all")
	{
	   echo "Debuglog cleared<br>";
	}
	else
	{
	    $d = date('Y-m-d', $cleardate);
	    echo "Debuglog cleared prior to $d<br><br>";
	}
	finish_page("BACK", 0, 0);
}

define ("DAY", 24*60*60);
define ("WEEK", 7*DAY);
define ("DAYS30", 30*DAY);
define ("DAYS60", 60*DAY);

function rlc_del_dlog()
{
	echo "Clear debuglog info earlier than:<br>";
        echo "<table>";
	$t = time();
	$yd = $t-DAY;
	$y = date('Y-m-d', $yd);
	$wd = $t-WEEK;
	$w = date('Y-m-d', $wd);
	$d30 = $t-DAYS30;
	$days30 = date('Y-m-d', $d30);
	$d60 = $t-DAYS60;
	$days60 = date('Y-m-d', $d60);
        echo "<tr><td><input type=radio name=cleardate value=$yd> Yesterday&nbsp&nbsp&nbsp</td><td>($y)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$wd> One week ago&nbsp&nbsp&nbsp</td><td>($w)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$d30> 30 days ago&nbsp&nbsp&nbsp</td><td>($days30)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=dspec> Earlier than: &nbsp&nbsp&nbsp</td>";
        echo "<td><input type=text name=dspec size=10 value=$days60> </td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=\"all\" checked=true> EVERYTHING&nbsp&nbsp&nbsp</td><td>(Delete Entire Debuglog)</td></tr>";
        echo "</table>";
	$hid = "<input type='hidden' name='clear' value='yes'>";
	echo "<br><b>Are you sure you want to clear the debuglog?</b><br>";
	finish_page_extra("YES - Clear Debuglog", 0, 0, 0, 0, "NO - CANCEL", 
			"rlc_debuglog.php", $hid, "");
}


/*
 *	First, read the debug log and display it.
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DEBUG);

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$sql = rlc_mysql_init($isv);

	if (array_key_exists('clear', $_POST))
	{
	    rlc_web_title("", "rlc_debuglog.php");
	    echo "<h3>Clearing Debuglog</h3>";
	    if (array_key_exists('cleardate', $_POST)) 
	    {
		$cleardate = $_POST['cleardate'];
		if (!strcmp($cleardate, "all"))
		{
		  /* Leave as is */
		}
		if (!strcmp($cleardate, "dspec"))
		{
		    $cleardate = $_POST['dspec'];
		    $cleardate = strtotime($cleardate);
		}
	   }
	    else
		$cleardate = "0";

	    rlc_del_debuglog_doit($sql, $cleardate);
	    return;
	}
	else if (array_key_exists('delete_dlog', $_POST))
	{
	    rlc_web_title("", "rlc_debuglog.php");
	    echo "<h3>Clear Debug Log</h3>";
	    rlc_del_dlog();
	    return;
	}
	else if (array_key_exists('turn_on_log', $_POST))
	{
	    rlc_web_title("", "rlc_admin_debug.php");
	    echo "<h3>Debug Log</h3>";
	    rlc_mysql_write_setup($sql, "debug-on", "1");
	    echo "Debug Logging turned ON<br>";
	    finish_page("BACK", 0, 0);
	    return;
	}
	else if (array_key_exists('turn_off_log', $_POST))
	{
	    rlc_web_title("", "rlc_admin_debug.php");
	    echo "<h3>Debug Log</h3>";
	    rlc_mysql_write_setup($sql, "debug-on", "0");
	    echo "Debug Logging turned OFF<br>";
	    finish_page("BACK", 0, 0);
	    return;
	}

	rlc_web_title("", "rlc_admin_debug.php");

	if (array_key_exists('select', $_POST))
	    $sel = $_POST['select'];
	else
	    $sel = "";
	$stat = rlc_get_dlog($sql, $sel, $dlog);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read debug log, status: $stat<br>");
	}
	else
	{
	    echo "<h3>Debug Log";
	    if ($sel != "") echo " (filtered for expression \"$sel\")";
	    echo "</h3>";
	    $rows = mysqli_num_rows($dlog);
	    $numdisp = 0;

	    if ($rows == 0)
	    {
	    	    echo "Debug log empty<br>";
	    }
	    else
	    {
		echo "<table>";
		$errlevel = rlc_turn_off_warnings();
		while ($row = mysqli_fetch_array($dlog, MYSQLI_ASSOC))
		{
		    if ($row['date']) 
			echo "<tr><td><b>".date("Y-m-d G:i:s", $row['date']).
								"</b></td>";
		    echo "<td>&nbsp</td>";
		    if ($row['logdata']) 
			echo "<td>".$row['logdata']."</td></tr>";
		    $numdisp++;
		}
		error_reporting($errlevel);
		echo "<tr><td>&nbsp</td></tr><tr><td>$numdisp log entries</td></tr></table>";
	    }
	}
	mysqli_free_result($dlog);

	rlc_mysql_close($sql);
	$hid = "<input type='hidden' name='delete_dlog' value='delete'>";
	if ($numdisp > 0)
	    finish_page_extra("BACK", 0, 0,
			"Refresh Debug Log", "rlc_debuglog.php", 
			"Clear Debug Log", "rlc_debuglog.php", "", $hid);
	else
	    finish_page_extra("BACK", 0, 0, "Refresh Debug Log", 
				"rlc_debuglog.php", 0, 0, "", "");
?>
