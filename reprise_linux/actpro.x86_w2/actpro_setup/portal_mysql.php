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

 	$Id: portal_mysql.php,v 1.7 2017/06/24 03:19:18 matt Exp $

 *****************************************************************************/

/*	
 *	RLM activation MySQL interface for rlc customer portal
 */


define("MAX_SQL_QUERY", 1000);	/* Queries are always < 1000 bytes long */
define("RLC_SQL_DBDESC", "actpro.php");
define("RLC_SQL_DBDESC_OLD", "rlmact.mysql");
define("RLC_DBHEADER", "mattchr_");

define("QUERY_LIC", "SELECT * FROM licf WHERE (id = %d)");
define("QUERY_PROD", "SELECT * FROM prod join portal_keyd_%d on (prod.id=portal_keyd_%d.product_id  OR prod.prod_id=portal_keyd_%d.product_id) WHERE (id = %d)");
define("QUERY_KEY", "SELECT * FROM portal_keyd_%d WHERE (akey = \"%s\")");
define("QUERY_KEY_BY_PROD", "SELECT * FROM portal_keyd_%d WHERE (product_id = %d)");
define("QUERY_KEY_FULFILL", "SELECT * FROM keyf WHERE (akey = \"%s\")");
define("QUERY_ALL_PROD", "SELECT prod.* FROM prod join portal_keyd_%d on (prod.id=portal_keyd_%d.product_id OR prod.prod_id=portal_keyd_%d.product_id)");
define("QUERY_ALL_CUST", "SELECT * FROM `contact` LEFT JOIN `company` USING (company_id)");
define("QUERY_ALL_COMPANIES", "SELECT * FROM `company`");
define("QUERY_ALL_REPORTCOLS", "SELECT * FROM `report_cols` %s ORDER BY `displayorder`");
define("QUERY_ALL_AKEY", "SELECT portal_keyd_%d.*,prod.name FROM `prod` STRAIGHT_JOIN `portal_keyd_%d` ON prod.id = portal_keyd_%d.product_id %s %s");
define("QUERY_ALL_AKEY_WITH_CONTACT", "SELECT portal_keyd_%d.*,prod.name,prod.product,prod.version,prod.lictype,keyf.num_revoked,keyf.num,contact.*,company.* FROM `keyf` RIGHT JOIN `portal_keyd_%d` on (keyf.akey = portal_keyd_%d.akey) LEFT JOIN `prod` ON (prod.id = portal_keyd_%d.product_id) LEFT JOIN `contact` ON (contact.contact_id = portal_keyd_%d.contact_id) LEFT JOIN `company` on (contact.company_id = company.company_id) %s %s");
define("QUERY_SETUP", "SELECT data FROM setup WHERE what=\"%s\"");
/*
 *	Join the fulfillment tables with the view of keyd, so we only
 *	get fulfillments on our keys.
 */
define("QUERY_ALL_FULFILL", "SELECT * FROM prod LEFT JOIN licf ON prod.id = licf.product_id JOIN portal_keyd_%d ON licf.akey = portal_keyd_%d.akey WHERE (revoked=0) %s");
define("QUERY_ALL_FULFILL_SELECT", "SELECT * FROM prod LEFT JOIN licf ON prod.id = licf.product_id JOIN portal_keyd_%d ON licf.akey = portal_keyd_%d.akey %s AND revoked=0 %s");

define("QUERY_DBSIZE", "SELECT table_schema %s, sum( data_length + index_length ) / 1024 / 1024 'DB Size' FROM information_schema.TABLES GROUP BY table_schema");

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

function portal_mysql_close($id, $db="")
{
	if ($id > 0)
	{
	    $temp = sprintf("DROP VIEW portal_keyd_%d", $id);
	    $res = mysqli_query($db, $temp);
	    $temp = sprintf("DROP VIEW portal_cust_%d", $id);
	    $res = mysqli_query($db, $temp);
	}
	mysqli_close($db);
}
/*
 *	rlc_mysql_init() - initialize connection to mysql server
 */

function portal_mysql_init($id, &$isv, $db="")
{
/*
 *	Locate the MySQL database
 */

	$host = "localhost";
	$port = 3306;
	$dbuser = "mysql";
	$dbpw = "mysql";
	$data = file(RLC_SQL_DBDESC);
	$isv = "";
	$offset = 1;
	if ($data[0] == "")
	{
	    $data = file(RLM_SQL_DBDESC_OLD);
	    $offset = 0;
	}
	if ($data[$offset] != "") $host = rtrim($data[$offset+0]);
	if ($data[$offset+1] != "") $port = rtrim($data[$offset+1]);
	if ($data[$offset+2] != "") $db = rtrim($data[$offset+2]);
	if ($data[$offset+3] != "") $dbuser = rtrim($data[$offset+3]);
	if ($data[$offset+4] != "") $dbpw = rtrim($data[$offset+4]);
	if ($data[$offset+5] != "") $isv = rtrim($data[$offset+5]);

	$sql = mysqli_connect($host, $dbuser, $dbpw, $db, $port);
	///// echo "Connecting to database $host, $dbuser, $db, $port<br>";
	if (mysqli_connect_error())
	{
		echo "ERROR: Can't connect to MySQL database server<br>";
		echo "mysqli_connect() error: ".mysqli_connect_error()."<br>";
	}
/*
 *	Now, create the view for this user.
 */

	if ($id > 0)
	{
/*
 *	    First, join the company and customer tables to get the list 
 *	    of contacts for this company.  Then, create the view by 
 *	    joining the new contact table with the keyd table.
 */
	    $temp = sprintf("CREATE ALGORITHM=TEMPTABLE VIEW portal_cust_%d as select contact_id from contact where company_id=%d", $id, $id);
	    $res = mysqli_query($sql, $temp);

	    $temp = sprintf("CREATE ALGORITHM=TEMPTABLE VIEW portal_keyd_%d AS select keyd.* from keyd join portal_cust_%d where keyd.contact_id=portal_cust_%d.contact_id", $id, $id, $id);
	    $res = mysqli_query($sql, $temp);
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
 *	Delete a single license fulfillment (license), return the fulfill count
 */


/*
 *	Read all the products, return in an array.
 */

function rlc_mysql_read_products($sql, &$products, &$lictype, &$license,
				  	&$version, &$version_type, &$active, 
					$sc, $sd, $primary)
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
			$num++;
		}
	}
	return($num);
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

function portal_mysql_read_key($id=-1, $sql, $akey)
{
	$temp = sprintf(QUERY_KEY, $id, $akey);
	$res = mysqli_query($sql, $temp);
	if (mysqli_num_rows($res) > 0)
	{
		if (($row = mysqli_fetch_array($res))) return($row);
		else return(0);
	}
	return(0);
}

function portal_mysql_get_keys($id=-1, $sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_AKEY, $id, $id, $id, $select, $sort);
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

function portal_mysql_get_products($id, $sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_PROD, $id, $id, $id);
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
}

/*
 *	Query all the license fulfillments for later retrieval.
 */

function portal_mysql_get_fulfillments($id, $sql, $select, &$res, $sc, $sd)
{
	$sort = rlc_mysql_sort($sc, $sd);
	if ($select != "")
		$temp = sprintf(QUERY_ALL_FULFILL_SELECT, $id, $id, $select, 
								$sort);
	else
		$temp = sprintf(QUERY_ALL_FULFILL, $id, $id, $sort);
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

function portal_mysql_num_keys($id=-1, $sql, $pid)
{
	$temp = sprintf(QUERY_KEY_BY_PROD, $id, $pid);
	$res = mysqli_query($sql, $temp);
	return(mysqli_num_rows($res));
}

/*
 *	Get the activation keys, with contacts.
 */

function portal_mysql_get_keys_with_contact($id=-1, $sql, &$res, $sc, $sd, $select)
{
	$sort = rlc_mysql_sort($sc, $sd);
	$temp = sprintf(QUERY_ALL_AKEY_WITH_CONTACT, $id, $id, $id, $id, $id,
							$select, $sort);
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
