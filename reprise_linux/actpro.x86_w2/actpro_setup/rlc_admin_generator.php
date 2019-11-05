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

 	$Id: rlc_admin_generator.php,v 1.8 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_GENERATOR);
	$sql = rlc_mysql_init($isv);
	rlc_mysql_read_rlc_setup($sql, 'allow-non-encrypted', $s);
	if (array_key_exists('allow-non-encrypted', $s))
		$allow_non_encrypted = $s['allow-non-encrypted'];
	else
		$allow_non_encrypted = 1;	/* old default */
	rlc_mysql_close($sql);
?>
	<h3>License Generator Settings</h3>
	<table>
	<tr><td colspan=2>
	<b>Upload Generator Settings File (isv.gen)</b></td></tr>
	<tr><td colspan=3>Note: Generator settings files are always < 1kb.  Anything larger will fail.</td></tr>
	<tr><td>&nbsp;</td></tr>
	<tr><td>
	<form enctype="multipart/form-data" action="rlc_upload_gen.php" method="POST">
	<input type="hidden" name="MAX_FILE_SIZE" value="1000">
	Generator File: 
	</td><td>
	<input name="generatorfile" size=10 type="file">
	</td><td>
	<input type="submit" value="Upload File">
	</form>
	</td></tr>
	</table>

	<table>
	<tr><td>&nbsp;</td></tr>
	<tr><td>&nbsp;</td></tr>
	<tr><td>&nbsp;</td></tr>
	<tr><td colspan=3>
	<b>Control over request encryption</b></td></tr>
	<tr><td>&nbsp;</td></tr>
	<tr><td colspan=4>
	If you allow non-encrypted requests, users can input any data into optional fields</td></tr>
	<tr><td colspan=4>by creating their own web pages which access your license generator.</td></tr>
	<tr><td colspan=4>This was the default prior to Actpro v12.0</td></tr>
	<tr><td>&nbsp;</td></tr>
	<tr><td>
	<form enctype="multipart/form-data" action="rlc_set_encrypted_keys.php" method="POST">
	Allow Non-Encrypted Requests?
	</td><td>
	<input type=checkbox name='allow-non-encrypted' value=1<?php if ($allow_non_encrypted == 1) echo " checked=true"; ?> >
	</td>
	<td>&nbsp;</td><td>
	<input type='submit' value='Set'>
	</form></td></tr>
	</table>
<?php
   }
?>
