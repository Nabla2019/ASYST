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

 	$Id: rlc_del_key.php,v 1.10 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include "rlc.php";
include "rlc_mysql.php";
include "login_session.php";

	rlc_web_header(RLC_MENU_KEY, $session);

	if (!$session->canEdit())
        {
	    echo "You do not have permission to perform this operation.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	if (array_key_exists('akey', $_POST))
		$akey = $_POST['akey']; 
	else
		$akey = "";

	$cols = array("akey", "name", "prod.exp", "white", "keyd.misc","notes");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);

/*
 *	Delete (possibly) multiple keys. (V11.2)
 */
	if (array_key_exists(DELETE_MULTIPLE, $_POST))
	{
		rlc_web_title("Delete Activation Key", "rlc_del_key.php");
	        echo "<h3>Delete the following activation key(s):</h3><i>";
		$num = 0;
		foreach ($_POST as $elem=>$elem_value)
		{
		    if (substr($elem, 0, 2) != DELETE_ITEM) continue;
		    echo "&nbsp;&nbsp;&nbsp;$elem_value<br>";
		    rlc_web_hidden($elem, $elem_value);
		    $num++;
		}
		if ($num > 0)
		{
		    echo "</i><h2>  Are you sure (no undo)?</h2>";
		    rlc_web_hidden("submit_form", 1);
		    rlc_web_hidden(DELETE_MULTIPLE_DOIT, 1);
		    echo $pxtra;
		    finish_page_extra("YES - Delete", "Cancel - DO NOT DELETE",
						 "rlc_show_key.php",
						0, 0, 0, 0, $pxtra, "");
		}
		else
		{
		    echo "</i><h3>No Activation Keys specified for delete<h3>";
		    finish_page_extra(0, "Cancel", "rlc_show_key.php",
						0, 0, 0, 0, $pxtra, "");
		}
	}
/*
 *	Submitted the form.  Delete one or more keys
 */
	else if (array_key_exists('submit_form', $_POST))
	{
		rlc_web_title("Deleting Activation Key", "rlc_show_key.php");
 		$sql = rlc_mysql_init($isv);
		if (array_key_exists(DELETE_MULTIPLE_DOIT, $_POST))
			$list = $_POST;
		else
			$list = array(DELETE_ITEM=>$akey);

		$numdel = 0;
		foreach ($list as $k=>$k_val)
		{
		    if (substr($k, 0, 2) != DELETE_ITEM) continue;
		    $stat = rlc_mysql_del_akey($sql, $k_val);
		    if ($stat)
		    {
			$numdel++;
			echo "key $k_val deleted<br>";
			$res = rlc_mysql_add_audit($sql, $session->username,
					"delete", $k_val, "akey");
		    }
		    else
		    {
			echo "Error deleting key $k_val, sql status: ";
			echo mysqli_error($sql)."<br>";
		    }
		}
		rlc_mysql_close($sql);
		echo $pxtra;
		if ($numdel > 0)
			echo "$numdel Activation Key(s) deleted<br><br>";

		finish_page("Back to Activation Key List", 0, 0);
	}

/*
 *	"Normal" delete - single key.
 */
	else if ($akey == "")
	{
		rlc_web_title("Delete Activation Key", 0);
		echo "<br><h2>No activation key to delete - ID is NULL</h2>";
		echo $pxtra;
		finish_page(0, 0, 0);
	}
	else
	{
		rlc_web_title("Delete Activation Key", "rlc_del_key.php");
		rlc_web_start_prompt();
	        echo "<h3>Delete activation key<i>: ".$akey.
						"</i>.  Are you sure?</h3>";
		rlc_web_hidden("akey", $akey);
		rlc_web_hidden("submit_form", 1);
		echo $pxtra;
		finish_page_extra("YES - Delete", "Cancel - DO NOT DELETE", 
						"rlc_show_key.php",
						0, 0, 0, 0, $pxtra, "");
	}
?>
