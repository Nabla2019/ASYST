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

 	$Id: rlc_create_key.php,v 1.19 2017/08/19 02:31:21 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include 'rlc_mysql.php';
include 'login_session.php';
include 'rlc_akey.php';

/*
 *	Create an activation key
 */
	rlc_web_header(RLC_MENU_KEY, $session);
	$perm = check_user($session);
	if (!$perm['act_edit_enabled'])
	{
		rlc_noadmin($session);
		finish_page(0, 0, 0);
	}
	else
	{
		$sql = rlc_mysql_init($isv);
		if (!array_key_exists('submit_form', $_POST))
		{
			$product_id =
			   $key['product_id'] = rlc_getvar("product_id", "1"); 
			$key['count'] = rlc_getvar("count", "1"); 
			$type = $key['type'] = rlc_getvar("type", "0");
			$key['rehosts'] = rlc_getvar("rehosts", "0");
			$key['white'] = rlc_getvar("white", "");
			$key['lastdate'] = 
					strtolower(rlc_getvar("lastdate", ""));
			$key['exp'] = strtolower(rlc_getvar("exp", ""));
			if (array_key_exists('kver_type', $_POST))
			{
			    $key['kver_type']  = $_POST['kver_type'];
		    	    $key['kver'] = $_POST['kver'];
			}
			else
			{
			    $key['kver'] = "";
			    $key['kver_type'] = 0;
			}
			$misc = _values_to_misc();
			$key['misc'] = $misc;
			$key['notes'] = rlc_getvar("notes", ""); 
			$key['akey'] = rlc_getvar("akey", ""); 
			$key['contact_id'] = rlc_getvar("contact_id", ""); 
			$key['key_allowed_hostids'] = rlc_set_hostids($_POST);
			$key['sub_interval'] = 0;
			$key['sub_window'] = 0;
			$key['ash_sn'] = 0;
			$key['user_def'] = "";
			display_create_form($sql, $session->username, $key, 1, 
									0, 0);
		}
		else
		{
/*
 *			We submitted the form - create the key.
 */
			$type = $key['type'] = $_POST['type'];
			$product_id =
			  $key['product_id'] = $_POST['product_id'];
			$key['count']        = $_POST['count'];
			$key['rehosts']      = $_POST['rehosts'];
			$numkeys             = $_POST['numkeys'];
			$key['white']        = $_POST['white'];
			$key['lastdate']     = strtolower($_POST['lastdate']);
			$key['exp']          = strtolower($_POST['exp']);
			$key['kver_type']    = $_POST['kver_type'];
		    	$key['kver']         = $_POST['kver'];
			$misc		     = _values_to_misc();
			$key['misc']         = $misc;
			$key['notes']        = $_POST['notes'];
			$key['akey'] = $akey = $_POST['akey'];
			$key['contact_id']   = $_POST['contact_id'];
			$key['active']       = 1;
			$key['kcreate'] = date("Y-m-d", time());
			$key['key_allowed_hostids'] = rlc_set_hostids($_POST);
			if ($key['type'] == RLM_ACT_KEY_TYPE_SUBSCRIPTION)
			{
			    $key['count'] = 1;
			    $key['sub_interval'] = 
			    			rlc_getpost('sub_interval', -1);
			    if ($key['sub_interval'] == 0)
			    	$key['sub_interval'] = 
						rlc_getpost('sub_interval_val',
						    RLM_ACT_SUBSCRIPTION_MONTH);
			    $key['sub_window'] = rlc_getpost('sub_window', 2);
			}
			else
			{
			    $key['sub_interval'] = 0;
			    $key['sub_window'] = 0;
			}

			$illegal = rlc_check_akey($key['lastdate'], $key['exp'],
						    $key['misc'], $key['kver']);
			if ($illegal === FALSE)
			{
			    rlc_web_title("Creating Activation Key(s)...", 
							"rlc_show_key.php");
			    $req = $numkeys;
			    $n = 0;
			    $failures = 0;
			    $maxfail = $numkeys;
			    if ($type == RLM_ACT_KEY_TYPE_REFRESH) 
							$key['count'] = 1;
			    while (($numkeys > 0) && ($failures < $maxfail))
			    {
				$n++;
				$x = time();
				$s1 = sprintf("%04d", (($x + $product_id + $n) 
								& 0x1fff));
				$s2 = sprintf("%04d", (($x >> 13) & 0x1fff));
				$s3 = sprintf("%04d", rand() % 9999);
				$s4 = ($numkeys + rand()) % 9999;
				if ($akey != "")
				{
				    if ($req == 1)
				    {
					$key['akey'] = $akey;
				    }
				    else
				    {
					$key['akey'] = 
						sprintf("%s-%s-%s-%s-%04d", 
								$akey, $s1, $s2,
								$s3, $s4);
				    }
				}
				else
				    $key['akey'] = sprintf("%s-%s-%s-%04d", $s1,
				    				$s2, $s3, $s4);


				$res = rlc_mysql_write_key($sql, $key);
				if ($res == 0) 
				{
					$numkeys--;
/*
 *					Write the key to the results page
 */
					echo "<ht>".$key['akey']."<br>";
					$res = rlc_mysql_add_audit($sql, 
							$session->username,
							"add", $key['akey'], 
							"akey");
				}
				else $failures++;
			    }
			    echo "<br>";
			    echo $req-$numkeys.
			    		" (of $req) activation records written";
			    if (($req == 1) && ($numkeys > 0))
				echo "<br>Requested key not written. (This is".
				  " most likely the result of a duplicate key)";
			    else if (($numkeys > 0) && ($failures > 0)) 
				echo "<br>".$failures." key write failures";
			    rlc_web_hidden("output_key", 1);
			    finish_page("Back to List", 0, 0);
			}
			else
			{
			    display_create_form($sql, $session->username, $key,
			    			$numkeys, 1, $illegal);
			}
		}
		rlc_mysql_close($sql);
	}
?>
