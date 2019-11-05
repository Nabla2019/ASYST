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

 	$Id: rlc_add_cust.php,v 1.13 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_prompts.php';
include 'rlc_mysql.php';
include 'rlc_cust.php';
include 'login_session.php';

/*
 *	Add/edit a contact/company record
 */
	rlc_web_header(RLC_MENU_CUST, $session);
	$cols = array("contact", "contact_type", "title", "company", "phone", "email", "info");
	$perm = check_user($session);
	if (!$perm['act_edit_enabled'])
	{
		rlc_noadmin($session);
		finish_page(0, 0, 0);
	}
	else
	{
		if (array_key_exists('edit_customer', $_POST))
			$back = "rlc_show_cust.php";
		else
			$back = "rlc_add_cust.php";

		if (array_key_exists('submit_form_contact', $_POST))
		{
/*
 *			We submitted the form - create the contact record.
 */
			$_data_['contact_id']   = rlc_getpost("contact_id", 0);
			$_data_['contact']      = rlc_getpost("contact", "");
			$_data_['contact_type'] = rlc_getpost("contact_type", 
									"");
			$_data_['title']        = rlc_getpost("title", "");
			$_data_['phone']        = rlc_getpost("phone", "");
			$_data_['fax']          = rlc_getpost("fax", "");
			$_data_['email']        = rlc_getpost("email", "");
			$_data_['info']         = rlc_getpost("info", "");
			$_data_['company_id']   = rlc_getpost("company_id", "");
			if (array_key_exists("ccreate", $_POST))
				$_data_['ccreate']    = $_POST['ccreate'];
			else
				$_data_['ccreate']    = date("Y-m-d", time());	
			$title = "Creating Contact Person Record ...";
			$what = "add";
			$who = $_data_['contact'];
			if ($_data_['contact_id'] != 0)
			{
				$title = "Updating Contact Person Record ...";
				$what = "edit";
			}
			rlc_web_title($title, $back);
			$select = rlc_web_get_select($cols, $select_data, 
								$xtra, $pxtra);
			$sql = rlc_mysql_init($isv);
			$res = rlc_mysql_write_cust($sql, $_data_);
			if ($res)
			{
			    echo " Contact record written<br>";
			    $res = rlc_mysql_add_audit($sql, $session->username,
					$what, $who, "contact");
			}
			else
			{
			    echo "Contact record not written<br>";
			    echo "Error: ".mysqli_error($sql)."<br>";
			}
			rlc_mysql_close($sql);
			echo $pxtra;
			finish_page("Back", 0, 0);
		}
		else if (array_key_exists('submit_form_company', $_POST))
		{
/*
 *			We submitted the form - create the company record.
 */
			$_data_['company']    = rlc_getpost("company", "");
			$_data_['company_id'] = rlc_getpost("company_id", 0);
			$_data_['addr1']      = rlc_getpost("addr1", "");
			$_data_['addr2']      = rlc_getpost("addr2", "");
			$_data_['addr3']      = rlc_getpost("addr3", "");
			$_data_['city']       = rlc_getpost("city", "");
			$_data_['state']      = rlc_getpost("state", "");
			$_data_['zip']        = rlc_getpost("zip", "");
			$_data_['country']    = rlc_getpost("country", "");
			$_data_['c_notes']    = rlc_getpost("c_notes", "");
			$_data_['u1']         = rlc_getpost("u1", "");
			$_data_['u2']         = rlc_getpost("u2", "");
			$_data_['u3']         = rlc_getpost("u3", "");
			$_data_['u4']         = rlc_getpost("u4", "");
			$_data_['u5']         = rlc_getpost("u5", "");
			$_data_['u6']         = rlc_getpost("u6", "");
			$_data_['u7']         = rlc_getpost("u7", "");
			$_data_['u8']         = rlc_getpost("u8", "");
			$_data_['u9']         = rlc_getpost("u9", "");
			$_data_['u10']        = rlc_getpost("u10", "");

			$title = "Creating Company Record ...";
			$what = "add";
			$who = $_data_['company'];
			if ($_data_['company_id'] != 0)
			{
				$title = "Updating Company Record ...";
				$what = "edit";
			}
			rlc_web_title($title, $back);
			$select = rlc_web_get_select($cols, $select_data, 
								$xtra, $pxtra);
			$sql = rlc_mysql_init($isv);
			$res = rlc_mysql_write_company($sql, $_data_);
			if ($res)
			{
			    echo "Company record written<br>";
			    $res = rlc_mysql_add_audit($sql, $session->username,
					$what, $who, "company");
			}
			else
			{
			    echo "Company record not written<br>";
			    echo "Error: ".mysqli_error($sql)."<br>";
			}
			rlc_mysql_close($sql);
			echo $pxtra;
			finish_page("Back", 0, 0);
		}
		else
		{
			$cust['contact'] = rlc_getpost("contact", ""); 
			$cust['contact_id'] = rlc_getpost("contact_id", ""); 
			$cust['contact_type'] = rlc_getpost("contact_type",""); 
			$cust['title'] = rlc_getpost("title", ""); 
			$cust['phone'] = rlc_getpost("phone", "");
			$cust['fax'] = rlc_getpost("fax", "");
			$cust['email'] = rlc_getpost("email", "");
			$cust['info'] = rlc_getpost("info", "");
			$cust['ccreate'] = rlc_getpost("ccreate", "");
			$cust['company_id'] = rlc_getpost("company_id", 0);
			$comp['company_id'] = rlc_getpost("company_id", 0);
			$comp['company'] = rlc_getpost("company", "");
			$comp['addr1'] = rlc_getpost("addr1", ""); 
			$comp['addr2'] = rlc_getpost("addr2", ""); 
			$comp['addr3'] = rlc_getpost("addr3", ""); 
			$comp['city'] = rlc_getpost("city", ""); 
			$comp['state'] = rlc_getpost("state", ""); 
			$comp['zip'] = rlc_getpost("zip", ""); 
			$comp['country'] = rlc_getpost("country", ""); 
			$comp['c_notes'] = rlc_getpost("c_notes", ""); 
			$comp['u1'] = rlc_getpost("u1", ""); 
			$comp['u2'] = rlc_getpost("u2", ""); 
			$comp['u3'] = rlc_getpost("u3", ""); 
			$comp['u4'] = rlc_getpost("u4", ""); 
			$comp['u5'] = rlc_getpost("u5", ""); 
			$comp['u6'] = rlc_getpost("u6", ""); 
			$comp['u7'] = rlc_getpost("u7", ""); 
			$comp['u8'] = rlc_getpost("u8", ""); 
			$comp['u9'] = rlc_getpost("u9", ""); 
			$comp['u10'] = rlc_getpost("u10", ""); 

			$select = rlc_web_get_select($cols, $select_data, 
								$xtra, $pxtra);
			$sql = rlc_mysql_init($isv);
			if (array_key_exists('edit_customer', $_POST))
				display_edit_form($sql, $session->username,
							$cust, $comp, $pxtra);
			else
				display_create_form($sql, $session->username,
							$cust, $comp, $pxtra);
			rlc_mysql_close($sql);
		}
	}
?>
