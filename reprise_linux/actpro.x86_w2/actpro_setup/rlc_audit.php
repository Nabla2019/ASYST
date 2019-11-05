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

 	$Id: rlc_audit.php,v 1.6 2016/04/08 02:55:45 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';


define("GET_AUDIT", "SELECT * FROM `audit` order by `date`");

function rlc_get_audit($sql, &$res)
{
	$res = mysqli_query($sql, GET_AUDIT);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		echo "MySQL error ".mysqli_error($sql)."<br>";
		return(1);
	}
	else return(0);
}

function rlc_del_audit_doit($sql, $cleardate)
{
	$q = sprintf("DELETE FROM audit where date < %d", $cleardate);
	mysqli_query($sql, $q);
	$d = date('Y-m-d', $cleardate);
	echo "Audit Trail cleared prior to $d<br><br>";
	finish_page(0, 0, 0);
}

define ("DAY", 24*60*60);
define ("WEEK", 7*DAY);
define ("DAYS30", 30*DAY);
define ("DAYS60", 60*DAY);

function rlc_del_audit()
{
	echo "Clear audit trail info earlier than:<br>";
        echo "<table>";
	$t = time();
	$tomorrow = $t + DAY;
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
        echo "<tr><td><input type=radio name=cleardate value=$d30 checked=true> 30 days ago&nbsp&nbsp&nbsp</td><td>($days30)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=dspec> Earlier than: &nbsp&nbsp&nbsp</td>";
        echo "<td><input type=text name=dspec size=10 value=$days60> </td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$tomorrow> EVERYTHING&nbsp&nbsp&nbsp</td><td>(Delete Entire Audit Trail)</td></tr>";
        echo "</table>";
	$hid = "<input type='hidden' name='clear' value='yes'>";
	echo "<br><b>Are you sure you want to clear the audit trail?</b><br>";
	finish_page_extra("YES - Clear Audit Trail", 0, 0, 0, 0, "NO - CANCEL", 
			"rlc_audit.php", $hid, "");
}


/*
 *	First, read the audit trail and display it.
 */

    if ($session->isAdmin())
    {

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_AUDIT);
	rlc_web_title("", "rlc_audit.php");
	$perm = check_user($session);

	if (!$perm['act_view_enabled'])
	{
		rlc_noview($session);
		finish_page(0, 0, 0);
		return;
	}

	$sql = rlc_mysql_init($isv);

	if (array_key_exists('clear', $_POST))
	{
	    echo "<h3>Clearing Audit Trail</h3>";
	    if (array_key_exists('cleardate', $_POST)) 
	    {
		$cleardate = $_POST['cleardate'];
		if (!strcmp($cleardate, "dspec"))
		{
		    $cleardate = $_POST['dspec'];
		    $cleardate = strtotime($cleardate);
		}
	   }
	    else
		$cleardate = "0";


	    rlc_del_audit_doit($sql, $cleardate);
	    return;
	}
	else if (array_key_exists('delete_audit', $_POST))
	{
		echo "<h3>Clear Audit Trail</h3>";
		rlc_del_audit();
		return;
	}

	$stat = rlc_get_audit($sql, $audit);

	$numdisp = 0;

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read audit trail, status: $stat<br>");
	}
	else
	{
	    echo "<h3>Database Audit Trail</h3>";
	    $rows = mysqli_num_rows($audit);

	    if ($rows == 0)
	    {
	    	    echo "Audit Trail empty<br>";
	    }
	    else
	    {
		echo "<table>";
		$errlevel = rlc_turn_off_warnings();
		while ($row = mysqli_fetch_array($audit, MYSQLI_ASSOC))
		{
		    if ($row['date']) 
			echo "<tr><td><b>".date("Y-m-d G:i:s", $row['date']).
								"</b></td>";
		    echo "<td>&nbsp</td>";
		    if ($row['who']) echo "<td>".$row['who']."</td>";
		    if ($row['what']) echo "<td>".$row['what']."</td>";
		    if ($row['tablename']) echo "<td>".$row['tablename']."</td>";
		    if ($row['tablekey']) echo "<td>".$row['tablekey']."</td>";
		    echo "</tr>";
		    $numdisp++;
		}
		error_reporting($errlevel);
		echo "<tr><td>&nbsp</td></tr><tr><td>$numdisp audit trail entries</td></tr></table>";
	    }
	    mysqli_free_result($audit);
	}

	rlc_mysql_close($sql);
	$hid = "<input type='hidden' name='delete_audit' value='delete'>";
	if ($numdisp > 0)
	    finish_page_extra(0, 0, 0, "Refresh Audit Trail", 
			"rlc_audit.php", "Clear Audit Trail", 
			"rlc_audit.php", "", $hid);
	else
	    finish_page(0, 0, 0);
    }
?>
