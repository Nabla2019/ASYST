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

 	$Id: rlc_mysql.php,v 1.39 2017/10/04 02:20:39 matt Exp $

 *****************************************************************************/

/*	
 *	RLM activation MySQL interface for rlc
 */


define("MAX_SQL_QUERY", 1000);	/* Queries are always < 1000 bytes long */
define("RLC_SQL_DBDESC", "actpro.php");
define("RLC_SQL_DBDESC_OLD", "rlmact.mysql");
define("RLC_DBHEADER", "mattchr_");

define("INSERT_AUDIT", "INSERT INTO `audit` (date, who, what, tablekey, tablename) VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\")");
define("DELETE_AKEY", "DELETE FROM `keyd` WHERE (akey = \"%s\")");
define("DELETE_KEYF", "DELETE FROM `keyf` WHERE (akey = \"%s\")");
define("DELETE_BLACKLIST", "DELETE FROM `blacklist` WHERE (id = %d)");
define("DELETE_CONTACT", "DELETE FROM `contact` WHERE (contact_id = %d)");
define("DELETE_COMPANY", "DELETE FROM `company` WHERE (company_id = %d)");
define("DELETE_PROD", "DELETE FROM `prod` WHERE (id = %d)");

define("INSERT_BLACKLIST", "INSERT INTO `blacklist` (id, domain, type) VALUES (NULL, \"%s\", %d)");
define("DELETE_LIC", "DELETE FROM licf WHERE (id = %d)");
define("MERGE_COMPANY1","UPDATE contact SET company_id=%d where company_id=%d");
define("MERGE_CONTACT1", "UPDATE keyd SET contact_id=%d where contact_id=%d");
define("MERGE_CONTACT2", "UPDATE users SET contact_id=%d where contact_id=%d");
define("QUERY_LIC", "SELECT * FROM licf WHERE (id = %d)");
define("QUERY_PROD", "SELECT * FROM prod WHERE (id = %d)");
define("QUERY_KEY", "SELECT * FROM keyd WHERE (akey = \"%s\")");
define("QUERY_KEY_BY_PROD", "SELECT * FROM keyd WHERE (product_id = %d)");
define("QUERY_FULFILL_BY_PROD", "SELECT * FROM licf WHERE (product_id = %d)");
define("QUERY_KEY_FULFILL", "SELECT * FROM keyf WHERE (akey = \"%s\")");
define("QUERY_ALL_BLACK", "SELECT * FROM `blacklist` %s");
define("QUERY_ALL_PROD", "SELECT * FROM `prod`");
define("QUERY_ALL_CONTACT_TYPES", "SELECT * FROM `contact_types` ORDER BY contact_type");
define("QUERY_ALL_CUST", "SELECT * FROM `contact` LEFT JOIN `company` USING (company_id)");
define("QUERY_ALL_COMPANIES", "SELECT * FROM `company`");
define("QUERY_ALL_CONTACTS", "SELECT * FROM contact ORDER BY contact");
define("QUERY_ALL_REPORTCOLS", "SELECT * FROM `report_cols` %s ORDER BY `displayorder`");
define("QUERY_ALL_AKEY", "SELECT keyd.*, prod.name FROM `prod` STRAIGHT_JOIN `keyd` ON prod.id = keyd.product_id %s %s");
define("QUERY_ALL_AKEY_WITH_CONTACT", "SELECT keyd.*,prod.name,prod.product,prod.version,prod.lictype,keyf.num_revoked,keyf.num,contact.*,company.* FROM `keyf` RIGHT JOIN `keyd` on (keyf.akey = keyd.akey) LEFT JOIN `prod` ON (prod.id = keyd.product_id) LEFT JOIN `contact` ON (contact.contact_id = keyd.contact_id) LEFT JOIN `company` on (contact.company_id = company.company_id) %s %s");

define("QUERY_SETUP", "SELECT data FROM setup WHERE what=\"%s\"");
define("QUERY_ALL_FULFILL", "SELECT * FROM prod LEFT JOIN licf ON prod.id = licf.product_id LEFT JOIN keyd ON licf.akey = keyd.akey LEFT JOIN contact ON keyd.contact_id=contact.contact_id LEFT JOIN company ON contact.company_id=company.company_id WHERE (revoked=0) %s");
define("QUERY_ALL_FULFILL_SELECT", "SELECT * FROM prod LEFT JOIN licf ON prod.id = licf.product_id LEFT JOIN keyd ON licf.akey = keyd.akey LEFT JOIN contact ON keyd.contact_id=contact.contact_id LEFT JOIN company ON contact.company_id=company.company_id %s AND revoked=0 %s");
define("QUERY_DBSIZE", "SELECT table_schema %s, sum( data_length + index_length ) / 1024 / 1024 'DB Size' FROM information_schema.TABLES GROUP BY table_schema");
define("UPDATE_PROD", "REPLACE INTO prod (id, active, obsolete, name, version, version_type, upgrade_version, exp, lictype, issued, add_cust, add_akey, product, misc, generator, prod_id, nlic, prod_allowed_hostids, pcreate, ash_type, ash_tolerance, lictext) VALUES (%d, %d, %d, \"%s\", \"%s\", %d, \"%s\", \"%s\", %d, %d, %d, %d, \"%s\", \"%s\", %d, %d, %d, %d, \"%s\", %d, %d, \"%s\")");
define("UPDATE_PROD_NAME", "UPDATE prod SET name = \"%s\" where prod_id = %d OR id = %d");
define("UPDATE_KEY", "REPLACE INTO keyd (akey, active, product_id, count, type, rehosts, lastdate, exp, kver, kver_type, white, misc, notes, contact_id, key_allowed_hostids, kcreate, ash_sn, user_def, sub_interval, sub_window) VALUES (\"%s\", %d, %d, %d, %d, %d, \"%s\", \"%s\", \"%s\", %d, \"%s\", \"%s\", \"%s\", %d, %d, \"%s\", %d, \"%s\", %d, %d)");
define("UPDATE_KEYF", "UPDATE keyf SET num = %d WHERE akey = \"%s\"");
define("UPDATE_SETUP", "REPLACE INTO setup (what, data) VALUES (\"%s\", \"%s\")");
define("DELETE_SETUP", "DELETE FROM `setup` WHERE (what = \"%s\")");
define("WRITE_KEY", "INSERT INTO keyd (akey, active, product_id, count, type, rehosts, lastdate, exp, kver, kver_type, white, misc, notes, contact_id, key_allowed_hostids, kcreate, sub_interval, sub_window) VALUES (\"%s\", %d, %d, %d, %d, %d, \"%s\", \"%s\", \"%s\", %d, \"%s\", \"%s\", \"%s\", %d, %d, \"%s\", %d, %d)");

define("WRITE_CONTACT", "INSERT INTO contact (contact, contact_type, title, phone, fax, email, info, company_id, ccreate) VALUES (\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d, \"%s\")");

define("UPDATE_CONTACT", "REPLACE INTO contact (contact_id, contact, contact_type, title, phone, fax, email, info, company_id, ccreate) VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d, \"%s\")");

define("WRITE_COMPANY", "INSERT INTO company (company, addr1, addr2, addr3, city, state, zip, country, c_notes, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10) VALUES (\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\")");

define("UPDATE_COMPANY", "REPLACE INTO company (company_id, company, addr1, addr2, addr3, city, state, zip, country, c_notes, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10) VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\")");

define("WRITE_LICF", "INSERT INTO licf (akey, product_id, count, time, license_hostid, reference_hostid, expdate, hostname, remote_host, log, license, last_fulfill, num_fulfills, revoked, revoke_time, last_check) VALUES (\"%s\", %d, %d, %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d, %d, %d, %d, %d)");

define("WRITE_KEYF", "INSERT INTO keyf (akey, num, date, lasthostid, num_revoked) VALUES (\"%s\", %d, \"%s\", \"%s\", %d)");

function _rlc_act_quote_string($in, &$out)
{
	$out = " ";
	$inlen = strlen($in);
	if ($inlen == 0)
	{
		$out = "";
		return;
	}
	$p = 0;  $q = 0; $last='a';
	while ($p < $inlen)
	{
		if (($in[$p] == '"') && ($last != '\\')) $out[$q++] = '\\';
		$last = $in[$p];
		$out[$q++] = $in[$p++];
	}
}

function rlc_mysql_close($db="")
{
	mysqli_close($db);
}
/*
 *	rlc_mysql_init() - initialize connection to mysql server
 */

function rlc_mysql_init(&$isv, $db="", $dbdesc=RLC_SQL_DBDESC)
{
/*
 *	Locate the MySQL database
 */

	$host = "localhost";
	$port = 3306;
	$dbuser = "mysql";
	$dbpw = "mysql";
	$errlevel = rlc_turn_off_warnings();
	$data = file($dbdesc);
	error_reporting($errlevel);
	$isv = "";
	if (count($data) > 6) $offset = 1;
	else
	{
	    $errlevel = rlc_turn_off_warnings();
	    $data = file($dbdesc);
	    error_reporting($errlevel);
	    $offset = 0;
	}
	if ($data[$offset] != "") $host = rtrim($data[$offset+0]);
	if ($data[$offset+1] != "") $port = rtrim($data[$offset+1]);
	if ($data[$offset+2] != "") $db = rtrim($data[$offset+2]);
	if ($data[$offset+3] != "") $dbuser = rtrim($data[$offset+3]);
	if ($data[$offset+4] != "") $dbpw = rtrim($data[$offset+4]);
	if ($data[$offset+5] != "") $isv = rtrim($data[$offset+5]);

	$sql = mysqli_connect($host, $dbuser, $dbpw, $db, $port);
	//// echo "Connecting to database $host, $dbuser, $db, $port<br>";
	if (mysqli_connect_error())
	{
		echo "ERROR: Can't connect to MySQL database server<br>";
		echo "mysqli_connect() error: ".mysqli_connect_error()."<br>";
	}
	return($sql);
}

/*
 *	Create the sort string for the select statement.
 */

function rlc_mysql_sort($sc, $sd)
{
	if ($sc != "")
	{
		return(sprintf("ORDER BY %s %s", $sc, $sd == "d" ? "DESC" : 
									"ASC"));
	}
	else return("");
}

/*
 *	Merge companies - set all contacts from old company to new one.
 */

function rlc_mysql_merge_company($sql, $new, $old)
{
	$temp = sprintf(MERGE_COMPANY1, $new, $old);
	$res = mysqli_query($sql, $temp);
	return($res);
}

/*
 *	Merge contacts - set all contacts from akey and users tables to new
 */

function rlc_mysql_merge_contact($sql, $new, $old)
{
	$temp = sprintf(MERGE_CONTACT1, $new, $old);
	$res = mysqli_query($sql, $temp);
	if ($res)
	{
	    $temp = sprintf(MERGE_CONTACT2, $new, $old);
	    $res = mysqli_query($sql, $temp);
	}
	return($res);
}

/*
 *	Read a single product line
 */

function rlc_mysql_read_prod($sql, $product_id)
{
	$temp = sprintf(QUERY_PROD, $product_id);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) return($row);
		else return(0);
	}
	return(0);
}

/*
 *	Read a single license fulfillment (license)
 */

function rlc_mysql_get_license($sql, $fulfill_id)
{
	$temp = sprintf(QUERY_LIC, $fulfill_id);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) return($row);
		else return(0);
	}
	return(0);
}

/*
 *	Delete a contact or company
 */

function rlc_mysql_del_contact($sql, $id)
{
	$temp = sprintf(DELETE_CONTACT, $id);
	$res = mysqli_query($sql, $temp);
	return($res);
}

function rlc_mysql_del_company($sql, $id)
{
	$temp = sprintf(DELETE_COMPANY, $id);
	$res = mysqli_query($sql, $temp);
	return($res);
}


/*
 *	Delete a single license fulfillment (license), return the fulfill count
 */

function rlc_mysql_del_fulfill($sql, $fulfill_id)
{
	$temp = sprintf(QUERY_LIC, $fulfill_id);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) 
		{
			$count = ($row['count']);
			$temp = sprintf(DELETE_LIC, $fulfill_id);
			$res = mysqli_query($sql, $temp);
			return($count);
		}
	}
	return(-1);
}

/*
 *	Read all the products, return in an array.
 */

function rlc_mysql_read_products($sql, &$products, &$lictype, &$license,
				  	&$version, &$version_type, &$active, 
					&$obsolete, $sc, $sd, $primary)
{
	$num = 0;
	if ($primary) $sel = "WHERE prod_id = 0";
	else $sel = "";
	$stat = rlc_mysql_get_products($sql, $res, $sc, $sd, $sel);
	if ($stat == 0)
	{
		while ($row = mysqli_fetch_array($res))
		{
			$products[$row['id']] = $row['name'];
			$lictype[$row['id']] = $row['lictype'];
			$license[$row['id']] = $row['product'];
			$version[$row['id']] = $row['version'];
			$version_type[$row['id']] = $row['version_type'];
			$active[$row['id']] = $row['active'];
			$obsolete[$row['id']] = $row['obsolete'];
			$num++;
		}
	}
	return($num);
}

/*
 *	Read all the contact types, return in an array.
 */

function rlc_mysql_get_contact_types($sql, &$res)
{
	$temp = QUERY_ALL_CONTACT_TYPES;
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(RLM_ACT_NO_ROWS);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

/*
 *	Read all the report columns, return in an array.
 */

function rlc_mysql_read_report_cols($sql, &$reportcols, $select, &$tablecolumn,
							&$display, &$is_int)
{
	$num = 0;
	$temp = sprintf(QUERY_ALL_REPORTCOLS, $select);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(0);
	}
	if (mysqli_num_rows($res) > 0)
	{
	    $lastdisplay = -1;
	    while ($row = mysqli_fetch_array($res))
	    {
	        /* Toss dups */
	    	if ($lastdisplay == $row['displayorder']) continue;  
		
	    	$lastdisplay = $row['displayorder'];  
		$tablecolumn[$num] = $row['tablecolumn'];
		$display[$num] = $row['display'];
		$is_int[$num] = $row['is_int'];
		$num++;
	    }
	}
	else
	{
		echo "ERROR: No matching report column definitions<br>";
		echo "<br>Query is ".$temp."<br>";
	}
	return($num);
}

/*
 *	Read the blacklist for later retrieval.
 */

function rlc_mysql_get_black($sql, &$res, $sc, $sd)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_BLACK, $sort);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(-1);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

/*
 *	Delete an activation key
 */

function rlc_mysql_del_akey($sql, $id)
{
	$temp = sprintf(DELETE_AKEY, $id);
	$res = mysqli_query($sql, $temp);
	if ($res)
	{
		$temp = sprintf(DELETE_KEYF, $id);
		$res = mysqli_query($sql, $temp);
	}
	return($res);
}

/*
 *	Delete a blacklist entry
 */

function rlc_mysql_del_black($sql, $id)
{
	$temp = sprintf(DELETE_BLACKLIST, $id);
	$res = mysqli_query($sql, $temp);
	return($res);
}

/*
 *	Delete a product definition
 */

function rlc_mysql_del_prod($sql, $id)
{
	$temp = sprintf(DELETE_PROD, $id);
	$res = mysqli_query($sql, $temp);
	return($res);
}

/*
 *	Add an audit entry
 */

function rlc_mysql_add_audit($sql, $who, $what, $key, $table)
{
	$time = time();
	$temp = sprintf(INSERT_AUDIT, $time, $who, $what, $key, $table);
	$res = mysqli_query($sql, $temp);
	return($res);
}
/*
 *	Add a blacklist entry
 */

function rlc_mysql_add_black($sql, $domain, $type)
{
	$temp = sprintf(INSERT_BLACKLIST, $domain, $type);
	$res = mysqli_query($sql, $temp);
}

function rlc_mysql_read_key($sql, $akey)
{
	$temp = sprintf(QUERY_KEY, $akey);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) return($row);
		else return(0);
	}
	return(0);
}

function rlc_mysql_write_prod($sql, $p, &$prod_id)
{
	_rlc_act_quote_string($p['misc'], $misc);
	$temp = sprintf(UPDATE_PROD, $p['id'], $p['active'], $p['obsolete'],
				$p['name'], $p['version'], $p['version_type'],
				$p['upgrade_version'],
				$p['exp'], $p['lictype'],
				$p['issued'], $p['add_cust'], $p['add_akey'], 
				$p['product'], $misc, $p['generator'], 
				$p['prod_id'], $p['nlic'], 
				$p['prod_allowed_hostids'], $p['pcreate'], 
				$p['ash_type'], $p['ash_tolerance'], 
				$p['lictext']);
	$res = mysqli_query($sql, $temp);
	$prod_id = mysqli_insert_id($sql);
	return($res);
}

/*
 *	Update the product name in all non-primary license product entries.
 *	used when editing the product name in the primary license.
 */
function rlc_mysql_update_prod_name($sql, $name, $pid)
{
	$temp = sprintf(UPDATE_PROD_NAME, $name, $pid, $pid);
	$res = mysqli_query($sql, $temp);
	return($res);
}

function rlc_mysql_update_key($sql, $k)
{
	_rlc_act_quote_string($k['white'], $white);
	_rlc_act_quote_string($k['misc'], $misc);
	_rlc_act_quote_string($k['notes'], $notes);
	_rlc_act_quote_string($k['user_def'], $user_def);
	$temp = sprintf(UPDATE_KEY, $k['akey'], $k['active'], $k['product_id'],
				$k['count'], $k['type'], $k['rehosts'],
				$k['lastdate'], $k['exp'], $k['kver'], 
				$k['kver_type'], $white, $misc, $notes,
				$k['contact_id'], $k['key_allowed_hostids'],
				$k['kcreate'], $k['ash_sn'], $user_def, 
				$k['sub_interval'], $k['sub_window']);
	$res = mysqli_query($sql, $temp);
	return($res);
}

function rlc_mysql_write_key($sql, $k)
{
	_rlc_act_quote_string($k['white'], $white);
	_rlc_act_quote_string($k['misc'], $misc);
	_rlc_act_quote_string($k['notes'], $notes);
	$temp = sprintf(WRITE_KEY, $k['akey'], $k['active'], $k['product_id'],
				$k['count'], $k['type'], $k['rehosts'],
				$k['lastdate'], $k['exp'], $k['kver'],
				$k['kver_type'], $white, $misc, $notes, 
				$k['contact_id'], $k['key_allowed_hostids'],
				$k['kcreate'], $k['sub_interval'], 
				$k['sub_window']);
	$res = mysqli_query($sql, $temp);
	if ($res == 1) return(0);
	else return(-1);
}

function rlc_mysql_write_licf($sql, $licf)
{
	_rlc_act_quote_string($licf['akey'], $akey);
	_rlc_act_quote_string($licf['license_hostid'], $license_hostid);
	_rlc_act_quote_string($licf['reference_hostid'], $reference_hostid);
	_rlc_act_quote_string($licf['expdate'], $expdate);
	_rlc_act_quote_string($licf['hostname'], $hostname);
	_rlc_act_quote_string($licf['remote_host'], $remote_host);
	_rlc_act_quote_string($licf['log'], $log);
	_rlc_act_quote_string($licf['license'], $license);
	$temp = sprintf(WRITE_LICF, $akey, $licf['product_id'],
		$licf['count'], $licf['time'], $license_hostid,
		$reference_hostid, $expdate, $hostname, $remote_host,
		$log, $license, $licf['last_fulfill'], $licf['num_fulfills'],
		$licf['revoked'], $licf['revoke_time'], $licf['last_check']);
	$res = mysqli_query($sql, $temp);
	if ($res == 1) return(0);
	else return(-1);
}

function rlc_mysql_write_keyf($sql, $keyf)
{
	_rlc_act_quote_string($keyf['akey'], $akey);
	_rlc_act_quote_string($keyf['date'], $date);
	_rlc_act_quote_string($keyf['lasthostid'], $lasthostid);
	$temp = sprintf(WRITE_KEYF, $akey, $keyf['num'], $date, $lasthostid,
		$keyf['num_revoked']);
	$res = mysqli_query($sql, $temp);
	if ($res == 1) return(0);
	else return(-1);
}

function rlc_mysql_write_cust($sql, $contact)
{
	_rlc_act_quote_string($contact['contact'], $name);
	_rlc_act_quote_string($contact['contact_type'], $contact_type);
	_rlc_act_quote_string($contact['title'], $title);
	_rlc_act_quote_string($contact['phone'], $phone);
	_rlc_act_quote_string($contact['fax'], $fax);
	_rlc_act_quote_string($contact['email'], $email);
	_rlc_act_quote_string($contact['info'], $info);
	$contact_id = $contact['contact_id'];
	if ($contact_id == 0)
		$temp = sprintf(WRITE_CONTACT, $name, $contact_type,
						$title, $phone, $fax,
						$email, $info, 
						$contact['company_id'],
						$contact['ccreate']);
	else
		$temp = sprintf(UPDATE_CONTACT, $contact_id, $name, 
						$contact_type, $title, 
						$phone, $fax, $email, $info, 
						$contact['company_id'],
						$contact['ccreate']);
	$res = mysqli_query($sql, $temp);
	return($res);
}

function rlc_mysql_write_company($sql, $company)
{
	_rlc_act_quote_string($company['company'], $name);
	_rlc_act_quote_string($company['addr1'], $addr1);
	_rlc_act_quote_string($company['addr2'], $addr2);
	_rlc_act_quote_string($company['addr3'], $addr3);
	_rlc_act_quote_string($company['city'], $city);
	_rlc_act_quote_string($company['state'], $state);
	_rlc_act_quote_string($company['zip'], $zip);
	_rlc_act_quote_string($company['country'], $country);
	_rlc_act_quote_string($company['c_notes'], $c_notes);
	_rlc_act_quote_string($company['u1'], $u1);
	_rlc_act_quote_string($company['u2'], $u2);
	_rlc_act_quote_string($company['u3'], $u3);
	_rlc_act_quote_string($company['u4'], $u4);
	_rlc_act_quote_string($company['u5'], $u5);
	_rlc_act_quote_string($company['u6'], $u6);
	_rlc_act_quote_string($company['u7'], $u7);
	_rlc_act_quote_string($company['u8'], $u8);
	_rlc_act_quote_string($company['u9'], $u9);
	_rlc_act_quote_string($company['u10'], $u10);
	$company_id = $company['company_id'];
	if ($company_id == 0)
	    $temp = sprintf(WRITE_COMPANY, $name, $addr1, $addr2, $addr3, 
	    					$city, $state, $zip, $country, 
						$c_notes,
						$u1, $u2, $u3, $u4, $u5, 
						$u6, $u7, $u8, $u9, $u10);
	else
	    $temp = sprintf(UPDATE_COMPANY, $company_id, $name, $addr1, 
	    					$addr2, $addr3, $city, $state, 
						$zip, $country, $c_notes, $u1, 
						$u2, $u3, $u4, $u5,
						$u6, $u7, $u8, $u9, $u10);
	$res = mysqli_query($sql, $temp);
	return($res);
}

function rlc_mysql_get_keys($sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_AKEY, $select, $sort);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		echo "MySQL error ".mysqli_error($sql)."<br>";
		return(RLM_ACT_NO_KEY);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

function rlc_mysql_update_keyf($sql, $key, $count)
{
	$k = rlc_mysql_get_fulfilled($sql, $key);
	if ($k) 
	{
		$num = $k['num'];
		$numfulfilled = $num - $count;
		if ($numfulfilled < 0) $numfulfilled = 0;
		_rlc_act_quote_string($key, $akey);
		$temp = sprintf(UPDATE_KEYF, $numfulfilled, $akey);
	/*	echo "<br>mysql command is ".$temp."<br>";	/**/
		$res = mysqli_query($sql, $temp);
		if ($res == 1) return(0);
		else 
			echo "update of count in activation key record failed: "
						.mysqli_error($sql)."<br>";
	}
	return(-1);
}

function rlc_mysql_get_table($sql, &$res, $query)
{
	$res = mysqli_query($sql, $query);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$query."</i></b><br>";
		return(RLM_ACT_BAD_QUERY);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
	else
	{
		return(RLM_ACT_NO_ROWS);
	}
}

/*
 *	Query all the products for later retrieval.
 */

function rlc_mysql_get_products($sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = QUERY_ALL_PROD;
	if ($select != "") $temp = $temp." ".$select;
	if ($sort != "") $temp = $temp." ".$sort;
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(RLM_ACT_NO_PROD);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

/*
 *	Query all the customers for later retrieval.
 */

function rlc_mysql_get_customers($sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = QUERY_ALL_CUST;
	if ($select != "") $temp = $temp." ".$select;
	if ($sort != "") $temp = $temp." ".$sort;
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(-1);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
	return(-2);
}

/*
 *	Query all the companies for later retrieval.
 */

function rlc_mysql_get_companies($sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = QUERY_ALL_COMPANIES;
	if ($select != "") $temp = $temp." ".$select;
	if ($sort != "") $temp = $temp." ".$sort;
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(-1);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
	return(-2);
}

/*
 *	Query all the contacts for later retrieval.
 */

function rlc_mysql_get_contacts($sql, &$res)
{
	$res = mysqli_query($sql, QUERY_ALL_CONTACTS);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(-1);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

/*
 *	Query all the license fulfillments for later retrieval.
 */

function rlc_mysql_get_fulfillments($sql, $select, &$res, $sc, $sd)
{
	$sort = rlc_mysql_sort($sc, $sd);
	if ($select != "")
		$temp = sprintf(QUERY_ALL_FULFILL_SELECT, $select, $sort);
	else
		$temp = sprintf(QUERY_ALL_FULFILL, $sort);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>" .$temp. "</i></b><br>";
		return(-1);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
	else
	{
		return(-2);
	}
}


function rlc_mysql_get_fulfilled($sql, $akey)
{
	$temp = sprintf(QUERY_KEY_FULFILL, $akey);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) return($row);
		else return(0);
	}
	return(0);
}

/*
 *	Write the setup data out
 */

function rlc_mysql_write_setup($sql, $what, $val)
{
	_rlc_act_quote_string($val, $qval);
	$temp = sprintf(UPDATE_SETUP, $what, $qval);
	$res = mysqli_query($sql, $temp);
}

/*
 *	Delete a setup data item
 */

function rlc_mysql_delete_setup($sql, $what)
{
	$temp = sprintf(DELETE_SETUP, $what);
	$res = mysqli_query($sql, $temp);
}

/*
 *	Read setup data
 */

function rlc_mysql_read_rlc_setup($sql, $what, &$s)
{
	$s['url'] = "";
	$temp = sprintf(QUERY_SETUP, $what);
	$e = rlc_turn_off_warnings();
	$res = mysqli_query($sql, $temp);
	error_reporting($e);
	if ($res)
	{
	    $cols = mysqli_num_rows($res);
	    if ($cols == 1)
	    {
		$row = mysqli_fetch_array($res);
	 	$s[$what] = $row[0];
	    }
	}
}

/*
 *	Return the number of activation keys present for a product.
 */

function rlc_mysql_num_keys($sql, $pid)
{
	$temp = sprintf(QUERY_KEY_BY_PROD, $pid);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		return(-1);
	}
	return(mysqli_num_rows($res));
}

/*
 *	Return the number of activation keys + fulfillments for a product.
 *	(Fix for P433)
 */

function rlc_mysql_num_keys_and_fulfill($sql, $pid)
{
	$keys = rlc_mysql_num_keys($sql, $pid);
	if ($keys < 0) $keys = 0;
	
	$temp = sprintf(QUERY_FULFILL_BY_PROD, $pid);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		$fills = 0;
	}
	else $fills = mysqli_num_rows($res);

	return($keys + $fills);
}

/*
 *	Get the keys with their contact person.
 */
function rlc_mysql_get_keys_with_contact($sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_AKEY_WITH_CONTACT, $select, $sort);
	$res = mysqli_query($sql, $temp);
	if (!$res)
	{
		echo "ERROR in MySQL query: <i><b>".$temp."</i></b><br>";
		echo "MySQL error ".mysqli_error($sql)."<br>";
		return(RLM_ACT_NO_KEY);
	}
	else if (mysqli_num_rows($res) > 0)
	{
		return(0);
	}
}

/*
 *	Get the database size
 */

function rlc_mysql_get_db_size($sql, $dbname)
{
	$temp = sprintf(QUERY_DBSIZE, $dbname);
	$res = mysqli_query($sql, $temp);
	while ($row = mysqli_fetch_array($res))
	{
		if (!strcmp($row[0], $dbname))
			return($row[1]);
	}
	return(0);
}

?>
