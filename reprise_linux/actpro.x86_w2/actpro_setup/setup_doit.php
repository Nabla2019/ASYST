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

 	$Id: setup_doit.php,v 1.72 2017/10/01 20:27:45 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'rlc_setup.php';

/*
 *	table creation, in order
 */
$sqltbl = array("active_users", "audit", "badhost", "blacklist", 
		"company", "contact", "contact_types", "debuglog",
		"defaults", "keyd", "keyf", "licf", "prod", 
		"report_cols", "report_select", "report_types",
		"setup", "stats", "users");

/*
 *	Table inserts, in order.
 */
$sqltblins = array("contact_types", "report_types", "report_select", "report_cols", "setup");

$sqlcmds = array(

	"CREATE TABLE IF NOT EXISTS active_users (username varchar(30) 
			primary key,
 		timestamp int(11) unsigned not null)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS audit (
		date int(11) default 0, 
		who char(20) default NULL, 
		what char(10) default 'edit', 
		tablekey char(30) default NULL, 
		tablename char(20) default NULL)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS badhost (
	  	ip char(15) default NULL,
		first int(11) default NULL,
		last int(11) default NULL,
		count int(11) default NULL)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS blacklist (id int(11) default NULL 
			auto_increment, 
		domain varchar(255), 
		type int(2) NULL default 0,
		primary key (domain), key (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS company (
		company_id int(11) NOT NULL auto_increment,
 		company varchar(60) NOT NULL default '',
 		addr1 varchar(60) NOT NULL default '',
 		addr2 varchar(60) NOT NULL default '',
 		addr3 varchar(60) NOT NULL default '',
 		city varchar(60) NOT NULL default '',
 		state varchar(60) NOT NULL default '',
 		zip varchar(20) NOT NULL default '',
 		country varchar(60) NOT NULL default '',
 		c_notes varchar(255) NOT NULL default '',
 		u1 varchar(60) NOT NULL default '',
 		u2 varchar(60) NOT NULL default '',
 		u3 varchar(60) NOT NULL default '',
 		u4 varchar(60) NOT NULL default '',
 		u5 varchar(60) NOT NULL default '',
 		u6 varchar(60) NOT NULL default '',
 		u7 varchar(60) NOT NULL default '',
 		u8 varchar(60) NOT NULL default '',
 		u9 varchar(60) NOT NULL default '',
 		u10 varchar(60) NOT NULL default '',
		PRIMARY KEY (company_id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS contact (
		contact_id int(11) NOT NULL auto_increment,
 		contact varchar(60) NOT NULL default '',
 		contact_type varchar(60) NOT NULL default '',
 		title varchar(60) NOT NULL default '',
 		phone varchar(60) NOT NULL default '',
 		fax varchar(60) NOT NULL default '',
 		email varchar(60) NOT NULL default '',
 		info varchar(60) NOT NULL default '',
		company_id int(11) not null default 0,
		ccreate char(11) NULL DEFAULT NULL,
		PRIMARY KEY (contact_id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS contact_types (
		contact_type varchar(60) default '' NOT NULL)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS debuglog (
		date int(11) default NULL, 
		logdata varchar(500) default NULL)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS defaults (id INT(11) NOT NULL 
			auto_increment, 
		user varchar(30) NULL default NULL, 
		tab varchar(30) NULL default NULL,
		col varchar(30) NULL default NULL,
		value varchar(255) NULL default NULL,
		invis int(1) default 0,
		primary key (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS keyd (akey varchar(61),
		active INT(1),
		product_id int(11),
		count int(11) default 1,
		type int(1) default 0,
		rehosts int(11) default 0, 
		lastdate varchar(11) NOT NULL default '',
		exp varchar(11) NULL default NULL,
		kver char(11) NULL default NULL,
		kver_type int(2) default 0,
		white varchar(100) NULL default NULL,
		misc varchar(255) NULL default NULL,
		notes varchar(100) NULL default NULL,
		contact_id int(11) default '0',
		key_allowed_hostids int (11) NOT NULL default 0,
		kcreate char(11) NULL DEFAULT NULL,
		ash_sn int(11) NOT NULL AUTO_INCREMENT,
		user_def char(11) NOT NULL DEFAULT '',
		sub_interval smallint(6) NOT NULL DEFAULT 0,
		sub_window smallint(6) NOT NULL DEFAULT 0,
		PRIMARY KEY (akey),
		UNIQUE (ash_sn))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS keyf (akey varchar(61),
		num INT(11),
		date char(11) NOT NULL default '',
		lasthostid varchar(80) NOT NULL default '', 
		num_revoked int(11) NULL default 0,
		PRIMARY KEY (akey))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS licf (id INT(11) NOT NULL auto_increment, 
		akey varchar(61) NOT NULL default '', 
		product_id int(11), 
		count INT(11), 
		time int(16) default 0, 
		license_hostid varchar(80) NOT NULL default '', 
		reference_hostid varchar(80) NOT NULL default '', 
		expdate varchar(16) NOT NULL default '', 
		hostname varchar(80) NOT NULL default '', 
		remote_host varchar(80) NOT NULL default '', 
		log varchar(80) NOT NULL default '', 
		license text(2048) NOT NULL, 
		last_fulfill int(16) default 0, 
		num_fulfills int(16) default 1, 
		revoked int(1) not null default 0,
		revoke_time int(16) default 0, 
		last_check int(16) not null default 0, 
		primary key (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS prod (id INT(11) NOT NULL auto_increment,
		active INT (1),
		obsolete INT (1) default 0,
		name varchar(60) NOT NULL default '',
		version char(11) NOT NULL default '',
		version_type int(2) default 0,
		upgrade_version char(11) NOT NULL default '',
		exp char(11) NOT NULL default '', 
		lictype int(1) default 0,
		issued int(1) default 0,
		add_cust tinyint(1) default 0,
		add_akey int(1) NOT NULL default 0,
		product varchar (41) NOT NULL default '', 
		misc varchar(255) NOT NULL default '',
		generator int(11) NOT NULL default '0',
		prod_id int(11) NOT NULL default 0,
		nlic int (11) NOT NULL default 1,
		prod_allowed_hostids int (11) NOT NULL default 0,
		pcreate char(11) NULL DEFAULT NULL,
		ash_type int(1) NOT NULL DEFAULT 0,
		ash_tolerance int(11) NOT NULL DEFAULT 0,
		lictext varchar(1024) NOT NULL DEFAULT '', 
		PRIMARY KEY (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS setup (what char(30) NOT NULL, 
		data varchar(64) NOT NULL default '', 
		primary key (what))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	 "CREATE TABLE IF NOT EXISTS users (username varchar(30) NOT NULL 
	 		primary key,
 		password varchar(32) NOT NULL default '',
 		userid varchar(32) NOT NULL default '',
 		userlevel tinyint(1) unsigned not null,
 		email varchar(50) NOT NULL default '',
 		contact_id int(11) not null default 0,
 		vistabs int(11) not null default 0,
 		timestamp int(11) unsigned not null)
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS report_cols (id int(11) NOT NULL 
			auto_increment, 
		report varchar(40) NOT NULL default '',
		displayorder int(3),
		tablecolumn varchar(40) NOT NULL default '',
		display varchar(30) NOT NULL default '',
		is_int int(1) default 0,
		PRIMARY KEY (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS report_select (id int(11) NOT NULL 
			auto_increment,
		report varchar(40) NOT NULL default '',
		fixed int(1) default 0,
		displayorder int(2),
		display varchar(40) NOT NULL default '',
		var varchar(20) NOT NULL default '',
		size int(3) default 64,
		op varchar(20) NOT NULL default '',
		value varchar(64) NOT NULL default '',
		PRIMARY KEY (id))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS report_types (
		report varchar(40) NOT NULL,
		tablename varchar(200) NOT NULL default '',
		displayorder int(2),
		report_header varchar(80) NOT NULL default '',
		PRIMARY KEY (report))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"CREATE TABLE IF NOT EXISTS stats (
		date char(13) NOT NULL, 
		total int(11) default NULL, 
		good int(11) default NULL,
		badkey int(11) default NULL, 
		blacklist int(11) default NULL, 
		checks int(11) default NULL, 
		numfulfill int(11) default NULL, 
		rmfulfill int(11) default NULL, 
		prod int(11) default NULL, 
		badtime int(11) default NULL,
		info int(11) default NULL,
		keyvalid int(11) default NULL,
		PRIMARY KEY (date))
		ENGINE=MyISAM DEFAULT CHARSET=latin1;",

	"INSERT INTO `contact_types` (`contact_type`) VALUES
				('Administrative'), ('Billing'),
				('Exec'), ('Marketing'),
				('Sales'), ('Technical');",

	"INSERT INTO `report_types` (`report`, `displayorder`, `tablename`, 
						`report_header`) VALUES
		('Activation Keys', 10, 
			'keyd left join contact using (contact_id) left join company using (company_id)', 
					'Activation Keys'),
		('Unfulfilled Keys', 13, 
			'keyd left join keyf using (akey) left join contact using (contact_id) left join company using (company_id)', 
				'Activation Keys with No Fulfillments'),
		('Fulfilled Licenses', 30, 
			'licf left join keyd using (akey) left join contact using (contact_id) left join company using (company_id)', 
					'Fulfilled Licenses'),
		('Fulfillment Summary', 20, 'licf', 'Fulfillment Summary'),
		('Products', 40, 'prod', 'Products'),
		('Revoked Licenses', 50, 
			'licf left join keyd using (akey) left join contact using (contact_id) left join company using (company_id)', 
						'Revoked Licenses'),
		('Permanent Licenses', 20, 'prod', 
				'Permanent License Product Definitions'),
		('Statistics', 100, 'stats', 'License Activation Statistics');",

	"INSERT INTO `report_select` (`report`, `fixed`, `displayorder`, 
				`display`, `var`, `size`, `op`, `value`) VALUES
		('Products', 0, 10, 'Product Name', 'name', 30, '', ''),
		('Products', 0, 20, 'License Name', 'product', 30, '', ''),
		('Products', 0, 30, 'Version', 'version', 20, '', ''),
		('Products', 0, 40, 'Other License Parameters', 'misc', 64, '',
									 ''),
		('Fulfillment Summary', 0, 25, 'Activation Key', 'akey', 64, '',
									 ''),
		('Fulfilled Licenses', 0, 10, 'Activation Key', 'akey', 64, '',
									 ''),
		('Fulfilled Licenses', 0, 20, 'License Hostid', 
						'license_hostid', 64, '', ''),
		('Fulfilled Licenses', 0, 22, 'Reference Hostid', 
						'reference_hostid', 64, '', ''),
		('Fulfilled Licenses', 0, 23, 'License Expiration', 
						'expdate', 64, '', ''),
		('Fulfilled Licenses', 0, 25, 'License',
						'license', 64, '', ''),
		('Fulfilled Licenses', 1, 30, '', 'revoked', 1, '=', '0'),
		('Fulfilled Licenses', 1, 40, 'Activated from', 'remote_host', 20, '', ''),
		('Fulfilled Licenses', 0, 60, 'Contact', 'contact', 64, '', ''),
		('Fulfilled Licenses', 0, 70, 'Company', 'company', 64, '', ''),
		('Activation Keys', 0, 10, 'Product Name', 'product_id', 64, 
								'', ''),
		('Activation Keys', 0, 20, 'Activation Key', 'akey', 64, '', 
									''),
		('Activation Keys', 0, 30, 'Other License Parameters', 'misc', 
								64, '', ''),
		('Activation Keys', 0, 40, 'Notes', 'notes', 64, '', ''),
		('Activation Keys', 0, 50, 'Whitelist', 'white', 64, '', ''),
		('Activation Keys', 0, 60, 'Contact', 'contact', 64, '', ''),
		('Activation Keys', 0, 70, 'Company', 'company', 64, '', ''),
		('Unfulfilled Keys', 0, 10, 'Activation Key', 'akey', 64, '',
									 ''),
		('Unfulfilled Keys', 1, 20, '', 'num', 1, 'is', 'NULL'),
		('Unfulfilled Keys', 0, 60, 'Contact', 'contact', 64, '', ''),
		('Unfulfilled Keys', 0, 70, 'Company', 'company', 64, '', ''),
		('Revoked Licenses', 0, 10, 'Activation Key', 'akey', 64, '',
									 ''),
		('Revoked Licenses', 0, 20, 'License Hostid', 
						'license_hostid', 64, '', ''),
		('Revoked Licenses', 1, 30, '', 'revoked', 1, '=', '1'),
		('Revoked Licenses', 0, 60, 'Contact', 'contact', 64, '', ''),
		('Revoked Licenses', 0, 70, 'Company', 'company', 64, '', ''),
		('Permanent Licenses', 1, 10, '', 'exp', 64, '=', '0'),
		('Statistics', 0, 10, 'Date', 'date', 64, '', '');",

	"INSERT INTO `report_cols` (`report`, `displayorder`, `tablecolumn`, 
				`display`, `is_int`) VALUES
		('Products', 10, 'name', 'Product Name', 0),
		('Products', 20, 'product', 'License Name', 0),
		('Products', 30, 'version', 'Version', 0),
		('Products', 40, 'upgrade_version', 'Upgrade Version', 0),
		('Products', 50, 'exp', 'Expiration', 0),
		('Products', 60, 'lictype', 'License Type', 0),
		('Products', 70, 'issued', 'Issued', 0),
		('Products', 75, 'add_cust', 'Customer', 0),
		('Products', 80, 'misc', 'Additional License Data', 0),
		('Activation Keys', 10, 'akey', 'Activation Key', 0),
		('Activation Keys', 20, '@product', 'Product', 0),
		('Activation Keys', 30, 'count', 'Count', 1),
		('Activation Keys', 40, '@fulfill_count', '# Fulfilled', 0),
		('Activation Keys', 50, 'type', 'Activation Type', 0),
		('Activation Keys', 60, 'rehosts', '# rehosts', 1),
		('Activation Keys', 70, 'lastdate', 'Last Date Valid', 0),
		('Activation Keys', 80, 'exp', 'License Expiration Date', 0),
		('Activation Keys', 85, 'kver', 'License Version', 0),
		('Activation Keys', 90, 'white', 'Whitelist', 0),
		('Activation Keys', 100, 'misc', 'Extra License Data', 0),
		('Activation Keys', 110, 'notes', 'Notes', 0),
		('Activation Keys', 120, 'contact', 'Contact', 0),
		('Activation Keys', 130, 'company', 'Company', 0),
		('Unfulfilled Keys', 10, 'akey', 'Activation Key', 0),
		('Unfulfilled Keys', 20, '@product', 'Product', 0),
		('Unfulfilled Keys', 30, 'count', 'Count', 1),
		('Unfulfilled Keys', 50, 'type', 'Activation Type', 0),
		('Unfulfilled Keys', 60, 'rehosts', '# rehosts', 1),
		('Unfulfilled Keys', 70, 'lastdate', 'Last Date Valid', 0),
		('Unfulfilled Keys', 80, 'exp', 'License Expiration Date', 0),
		('Unfulfilled Keys', 85, 'kver', 'License Version', 0),
		('Unfulfilled Keys', 90, 'white', 'Whitelist', 0),
		('Unfulfilled Keys', 100, 'misc', 'Extra License Data', 0),
		('Unfulfilled Keys', 110, 'notes', 'Notes', 0),
		('Unfulfilled Keys', 120, 'contact', 'Contact', 0),
		('Unfulfilled Keys', 130, 'company', 'Company', 0),
		('Fulfillment Summary', 5, '@product', 'Product', 0),
		('Fulfillment Summary', 10, 'akey', 'Activation Key', 0),
		('Fulfillment Summary', 20, 'expdate', 'License Expiration', 0),
		('Fulfillment Summary', 30, 'license_hostid', 'License Hostid', 0),
		('Fulfillment Summary', 40, 'remote_host', 'Activated From', 0),
		('Fulfillment Summary', 60, '@time', 'When', 0),
		('Fulfilled Licenses', 10, 'akey', 'Activation Key', 0),
		('Fulfilled Licenses', 12, 'remote_host', 'Activated from', 0),
		('Fulfilled Licenses', 14, '@time', 'Initial Fulfill Time', 0),
		('Fulfilled Licenses', 16, '@last_fulfill', 'Last Fulfill Time',
									0),
		('Fulfilled Licenses', 18, 'num_fulfills', '# fulfills', 0),
		('Fulfilled Licenses', 19, 'license_hostid', 'License Hostid', 0),
		('Fulfilled Licenses', 22, 'reference_hostid', 'Reference Hostid', 0),
		('Fulfilled Licenses', 23, 'expdate', 'License Expiration', 0),
		('Fulfilled Licenses', 25, 'license', 'License', 0),
		('Fulfilled Licenses', 27, '@last_check', 'Last keyvalid()', 0),
		('Fulfilled Licenses', 30, 'log', 'Logged Data', 0),
		('Fulfilled Licenses', 120, 'contact', 'Contact', 0),
		('Fulfilled Licenses', 130, 'company', 'Company', 0),
		('Permanent Licenses', 10, 'name', 'Product Name', 0),
		('Permanent Licenses', 20, 'product', 'License Name', 0),
		('Permanent Licenses', 30, 'version', 'Version', 0),
		('Permanent Licenses', 50, 'lictype', 'License Type', 0),
		('Permanent Licenses', 70, 'misc', 'Additional License Data', 
									0),
		('Revoked Licenses', 10, 'akey', 'Activation Key', 0),
		('Revoked Licenses', 20, 'license_hostid', 'Hostid', 0),
		('Revoked Licenses', 30, '@time', 'Fulfill Time', 0),
		('Revoked Licenses', 40, '@revoke_time', 'Revoke Time', 0),
		('Revoked Licenses', 50, 'license', 'License', 0),
		('Revoked Licenses', 120, 'contact', 'Contact', 0),
		('Revoked Licenses', 130, 'company', 'Company', 0),
		('Statistics', 10, 'date', 'Statistics Hour', 0),
		('Statistics', 20, 'total', 'Transactions', 1),
		('Statistics', 30, 'good', 'Fulfillments', 1),
		('Statistics', 40, 'badkey', 'Bad Key', 1),
		('Statistics', 50, 'blacklist', 'Blacklisted', 1),
		('Statistics', 60, 'checks', 'Uptime Checks', 1),
		('Statistics', 70, 'badtime', 'Bad Client Time', 1);",

	"INSERT INTO `setup` (`what`, `data`) VALUES
		('actpro_version', '12'),
		('actpro_rev', '3'),
		('actpro_build', '1'),
		('actpro_patch', '0'),
		('debug-on', '0'),
		('revoke-expired', '0'),
		('portal-name', 'RLM Activation Pro Customer Portal'),
		('auto-bl-numkey', '50'),
		('auto-bl-maxsec', '600');"
	);

/*
 *	List of files to chmod to 444
 */

	$files444 = array(
			"actpro_web_serv.php",
			"actpro_web_serv_11.2.php",
			"rlc.css",
			"rlm_activation_pro.pdf",
			"images/add.png",
			"images/arrow_down.png",
			"images/arrow_left_up.png",
			"images/arrow_up.png",
			"images/delete.png",
			"images/edit.png",
			"images/repriselogo.gif",
			"images/show.png"
			);


function delete($file)
{
	chmod($file, 0777);
	unlink($file);
}

/*
 *	We submitted the form - set up the database
 */

	error_reporting(E_ERROR | E_PARSE);

	rlc_setup_header("Installing RLM Activation PRO ...");

	if (array_key_exists("db_upgrade", $_POST))
	{
		$upgrade = TRUE;
	}
	else
	{
		$upgrade = FALSE;
		$admin    = $_POST['admin'];
		$adminpw  = $_POST['adminpw'];
	}
	$dbhost   = $_POST['dbhost'];
	$dbport   = $_POST['dbport'];
	$dbuser   = $_POST['dbuser'];
	$dbpw     = $_POST['dbpw'];
	$dbname   = $_POST['dbname'];
	$cgibin   = $_POST['cgibin'];
	$isv      = $_POST['isv'];
	$next = "../actpro/setup_finish.php";

/*
 *	Make sure admin username and password are OK, otherwise, go back.
 */
	$error = 0;
	$usererr = "";  
	$passerr = "";
	if (!$upgrade)
	{
	    if (!preg_match("/^([0-9a-z])+$/", $admin))
	    {
	        $usererr = "Admin account name must be lowercase letters and numbers";
	        $error = 1;
	    }
	    if (!preg_match("/^([0-9a-zA-Z])+$/", $adminpw))
	    {
	        $passerr = "Admin password must be letters and numbers only";
	        $error = 1;
	    }
	}
	if ($error)
	{
	    rlc_web_title("", "setup.php");
	    echo "Form has errors, please re-submit<br>";
	    rlc_web_hidden("backto", $next);
	    rlc_web_hidden("dbhost", $dbhost);
	    rlc_web_hidden("dbport", $dbport);
	    rlc_web_hidden("dbuser", $dbuser);
	    rlc_web_hidden("dbpw", $dbpw);
	    rlc_web_hidden("dbname", $dbname);
	    rlc_web_hidden("cgibin", $cgibin);
	    rlc_web_hidden("isv", $isv);
	    rlc_web_hidden("admin", $admin);
	    rlc_web_hidden("adminpw", $adminpw);
	    rlc_web_hidden("passerr", $passerr);
	    rlc_web_hidden("usererr", $usererr);
	    finish_page("BACK to Re-Submit", 0, 0);
	}


	rlc_web_title("", $next);

	{
/*
 *	    Before anything, create the "real" directory, and copy
 *	    all the files over.  We do this because the webserver user
 *	    might be different from the user who installed this.
 */
	
	    $errlevel = rlc_turn_off_warnings();
	    $status = stat("../actpro");
	    if ($status)
	    {
 		echo "Removing old Activation Pro software from ../actpro ".
							"...<br>";
		
		$files = glob("../actpro/login/*");
		foreach ($files as $file) delete($file);
		rmdir("../actpro/login");

	        chmod("../actpro/images", 0777);
		$files = glob("../actpro/images/*");
		foreach ($files as $file) delete($file);
		rmdir("../actpro/images");

		$files = glob("../actpro/backups/*");
		foreach ($files as $file) delete($file);
		rmdir("../actpro/backups");

		$files = glob("../actpro/tmp/*");
		foreach ($files as $file) delete($file);
		unlink("../actpro/tmp/.htaccess");
		rmdir("../actpro/tmp");

		$files = glob("../actpro/*");
		foreach ($files as $file) delete($file);
		echo "Saving old .htaccess file as ".getcwd()."/saved_htaccess <br>";
		mycopy("../actpro/.htaccess", "./saved-htaccess");
		unlink("../actpro/.htaccess");
		rmdir("../actpro");
	    }
	    error_reporting($errlevel);

 	    echo "Copying Activation Pro software to ../actpro ...<br>";

	    mycopy(".", "../actpro");
	    $status = stat("saved-htaccess");

	    if ($status)
	    {
		echo "restoring old .htaccess file<br>";
	        mycopy("saved-htaccess", "../actpro/.htaccess");
	    }
	    unlink("../actpro/setup.php");
	    unlink("../actpro/setup_doit.php");
	    unlink("../actpro/upgrade.php");
	    unlink("../actpro/upgrade_db.php");
	    chdir("../actpro");
	    mkdir("tmp", 0755);	/* Temporary report directory */
	    delete("htaccess.tmp");
	    mkdir("backups", 0700);	/* Database backups directory */
	    delete("htaccess.backups");
/*
 *	    First - Create the database description file: rlmact.mysql
 *	    (for cgi-bin) and actpro.php for the php files.
 *	    If we are doing an upgrade, the correct file was copied over.
 */
	    if (!$upgrade)
	    {
/*
 *		First, the new actpro.php file (v12.3)
 */
 		$f = fopen(RLC_SQL_DBDESC, "w");
		if ($f)
		{
			fwrite($f, "<"."? php exit(); ?".">\n");
			fwrite($f, $dbhost."\n");
			fwrite($f, $dbport."\n");
			fwrite($f, $dbname."\n");
			fwrite($f, $dbuser."\n");
			fwrite($f, $dbpw."\n");
			fwrite($f, $isv."\n");
			fclose($f);
		}
		else
		{
			echo "Could not open ".RLC_SQL_DBDESC." database file";
		}
/*
 *		Now the old rlmact.mysql file.  This gets deleted after
 *		copying to cgi-bin below.
 */
 		$f = fopen(RLC_SQL_DBDESC_OLD, "w");
		if ($f)
		{
			fwrite($f, $dbhost."\n");
			fwrite($f, $dbport."\n");
			fwrite($f, $dbname."\n");
			fwrite($f, $dbuser."\n");
			fwrite($f, $dbpw."\n");
			fwrite($f, $isv."\n");
			fclose($f);
		}
		else
		{
			echo "Could not open ".RLC_SQL_DBDESC_OLD." database file";
		}
	    }
/*
 *	    9.4 - auto-detect where the cgi-bin directory is located.
 *	    (moved to setup in v12.1)
 */
 	  if (0)
	  {
	    $status = stat("../../cgi-bin");
	    if ($status) $cgibin = "../../cgi-bin";
	    else
	    {
		$status = stat("../cgi-bin");
		if ($status) $cgibin = "../cgi-bin";
		else
		{
			$status = stat("../../../cgi-bin");
			if ($status) $cgibin = "../../../cgi-bin";
			else $cgibin = "cgi-bin";
		}
	    }
	  }

	    delete($cgibin."/rlmact.mysql");
/*
 *	    v9.2 - license generator reads ISV.mysql, not rlmact.mysql
 */
	    delete($cgibin."/$isv.mysql");
	    copy(RLC_SQL_DBDESC_OLD, $cgibin."/$isv.mysql");
	    chmod($cgibin."/$isv.mysql", 0600);
	    delete(RLC_SQL_DBDESC_OLD);
/*
 *	    Copy the license generator.  
 *	    (v11.1) Don't copy the .gen file if it is there already - this 
 *			will handle an upgrade, too.
 */
	    $temp = sprintf("%s.gen", $isv);
	    $temp2 = sprintf("%s/%s", $cgibin, $temp);
	    $status = stat($temp2);
	    if (!$status)
	    {
 	        echo "<br>Copying license generator settings...<br>";
		touch($temp);		/* Create if it is not there */
		copy($temp, $temp2);
		chmod($temp2, 0600);
		delete($temp);
	    }

	    $temp = sprintf("%s_mklic", $isv);
	    $temp2 = sprintf("%s/%s", $cgibin, $temp);
	    touch($temp2);
	    chmod($temp2, 0777);
	    delete($temp2);
	
/*
 *	    v9.4 - if ISV_mklic is here, use it, otherwise
 *	    rename actpro_mklic to ISV_mklic in cgi-bin.
 *   
 *	    v10.1 - don't forget to check for .exe as well.
 */
	    $status = stat($temp);
	    if (!$status) $temp = $temp.".exe";

	    $status = stat($temp);
	    if (!$status) $temp = "actpro_mklic";
	    else $temp2 = $temp2.".exe";

	    $status = stat($temp);
	    if (!$status) 
	    {
		$temp = "actpro_mklic.exe";
		$temp2 = $temp2.".exe";
	    }

	    copy($temp, $temp2);
	    chmod($temp2, 0744);
	    delete($temp);

	    $lic = $cgibin."/".$isv.".lic";
	    $status = stat($lic);
/*
 *	    Only copy the license file if it wasn't there already.
 */
	    if (!$status)
	    {
	        copy("actpro.lic", $lic);
	        chmod($lic, 0600);
	    }
	    delete("actpro.lic");

/*
 *	    Next - Create the database.
 */

	    $sql = 0;
	    if ($upgrade)
	    {
		echo "Database already upgraded - skipping initialization<br>";
	    }
	    else
	    {
 		echo "<br>Initializing Activation Pro Database...<br>";
		$sql = mysqli_connect($dbhost, $dbuser, $dbpw, "", $dbport);
		if (mysqli_connect_error())
		{
			echo "ERROR: Can't connect to MySQL database server<br>";
			echo "SQL error: ".mysqli_connect_error()."<br>";
			exit(1);
		}

		$temp = sprintf("CREATE DATABASE IF NOT EXISTS %s", $dbname);
		$stat = mysqli_query($sql, $temp);
		if (!$stat)
		{
			echo "Error creating database".$dbname."<br>"
						.mysqli_error($sql)."<br>";
		}
		else
		{
			echo "Created database ".$dbname."...<br>";
		}
		rlc_mysql_close($sql);
		$sql = rlc_mysql_init($isv);

/*
 *		Now, create all the database tables
 */
		$count = count($sqlcmds);
		$createcount = count($sqltbl);
		for ($i = 0; $i < $count; $i++)
		{
			$stat = mysqli_query($sql, $sqlcmds[$i]);
			if (!$stat)
			{
				if ($i >= $createcount)
			    		echo "Error inserting in table <i>".
						$sqltblins[$i-$createcount].
						"</i>: ".
						mysqli_error($sql)."<br>";
				else
			    		echo "Error creating <i>".$sqltbl[$i].
						"</i> table<br>"
						.mysqli_error($sql)."<br>";
				     echo "SQL command: $sqlcmds[$i]<br>";
				     echo "status: $status<br>";
				     print_r($status); echo "<br>";
			}
			else
			{
				if ($i < $createcount)
					echo "Created table <i>".$sqltbl[$i].
								"</i>...<br>";
			}
		}
		$query = "INSERT INTO `setup` (`what`, `data`) VALUES ('cgi-bin', '".
								$cgibin."');";
		$stat = mysqli_query($sql, $query);
		if (!$stat)
		{
			echo "Error inserting cgi-bin in setup table<br>";
			echo mysqli_error($sql)."<br>";
		}
	    }
/*
 *	    Set all the file modes
 */
 	    echo "<br>Setting file modes...<br><br>";
/*
 *	    9.4+ - set everything to 0400, then change specific files to 0444
 */
	    $files = glob("*");
	    foreach ($files as $file) 
	    {
		if (!chmod($file, 0400))
			echo "WARNING: chmod 0400 of ".$file.
			    " failed.  Please change permission by hand.<br>";
	    }


	    chmod("images", 0777);
	    $count = count($files444);
	    for ($i = 0; $i < $count; $i++)
	    {
		if (!chmod($files444[$i], 0444))
			echo "WARNING: chmod 0444 of ".$files444[$i].
			    " failed.  Please change permission by hand.<br>";
	    }
	    chmod("images", 0755);
	    chmod("backups", 0700);
	    chmod("tmp", 0755);
	    chmod("rlmact.mysql", 0600);
	    chmod("actpro.php", 0600);
/*
 *	    Set up the admin account and password
 */
 	    if (!$upgrade)
	    {

 		echo "Setting up admin user ...<br>";
		$time = time();
		$temp = sprintf("INSERT INTO users (username, password, ".
			"userlevel, timestamp, vistabs) VALUES (\"%s\", \"%s\", 9, %d, 63)", 
						$admin, md5($adminpw), $time);
		if ($sql == 0) $sql = rlc_mysql_init($isv);
		$stat = mysqli_query($sql, $temp);
		if (!$stat)
		{
			echo "Error creating admin user<br>"
					.mysqli_error($sql)."<br>";
		}
		else
		{
			echo "Created admin user ".$admin."...<br>";
		}

		echo "RLM Activation database set up for ISV ".$isv."<br><br>";
	    } 
	}

	if ($sql) rlc_mysql_close($sql);

/*
 *	Make sure setup_finish.php goes back to the right place.
 */

	if (array_key_exists("backto", $_POST))
	{
		rlc_web_hidden("backto", $_POST['backto']);
		rlc_web_hidden("backtotext", "Continue Installation");
	}
	else
	{
		rlc_web_hidden("backto", "../actpro/index.php");
		rlc_web_hidden("backtotext", "Done - Start RLC");
	}

	rlc_web_hidden("phase", 4);
	rlc_web_hidden("isv", $isv);
	finish_page("Next - Clean up Installation Files", 0, 0);
?>
