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

 	$Id: rlc_check_db.php,v 1.10 2016/04/08 02:55:45 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include 'login_session.php';


define("CHECK_ALL_AKEY", "SELECT * FROM `keyd` LEFT JOIN `prod` ON prod.id = keyd.product_id");

define("CHECK_FULFILL", "SELECT * FROM licf LEFT JOIN prod ON prod.id = licf.product_id");
define("CHECK_FULFILL_KEY", "SELECT * FROM licf LEFT JOIN keyd USING (akey)");

define("CHECK_KEYF_KEY", "SELECT * FROM keyf LEFT JOIN keyd USING (akey)");

define("CHECK_ALL_COMPANY", "SELECT * FROM `company` LEFT JOIN `contact` ON company.company_id = contact.company_id");

define("CHECK_ALL_CONTACT", "SELECT * FROM `contact` LEFT JOIN `company` ON company.company_id = contact.company_id");

function rlc_dbcheck($sql, $query, &$res)
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
 *	First, read all the activation keys and make sure they have
 *	associated product definitions.
 */

	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("Database Consistency Check", "rlc_admin_db.php");
	$perm = check_user($session);

	if (!$perm['act_view_enabled'])
	{
		rlc_noview($session);
		finish_page(0, 0, 0, 0);
		return;
	}

	$sql = rlc_mysql_init($isv);

	echo "<h4>Checking Activation Keys...</h4>";
	$stat = rlc_dbcheck($sql, CHECK_ALL_AKEY, $keys);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read activation keys, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($keys);

	    if ($rows == 0)
	    {
	    	    echo "No activation keys in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badprod = 0;
		$keymiss[0] = "";
		while ($row = mysqli_fetch_array($keys, MYSQLI_ASSOC))
		{
		    if (!$row['name']) 
		    {
		    	$badprod++;
			$keymiss[$badprod-1] = $row['akey'];
		    }
		    $numdisp++;
		}
		echo "$numdisp activation keys, $badprod missing ".
				"product definitions<br>";
		if ($badprod > 0)
		{
			echo "<br>Product definitions missing for:<br>";
			$max = $badprod;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$keymiss[$i]<br>";
			$more = $badprod - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($keys);
/*
 *	Now check fulfillments.
 */
	echo "<h4>Checking Fulfillments ...</h4>";
	echo "1. Check product definitions in fulfillments...<br><br>";
	$stat = rlc_dbcheck($sql, CHECK_FULFILL, $fulfill);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read fulfillments, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($fulfill);

	    if ($rows == 0)
	    {
	    	    echo "No fulfillments in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badprod = 0;
		$keymiss[0] = "";
		while ($row = mysqli_fetch_array($fulfill, MYSQLI_ASSOC))
		{
		    if (!$row['name']) 
		    {
		    	$badprod++;
			$keymiss[$badprod-1] = $row['akey'];
		    }
		    $numdisp++;
		}
		echo "$numdisp fulfillments, $badprod missing ".
					"product definitions<br>";
		if ($badprod > 0)
		{
			echo "<br>Product definitions missing for:<br>";
			$max = $badprod;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$keymiss[$i]<br>";
			$more = $badprod - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($fulfill);

	echo "<br>2. Check activation keys in fulfillments ...<br><br>";
	$stat = rlc_dbcheck($sql, CHECK_FULFILL_KEY, $fulfill);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read fulfillments, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($fulfill);

	    if ($rows == 0)
	    {
	    	    echo "No fulfillments in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badprod = 0;
		$keymiss[0] = "";
		while ($row = mysqli_fetch_array($fulfill, MYSQLI_ASSOC))
		{
		    if ($row['type'] == NULL) 
		    {
		    	$badprod++;
			$keymiss[$badprod-1] = $row['akey'];
		    }
		    $numdisp++;
		}
		echo "$numdisp fulfillments, $badprod missing ".
						"activation keys<br>";
		if ($badprod > 0)
		{
			echo "<br>Activation keys missing:<br>";
			$max = $badprod;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$keymiss[$i]<br>";
			$more = $badprod - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($fulfill);

	echo "<h4>Checking Key Fulfillment Table (keyf) ...</h4>";
	$stat = rlc_dbcheck($sql, CHECK_KEYF_KEY, $keyf);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read keyf table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($keyf);

	    if ($rows == 0)
	    {
	    	    echo "No fulfillments in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badprod = 0;
		$keymiss[0] = "";
		while ($row = mysqli_fetch_array($keyf, MYSQLI_ASSOC))
		{
		    if ($row['type'] == NULL) 
		    {
		    	$badprod++;
			$keymiss[$badprod-1] = $row['akey'];
		    }
		    $numdisp++;
		}
		echo "$numdisp keyf entries, $badprod missing ".
						"activation keys<br>";
		if ($badprod > 0)
		{
			echo "<br>Activation keys missing:<br>";
			$max = $badprod;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$keymiss[$i]<br>";
			$more = $badprod - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($keyf);

	echo "<h4>Checking Company Table (company) ...</h4>";
	$stat = rlc_dbcheck($sql, CHECK_ALL_COMPANY, $company);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read company table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($company);

	    if ($rows == 0)
	    {
	    	    echo "No companies in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badco = 0;
		$comiss[0] = "";
		while ($row = mysqli_fetch_array($company, MYSQLI_ASSOC))
		{
		    if ($row['contact_id'] == NULL) 
		    {
		    	$badco++;
			$comiss[$badco-1] = $row['company'];
		    }
		    $numdisp++;
		}
		echo "$numdisp company/contact entries, $badco companies ".
					"with no contacts<br>";
		if ($badco > 0)
		{
			echo "<br>Companies with no contacts:<br>";
			$max = $badco;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$comiss[$i]<br>";
			$more = $badco - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($company);

	echo "<h4>Checking Contact Table (contact) ...</h4>";
	$stat = rlc_dbcheck($sql, CHECK_ALL_CONTACT, $contact);

	if ($stat != 0)
	{
	    	rlc_web_info("Cannot read contact table, status: $stat<br>");
	}
	else
	{
	    $rows = mysqli_num_rows($contact);

	    if ($rows == 0)
	    {
	    	    echo "No companies in database<br>";
	    }
	    else
	    {
		$numdisp = 0;
		$badco = 0;
		$comiss[0] = "";
		while ($row = mysqli_fetch_array($contact, MYSQLI_ASSOC))
		{
		    if ($row['company_id'] == NULL) 
		    {
		    	$badco++;
			$comiss[$badco-1] = $row['contact'];
		    }
		    $numdisp++;
		}
		echo "$numdisp company/contact entries, $badco contacts with ".
					"no companies<br>";
		if ($badco > 0)
		{
			echo "<br>Contacts with no company:<br>";
			$max = $badco;
			if ($max > 10) $max = 10;
			for ($i=0; $i<$max; $i++) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;$comiss[$i]<br>";
			$more = $badco - $max;
			if ($more > 0) 
				echo "&nbsp;&nbsp;&nbsp;&nbsp;... ".
					"plus $more more ...<br>";
		}
	    }
	}
	mysqli_free_result($contact);

	rlc_mysql_close($sql);

	finish_page("BACK", 0, 0);
?>
