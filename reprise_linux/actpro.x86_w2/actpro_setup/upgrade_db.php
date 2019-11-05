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

 	$Id: upgrade_db.php,v 1.50 2017/08/19 02:24:11 matt Exp $

 *****************************************************************************/

/*
 *	Executing the sql commands is the same for every update.
 */
function sql_execute($isv, $sqlcmds)
{
	$sql = rlc_mysql_init($isv);
	$count = count($sqlcmds);
	echo "$count Database upgrade commands to execute<br><br>";
	for ($i = 0; $i < $count; $i++)
	{
	echo "executing: $sqlcmds[$i]<br>";
		$stat = mysqli_query($sql, $sqlcmds[$i]);
		if (!$stat)
		{
			echo "Error executing SQL command<br>"
					.mysqli_error($sql)."<br>";
			echo "    Command: ".$sqlcmds[$i]."<br><br>";
		}
	}
	echo "$i Database upgrade commands executed<br><br>";
	rlc_mysql_close($sql);
}

function rlc_upgrade_12_2BL2_to_12_3BL1($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `defaults` CHANGE `value` `value` VARCHAR( 255 ) NULL 
	  						DEFAULT NULL",

/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '12' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '3' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
/*
 *	  Only keep these 6 cmds  in the last upgrade, to purge these 3 tables
 */
	  "ALTER IGNORE TABLE report_cols ADD UNIQUE INDEX x (report, displayorder, tablecolumn, display)",
	  "ALTER IGNORE TABLE report_cols drop INDEX x",
	  "ALTER IGNORE TABLE report_select ADD UNIQUE INDEX x (report, displayorder, display, var)",
	  "ALTER IGNORE TABLE report_select drop INDEX x",
	  "ALTER IGNORE TABLE contact_types ADD UNIQUE INDEX x (contact_type)",
	  "ALTER IGNORE TABLE contact_types drop INDEX x"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v12.1BL1 to v12.1BL2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_12_1BL1_to_12_2BL2($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `prod` ADD `add_cust` tinyint(1) DEFAULT '0' AFTER 
	  							`issued`",
	  "ALTER TABLE `keyd` ADD `sub_interval` smallint(6) DEFAULT '0' AFTER 
	  							`user_def`",
	  "ALTER TABLE `keyd` ADD `sub_window` smallint(6) DEFAULT '0' AFTER 
	  							`sub_interval`",

/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '12' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v12.1BL1 to v12.1BL2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}
function rlc_upgrade_12_0BL2_to_12_1BL1($isv)
{

	$sqlcmds = array(

/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '12' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v12.0BL2 to v12.1BL1 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_12_0BL1_to_12_0BL2($isv)
{

	$sqlcmds = array(

/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '12' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v12.0BL1 to v12.0BL2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_3BL1_to_12_0BL1($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `keyd` ADD `user_def` char(11) NOT NULL 
					DEFAULT '' AFTER `ash_sn`",
	  "ALTER TABLE `prod` ADD `lictext` varchar(1024) NOT NULL 
					DEFAULT '' AFTER `ash_tolerance`",
/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '12' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.3BL1 to v12.0BL1 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_2BL2_to_11_3BL1($isv)
{

	$sqlcmds = array(

	  "CREATE TABLE IF NOT EXISTS contact_types (
		contact_type varchar(60) default '' NOT NULL)",
	  "INSERT INTO `contact_types` (`contact_type`) VALUES
			('Administrative'), ('Billing'),
			('Exec'), ('Marketing'),
			('Sales'), ('Technical');",
	  "ALTER TABLE `contact` ADD `contact_type` varchar(60) NOT NULL 
					DEFAULT '' AFTER `contact`",
	  "ALTER TABLE `prod` ADD `obsolete` INT(1) DEFAULT '0' AFTER `active`",
	  "ALTER TABLE `users` ADD `vistabs` INT(11) DEFAULT '0' 
	  					AFTER `contact_id`",
	  "UPDATE `users` SET `vistabs` = 63 WHERE 1",
	  "CREATE TABLE IF NOT EXISTS defaults (id INT(11) default NULL 
			auto_increment, 
		user varchar(30) NULL default NULL, 
		tab varchar(30) NULL default NULL,
		col varchar(30) NULL default NULL,
		value varchar(80) NULL default NULL,
		invis int(1) default 0,
		primary key (id))",
/*
 *	  Update the setup table for this version
 */
	  "UPDATE `setup` SET `data` = '11' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '3' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.2BL2 to v11.3BL1 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_2BL1_to_11_2BL2($isv)
{

	$sqlcmds = array(

	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Fulfilled Licenses', 27, '@last_check', 'Last keyvalid()', 0);",
	  "ALTER TABLE `licf` ADD `last_check` INT(16) NOT NULL 
					DEFAULT '0' AFTER `revoke_time`",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.2BL1 to v11.2BL2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_1BL2_to_11_2BL1($isv)
{

	$sqlcmds = array(

	  "CREATE TABLE IF NOT EXISTS audit (
			date int(11) default 0, 
			who char(20) default NULL,
			what char(10) default 'edit',
			tablekey char(30) default NULL,
			tablename char(20) default NULL)",
	  "ALTER TABLE `prod` CHANGE `product` `product` VARCHAR(41) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL", 
	  "ALTER TABLE `prod` ADD `prod_allowed_hostids` INT(11) NOT NULL DEFAULT '0' AFTER `nlic`",
	  "ALTER TABLE `prod` ADD `pcreate` CHAR(11) NULL DEFAULT NULL",
	  "ALTER TABLE `prod` ADD `ash_type` INT(1) NOT NULL DEFAULT '0'",
	  "ALTER TABLE `prod` ADD `ash_tolerance` INT(11) NOT NULL DEFAULT '0'",
	  "ALTER TABLE `keyd` ADD `kcreate` CHAR(11) NULL DEFAULT NULL",
	  "ALTER TABLE `keyd` ADD `ash_sn` INT(11) NOT NULL AUTO_INCREMENT UNIQUE", 
	  "ALTER TABLE `contact` ADD `ccreate` CHAR(11) NULL DEFAULT NULL",
	  "ALTER TABLE `keyd` ADD `key_allowed_hostids` INT(11) NOT NULL DEFAULT '0' AFTER `contact_id`",
	  "UPDATE `setup` SET `data` = '11' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.1BL2 to v11.2BL1 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_1BL1_to_11_1BL2($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `report_types` CHANGE `tablename` `tablename` 
			VARCHAR(200) CHARACTER SET latin1 
			COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
			      ('Activation Keys', 0, 60, 'Contact', 
						'contact', 64, '', ''),
			      ('Activation Keys', 0, 70, 'Company', 
						'company', 64, '', ''),
			      ('Fulfilled Licenses', 0, 60, 'Contact', 
						'contact', 64, '', ''),
			      ('Fulfilled Licenses', 0, 70, 'Company', 
						'company', 64, '', ''),
			      ('Revoked Licenses', 0, 60, 'Contact', 
						'contact', 64, '', ''),
			      ('Revoked Licenses', 0, 70, 'Company', 
						'company', 64, '', ''),
			      ('Unfulfilled Keys', 0, 60, 'Contact', 
						'contact', 64, '', ''),
			      ('Unfulfilled Keys', 0, 70, 'Company', 
						'company', 64, '', '');",
	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
			('Activation Keys', 120, 'contact', 'Contact', 0),
			('Activation Keys', 130, 'company', 'Company', 0),
			('Fulfilled Licenses', 120, 'contact', 'Contact', 0),
			('Fulfilled Licenses', 130, 'company', 'Company', 0),
			('Revoked Licenses', 120, 'contact', 'Contact', 0),
			('Revoked Licenses', 130, 'company', 'Company', 0),
			('Unfulfilled Keys', 120, 'contact', 'Contact', 0),
			('Unfulfilled Keys', 130, 'company', 'Company', 0);",
	  "UPDATE `report_types` SET `tablename` = 
			'keyd left join contact using (contact_id) left join company using (company_id)' 
		WHERE `report_types`.`report` = 'Activation Keys' ",
	  "UPDATE `report_types` SET `tablename` = 
			'licf left join keyd using (akey) left join contact using (contact_id) left join company using (company_id)'  
		WHERE `report_types`.`report` = 'Fulfilled Licenses' ",
	  "UPDATE `report_types` SET `tablename` = 
			'licf left join keyd using (akey) left join contact using (contact_id) left join company using (company_id)' 
		WHERE `report_types`.`report` = 'Revoked Licenses' ",
	  "UPDATE `report_types` SET `tablename` = 
			'keyd left join keyf using (akey) left join contact using (contact_id) left join company using (company_id)'  
		WHERE `report_types`.`report` = 'Unfulfilled Keys' ",
	  "UPDATE `setup` SET `data` = '11' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.1BL1 to v11.1BL2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_11_0_to_11_1($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `licf` ADD `reference_hostid` VARCHAR(80) NOT NULL 
					DEFAULT '' AFTER `license_hostid`",
	  "ALTER TABLE `licf` ADD `expdate` VARCHAR(16) NOT NULL 
					DEFAULT '' AFTER `reference_hostid`",
	  "ALTER TABLE `report_types` CHANGE `tablename` `tablename` 
			VARCHAR(200) CHARACTER SET latin1 
			COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
			      ('Fulfillment Summary', 0, 25, 'Activation Key', 
					'akey', 64, '', ''),
			      ('Fulfilled Licenses', 0, 22, 'Reference Hostid', 
					'reference_hostid', 64, '', ''),
			      ('Fulfilled Licenses', 0, 23, 'License Expiration', 
					'expdate', 64, '', '');",
	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
			('Fulfillment Summary', 5, '@product', 'Product', 0),
			('Fulfillment Summary', 10, 'akey', 'Activation Key', 0),
			('Fulfillment Summary', 20, 'expdate', 
						'License Expiration', 0),
			('Fulfillment Summary', 30, 'license_hostid', 
						'License Hostid', 0),
			('Fulfillment Summary', 40, 'remote_host', 
						'Activated From', 0),
			('Fulfillment Summary', 60, '@time', 'When', 0),
			('Fulfilled Licenses', 22, 'reference_hostid', 
					'Reference Hostid', 0),
			('Fulfilled Licenses', 23, 'expdate', 
					'License Expiration', 0);",
	  "UPDATE `report_cols` SET `displayorder` = '25' WHERE 
		`report_cols`.`report` = 'Fulfilled Licenses' AND 
		`report_cols`.`tablecolumn` = 'license'",
	  "UPDATE `report_select` SET `fixed` = '1' WHERE 
		`report_select`.`report` = 'Fulfilled Licenses' AND 
		`report_select`.`var` = 'revoked'",
	  "INSERT INTO `setup` (`what`, `data`) VALUES ('revoke-expired', '0')",
	  "UPDATE `setup` SET `data` = '11' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v11.0 to v11.1 for ISV "
				."<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

function rlc_upgrade_10_1_to_11_0($isv)
{

	$sqlcmds = array(

/*
 *	  Fix all the old NULL columns in the old tables
 */
	  "ALTER TABLE `company` CHANGE `company` `company` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `addr1` `addr1` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `addr2` `addr2` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `addr3` `addr3` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `city` `city` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `state` `state` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `zip` `zip` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `country` `country` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `u1` `u1` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `u2` `u2` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `company` CHANGE `u3` `u3` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `contact` CHANGE `contact` `contact` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `contact` CHANGE `title` `title` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `contact` CHANGE `phone` `phone` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `contact` CHANGE `fax` `fax` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `contact` CHANGE `email` `email` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `contact` CHANGE `info` `info` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `keyd` CHANGE `lastdate` `lastdate` VARCHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `keyd` CHANGE `exp` `exp` VARCHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `keyd` CHANGE `white` `white` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `keyd` CHANGE `misc` `misc` VARCHAR(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `keyd` CHANGE `notes` `notes` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `keyf` CHANGE `date` `date` CHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `keyf` CHANGE `lasthostid` `lasthostid` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `licf` CHANGE `akey` `akey` VARCHAR(61) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `licf` CHANGE `license_hostid` `license_hostid` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `licf` CHANGE `hostname` `hostname` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `licf` CHANGE `remote_host` `remote_host` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `licf` CHANGE `log` `log` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `licf` CHANGE `license` `license` TEXT(2048) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `prod` CHANGE `name` `name` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `prod` CHANGE `version` `version` CHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `prod` CHANGE `upgrade_version` `upgrade_version` CHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `prod` CHANGE `exp` `exp` CHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `prod` CHANGE `product` `product` VARCHAR(31) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `prod` CHANGE `misc` `misc` VARCHAR(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `report_cols` CHANGE `report` `report` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_cols` CHANGE `tablecolumn` `tablecolumn` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_cols` CHANGE `display` `display` VARCHAR(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `report_select` CHANGE `report` `report` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_select` CHANGE `display` `display` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_select` CHANGE `var` `var` VARCHAR(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_select` CHANGE `op` `op` VARCHAR(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_select` CHANGE `value` `value` VARCHAR(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `report_types` CHANGE `report` `report` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_types` CHANGE `tablename` `tablename` VARCHAR(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `report_types` CHANGE `report_header` `report_header` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `setup` CHANGE `data` `data` VARCHAR(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "ALTER TABLE `users` CHANGE `password` `password` VARCHAR(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `users` CHANGE `userid` `userid` VARCHAR(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	  "ALTER TABLE `users` CHANGE `email` `email` VARCHAR(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	  "CREATE TABLE IF NOT EXISTS debuglog (
		date int(11) default 0, 
		logdata varchar(500) default NULL)",

	  "ALTER TABLE `prod` ADD `prod_id` INT(11) NOT NULL DEFAULT '0' AFTER `generator`",
	  "UPDATE `prod` SET `prod_id` = 0",
	  "ALTER TABLE `prod` ADD `add_akey` INT(1) NOT NULL DEFAULT '0' AFTER `issued`",
	  "UPDATE `prod` SET `add_akey` = 0",
	  "ALTER TABLE `prod` ADD `nlic` INT(11) NOT NULL DEFAULT '1' AFTER `prod_id`",
	  "ALTER TABLE `keyd` ADD `kver` CHAR(11) NULL DEFAULT NULL AFTER `exp`",
	  "ALTER TABLE `keyd` ADD `kver_type` INT(2) NULL DEFAULT 0 AFTER `kver`",
	  "UPDATE `prod` SET `nlic` = 1",
	  "ALTER TABLE `company` ADD `c_notes` varchar(255) NOT NULL DEFAULT '' AFTER `country`",
	  "ALTER TABLE `company` ADD `u4` varchar(60) NOT NULL DEFAULT '' AFTER `u3`",
	  "ALTER TABLE `company` ADD `u5` varchar(60) NOT NULL DEFAULT '' AFTER `u4`",
	  "ALTER TABLE `company` ADD `u6` varchar(60) NOT NULL DEFAULT '' AFTER `u5`",
	  "ALTER TABLE `company` ADD `u7` varchar(60) NOT NULL DEFAULT '' AFTER `u6`",
	  "ALTER TABLE `company` ADD `u8` varchar(60) NOT NULL DEFAULT '' AFTER `u7`",
	  "ALTER TABLE `company` ADD `u9` varchar(60) NOT NULL DEFAULT '' AFTER `u8`",
	  "ALTER TABLE `company` ADD `u10` varchar(60) NOT NULL DEFAULT '' AFTER `u9`",
	  "ALTER TABLE `users` ADD `contact_id` int(11) NOT NULL DEFAULT 0 
							AFTER `email`",
	  "UPDATE `users` SET `contact_id` = 0",
	  "UPDATE `setup` SET `data` = '11' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",
	  "INSERT INTO `setup` (`what`, `data`) VALUES ('debug-on', '0')",
	  "INSERT INTO `setup` (`what`, `data`) VALUES ('portal-name', 
					'RLM Activation Pro Customer Portal')",
	  "ALTER TABLE `keyf` ADD `num_revoked` int(11) NULL DEFAULT '0' 
						AFTER `lasthostid`",
	  "ALTER TABLE `stats` ADD `keyvalid` INT(11) NULL DEFAULT '0' 
						AFTER `info`",
	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Activation Keys', 85, 'kver', 'License Version', 0),
		('Unfulfilled Keys', 85, 'kver', 'License Version', 0),
		('Statistics', 80, 'info', 'Info calls', 1),
		('Statistics', 90, 'keyvalid', 'keyvalid calls', 1);"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database to v11.0 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

/*
 *	Upgrade 10.0 to 10.1
 */

function rlc_upgrade_10_0_to_10_1($isv)
{

	$sqlcmds = array(


	  "UPDATE `setup` SET `data` = '10' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '2' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",

	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Fulfilled Licenses', 0, 25, 'License', 
						'license', 64, '', '');"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database to v10.1 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

/*
 *	Upgrade 9.4 to 10.0
 */


function rlc_upgrade_9_4_to_10_0($isv)
{

	$sqlcmds = array(

	  "ALTER TABLE `prod` ADD `version_type` INT(2) NULL DEFAULT '0' AFTER `version`",	/* New for 10.0BL1 */
	  "ALTER TABLE `prod` ADD `generator` INT(11) NULL DEFAULT '0' AFTER `misc`",	/* New for 9.4BL3 */

	  "ALTER TABLE `stats` ADD `info` INT(11) NULL DEFAULT '0' AFTER `badtime`",
	  "ALTER TABLE `contact` CHANGE `notes` `info` VARCHAR(60) NULL DEFAULT NULL",

	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Statistics', 90, 'info', 'Get Info Requests', 1);",

	  "UPDATE `setup` SET `data` = '10' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",

	  "INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Statistics', 100, 'stats', 'License Activation Statistics');",

	  "INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Unfulfilled Keys', 13, 'keyd left join keyf using (akey)', 
				'Activation Keys with No Fulfillments');",

	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Unfulfilled Keys', 0, 10, 'Activation Key', 'akey', 64, '', 
									''),
		('Unfulfilled Keys', 1, 20, '', 'num', 1, 'is', 'NULL'),
		('Statistics', 0, 10, 'Date', 'date', 64, '', '');",

	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Unfulfilled Keys', 10, 'akey', 'Activation Key', 0),
		('Unfulfilled Keys', 30, 'count', 'Count', 1),
		('Unfulfilled Keys', 50, 'type', 'Activation Type', 0),
		('Unfulfilled Keys', 60, 'rehosts', '# rehosts', 1),
		('Unfulfilled Keys', 70, 'lastdate', 'Last Date Valid', 0),
		('Unfulfilled Keys', 80, 'exp', 'License Expiration Date', 0),
		('Unfulfilled Keys', 90, 'white', 'Whitelist', 0),
		('Unfulfilled Keys', 100, 'misc', 'Extra License Data', 0),
		('Unfulfilled Keys', 110, 'notes', 'Notes', 0),
		('Unfulfilled Keys', 20, '@product', 'Product', 0),
		('Fulfilled Licenses', 30, 'log', 'Logged Data', 0),
		('Statistics', 10, 'date', 'Statistics Hour', 0),
		('Statistics', 20, 'total', 'Transactions', 1),
		('Statistics', 30, 'good', 'Fulfillments', 1),
		('Statistics', 40, 'badkey', 'Bad Key', 1),
		('Statistics', 50, 'blacklist', 'Blacklisted', 1),
		('Statistics', 60, 'checks', 'Uptime Checks', 1),
		('Statistics', 70, 'badtime', 'Bad Client Time', 1);"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database to v10.0 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

/*
 *	Upgrade 9.3 to 9.4
 */

function rlc_upgrade_9_3_to_9_4($isv)
{

	$sqlcmds = array(

	  "CREATE TABLE IF NOT EXISTS stats (
		date char(13) default NULL, 
		total int(11) default NULL, 
		good int(11) default NULL,
		badkey int(11) default NULL, 
		blacklist int(11) default NULL, 
		checks int(11) default NULL, 
		numfulfill int(11) default NULL, 
		rmfulfill int(11) default NULL, 
		prod int(11) default NULL, 
		badtime int(11) default NULL,
		PRIMARY KEY (date))",

	  "CREATE TABLE IF NOT EXISTS badhost (
		ip char(15) default NULL, 
		first int(11) default NULL, 
		last int(11) default NULL,
		count int(11) default NULL)",

	  "CREATE TABLE IF NOT EXISTS contact (
		contact_id int(11) NULL default NULL auto_increment,
 		contact varchar(60) default NULL,
 		title varchar(60) default NULL,
 		phone varchar(60) default NULL,
 		fax varchar(60) default NULL,
 		email varchar(60) default NULL,
 		info varchar(60) default NULL,
		company_id int(11) default 0,
		PRIMARY KEY (contact_id))",

	  "CREATE TABLE IF NOT EXISTS company (
		company_id int(11) NULL default NULL auto_increment,
 		company varchar(60) default NULL,
 		addr1 varchar(60) default NULL,
 		addr2 varchar(60) default NULL,
 		addr3 varchar(60) default NULL,
 		city varchar(60) default NULL,
 		state varchar(60) default NULL,
 		zip varchar(20) default NULL,
 		country varchar(60) default NULL,
 		u1 varchar(60) default NULL,
 		u2 varchar(60) default NULL,
 		u3 varchar(60) default NULL,
		PRIMARY KEY (company_id))",

	  "ALTER TABLE `blacklist` ADD `type` INT(2) NULL DEFAULT 0 AFTER `domain`",
	  "UPDATE `setup` SET `data` = '9' WHERE `setup`.`what` = 
							'actpro_version'",
	  "UPDATE `setup` SET `data` = '4' WHERE `setup`.`what` = 
							'actpro_rev'",
	  "UPDATE `setup` SET `data` = '1' WHERE `setup`.`what` = 
							'actpro_build'",
	  "UPDATE `setup` SET `data` = '0' WHERE `setup`.`what` = 
							'actpro_patch'",

	  "ALTER TABLE `keyd` ADD `contact_id` INT(11) NULL DEFAULT 0 AFTER `notes`",
        "INSERT INTO `setup` (`what`, `data`) VALUES
		('auto-bl-numkey', '50'),
		('auto-bl-maxsec', '600')",

	  "INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Statistics', 100, 'stats', 'License Activation Statistics')",

	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Statistics', 0, 10, 'Date', 'date', 64, '', '');",

	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Statistics', 10, 'date', 'Statistics Hour', 0),
		('Statistics', 20, 'total', 'Transactions', 1),
		('Statistics', 30, 'good', 'Fulfillments', 1),
		('Statistics', 40, 'badkey', 'Bad Key', 1),
		('Statistics', 50, 'blacklist', 'Blacklisted', 1),
		('Statistics', 60, 'checks', 'Uptime Checks', 1),
		('Statistics', 70, 'badtime', 'Bad Client Time', 1);"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database to v9.4 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

/*
 *	Upgrade 9.2 to 9.3 (BL1)
 */

function rlc_upgrade_9_2_to_9_3($isv)
{

	$sqlcmds = array(

	  "UPDATE setup SET data = 9 WHERE what = 'actpro_version';",
	  "UPDATE setup SET data = 3 WHERE what = 'actpro_rev';",
	  "UPDATE setup SET data = 1 WHERE what = 'actpro_build';",
	  "UPDATE setup SET data = 0 WHERE what = 'actpro_patch';",
	  "UPDATE report_select SET op = '=' WHERE report = 
						'Permanent Licenses';",
	  "ALTER TABLE `licf` ADD `last_fulfill` int(16) DEFAULT 0",
	  "ALTER TABLE `licf` ADD `num_fulfills` int(16) DEFAULT 1",
	  "ALTER TABLE `licf` ADD `revoked` INT(1) NOT NULL DEFAULT '0'",
	  "ALTER TABLE `licf` ADD `revoke_time` int(16) DEFAULT NULL",
	  "INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Revoked Licenses', 50, 'licf', 'Revoked Licenses');",
	  "INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Revoked Licenses', 0, 10, 'Activation Key', 'akey', 64, '',
									 ''),
		('Revoked Licenses', 0, 20, 'License Hostid', 
						'license_hostid', 64, '', ''),
		('Revoked Licenses', 1, 30, '', 'revoked', 1, '=', '1'),
		('Fulfilled Licenses', 1, 30, '', 'revoked', 1, '=', '0'),
		('Fulfilled Licenses', 1, 40, 'Activated from', 'remote_host', 
								20, '', '');",
	  "INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Revoked Licenses', 10, 'akey', 'Activation Key', 0),
		('Revoked Licenses', 20, 'license_hostid', 'Hostid', 0),
		('Revoked Licenses', 30, '@time', 'Fulfill Time', 0),
		('Revoked Licenses', 40, '@revoke_time', 'Revoke Time', 0),
		('Revoked Licenses', 50, 'license', 'License', 0),
		('Fulfilled Licenses', 12, 'remote_host', 'Activated from', 0),
		('Fulfilled Licenses', 14, '@time', 'Initial Fulfill Time', 0),
		('Fulfilled Licenses', 16, '@last_fulfill', 'Last Fulfill Time',
									0),
		('Fulfilled Licenses', 18, 'num_fulfills', '# fulfills', 0),
		('Fulfilled Licenses', 19, 'license_hostid', 'License Hostid', 0);"
	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database to v9.3 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}

/*
 *	Upgrade 9.1 to 9.2 (BL3)
 */

function rlc_upgrade_9_1_to_9_2($isv)
{
	$sqlcmds = array(

	"ALTER TABLE `prod` CHANGE `name` `name` VARCHAR(60) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `prod` CHANGE `product` `product` VARCHAR(31) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `prod` CHANGE `misc` `misc` VARCHAR(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",

	"ALTER TABLE `keyd` CHANGE `akey` `akey` VARCHAR(61) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	"ALTER TABLE `keyd` CHANGE `lastdate` `lastdate` VARCHAR(11) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `keyd` ADD `exp` VARCHAR(11) NULL DEFAULT NULL AFTER `lastdate`",
	"ALTER TABLE `keyd` CHANGE `white` `white` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `keyd` CHANGE `misc` `misc` VARCHAR(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `keyd` CHANGE `notes` `notes` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",

	"ALTER TABLE `keyf` CHANGE `akey` `akey` VARCHAR(61) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",
	"ALTER TABLE `keyf` CHANGE `lasthostid` `lasthostid` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",

	"ALTER TABLE `licf` CHANGE `akey` `akey` VARCHAR(61) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `licf` CHANGE `license_hostid` `license_hostid` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `licf` CHANGE `hostname` `hostname` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `licf` CHANGE `remote_host` `remote_host` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",
	"ALTER TABLE `licf` CHANGE `log` `log` VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",

	"ALTER TABLE `blacklist` CHANGE `domain` `domain` VARCHAR(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''",

	"ALTER TABLE `setup` CHANGE `data` `data` VARCHAR(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL",

	"CREATE TABLE IF NOT EXISTS report_types (report varchar(40),
		tablename varchar(40),
		displayorder int(2),
		report_header varchar(80),
		PRIMARY KEY (report))",

	"CREATE TABLE IF NOT EXISTS report_select (id int(11) default NULL
			auto_increment,
		report varchar(40),
		fixed int(1) default 0,
		displayorder int(2),
		display varchar(40),
		var varchar(20),
		size int(3) default 64,
		op varchar(20),
		value varchar(64),
		PRIMARY KEY (id))",

	"CREATE TABLE IF NOT EXISTS report_cols (id int(11) default NULL
			auto_increment,
		report varchar(40),
		displayorder int(2),
		tablecolumn varchar(40),
		display varchar(30),
		is_int int(1) default 0,
		PRIMARY KEY (id))",

	"INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Products', 40, 'prod', 'Products'),
		('Activation Keys', 10, 'keyd', 'Activation Keys'),
		('Fulfilled Licenses', 30, 'licf', 'Fulfilled Licenses'),
		('Permanent Licenses', 20, 'prod', 
				'Permanent License Product Definitions');",

	"INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Products', 0, 10, 'Product Name', 'name', 30, '', ''),
		('Products', 0, 20, 'License Name', 'product', 30, '', ''),
		('Products', 0, 30, 'Version', 'version', 20, '', ''),
		('Products', 0, 40, 'Other License Parameters', 'misc', 64, '',
									 ''),
		('Fulfilled Licenses', 0, 10, 'Activation Key', 'akey', 64, '',
									 ''),
		('Fulfilled Licenses', 0, 20, 'License Hostid', 
						'license_hostid', 64, '', ''),
		('Activation Keys', 0, 10, 'Product Name', 'product_id', 64, 
								'', ''),
		('Activation Keys', 0, 20, 'Activation Key', 'akey', 64, '', 
									''),
		('Activation Keys', 0, 30, 'Other License Parameters', 'misc', 
								64, '', ''),
		('Activation Keys', 0, 40, 'Notes', 'notes', 64, '', ''),
		('Activation Keys', 0, 50, 'Whitelist', 'white', 64, '', ''),
		('Permanent Licenses', 1, 10, '', 'exp', 64, '=', '0');",
		

	"INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Products', 10, 'name', 'Product Name', 0),
		('Products', 20, 'product', 'License Name', 0),
		('Products', 30, 'version', 'Version', 0),
		('Products', 40, 'upgrade_version', 'Upgrade Version', 0),
		('Products', 50, 'exp', 'Expiration', 0),
		('Products', 60, 'lictype', 'License Type', 0),
		('Products', 70, 'issued', 'Issued', 0),
		('Products', 80, 'misc', 'Additional License Data', 0),
		('Activation Keys', 10, 'akey', 'Activation Key', 0),
		('Activation Keys', 60, 'rehosts', '# rehosts', 1),
		('Activation Keys', 30, 'count', 'Count', 1),
		('Activation Keys', 50, 'type', 'Activation Type', 0),
		('Activation Keys', 70, 'lastdate', 'Last Date Valid', 0),
		('Activation Keys', 80, 'exp', 'License Expiration Date', 0),
		('Activation Keys', 90, 'white', 'Whitelist', 0),
		('Activation Keys', 100, 'misc', 'Extra License Data', 0),
		('Activation Keys', 110, 'notes', 'Notes', 0),
		('Activation Keys', 40, '@fulfill_count', '# Fulfilled', 0),
		('Activation Keys', 20, '@product', 'Product', 0),
		('Fulfilled Licenses', 10, 'akey', 'Activation Key', 0),
		('Fulfilled Licenses', 20, 'license', 'License', 0),
		('Permanent Licenses', 10, 'name', 'Product Name', 0),
		('Permanent Licenses', 50, 'lictype', 'License Type', 0),
		('Permanent Licenses', 20, 'product', 'License Name', 0),
		('Permanent Licenses', 30, 'version', 'Version', 0),
		('Permanent Licenses', 70, 'misc', 'Additional License Data', 
									0);",

	"INSERT INTO `setup` (`what`, `data`) VALUES
					('cgi-bin', '../../cgi-bin/');",
	"INSERT INTO `setup` (`what`, `data`) VALUES ('actpro_version', '9');",
	"INSERT INTO `setup` (`what`, `data`) VALUES ('actpro_rev', '2');",
	"INSERT INTO `setup` (`what`, `data`) VALUES ('actpro_build', '3');",
	"INSERT INTO `setup` (`what`, `data`) VALUES ('actpro_patch', '0');"

	);

	error_reporting(E_ERROR | E_PARSE);

	echo "<br><b>Upgrading RLM ActPro database from v9.1 to v9.2 for ISV ".
				"<i>$isv</i></b><br><br>";
/*
 *	Now, execute all the database commands
 */
	sql_execute($isv, $sqlcmds);
}
?>
