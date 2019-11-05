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

 	$Id: rlc_upload_db.php,v 1.7 2016/03/27 21:12:51 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Upload the database data - do the operation
 */

	$sql = rlc_mysql_init($isv);
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    return;
	}

	$errors = 0;
	echo '<pre>';
	if ($_FILES['dbfile']['tmp_name'] ==  "")
	{
	    echo "Error - no upload file specified<br>";
	    return;
	}
	$data = file($_FILES['dbfile']['tmp_name']);
	$sqlcmd = "";
	$count = 0;
	foreach ($data as $line)
	{
	    $sqlcmd .= $line;

	    if ((substr($sqlcmd, -1) == ';') || (substr($sqlcmd, -2, 1) == ';') 
					|| (substr($sqlcmd, -3, 1) == ';'))
	    {
		/* echo "Executing sql command: $sqlcmd<br>"; */

		$res = mysqli_query($sql, $sqlcmd);
		$count += 1;
		if (!$res)
		{
		    $errors++;
		    echo "<br>Error executing SQL command: $sqlcmd<br>";
		    echo "<br>SQL error: ".mysqli_error($sql)."<br>";
		}
	        $sqlcmd = "";
	    }
 	} 

/*
 *	Delete the file
 */
	unlink($_FILES['dbfile']['tmp_name']);
	echo "<br><b>Database update complete, $count SQL commands, $errors errors.</b><br>";

	rlc_mysql_close($sql);
?>
