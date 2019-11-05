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

 	$Id: rlc_admin_db.php,v 1.28 2017/07/25 02:06:43 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_DB);

	$errlevel = rlc_turn_off_warnings();
	$files = glob("backups/*");
	foreach ($files as $file) 
	{
		chmod($file, 0777);
		unlink($file);
	}
	chmod(DLCMDFILE, 0777);
	unlink(DLCMDFILE);
	error_reporting($errlevel);

	$sql = rlc_mysql_init($isv);	/* Get ISV name */
	rlc_mysql_read_rlc_setup($sql, 'url', $s);
	$url = $s['url'];
	rlc_mysql_read_rlc_setup($sql, 'auto-bl-numkey', $s);
	if (array_key_exists('auto-bl-numkey', $s))
		$numkey = $s['auto-bl-numkey'];
	else
		$numkey = AUTO_BL_NUMKEY;
	rlc_mysql_read_rlc_setup($sql, 'auto-bl-maxsec', $s);
	if (array_key_exists('auto-bl-maxsec', $s))
		$maxsec = $s['auto-bl-maxsec'];
	else
		$maxsec = AUTO_BL_MAXSEC;

	rlc_mysql_read_rlc_setup($sql, 'revoke-expired', $s);
	if (array_key_exists('revoke-expired', $s))
		$revoke_expired = $s['revoke-expired'];
	else
		$revoke_expired = 0;

	rlc_mysql_read_rlc_setup($sql, 'isvport', $s);
	if (array_key_exists('isvport', $s))
		$isvport = $s['isvport'];
	else
		$isvport = 0;
	rlc_mysql_close($sql);
?>
	<table>
	<tr><td colspan=3><hr></td></tr>

<?php
/*
 *	Backup the activation database
 */
?>


	<tr><td></td><td>

	<h3>Backup Activation Database to local file</h3>
	</td></tr>
	<tr><td>
	<form enctype="multipart/form-data" action="rlc_backup_db.php" method="POST">
	<input type="hidden" name="MAX_FILE_SIZE" value="1000">
	Backup file name: </td><td>
	<input type=text name=backupfile size=40 value=
<?php
		$date = date("Y-m-j"); 
		$backupfile = "backups/actpro-$isv-backup.$date.sql";
		echo $backupfile;
?>
>
	</td><td>
	<input type="submit" value="Backup Database">
	</form>
	</td></tr>
	<tr><td colspan=3><hr></td></tr>

<?php
/*
 *	Convert local RLM Activation database to a MySQL database
 */
?>
	<tr><td></td><td>

	<h3>Upload Activation database data (.sql)</h3>
	</td></tr>

	<tr><td>
	<form enctype="multipart/form-data" action="rlc_upload_db.php" method="POST">
     	Database File: 
	</td><td>
	<input name="dbfile" size=50 type="file">
	</td><td>
	<input type="submit" value="Upload File">
	</form>
	</td></tr>

	<tr><td colspan=3><hr></td></tr>

<?php
/*
 *	Database consistency check
 */
	echo "<tr><td></td><td><h3>Database Consistency Check</h3>";
	echo "</td><td>";
	echo "<form enctype='multipart/form-data' action='rlc_check_db.php' method='POST'>";
	echo "<input type='submit' value='Check Database'>";
	echo "</form> </td></tr>";
?>
	<tr><td colspan=3><hr></td></tr>
<?php
/*
 *	Purge statistics
 */
	echo "<tr><td></td><td><h3>Purge Activation Statistics</h3>";
	echo "</td><td>";
	echo "<form enctype='multipart/form-data' action='rlc_purge_stats.php' method='POST'>";
	echo "<input type='submit' value='Purge Statistics'>";
	echo "</form> </td></tr>";
?>
	<tr><td colspan=3><hr></td></tr>
<?php

/*
 *	Edit Product Defaults
 */
	echo "<tr><td></td><td><h3>Edit System-Wide Product Definition Defaults</h3>";

	echo "</td><td>";
	echo "<form enctype='multipart/form-data' ".
				"action='rlc_prod_defaults.php' method='POST'>";
	rlc_web_hidden("system_defaults", 1);
	echo "<input type='submit' value='Setup Product Defaults'>";
	echo "</form> </td></tr>";
/*
 *	Edit Activation Key Defaults
 */
	echo "<tr><td></td><td><h3>Edit System-Wide Activation Key Defaults</h3>";

	echo "</td><td>";
	echo "<form enctype='multipart/form-data' ".
				"action='rlc_akey_defaults.php' method='POST'>";
	rlc_web_hidden("system_defaults", 1);
	echo "<input type='submit' value='Setup Activation Key Defaults'>";
	echo "</form> </td></tr>";

/*
 *	Edit ISV port #
 */
	echo "<tr><td></td><td><h3>Set Default ISV server Port (0=dynamic)</h3>";

	echo "</td><td>";
	echo "<form enctype='multipart/form-data' ".
				"action='rlc_admin_isvport.php' method='POST'>".
		"<input name='isvport' size=5 value=$isvport >";
	echo "<input type='submit' value='Set Default ISV Port'>";
	echo "</form> </td></tr>";

?>
	<tr><td colspan=3><hr></td></tr>

	<tr><td></td><td>
	<h3>Revocation of  expired rehostable hostids</h3>
	</td></tr> <tr><td>
	</td></tr><tr><td></td><td colspan=2>
	If an expired rehostable license is revoked, by default the
	activation server will 
	</td></tr><tr><td></td><td colspan=2>
	reject the revocation with an 
	RLM_ACT_REVOKE_TOOLATE error.  By checking
	</td></tr><tr><td></td><td colspan=2>
	the box below, expired licenses can be revoked without error.
	</td></tr><tr><td></td><td>
	<form enctype='multipart/form-data' action='rlc_set_revoke_expired.php' method='POST'>
	<tr><td>
	Revoke expired keys?
	</td><td>
	<input type=checkbox name='revoke-expired' value=1<?php if ($revoke_expired == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>&nbsp;</td><td>
	<input type='submit' value='Set Revoke Expiration'>
	</form></td></tr>
	<tr><td colspan=3><hr></td></tr>

	<tr><td></td><td>
	<h3>Automatic blacklisting of IP addresses</h3>
	</td></tr> <tr><td></td><td colspan=2>
	If this # of bad keys are presented to the server within
	this # of 
	<tr><td></td><td colspan=2>
	seconds from one IP address, the address is blacklisted.
	</td></tr> <tr><td>
	<form enctype='multipart/form-data' action='rlc_set_auto_black.php' method='POST'>
	<tr><td>
	# of bad keys:
	</td><td>
	<input name='numkey' size=5 value=<?php echo $numkey; ?> >
	</td></tr>
	<tr><td>
	in this # seconds: 
	</td><td>
	<input name='maxsec' size=5 value= <?php echo $maxsec; ?> >
	</td></tr>
	<tr><td>&nbsp;</td><td>
	<input type='submit' value='Set Blacklist Parameters'>
	</form></td></tr>
	<tr><td colspan=3><hr></td></tr>

	<tr><td></td><td>
	<h3>Bulk-Load Customer database data</h3>
	</td></tr>

	<tr><td></td><td colspan=2>
	A customer upload file consists of tab-separated records
	containing the following data:
	</td></tr><tr><td></td><td colspan=2>
	contact name, title, phone, fax, email, info,
	company name, addr1, addr2, 
	</td></tr><tr><td></td><td colspan=2>
	addr3, city, state, zip, country,
	<ht>notes, u1-u10 (10 user-defined fields)
	</td></tr>
	<tr><td>
	<form enctype="multipart/form-data" action="rlc_upload_cust.php" method="POST">
     	Customer File: 
	</td><td>
	<input name="custfile" size=50 type="file">
	</td><td>
	<input type="submit" value="Upload File">
	</form>
	</td></tr>

	<tr><td colspan=3><hr></td></tr>

<?php
/*
 *	Customize Company fields
 */
	echo "<tr><td></td><td><h3>Customize user-defined Company fields</h3>";
	echo "</td><td>";
	echo "<form enctype='multipart/form-data' action='rlc_custom_cust.php' method='POST'>";
	echo "<input type='submit' value='Customize Company fields'>";
	echo "</form> </td></tr>";
?>
	<tr><td></td><td>
<?php
/*
 *	Setup refresh removed in v11.  Uncomment to
 *	put it back.
 *	v11.2 - turned into general server URL for server alt hostids
 */
?>
	<tr><td colspan=3><hr></td></tr>
	<tr><td></td><td><h3>Activation Server URL</h3>
	</td></tr>

	<tr><td>
	<form enctype="multipart/form-data" action="rlc_setup_doit.php" 
							method="POST">
	<input type="hidden" name="MAX_FILE_SIZE" value="1000">
	<abbr title="The activation server URL is required for Alternate Server Hostids.  It is unused by the rest of Activation Pro">Activation Server URL: </abbr>
	</td><td>
	<input type=text name=actserverurl size=40 value=
<?php
echo $url;
?>
	></td><td>
	<input type="submit" value="Set ACTIVATION Server URL">
	</form>
	</td></tr>

	<tr><td colspan=3><hr></td></tr>
	<tr><td></td><td><h3>Delete Activation Keys with Revoked Licenses</h3>
	</td></tr>

	</td></tr><tr><td></td><td colspan=2>
	If an activation key has been fulfilled with 
	a rehostable hostid then is later revoked, 
	</td></tr><tr><td></td><td colspan=2>
	this key cannot be deleted in the normal
	"Activation Keys" tab.   However, if this key 
	</td></tr><tr><td></td><td colspan=2>
	has no current fulfillments, it can be deleted here.
	</td></tr><tr><td></td><td>
	</td></tr><tr><td></td><td>&nbsp;</td></tr><tr><td>
	<form enctype='multipart/form-data' action='rlc_show_key.php' method='POST'>
	<tr><td>&nbsp;</td><td>
	<input type="hidden" name="delrevoked" value="1">
	<input type='submit' value='Delete Keys with Revoked Licenses'>
	</form></td></tr>
	<tr><td>

	<tr><td colspan=3><hr></td></tr>
	<tr><td></td><td>
	<h3>Normalize dates</h3>
	</td></tr> <tr><td>
	</td></tr><tr><td></td><td colspan=2>
	Many dates in actpro are in the RLM format (dd-mmm-yyyy),
	 which does not sort 
	</td></tr><tr><td></td><td colspan=2>
	 correctly.  This function converts
	these dates to yyyy-mm-dd (in an all-numeric format), 
	</td></tr><tr><td></td><td colspan=2>
	so that the dates sort correctly.  This applies to the expiration
	date and last date valid
	</td></tr><tr><td></td><td colspan=2>
	in the activation keys table, and
	the expiration date in the product definition table.
	</td></tr><tr><td></td><td>&nbsp;</td></tr><tr><td>
	<form enctype='multipart/form-data' action='rlc_normalize_dates.php' method='POST'>
	<tr><td>&nbsp;</td><td>
	<input type='submit' value='Normalize Dates'>
	</form></td></tr>
<?php
	echo "</table>";
   }
?>
