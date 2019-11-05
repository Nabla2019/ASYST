<?php
include "rlc.php";
include "portal_mysql.php";
	$sql = portal_mysql_init(-1, $isv);
	rlc_mysql_read_rlc_setup($sql, "portal-name", $name);
	portal_mysql_close(-1, $sql);
	if (array_key_exists('portal-name', $name))
		$pname = $name['portal-name'];
	else
		$pname = "RLM Activation Pro Customer Portal";
	echo "<h0>$pname</h0>";
	echo "<h5>Copyright &copy; 2006-2016, Reprise Software, Inc.  All Rights Reserved.</h5>";
?>
