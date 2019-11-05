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

 	$Id: rlc_purge_stats.php,v 1.3 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';


function rlc_del_stats_doit($sql, $cleardate)
{
	$cd = $cleardate." 00";	/* From 0 hour */
	$q = sprintf("DELETE FROM stats where date < \"%s\"", $cd);
	mysqli_query($sql, $q);
	echo "Statistics cleared prior to $cleardate<br><br>";
	finish_page(0, 0, 0);
}

define ("DAY", 24*60*60);
define ("WEEK", 7*DAY);
define ("DAYS30", 30*DAY);
define ("DAYS60", 60*DAY);

function rlc_del_stats()
{
	echo "Purge statistics info earlier than:<br>";
        echo "<table>";
	$t = time();
	$tomorrow = date('Y-m-d', $t + DAY);
	$y = date('Y-m-d', $t-DAY);
	$w = date('Y-m-d', $t-WEEK);
	$days30 = date('Y-m-d', $t-DAYS30);
	$days60 = date('Y-m-d', $t-DAYS60);
        echo "<tr><td><input type=radio name=cleardate value=$y> Yesterday&nbsp&nbsp&nbsp</td><td>($y)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$w> One week ago&nbsp&nbsp&nbsp</td><td>($w)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$days30 checked=true> 30 days ago&nbsp&nbsp&nbsp</td><td>($days30)</td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=dspec> Earlier than: &nbsp&nbsp&nbsp</td>";
        echo "<td><input type=text name=dspec size=10 value=$days60> </td></tr>";
        echo "<tr><td><input type=radio name=cleardate value=$tomorrow> EVERYTHING&nbsp&nbsp&nbsp</td><td>(Delete all Statistics)</td></tr>";
        echo "</table>";
	$hid = "<input type='hidden' name='clear' value='yes'>";
	echo "<br><b>Are you sure you want to purge the statistics?</b><br>";
	finish_page_extra("YES - Purge Statistics", 0, 0, 0, 0, "NO - CANCEL", 
			"rlc_admin_db.php", $hid, "");
}

    if ($session->isAdmin())
    {

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	$perm = check_user($session);

	if (!$perm['act_view_enabled'])
	{
		rlc_noview($session);
		finish_page(0, 0, 0);
		return;
	}


	if (array_key_exists('clear', $_POST))
	{
	    rlc_web_title("", "rlc_admin_db.php");
	    echo "<h3>Purging Statistics</h3>";
	    if (array_key_exists('cleardate', $_POST)) 
	    {
		$cleardate = $_POST['cleardate'];
		if (!strcmp($cleardate, "dspec")) $cleardate = $_POST['dspec'];
	   }
	    else
		$cleardate = "0";


	    $sql = rlc_mysql_init($isv);
	    rlc_del_stats_doit($sql, $cleardate);
	    rlc_mysql_close($sql);
	    return;
	}
	else 
	{
		rlc_web_title("", "rlc_purge_stats.php");
		echo "<h3>Purge Statistics</h3>";
		rlc_del_stats();
		return;
	}

    }
?>
