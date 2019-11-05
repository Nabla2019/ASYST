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

 	$Id: rlc_del_fulfill.php,v 1.17 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_mysql.php";
include 'login_session.php';

/*
 *	Delete one or more license fulfillments.  For each, remove the 
 *	row from the licf table and decrement "num" in the keyf table.
 */

	$perm = check_user($session);
	rlc_web_header(RLC_MENU_FULFILL, $session);

	$back = rlc_getinput('back', "");
	if ($back != "") $pxtra = rlc_web_hidden_string("back", $back);
	else		 $pxtra = "";

	if (array_key_exists('r-akey', $_POST)) 
	    $akey = $_POST['akey'];		/* P414 */


	if (!$perm['act_edit_enabled'])
	{
		rlc_noadmin($session);
		finish_page(0, 0, 0);
	}
	else
	{
	    if (!array_key_exists('submit', $_POST)) 
	    {
	    	rlc_web_title("Delete Fulfilled Licenses", 
						"rlc_del_fulfill.php");
		$num = 0;
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM) $num++;
		}
		if ($num < 1)
		{
		    echo "<br><h2>No Fulfillments selected to delete</h2>";
		    echo $pxtra;
		    finish_page(0, "BACK", "rlc_show_fulfill.php");
		}
	    	rlc_web_info("Deleting a fulfillment record means that your customer will be able to re-fulfill licenses using the same activation key.<br>When deleted, the total fulfillment count for the activation key will be decremented by the number of fulfillments used.");
	        $sql = rlc_mysql_init($isv);

		if ($num > 1) 
		{ $s="s"; $t = "these"; } 
		else 
		{ $s=""; $t = "this"; }

		echo "<h3>Delete $t Fulfillment$s - Are you sure?</h3>";
		rlc_web_tableheader();
		echo "<tr><td><b>Activation Key</b></td><td>".
				"<b>License Hostid</b></td></tr>";
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM)
		    {
			$row = rlc_mysql_get_license($sql, $pval);
			if ($row) 
			{
			    echo "<tr><td>".$row['akey']."</td><td>".
				$row['license_hostid']."</td></tr>";
			}
		        rlc_web_hidden($p, $pval);
		    }
		}
		rlc_web_table_end(0);
	        rlc_mysql_close($sql);
		rlc_web_hidden("submit", 1);
		if (array_key_exists("r-akey", $_POST))
		    $pxtra .= rlc_web_hidden_string("r-akey", 1).
			      rlc_web_hidden_string("akey", $akey);
		echo $pxtra;
		finish_page_extra("YES - Delete", "Cancel - DO NOT DELETE", 
						"rlc_show_fulfill.php",
						0, 0, 0, 0, $pxtra, "");
	    }
	    else
	    {
	        $sql = rlc_mysql_init($isv);
		$num = 0;
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM) $num++;
		}
		if ($num > 1) $s="s"; else $s = "";

	    	rlc_web_title("Deleting Fulfilled License".$s, 
						"rlc_show_fulfill.php");

		$num = 0;
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM)
		    {
			$row = rlc_mysql_get_license($sql, $pval);
			if ($row) 
			{
			    $count = rlc_mysql_del_fulfill($sql, $pval);
	
	    		    if ($count > 0)
	    		    {
			        $res = rlc_mysql_add_audit($sql, 
						$session->username, "delete", 
						$row['license_hostid'], "licf");
				rlc_mysql_update_keyf($sql, $row['akey'], 
								$count);
				$num++;
	        	    }
	        	    else
	    		    {
				echo "<b><br>Error deleting fulfillment for key"
					. $row['akey']."</b><br>";
				echo mysqli_error($sql)."<br>";
			    }
			}
		        rlc_web_hidden($p, $pval);
		    }
		}
		if ($num > 1) $s = "s"; else $s = "";
		echo "<b><br>$num Fulfillment$s Deleted</b><br>";
	        rlc_mysql_close($sql);

		if (array_key_exists("r-akey", $_POST))
		    $pxtra .= rlc_web_hidden_string("akey", $akey);
		echo $pxtra;
		finish_page("Back to List", 0, 0);
	    }
	}
?>
