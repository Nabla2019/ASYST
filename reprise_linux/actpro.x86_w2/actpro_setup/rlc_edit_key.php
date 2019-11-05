<?php
/*****************************************************************************

	    COPYRIGHT (c) 2010, 2017 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_edit_key.php,v 1.20 2017/08/19 02:27:34 matt Exp $

 *****************************************************************************/

/*
 *	Edit Activation Key.  Including enable/disable.
 */

include "rlc.php";
include "rlc_prompts.php";
include "rlc_mysql.php";
include "login_session.php";
include "rlc_akey.php";

/*
 *	Create the form
 */
	rlc_web_header(RLC_MENU_KEY, $session);
	if (!$session->canEdit())
        {
	    echo "You do not have permission to perform this operation.<br>";
	    finish_page(0, 0, 0);
	    return;
	}

	$cols = array("akey", "name", "exp", "white", "keyd.misc","notes");
	$select = rlc_web_get_select($cols, $select_data, $xtra, $pxtra);


	$sql = rlc_mysql_init($isv);
	if (!array_key_exists('submit_form', $_POST)) 
	{
/*
 *		Put up the form, display the data for editing.
 */
		display_edit_form($sql, $session->username, 0, 0, 0, $pxtra);
	}
	else
	{
/*
 *		Write the results out.
 */
		if (array_key_exists('product_id', $_POST))
		{
			$prod_ok = 1;
			$k['product_id'] = $_POST['product_id'];
		}
		else 
		{
			$prod_ok = 0;
			$k['product_id'] = 0;
		}

		$k['akey']       = $_POST['akey'];
		if (array_key_exists('active', $_POST))
		    $k['active'] = $_POST['active'];
		else
		    $k['active'] = 0;
		$k['type']       = $_POST['type'];
		$k['count']      = $_POST['count'];
		$k['rehosts']    = $_POST['rehosts'];
		$k['lastdate']   = strtolower($_POST['lastdate']);
		$k['exp']        = strtolower($_POST['exp']);
		if (array_key_exists('kver_type', $_POST))
		{
		    $k['kver_type']  = $_POST['kver_type'];
		    $k['kver']	     = $_POST['kver'];
		}
		else
		{
		    $k['kver_type'] = 0;
		    $k['kver'] = "";
		}
		$k['white']      = $_POST['white'];
		$misc		 = _values_to_misc();
		$k['misc']       = $misc;
		$k['notes']      = $_POST['notes'];
		$k['contact_id'] = $_POST['contact_id'];
		$k['key_allowed_hostids'] = rlc_set_hostids($_POST);
		$k['kcreate']	 = $_POST['kcreate'];
		if ($k['type'] == RLM_ACT_KEY_TYPE_SUBSCRIPTION)
		{
		    $k['count'] = 1;
		    $k['sub_interval'] = rlc_getpost('sub_interval', -1);
		    if ($k['sub_interval'] == 0)
		    	$k['sub_interval'] = rlc_getpost('sub_interval_val',
						RLM_ACT_SUBSCRIPTION_MONTH);
		    $k['sub_window'] = rlc_getpost('sub_window', 2);
		}
		else
		{
		    $k['sub_interval'] = 0;
		    $k['sub_window'] = 0;
		}
		$k['ash_sn'] = rlc_getpost('ash_sn', 1);
		$k['user_def'] = rlc_getpost('user_def', "");

		if (!$prod_ok)
		{
			echo "ERROR - no product definition for this key.  ".
				"Disabling the Activation Key now<br><br>";
			$k['active'] = 0;
		}
		$illegal = rlc_check_akey($k['lastdate'], $k['exp'],
							$k['misc'], $k['kver']);
		if ($illegal === FALSE)
		{
/*
 *			Now write it out
 */
			echo "<h2>Edit Activation Key</h2><form action=".
						"rlc_show_key.php method=POST>";
			$res = rlc_mysql_update_key($sql, $k);
			if ($res)
			{
			    $res = rlc_mysql_add_audit($sql, $session->username,
					"edit", $k['akey'], "akey");
			    echo "Activation Key edited<br><br>";
			}
			else
			{
			    echo "Activation Key Not saved<br>";
			    echo "Error: ".mysqli_error($sql)."<br><br>";
			}

			echo $pxtra;
			finish_page("Back to List", 0, 0);
		}
		else
		{
			display_edit_form($sql, $session->username, $k, 1, 
							$illegal, $pxtra);
		}
	}
	rlc_mysql_close($sql);
?>
