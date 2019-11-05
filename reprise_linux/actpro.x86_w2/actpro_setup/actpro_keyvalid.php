<?php
/*
 *	Web service to create a fulfillment from the activation key and
 *	hostid passed in, or just return success if such a fulfillment
 *	already exists.
 *
 *	Bob Mearns
 *	8/8/2017
 */

include "rlc.php";
include "rlc_mysql.php";

/*
 *	Send a response to the client.  
 */
function send_response($status, $items) {
	$messages = array();
	$messages['0'] = "success";
	$messages['1'] = "no matching activation key";
	$messages['2'] = "inactive activation key";
	$messages['3'] = "no fulfillments left on key";
	$messages['4'] = "licf table update failed";
	$messages['5'] = "keyf table update failed";
	$messages['6'] = "license expired";
	$messages['7'] = "activation key expired";
	$messages['8'] = "hostid supplied is < 8 characters long";
	$messages['9'] = "No hostid supplied in query string";
	$messages['10'] = "No activation key supplied in query string";

	$resp['status'] = $status;
	$resp['description'] = $messages[$status];
	if ($items != null)
	{
		foreach ($items as $key => $value)
			$resp[$key] = $value;
	}
	$json_string = json_encode($resp);
	echo $json_string;
}

/*
 *	Determine if an expiration date is already past, based on a UNIX
 *	timestamp passed in.
 */
function expired($expdate) {
	if ($expdate == "permanent")
		return false;
	$expunix = strtotime($expdate);
	$expunix += 60*60*24;
	if ($expunix < time(0))
		return true;
	else
		return false;
}

/*
 *	Compute the expiration date from the keyd rec passed in.
 *
 *	If the exp string is 0 or "permanent", the license is permanent.
 *	If it's an RLM date (dd-mmm-yyyy), it's a hard expiration date.
 *	If it's a number it's an expiration date relative to today - compute it.
 */
function compute_exp_date($sql, $keyd_rec) {
	$exp_string = $keyd_rec['exp'];
/*
 *	This code gets the expiration string from the product definition
 *	if it's not specified in the acivation key.  We later decided not to 
 *	look at the product definition at all, for simplicity for the user.
 *
	if ($exp_string == null)
	{
		$query = "SELECT exp FROM prod WHERE id='"
			.$keyd_rec['product_id']."'";
		$prod_result = mysqli_query($sql, $query);
		if (mysqli_num_rows($prod_result) == 0) 
		{
			return "prod table query error";
		}
		$prod_row = mysqli_fetch_assoc($prod_result);
		$exp_string = $prod_row['exp'];
	}
 */

	if ($exp_string == null || $exp_string == "permanent")
		return "permanent";
	$hyphen = strpos($exp_string, "-");
	if ($hyphen != 0)
		return $exp_string;
	$exp_date = date("Y-m-d", time(0)+$exp_string*86400);
	return $exp_date;
}

/*
 *	Say we're going to return JSON
 */
	header('Content-Type: application/json');
/*
 *	The activation key and hostid are in the query string
 */
	$query_string = $_SERVER['QUERY_STRING'];
//echo "query string: ".$query_string."\n";
	if ($query_string == null) 
	{
		echo "error query string";
	}
	parse_str($query_string, $qs_array);
	if (array_key_exists('akey', $qs_array))
		$akey = $qs_array['akey'];
	else
	{
		send_response(10,null);
		return;
	}
	if (array_key_exists('hostid', $qs_array))
		$hostid = $qs_array['hostid'];
	else
	{
		send_response(9,null);
		return;
	}
//echo "got akey ".$akey; echo "\n";
//echo "got hostid ".$hostid; echo "\n";

/*
 *	Get the client's IP address and hostname
 */
	$ip = $_SERVER['REMOTE_ADDR'];
	$hostname = gethostbyaddr($ip);

/*
 *	Connect to the SQL server
 */
	$isv = "";
	$sql = rlc_mysql_init($isv);

/*
 *	See if there is an activation key matching the one specified, and if
 *	so, check that it's active and not expired.
 */
	$query = "SELECT * FROM keyd WHERE ";
	$query = $query."akey='".$akey."'";
	$keyd_result = mysqli_query($sql, $query);
	if (mysqli_num_rows($keyd_result) == 0) 
	{
		send_response(1,null);	// no matching activation key
		return;
	}
	$keyd_row = mysqli_fetch_assoc($keyd_result);
	if ($keyd_row['active'] == 0) 
	{
		send_response(2,null);	// key not active
		return;
	}
	$key_exp_date = $keyd_row['lastdate'];
	if ($key_exp_date != "")
	{
		$unix_time = strtotime($key_exp_date);
		if (expired($unix_time))
		send_response(7, null);	// Activation key expired
		return;
	}

/*
 *	See if there is already a fulfillment for the akey/hostid pair.  If there
 *	is and it's not expired, update the last_check time in the licf record 
 *	and return success.  There may be multiple rows for the akey/hostid
 *	pair - check all of them looking for one that's not expired.
 */
	$query = "SELECT * from licf WHERE ";
	$query = $query."akey='".$akey."' AND license_hostid='sn=".$hostid."'";
	$licf_result = mysqli_query($sql, $query);
	if (mysqli_num_rows($licf_result) != 0) 
	{
		$licf_rows = array();
		while ($r = mysqli_fetch_assoc($licf_result))
		{
			if (expired($r['expdate']))
				continue;
			$gotone = true;
			$query = "UPDATE licf SET last_check=".time(0)." WHERE ";
			$query .= "id=".$r['id'];
			$licf_result = mysqli_query($sql, $query);
			$resp_item['expiration'] = $r['expdate'];
			$resp_item['extra'] = $keyd_row['misc'];
			send_response(0, $resp_item);
			return;
		}
		send_response(6,null);
		return;
	}

/*
 *	No fulfillment for the activation key on the specified hostid.
 *	See if the hostid passed in is valid.
 */
	if (strlen($hostid) < 8)
	{
		send_response(8,null);
		return;
	}

/*
 *	See if there is count left on the activation key.
 */
	$query = "SELECT * from keyf WHERE akey='".$akey."'";
	$keyf_result = mysqli_query($sql, $query);
	if (mysqli_num_rows($keyf_result) == 0) 
	{
		$num_fulfilled = 0;
		$keyf_exists = false;
	}
	else 
	{
		$keyf_row = mysqli_fetch_assoc($keyf_result);
		$num_fulfilled = $keyf_row['num'];
		$keyf_exists = true;
	}
	$count = $keyd_row['count'];
	if ($num_fulfilled >= $count) 
	{
		send_response(3,null);
		return;
	}

/*
 *	There is count available.  Create a new licf record and create or
 *	update the row in the keyf table. First create the licf record.
 */
	$licf_rec = array();
	$licf_rec['akey'] = $akey;
	$licf_rec['product_id'] = $keyd_row['product_id'];
	$licf_rec['count'] = 1;
	$licf_rec['time'] = time();
	$licf_rec['license_hostid'] = "sn=".$hostid;
	$licf_rec['license'] = "web keyvalid license";
	$expiration_date = compute_exp_date($sql, $keyd_row);
	$licf_rec['expdate'] = $expiration_date;
	$licf_rec['last_fulfill'] = time(0);
	$licf_rec['num_fulfills'] = 1;
	$licf_rec['revoked'] = 0;
	$licf_rec['revoke_time'] = 0;
	$licf_rec['last_check'] = 0;
	$licf_rec['remote_host'] = $ip;
	$licf_rec['reference_hostid'] = "";
	$licf_rec['hostname'] = $hostname;
	$licf_rec['log'] = "";
	$stat = rlc_mysql_write_licf($sql, $licf_rec);
	if ($stat != 0) 
	{
		send_response(4,null);
		return;
	}

/*
 *	Create or update the keyf row
 */
	$num_fulfilled += 1;
	if ($keyf_exists)
	{
		$query = "UPDATE keyf SET num=".$num_fulfilled;
		$query = $query.", lasthostid='sn=".$hostid."'";
		$query = $query." WHERE akey='".$akey."'";
		$res = mysqli_query($sql, $query);
		if ($res != 1)
			$res = -1;	// Normalize 
	}
	else
	{
		$keyf_rec = array();
		$keyf_rec['akey'] = $akey;
		$keyf_rec['num'] = $num_fulfilled;
		$keyf_rec['lasthostid'] = "sn=".$hostid;
		$keyf_rec['num_revoked'] = 0;
// TODO: date
		$keyf_rec['date'] = "";
		$res = rlc_mysql_write_keyf($sql, $keyf_rec);
	}
	if ($res === -1)	// fails if ==, why?
	{
// TODO delete licf record written above
		send_response(5,null);
		return;
	}


	$resp_item['expiration'] = $expiration_date;
	$resp_item['extra'] = $keyd_row['misc'];
	send_response(0, $resp_item);
	return;
?>
