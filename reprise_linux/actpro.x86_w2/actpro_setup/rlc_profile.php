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

 	$Id: rlc_profile.php,v 1.11 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'login_session.php';
include 'rlc.php';
include 'rlc_mysql.php';

    global $form;
    rlc_web_header(RLC_MENU_PROFILE, $session);
    if (!$session->canView())
    {
	echo "You do not have permission to perform this operation.<br>";
	finish_page(0, 0, 0);
	return;
    }


?>
	<h2>Edit Profile Settings for user <i><?php echo "$session->username";?>
			</i></h2>
	<table>
	<tr><td><br><hr></td><td><br><hr></td></tr>

<?php

	echo "<tr><td>";
	echo "User:";
	echo "</td><td>";
	echo $session->username;
	echo "</td></tr>";

/*
	echo "<tr><td>";
	echo "Full Name:";
	echo "</td><td>";
	echo "<form action=login_process.php method=POST>";
	echo "<input type=text name=fullname size=40 value=\"".
			$session->fullname."\">";
	echo "</td><td>";
	echo "<input type=submit value='Update'>";
	echo "<input type=hidden name=curpass value=0>";
	echo "<input type=hidden name=newpass value=0>";
	echo "<input type=hidden name=newpass2 value=0>";
	echo "<input type=hidden name=contact_id value=0>";
	echo "<input type=hidden name=subedit value=1></form>";
	echo "</td></tr>";
*/

	echo "<tr><td>";
	echo "Email:";
	echo "</td><td>";
	echo "<form action=login_process.php method=POST>";
	echo "<input type=text name=email size=40 value='$session->email'>";
	echo $form->error("email");
	echo "</td><td>";
	echo "<input type=submit value='Update'>";
	echo "<input type=hidden name=curpass value=0>";
	echo "<input type=hidden name=newpass value=0>";
	echo "<input type=hidden name=newpass2 value=0>";
	echo "<input type=hidden name=contact_id value=0>";
	echo "<input type=hidden name=subedit value=1></form>";
	echo "</td></tr>";
/*
 *	Change Password
 */
	echo "<tr><td>";
	echo "<form enctype='multipart/form-data' action='login_useredit.php'".
				"method='POST'>";
	echo "</td><td><input type='submit' value='Change Password'>";
	echo "</form> </td></tr>";
/*
 *	Edit Product/Activation Key Defaults
 */
	echo "<tr><td><br><hr></td><td><br><hr></td></tr>";
	echo "<br>";
	echo "<tr><td>";
	echo "<form enctype='multipart/form-data' ".
				"action='rlc_prod_defaults.php' method='POST'>";
	echo "</td><td><input type='submit' ".
				"value='Edit Product Definition Defaults'>";
	echo "</form> </td></tr>";

	echo "<tr><td></td></tr><tr><td>";
	echo "<form enctype='multipart/form-data' ".
				"action='rlc_akey_defaults.php' method='POST'>";
	echo "</td><td><input type='submit' ".
				"value='Edit Activation Key Defaults'>";
	echo "</form> </td></tr>";
?>

	<tr><td><br><hr></td><td><br><hr></td></tr>
	<tr><td></td><td>
