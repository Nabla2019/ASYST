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

        $Id: actpro_web_serv_11.2.php,v 1.2 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

/*
 * Web services for access to the ActPro database
 */

include "login_db.php";
include "rlc_mysql.php";
include "rlc_akey.php";

$user = "";
$password = "";
/*
 * Check the credentials passed in.   On return:
 *	0 means success
 *	1 means authentication failed (could be bad user or bad password)
 *
 * NOTE: password is an MD5 hash of the actual password.
 */
function authenticate_user($user, $password)
{
    global $database;
	$ok = $database->confirmUserPass($user, $password);
	if ($ok == 0)
		return 0;
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


	header('Content-Type: application/json');
	if ($_SERVER['REQUEST_METHOD'] != "POST")
	{
		send_status(FALSE, "Only HTTP POST is supported", TRUE);
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
		send_status(FALSE, "Wrong user or password in header", TRUE);
		return;
	}
	if (!array_key_exists('operation', $header)) 
	{
		send_status(FALSE, "Operation missing from header", TRUE);
		return;
	}
	$operation = $header['operation'];
	$operation = strtolower($operation);
	if (!array_key_exists('table', $header)) 
	{
		send_status(FALSE, "Table missing from header", TRUE);
		return;
	}
	$table = $header['table'];
	if ($table != "keyd" && $table != "licf" && $table != "prod")
	{
		send_status(FALSE, "Table in header must be keyd, licf, or prod",
			TRUE);
		return;
	}

/*
 *	Connect to the SQL server
 */
	$isv = "";
	$sql = rlc_mysql_init($isv);
// TODO error check?

	if ($table == "keyd")
	{
		if ($operation != "post" && $operation != "get" && 
			$operation != "delete")
		{
			send_status(FALSE,
			   "Operation in header must be post, get, or delete",
			   TRUE);
			return;
		}
		if ($operation == "post")
		{
			if (!array_key_exists('data', $postobject)) 
			{
				send_status(FALSE, "data missing from message",
					TRUE);
				return;
			}
			$data = $postobject['data'];
			$rowcount = 0;
			foreach ($data as $row)
			{
				$status = rlc_mysql_write_key($sql, $row);
				if ($status)
				{
					$msg = mysqli_error($sql).
					". {$rowcount} rows added before error";
					send_status(FALSE, $msg, TRUE);
					return;
				}
				$rowcount++;
			}
			send_status(TRUE, "{$rowcount} rows added", TRUE);
		}
		else if ($operation == "get")
		{
			if (array_key_exists('akey', $header)) 
			{
				$akey = $header['akey'];
				$query = 
				  sprintf("SELECT * FROM keyd WHERE (akey = \"%s\")",
					$akey);
			}
			else
				$query = "SELECT * FROM keyd";
			$res = mysqli_query($sql, $query);
			$rows = array();
			while ($r = mysqli_fetch_assoc($res))
				$rows[] = $r;
			$nrows = count($rows);
			$result = json_encode($rows);
			send_status(TRUE, "{$nrows} rows found", FALSE);
			echo $result;
			echo "]";
		}
		else if ($operation == "delete")
		{
			if (!array_key_exists('akey', $header)) 
			{
				send_status(FALSE, "akey missing from header",
					TRUE);
				return;
			}
			$akey = $header['akey'];
			$query = sprintf(
				"DELETE FROM `keyd` WHERE (akey = \"%s\")",
				$akey);
			$res = mysqli_query($sql, $query);
			if ($res)
				send_status(TRUE, "OK", TRUE);
			else
				send_status(FALSE, "failed", TRUE);
		}
	}
	else if ($table == "licf")
	{
		if ($operation != "get" && $operation != "delete")
		{
			send_status(FALSE, 
				"Operation in header must be get or delete",
				TRUE);
			return;
		}
		if ($operation == "get")
		{
			if (array_key_exists('id', $header))
				$id = $header['id'];
			else
				$id = null;
			if (array_key_exists('since', $header))
				$since = $header['since'];
			else
				$since = null;
			if ($since != null) {
			    $unixtime = strtotime($since);
			    if ($unixtime === false)
			    {
				send_status(FALSE, "invalid since date",
					TRUE);
				return;
			    }
			    $query =
			      sprintf("SELECT * FROM licf WHERE (time >= \"%s\")",
					$unixtime);
			}
			else if ($id != null)
			    $query = 
			      sprintf("SELECT * FROM licf WHERE (id = \"%s\")",
					$id);
			else
				$query = "SELECT * FROM licf";
			$res = mysqli_query($sql, $query);
			$rows = array();
			while ($r = mysqli_fetch_assoc($res))
				$rows[] = $r;
			$nrows = count($rows);
			$result = json_encode($rows);
			send_status(TRUE, "{$nrows} rows found", FALSE);
			echo $result;
			echo "]";
		}
		else if ($operation == "delete")
		{
			if (!array_key_exists('akey', $header))
			{
				send_status(FALSE, "akey missing in header",
					TRUE);
				return;
			}
			$akey = $header['akey'];
			$query = sprintf(
				"DELETE FROM `licf` WHERE (akey = \"%s\")",
				$akey);
			$res = mysqli_query($sql, $query);
			if ($res)
				send_status(TRUE, "OK", TRUE);
			else
				send_status(FALSE, "failed", TRUE);
		}
	}
	else if ($table == "prod")
	{
		if ($operation != "get")
		{
			send_status(FALSE, 
				"Operation in header must be get", TRUE);
			return;
		}
		if (array_key_exists('name', $header))
			$name = $header['name'];
		else
			$name = null;
		if ($name != null)
		    $query = 
		      sprintf("SELECT * FROM prod WHERE (name = \"%s\")",
				$name);
		else
			$query = "SELECT * FROM prod";
		$res = mysqli_query($sql, $query);
		$rows = array();
		while ($r = mysqli_fetch_assoc($res))
			$rows[] = $r;
		$nrows = count($rows);
		$result = json_encode($rows);
		send_status(TRUE, "{$nrows} rows found", FALSE);
		echo $result;
		echo "]";
	}

	rlc_mysql_close($sql);
?>
