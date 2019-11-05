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

 	$Id: rlc_admin_portal.php,v 1.3 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_PORTAL);

	rlc_web_title("Activation Customer Portal settings", 0);

	rlc_web_info("Setup the Activation Pro Customer Portal<br><br>Once you set the directory and name, you can install the portal by pressing<br>the \"INSTALL Portal Software Now\" button at the bottom of the form.<br>Once installed, upload the Portal Logo.");

	$sql = rlc_mysql_init($isv);
	rlc_mysql_read_rlc_setup($sql, 'portal-name', $s);
	if (array_key_exists('portal-name', $s))
		$portal = $s['portal-name'];
	else
		$portal = "";
	rlc_mysql_read_rlc_setup($sql, 'portal-dir', $s);
	if (array_key_exists('portal-dir', $s))
		$portal_dir = $s['portal-dir'];
	else
		$portal_dir = "";
	rlc_mysql_close($sql);

?>
	<table>
	<tr><td><hr></td><td><hr></td><td><hr></td></tr>

	<tr><td></td><td>

	<h3>Activation Pro Customer Portal Settings</h3>
	</td></tr>

	<tr><td> </td></tr>
	<tr><td>
	<form enctype="multipart/form-data" action="rlc_set_portal.php" 
							method="POST">
	Portal Directory: 
	</td><td>
	<input type=text name=portal-dir size=64 value=
<?php
echo "'"."$portal_dir"."'";
?>
	></td><td>
	<input type="submit" value="Set Portal Directory">
	</form>
	</td></tr>

	<tr><td>
	<form enctype="multipart/form-data" action="rlc_set_portal.php" 
							method="POST">
	Portal Name: 
	</td><td>
	<input type=text name=portal-name size=64 value=
<?php
echo "'"."$portal"."'";
?>
	></td><td>
	<input type="submit" value="Set Portal Name">
	</form>
	</td></tr>

	<tr><td>
	<form enctype="multipart/form-data" action="rlc_install_portal.php" method="POST">
     	Portal Installation: 
	</td><td>
	<input type="submit" value="INSTALL Portal Software now">
	</form>
	</td></tr>

	<tr><td>
	<form enctype="multipart/form-data" action="rlc_upload_logo.php" method="POST">
     	Portal Logo: 
	</td><td>
	<input name="portal-logo" size=50 type="file">
	</td><td>
	<input type="submit" value="Upload Portal Logo (GIF only, max: 100x80)">
	</form>
	</td></tr>

	</table>
<?php
    }
?>
