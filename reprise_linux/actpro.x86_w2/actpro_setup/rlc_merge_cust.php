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

 	$Id: rlc_merge_cust.php,v 1.3 2016/04/08 02:55:45 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';

define("QUERY_KEY_CONTACT", "SELECT * FROM keyd WHERE (contact_id = %d)");
define("MERGE_COMPANY", 1);
define("MERGE_CONTACT", 2);

/*
 *	Merge 2 contacts or companies
 */
	rlc_web_header(RLC_MENU_CUST, $session);
	$sql = rlc_mysql_init($isv);
	$perm = check_user($session);

	if (!$perm['act_view_enabled'])
	{
	    rlc_noview($session);
	    finish_page(0, 0, 0);
	    return;	/* Fix P280 */
	}
	$mergephase = rlc_getpost("mergephase", 1);
/*
 *	Figure out what we are doing.
 */
 	if (array_key_exists(MERGE_CONTACTS, $_POST))
	{
	    $title = "Merging Contacts";
	    $whatdisp = "Contact";
	    $whatdispp = "Contacts";
	    $help = 
	       "When you merge 2 contacts, all activation keys and<br>".
	       "login records that refer to the disappearing contact<br>".
	       "will be assigned to the surviving contact.  All other<br>".
	       "data in the disappearing contact's record will be lost.";
	    
	    $what = MERGE_CONTACT;
	    $hide = rlc_web_hidden_string(MERGE_CONTACTS, "1");
	}
	else if (array_key_exists(MERGE_COMPANIES, $_POST))
	{
	    $title = "Merging Companies";
	    $whatdisp = "Company";
	    $whatdispp = "Companies";
	    $help = 
	       "When you merge 2 companies, all contacts who are<br>".
	       "associated with the disappearing company will be<br>". 
	       "assigned to the surviving company.  All other data<br>".
	       "in the disappearing company's record will be lost.";
	    $what = MERGE_COMPANY;
	    $hide = rlc_web_hidden_string(MERGE_COMPANIES, "1");
	}
	else 
	{
	    echo "Unknown merge operation<br>";
	    finish_page(0, "Back", "rlc_show_cust.php");
	    return;
	}
	$next = "rlc_merge_cust.php";
	if ($mergephase == 3) $next = "rlc_show_cust.php";

	rlc_web_title($title, $next);
	$sql = rlc_mysql_init($isv);

	$stat = rlc_mysql_get_customers($sql, $cust, "", "", "");

	if ($stat != 0)
	{
	    if ($stat == -2)
		$tmp = sprintf("No customer data found (status: %s)<br>", 
									$stat);
	    else
		$tmp = sprintf("Cannot read customer data, status: %s<br>",
									$stat);
	    rlc_web_info($tmp);
	    finish_page(0, "Back", "rlc_show_cust.php");
	    rlc_mysql_close($sql);
	    return;
	}

	$c1 = $c2 = 0;
	echo "<br>";
	foreach ($_POST as $elem=>$elem_value)
	{
	    if (substr($elem, 0, 2) != MERGE_ITEM) continue;
	    $hide .= rlc_web_hidden_string($elem, $elem_value);
	    if ($c1 == 0) $c1 = $elem_value;
	    else if ($c2 == 0) $c2 = $elem_value;
	    else
	    {
	    	echo "Only 2 items can be selected to merge!<br>";
		finish_page(0, "Back", "rlc_show_cust.php");
		return;
	    }
	}
	if (($c1 == 0) || ($c2 == 0))
	{
	    echo "2 items must be selected to merge!<br>";
	    finish_page(0, "Back", "rlc_show_cust.php");
	    return;
	}
	if ($mergephase == 1)
	{
	    rlc_web_info($help);
	    rlc_web_tableheader_blank();

	    rlc_web_row_elem($title.":");
	    rlc_web_row_start();
	    rlc_web_row_elem("");
	    rlc_web_row_end();
	    $list = array();
	    $first = true;
	    while ($row = mysqli_fetch_array($cust, MYSQLI_ASSOC))
	    {
		if (($row['contact_id'] != $c1) && $row['contact_id'] != $c2)
	    	    continue;
		
		$list[$row['contact_id']] = $row['contact']."/".$row['company'];
		rlc_web_row_start();
		rlc_web_row_elem($row['contact']);
		rlc_web_row_elem("of");
		rlc_web_row_elem($row['company']);
		if ($first) 
		{
	    	    rlc_web_row_elem("with"); 
		    $co_id1 = $row['company_id'];
		    $p_id1 = $row['contact_id'];
		    $first = false;
		}
		else
		{
		    $co_id2 = $row['company_id'];
		    $p_id2 = $row['contact_id'];
		}
		rlc_web_row_end();
	    }
	    mysqli_free_result($cust);
	    rlc_web_table_end();

	    if (($what == MERGE_COMPANY) && ($co_id1 == $co_id2))
	    {
		echo "<b>Error: Merge Company selected, but the 2 companies ".
				"are the same.</b><br><br>";
		finish_page(0, "Back", "rlc_show_cust.php");
		return;
	    }
	    else if (($what == MERGE_CONTACT) && ($co_id1 != $co_id2))
	    {
		echo "<b>Error: Merge Contacts selected, but the 2 companies ".
			"are different.</b><br>".
			"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp".
		  	"Contacts can only be merged from the same company.".
			"<br><br>";
		finish_page(0, "Back", "rlc_show_cust.php");
		return;
	    }
	    rlc_web_tableheader_blank();
	    rlc_web_prompt_contact_id($list, $whatdisp);
	    rlc_web_table_end();
	    rlc_web_hidden("mergephase", "2");
	    echo $hide;
	    rlc_mysql_close($sql);
	    finish_page("Merge ".$whatdispp, "Cancel - Do Not Merge", 
							"rlc_show_cust.php");
	}
	else if ($mergephase == 2)
	{
	    $survivor = rlc_getpost("survivor", 0);
	    if ($survivor == 0)
	    {
	        echo "Error - no surviving $whatdisp selected<br>";
		finish_page(0, "Back", "rlc_show_cust.php");
		return;
	    }
	    echo "merged these two $whatdispp:<br><br>";
	    while ($row = mysqli_fetch_array($cust, MYSQLI_ASSOC))
	    {
		if (($row['contact_id'] != $c1) && $row['contact_id'] != $c2)
	    	    continue;
		
		$a = $row['contact']."/".$row['company'];
		echo $a;
		if ($row['contact_id'] == $survivor) 
		{
		    echo " (surviving $whatdisp)";
		    if ($what == MERGE_CONTACT) 
		    	$newid = $row['contact_id'];
		    else 
		    	$newid = $row['company_id'];
		}
		else
		{
		    $obsid = $row['contact_id'];
		    $obsolete = $a;
		    if ($what == MERGE_CONTACT) 
		    {
		    	$oldid = $row['contact_id'];
			$name = $row['contact'];
		    }
		    else 
		    {
		    	$oldid = $row['company_id'];
			$name = $row['company'];
		    }
		}
	 	echo "<br>";
	    }
	    if ($what == MERGE_COMPANY)
	    {
		$res = rlc_mysql_merge_company($sql, $newid, $oldid);
		if (!$res)
		{
		    echo "Merge company DB operation failed<br>";
		    echo "db error: ".mysqli_error($sql)."<br>";
		    mysql_close($sql);
	    	    finish_page(0, "BACK", "rlc_show_cust.php");
		    return;
		}
	    }
	    else
	    {
		$res = rlc_mysql_merge_contact($sql, $newid, $oldid);
		if (!$res)
		{
		    echo "Merge contact DB operation failed<br>";
		    echo "db error: ".mysqli_error($sql)."<br>";
		    mysql_close($sql);
	    	    finish_page(0, "BACK", "rlc_show_cust.php");
		    return;
		}
	    }

	    rlc_mysql_close($sql);
	    rlc_web_hidden("mergephase", "3");
	    rlc_web_hidden("deleteme", $obsid);
	    rlc_web_hidden("name", $name);
	    echo $hide;
	    if ($what == MERGE_CONTACT)
	    {
		echo "<br><br>";
		echo "Do you want to delete the old $whatdisp $obsolete?<br>";
		finish_page("YES - Delete", "No - Do Not Delete", 
	    						"rlc_show_cust.php");
	    }
	    else
	    {
		finish_page("CONTINUE", 0, 0);
	    }
	    return;
	}
	else if ($mergephase == 3)
	{
	    $deleteme = rlc_getpost("deleteme", 0);
	    $name = rlc_getpost("name", 0);
	    if ($deleteme == 0)
	    {
	        echo "Error - no obsolete $whatdisp to delete<br>";
		finish_page(0, "Back", "rlc_show_cust.php");
		return;
	    }
	    if ($what == MERGE_CONTACT) rlc_mysql_del_contact($sql, $deleteme);
	    else
	    {
		while ($row = mysqli_fetch_array($cust, MYSQLI_ASSOC))
		{
		    if ($row['contact_id'] != $deleteme) continue;
	    	    rlc_mysql_del_company($sql, $row['company_id']);
		    break;
		}
	    }
	    echo "Deleted obsolete $whatdisp $name<br>";
	    rlc_mysql_close($sql);
	    finish_page(0, "Back", "rlc_show_cust.php");
	    return;
	}
?>
