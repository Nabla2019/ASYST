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

        $Id: actpro_web_serv.php,v 1.17 2017/04/13 20:46:20 matt Exp $

 *****************************************************************************/

/*
 * Web services for access to the ActPro database
 */

include "login_db.php";
include "rlc_mysql.php";
include "rlc_akey.php";

/*
 *	Define the allowed ops on each table
 */
	$allowed_methods = array();
	$allowed_methods['prod'] = array("post", "get", "put", "delete");
	$allowed_methods['keyd'] = array("post", "get", "put", "delete");
	$allowed_methods['company'] = array("post", "get", "put", "delete");
	$allowed_methods['contact'] = array("post", "get", "put", "delete");
	$allowed_methods['licf'] = array("get", "delete");
	$allowed_methods['keyf'] = array("get", "delete");

/*
 *	Define the column names in each table
 */
	$cols = array();
	$cols['keyd'] = array("akey", "active", "product_id", "count", "type", 
		"rehosts", "lastdate", "exp", "kver", "kver_type", "white",
		"misc", "notes", "contact_id", "key_allowed_hostids", "kcreate",
		"ash_sn");
	$cols['licf'] = array("id", "akey", "product_id", "count", "time", 
		"license_hostid", "reference_hostid", "expdate", "hostname", 
		"remote_host", "log", "license", "last_fulfill", 
		"num_fulfills", "revoke", "revoke_time");
	$cols['prod'] = array("id", "active", "name", "version", 
		"version_type", "upgrade_version", "exp", "lictype", 
		"issued", "add_akey",
		"product", "misc", "generator", "prod_id", "nlic", 
		"prod_allowed_hostids", "pcreate", "ash_type", "ash_tolerance",
		"obsolete", "lictext");
	$cols['contact'] = array("contact_id", "contact", "title", "phone",
		"fax", "email", "info", "company_id", "ccreate", 
		"contact_type");
	$cols['company'] = array("company_id", "company", "addr1", "addr2",
		"addr3", "city", "state", "zip", "country", "c_notes",
		"u1","u2","u3","u4","u5","u6","u7","u8","u9","u10");
	$cols['keyf'] = array("akey", "num", "date", "lasthostid", 
		"num_revoked");


/*
 *	Define the tables which have an autoincrement ID column, so on an INSERT
 *	we know which tables to get IDs of newly-created for.
 */
	$autoinc = array("prod","company", "contact");



/*
 * Check the credentials passed in.   On return:
 *	0 means success
 *	1 means authentication failed (could be bad user or bad password)
 *	2 means insufficient privilege
 *
 * NOTE: password is an MD5 hash of the actual password.
 */
function authenticate_user($user, $password)
{
    global $database;
	$ok = $database->confirmUserPass($user, $password);
	if ($ok == 0) 
	{
		$userdata = $database->getUserInfo($user);
		if ($userdata != NULL)
		{
			$userlevel = $userdata['userlevel'];
			if (($userlevel == EDIT_LEVEL) || 
						($userlevel == ADMIN_LEVEL))
				return 0;
			else
				return 2;
		}
		return 1;
	}
	else
		return 1;
}

/*
 * Encode a response message as JSON and echo it.  If the caller indicates
 * it's done, ie , no more data is to be sent to the client, echo a "]",
 * closing the response array.  Otherwise echo a ",", setting up for
 * more response.
 */
function send_status($success, $message, $done)
{
	$respobj = new stdClass();
	if ($success)
		$respobj->status = "OK";
	else
		$respobj->status = "ERROR";
	$respobj->message = $message;
	$json_string = json_encode($respobj);
	echo "[";
	echo $json_string;
	if ($done)
		echo "]";
	else
		echo ",";
}

/*
 * Builds the WHERE clause of an SQL query.  Array keys in the post arg are
 *	column name, eg, akey
 */
function build_select($post)
{
  global $cols;

/*
 *	Define the operators that can be used in a query
 */
 	$operators = array(">", ">=", "=", "<", "<=", "<>", "LIKE", "REGEX");

	$gotwhere = 0;
	$select = " WHERE ";

/*
 *	Special case column name "sql_where" is an sql where clause - use it 
 *	verbatim
 */
	if (array_key_exists("sql_where", $post))
	{
		$select = $select.$post['sql_where'];
//echo $select;
		return ($select);
	}

	$table = $post['table'];
	$okcols = $cols[$table]; 
	$gotone = 0;
/*
 *	Our search term data in post looks like:
 *		$post[$col] = "[<operator> ]<value>" OR
 *		$post[$col] = array("[<operator> ]<value>", "[<operator> ]<value>",...)
 *		Operators are SQL operators ">", ">=", "=", "<", "<=", "<>", 
 *			and LIKE.
 *	If no operator is supplied, REGEXP is used as an operator.
 *	Multiple terms are ANDed together.
 */
	foreach ($okcols as $col)
	{
	    if (array_key_exists($col, $post))
	    {
		$terms = $post[$col];
		$singlequote = true;
/*
 *		If terms is not already an array make it an array of 
 *		size one for simplicity 
 */
		if (!is_array($terms))
		{
		    $new = array($terms);
		    $terms = $new;
		}
		foreach ($terms as $term)
		{
		    $op = "";
		    $value = "";
		    $n = sscanf($term, "%s %s", $op, $value);
		    if ($n == 1)
		    {
			    $value = $op;
			    $op = "REGEXP";
			    $singlequote = true;
		    }
		    else
		    {
			    $gotop = false;
			    foreach($operators as $oneop)
			    {
			    	if ($op == $oneop)
				{
				    $gotop = true;
				    break;
				}
			    }
			    if (!$gotop)
			    {
				$value = $term;
				$op = "REGEXP";
				$singlequote = true;
			    }
		    }
		    if ($singlequote)
			$value = "'".$value."'";
		    $term = $col." ".$op." ".$value;
		    if ($gotone > 0)
			    $select = $select." AND ";
		    else
			    $gotone = 1;
		    $select = $select.$term;
		}
	    }
	}
	if ($select == " WHERE ")
		$select = "";
//echo $select;
	return ($select);
}

/*
 *	Make sure all columns have values in a row
 */
function set_default_values($columns, $table, &$row)
{
	foreach ($columns[$table] as $col)
	{
		if (!array_key_exists($col, $row))
		{
			$row[$col] = "";
		}
	}
}



	header('Content-Type: application/json');
	$method = strtolower($_SERVER['REQUEST_METHOD']);
	if ($method != "post" && $method != "get" && $method != "put" && 
		$method != "delete")
	{
		send_status(FALSE, 
		    "HTTP request method must be POST, GET, PUT, or DELETE", 
		    TRUE);
		return;
	}

/*
 *	Get the message body, decode it from JSON, and get the header
 *	contents which tell us what to do.
 */
	$postdata = file_get_contents("php://input");
	$postobject = json_decode($postdata, TRUE);
	if ($postobject == null) {
		send_status(FALSE, "JSON decode error", TRUE);
		return;
	}
	if (!array_key_exists('header', $postobject))
	{
		send_status(FALSE, "header object not present", TRUE);
		return;
	}
	$header = $postobject['header'];
	if (!array_key_exists('user', $header) || 
		!array_key_exists('password', $header))
	{
		send_status(FALSE, "Username or password missing from header",
			TRUE);
		return;
	}
	$user = $header['user'];
	$password = $header['password'];
	$auth = authenticate_user($user, $password);
	if ($auth != 0)
	{
		if ($auth == 1)
			send_status(FALSE, 
				"Wrong user or password in header", TRUE);
		else
			send_status(FALSE, "Insufficient privilege", TRUE);
		return;
	}
	if (!array_key_exists('table', $header)) 
	{
		send_status(FALSE, "Table missing from header", TRUE);
		return;
	}
	$table = strtolower($header['table']);

/*
 *	Check for an HTTP method override in the header.  Salesforce
 *	doesn't allow GETs with a JSON body so it turns them into
 *	POSTs!
 */
	if (array_key_exists('method_override', $header))
	{
		$new_method = strtolower($header['method_override']);
		if ($new_method != "post" && $new_method != "get" && 
			$new_method != "put" && $new_method != "delete")
		{
			send_status(FALSE, 
			    "override method must be POST, GET, PUT, or DELETE",
			    TRUE);
			return;
		}
		$method = $new_method;
	}

/*
 *	Check that the table is one that we operate on, and that the method is
 *	allowed.
 */
	if (!array_key_exists($table, $allowed_methods))
	{
		$err = sprintf("Unsupported table %s", $table);
		send_status(FALSE, $err, TRUE);
		return;
	}
	$methods = $allowed_methods[$table];
	$methods_len = count($methods);
	$ok = 0;
	for ($i = 0; $i < $methods_len; $i++)
	{
		if ($method == $methods[$i])
		{
			$ok = 1;
			break;
		}
	}
	if ($ok != 1)
	{
		$err = sprintf("method %s not allowed in table %s", 
			$method, $table);
		send_status(FALSE, $err, TRUE);
		return;
	}
	
/*
 *	Connect to the SQL server
 */
	$isv = "";
	$sql = rlc_mysql_init($isv);
// TODO error check?

/*
 *	If the method is a post, get the data to be posted and post it
 */
	if ($method == "post")
	{
		if (!array_key_exists('data', $postobject)) 
		{
			send_status(FALSE, "data missing from message",
				TRUE);
			return;
		}
		$data = $postobject['data'];
		$rowcount = 0;
		$getid = false;
		$newid = "";
		foreach ($autoinc as $tab)
		{
			if ($table == $tab)
			{
				$getid = true;
				break;
			}
		}
		$generated_keys = array();
		foreach ($data as $row)
		{
/*
 *			Fill in values for unspecified columns
 */
			$status = 0;
			set_default_values($cols, $table, $row);
			if ($table == "keyd")
			{
/*
 *			    If no akey is supplied make one up and
 *			    save for return.
 */
			    if (!array_key_exists('akey', $row) || 
						$row['akey'] == "")
			    {
				$x = time();
				$s1 = sprintf("%04d", (($x + $row['product_id'] 
					+ $rowcount) & 0x1fff));
				$s2 = sprintf("%04d", (($x >> 13) & 0x1fff));
				$s3 = sprintf("%04d", rand() % 9999);
				$s4 = ($rowcount + rand()) % 9999;
				$akey = sprintf("%s-%s-%s-%04d", $s1,
							    $s2, $s3, $s4);
				$row['akey'] = $akey;
				$generated_keys[$rowcount] = $akey;
			    }
			    $row['kcreate'] = date("Y-m-d", time());
			    $status = rlc_mysql_write_key($sql, $row);
			}
			else if ($table == 'company')
			{
				$res = rlc_mysql_write_company($sql, $row);
				if ((gettype($res) == "boolean") && !$res)
					$status = 1;
			}
			else if ($table == 'contact')
			{
				$row['ccreate'] = date("Y-m-d", time());
				$res = rlc_mysql_write_cust($sql, $row);
				if ((gettype($res) == "boolean") && !$res)
					$status = 1;
			}
			else if ($table == 'prod')
			{
				$row['pcreate'] = date("Y-m-d", time());
				$res = rlc_mysql_write_prod($sql, $row, $_x);
				if ((gettype($res) == "boolean") && !$res)
					$status = 1;
			}
/*
 *			Add elseifs here for other tables that we write to,
 *			and call their specific rlc_mysql_write_ functions
 */
			if ($status)
			{
				$msg = mysqli_error($sql).
				". {$rowcount} rows added before error";
				send_status(FALSE, $msg, TRUE);
				return;
			}
			if ($getid)
			{
				$newid .= mysqli_insert_id($sql)." ";
			}
			$rowcount++;
		}
		if ($getid)
			send_status(TRUE, 
				"{$rowcount} rows added, IDs: {$newid}", TRUE);
		else
		{
//echo "count: ".count($generated_keys);
			if (count($generated_keys) > 0)
			{
			    $keystring = "";
			    foreach ($generated_keys as $akey)
			    {
//echo "\n".$akey."\n";
				    $keystring .= $akey." ";
			    }
			    send_status(TRUE, "{$rowcount} rows added".
				    ". Activation keys: ".$keystring, TRUE);
			}
			else
			{
			    send_status(TRUE, "{$rowcount} rows added", TRUE);
			}
		}
	}
/*
 *	If it's a put, build a query from the columns provided.
 */
	else if ($method == "put")
	{
		if (!array_key_exists('data', $postobject)) 
		{
			send_status(FALSE, "data missing from message",
				TRUE);
			return;
		}
		$select = build_select($header);
		$data = $postobject['data'];
		$first = true;
		$query = "UPDATE ".$table." SET ";
		foreach ($data as $row)
		{
			foreach ($row as $key => $value)
			{
				if (!$first)
					$query .= ",";
				else
					$first = false;
				$query .= $key."= '".$value."'";
			}
		}
		$query .= " ".$select;
//echo "\n query: ".$query."\n";
		$res = mysqli_query($sql, $query);
		if (!$res)
		{
			$msg = mysqli_error($sql);
			send_status(FALSE, $msg, TRUE);
			return;
		}
		$rowcount = mysqli_affected_rows($sql);
		send_status(TRUE, "{$rowcount} rows updated", TRUE);
	}
/*
 *	If it's a get, see if there are search qualifiers and build a query
 */
	else if ($method == "get")
	{
		$select = build_select($header);
		$query = "SELECT * FROM ".$table." ".$select;
		$rows = array();
		$res = mysqli_query($sql, $query);
		if ($res)
		{
			while ($r = mysqli_fetch_assoc($res))
				$rows[] = $r;
		}
		$result = json_encode($rows);
		$nrows = count($rows);
		send_status(TRUE, "{$nrows} rows found", FALSE);
		echo $result;
		echo "]";
	}
/*
 *	If it's a delete, get the key to delete and build the query
 */
	else if ($method == "delete")
	{
	    $select = build_select($header);
/*
 *	    If table is licf, get the rows to be deleted and count up
 *	    the number of rows with each akey.  Then decrement the num
 *	    column in the keyf table for each corresponding keyf row by
 *	    the count for that akey.
 */
	    if ($table == "licf")
	    {
		$query = "SELECT * FROM ".$table." ".$select;
		$resx = mysqli_query($sql, $query);
		if ($resx)
		{
		    $counts = array();
		    while ($row = mysqli_fetch_assoc($resx))
		    {
			$akey = $row['akey'];
			if (array_key_exists($akey, $counts))
			    $counts[$akey]++;
			else
			    $counts[$akey] = 1;
		    }
		    foreach ($counts as $akey => $decrement)
		    {
			$query = "SELECT akey,num FROM `keyf` where akey=";
			$query.= "'$akey'";
			$res = mysqli_query($sql, $query);
			if ($res)
			{
			    $row = mysqli_fetch_assoc($res);
			    $val = $row['num'];
			    $val -= $decrement;
			    if ($val < 0) $val = 0;
			    $query = sprintf(UPDATE_KEYF, $val, $akey);
			    $res = mysqli_query($sql, $query);
			}
		    }
		}
	    }
	    $query = "DELETE FROM ".$table." ".$select;
	    $res = mysqli_query($sql, $query);
	    if ($res)
	    {
		    $rowcount = mysqli_affected_rows($sql);
		    send_status(TRUE, "${rowcount} rows deleted", TRUE);
	    }
	    else
	    {
		    $msg = mysqli_error($sql);
		    send_status(FALSE, $msg, TRUE);
	    }
	}
	
	rlc_mysql_close($sql);
?>
