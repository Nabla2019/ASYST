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

 	$Id: portal_show_lic.php,v 1.12 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "portal_mysql.php";
include 'login_session.php';

	$perm = check_user($session);
	rlc_web_header(RLC_MENU_FULFILL, $session);
	if (!$session->canView())
        {
	    echo "You do not have permission to perform this operation.<br>";
	    finish_page(0, 0, 0);
	    return;
	}
	$license_hostid = $_POST["license_hostid"];
	$hostname = $_POST["hostname"];
	$fulfill_id = $_POST["fulfill_id"];
	$akey = $_POST["akey"];
	$lictype = $_POST["lictype"];
	$temp = "Fulfilled License for activation key <i>".$akey."</i>";
	rlc_web_title($temp, "portal_show_fulfill.php");
	$numrec = 0;
	$cols = array("name", "akey", "license_hostid", "remote_host", "log");

	$select_data = array("");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);
	$back = rlc_getinput('back', "");
	if ($back != "") $pxtra .= rlc_web_hidden_string("back", $back);

	if (array_key_exists("r-akey", $_POST))
		$pxtra .= rlc_web_hidden_string("akey", $akey);

	if (!$perm['act_portal_enabled'])
	{
		rlc_noadmin($session);
	}
	else
	{
	    $sql = portal_mysql_init($session->company_id, $isv);
	    $fulfill = rlc_mysql_get_license($sql, $fulfill_id);
	
	    if (!$fulfill)
	    {
		echo "No license to display for fulfillment id <b>".$fulfill_id.
								"</b><br>";
	    }
	    else
	    {
		if (!$lictype)
		{
			echo "SERVER ".$hostname." ".$license_hostid." 5053<br>";
			echo "ISV ".$isv."<br>";
		}
		$temp = $fulfill['license'];
		$temp2 = str_replace("\n", "<br>", $temp);
		$temp = str_replace("<br>  ", "<br>&nbsp&nbsp", $temp2);
		echo $temp;
		echo "<br>";


		if (($fulfill['time'] != NULL) && ($fulfill['time'] != 0)) 
		{
		    $timestr = rlc_get_timestr($fulfill['time']);	
		    echo "License first fulled at $timestr<br>";
		}

		if (($fulfill['last_fulfill'] != NULL) && 
		    ($fulfill['last_fulfill'] != 0)) 
		{
		    $timestr = rlc_get_timestr($fulfill['last_fulfill']);
		    echo "License last fulled at $timestr<br>";
		}

		$errlevel = rlc_turn_off_warnings();
		echo "Fulfilled from IP address: <b>"
					.$fulfill['remote_host']."</b><br>";
		echo "Remote host name: <b>";
		$hostname = gethostbyaddr($fulfill['remote_host']);
		if ($hostname != $fulfill['remote_host']) 
			echo "$hostname</b><br>";
		else
			echo "<i>unknown hostname</i></b> (reverse DNS lookup failed)<br>";
		error_reporting($errlevel);

	    }
	    portal_mysql_close($session->company_id, $sql);
	}
	echo $pxtra;
	finish_page("Back", 0, 0);
?>
