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

 	$Id: login_useredit.php,v 1.7 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/
/*
 *
 * Edit user password.
 *
 */

include "rlc_web.php";
include "login_session.php";

    rlc_web_header(RLC_MENU_ADMIN, $session);

/*
 *  Put up the edit password form.
 */
    if ($session->logged_in)
    {
	echo "<h2>Change Password for ";
	echo $session->username; 
	echo "</h2>";
	if ($form->num_errors > 0)
	{
	    echo "<td><font size=\"2\" color=\"#ff0000\">".$form->num_errors.
						" error(s) found</font></td>";
	}
	echo "<form action=login_process.php method=POST>";
	echo "<table align=left border=0 cellspacing=0 cellpadding=3>";
	echo "<tr><td>Current Password:</td>";
	echo "<td><input type=password name=curpass maxlength=30></td>";
	echo "<td>";
	echo $form->error("curpass");
	echo "</td></tr>";
	echo "<tr><td>New Password:</td>";
	echo "<td><input type=password name=newpass maxlength=30 value=\"";
	echo $form->value("newpass"); 
	echo "\"></td><td>";
	echo $form->error("newpass"); 
	echo "</td></tr>";
	echo "<tr><td>New Password (again):</td>";
	echo "<td><input type=password name=newpass2 maxlength=30 value=\"";
	echo $form->value("newpass2"); 
	echo "\"></td><td>";
	echo $form->error("newpass2"); 
	echo "</td></tr>";
	echo "<tr><td colspan=2 align=left>";
	echo "<input type=hidden name=subedit value=1>";
	echo "<input type=hidden name=email value=0>";
	echo "<input type=hidden name=contact_id value=0>";
	echo "<input type=submit value='Change Password'></td></tr>";
	echo "<tr><td colspan=2 align=left></td></tr>";
	echo "</table></form>";
    }
    finish_page(0, 0, 0);
