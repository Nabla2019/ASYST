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

 	$Id: rlc_del_prod.php,v 1.11 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include "login_session.php";

	rlc_web_header(RLC_MENU_PROD, $session);
	if (!$session->canEdit())
        {
	    echo "You do not have permission to perform this operation.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	if (array_key_exists('id', $_POST))
		$id = $_POST['id']; 
	else
		$id = -1;


	$cols = array("name", "product", "version", "upgrade_version", "exp",
							"misc");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);

	if (array_key_exists("view_name", $_POST))
		$name = $_POST['view_name'];
	else
		$name = "";
	if (array_key_exists("view_one_prod", $_POST))
	{
		$view_one_prod = $_POST['view_one_prod'];
		$text = "Back to $name Product Definition";
		$pxtra = $pxtra.rlc_web_hidden_string("view_name", $name).
			 rlc_web_hidden_string("view_one_prod", $view_one_prod);
	}
	else
		$text = "Back to Product Definition List";

 	$sql = rlc_mysql_init($isv);
	if (!array_key_exists('submit_form', $_POST))
	{
	    rlc_web_title("Delete Product Definition", "rlc_del_prod.php");
	    $num = 0;
	    foreach ($_POST as $p=>$pval)
		if (substr($p, 0, 2) == DELETE_ITEM) $num++;

	    if ($num < 1)
	    {
		echo "<br><h2>No product definiton to delete - ID is NULL</h2>";
		echo $pxtra;
	        rlc_mysql_close($sql);
		finish_page(0, 0, 0);
	    }
	    else
	    {
		if ($num > 1) $s="s"; else $s="";
		echo "<h3>Delete product defintion$s - Are you sure?</h3>";
		rlc_web_tableheader();
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM)
		    {
			$row = rlc_mysql_read_prod($sql, $pval);
			if ($row) 
			{
			    echo "<tr><td>".$row['name']."</td><td>".
				$row['product']."</td><td>".$row['version'].
				"</td></tr>";
			}
		        rlc_web_hidden($p, $pval);
		    }
		}
		rlc_web_table_end(0);
	        rlc_mysql_close($sql);
		if (array_key_exists('name', $_POST))
		    rlc_web_hidden("view_name", $_POST['name']);
		rlc_web_hidden("submit_form", 1);
		echo $pxtra;
		finish_page_extra("YES - Delete", "Cancel - Do Not Delete", 
						"rlc_show_prod.php",
						0, 0, 0, 0, $pxtra, "");
	    }
	}
	else
	{
		rlc_web_title("Deleting Product Definition", 
							"rlc_show_prod.php");
 		$sql = rlc_mysql_init($isv);
		foreach ($_POST as $p=>$pval)
		{
		    if (substr($p, 0, 2) == DELETE_ITEM)
		    {
			$row = rlc_mysql_read_prod($sql, $pval);
			if ($row) $n = $row['name']; else $n = "???";
			$res = rlc_mysql_del_prod($sql, $pval);
			if ($res)
			{
			    $res = rlc_mysql_add_audit($sql, $session->username,
						"delete", $n, "prod");
			    echo "Product ".$n." (id ".$pval.") deleted.<br>";
			}
			else
			{
			    echo "Product ".$n." (id ".$pval.") delete failed.<br>";
			    echo mysqli_error($sql)."<br>";
			}
		    }
		}
		rlc_mysql_close($sql);
		echo $pxtra;
		finish_page($text, 0, 0);
	}
?>
