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

 	$Id: rlc_del_black.php,v 1.9 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_mysql.php";
include "login_session.php";

	rlc_web_header(RLC_MENU_ADMIN, $session);
	$black_id = $_POST['black_id']; 
	$black_domain = $_POST['black_domain']; 

	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page("BACK", 0, 0);
	    return;
	}

	if ($black_id == 0)
	{
		echo "<br><h2>Could not retrive blacklist</h2><h3>Blacklist ".
							"ID is NULL</h3>";
		finish_page(0, 0, 0);
	}
	else if (!array_key_exists('submit_form', $_POST))
	{
		rlc_web_title("Delete BLACKLIST Definition", 
							"rlc_del_black.php");
		rlc_web_start_prompt();
	        echo "<h3>Delete domain<i>: ".$black_domain.
				"</i> from blacklist.  Are you sure?</h3>";
		rlc_web_hidden("black_id", $black_id);
		rlc_web_hidden("black_domain", $black_domain);
		rlc_web_hidden("submit_form", 1);
		finish_page("Delete", "Cancel", "rlc_show_black.php");
	}
	else
	{
		rlc_web_title("Deleting Blacklist Definition", 
							"rlc_show_black.php");
 		$sql = rlc_mysql_init($isv);
		$res = rlc_mysql_del_black($sql, $black_id);
		if ($res)
		{
		    echo "Blacklist definition deleted<br><br>";
		    $res = rlc_mysql_add_audit($sql, $session->username,
					"delete", $black_domain, "blacklist");
		}
		else
		{
		    echo "Blacklist definition not deleted<br>";
		    echo "Error: ".mysqli_error($sql)."<br>";
		}
		rlc_mysql_close($sql);
		finish_page("Back to BlackList", 0, 0);
	}
?>
