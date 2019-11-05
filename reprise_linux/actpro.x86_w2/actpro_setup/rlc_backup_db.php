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

 	$Id: rlc_backup_db.php,v 1.11 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

/*
 *	Backup the Activation Pro Database
 */

function backup_actpro_db($filename)
{
  
	$sql = rlc_mysql_init($isv);
	$tables = array();
	$result = mysqli_query($sql, 'SHOW TABLES');
	$return = "";
	while($row = mysqli_fetch_row($result))
	{
      		$tables[] = $row[0];
	}
	foreach ($tables as $table)
	{
		$return.= 'DROP TABLE IF EXISTS '.$table.';';
		$row2 = mysqli_fetch_row(mysqli_query($sql, 
					'SHOW CREATE TABLE '.$table));
		$return.= "\n\n".$row2[1].";\n\n";
/*
 *		Don't backup anything from the active users table
 */
		if (!strcmp($table, "active_users")) continue;

		$result = mysqli_query($sql, 'SELECT * FROM '.$table);
		$num_fields = mysqli_num_fields($result);

		for ($i = 0; $i < $num_fields; $i++) 
		{
			while($row = mysqli_fetch_row($result))
			{
				$return.= 'INSERT INTO '.$table.' VALUES(';
				for($j=0; $j<$num_fields; $j++) 
				{
					$row[$j] = addslashes($row[$j]);
					$row[$j] = preg_replace("/\n/", "\\n",
								$row[$j]);
					if (isset($row[$j])) 
					{ 
					    if (($row[$j] == null) ||
						($row[$j] == ""))
					    {
						$return.='""';
					    }
					    else
					    {
						$return.= '"'.$row[$j].'"' ; 
					    }
					} 
					else 
					{ 
						$return.= '""'; 
					}
					if ($j<($num_fields-1)) 
					{ 
						$return.= ','; 
					}
				}
				$return.= ");\n";
			}
		}
		$return.="\n\n\n";
	}
	rlc_mysql_close($sql);
  
/*
 *	OK, now write it all to the file.
 */
	$handle = fopen($filename, 'w+');
	fwrite($handle, $return);
	fclose($handle);
	chmod($filename, 0400);
}

/*
 *	OK, back up the database.
 */
	rlc_web_header(RLC_MENU_ADMIN, $session);
	rlc_admin_menu(RLC_ADMIN_MENU_DB);
	rlc_web_title("Database Backup", "rlc_admin_db.php");
 	$ds = DIRECTORY_SEPARATOR;
	if (!$session->isAdmin())
        {
	    echo "You must log in as an administrator to do this.<br>";
	    finish_page("BACK", 0, 0);
	    return;
	}
	if (array_key_exists('backupfile', $_POST))
	{
		$filename = $_POST['backupfile'];
/*
 *		Get the filename without the leading "backups/"
 */
		$x = $ds."backups".$ds.$filename;
		while ($x)
		{
			$last = $x;
			$x = strstr(substr($x, 1), "backups".$ds);
		}
		$plainfile = substr($last, 8);
/*
 *		OK, we passed in backups/mumble, so make sure that
 *		even on windows, where $ds is '\', we get rid of
 *		the 'backups/' in the front:
 */
		$x = strstr($plainfile, "backups/");
		if ($x) $plainfile = substr($x, 8);
	}
	else
	{
		$filename = "backups/actpro_db_backup.sql";
		$plainfile = "actpro_db_backup.sql";
	}
	$relative_path = "../backups/".$plainfile;

	echo "<br>Backing up database to file: <i>".$plainfile."</i><br>";
	backup_actpro_db($filename);
	echo "<br>Backup to file <i>".$plainfile."</i><b> complete.</b><br>";

/*
 *	Create the temporary file we will use to download.
 */
 	$cmdname = DLCMDFILE;
 	$cmdname[3] = $ds;
	$file2 = fopen($cmdname, "w");
	if ($file2 == FALSE)
	{
	    echo "<br>ERROR opening temporary file ".$cmdname."<br>";
	}
	else
	{
	    fwrite($file2, "<?php\n");
	    fwrite($file2, "header('Content-type: text/plain');\n");
	    fwrite($file2, "header('Content-disposition: attachment; filename=".$relative_path."');\n");
	    fwrite($file2, "readfile('$relative_path');\n");
	    fwrite($file2, "?>\n");
	    fclose($file2);
	    chmod($cmdname, 0600);
	}

/*
 *	create the download link here.
 */

	$cmdname[3] = '/';	/* Force to forward slash for browser */
	echo "<br><br><a href=$cmdname>Click here to download database backup.</a><br><br>";
	finish_page("BACK (remove temporary Database file)", 0, 0);
?>
