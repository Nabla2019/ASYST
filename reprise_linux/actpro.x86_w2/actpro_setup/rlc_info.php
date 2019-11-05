<?php

include "rlc.php";
include "rlc_mysql.php";
include "login_session.php";

rlc_web_header(RLC_MENU_ABOUT, $session);

rlc_get_isvname($session, $isv, $db, $dbhost);
$sql = rlc_mysql_init($isv);
$dbsize = rlc_mysql_get_db_size($sql, $db);
rlc_mysql_read_rlc_setup($sql, "license-exp", $exp);
$dbsize_print = sprintf("%.3f", $dbsize);

echo "<h2>RLM License Center (RLM Activation Pro), v".RLC_ACTPRO_VERSION.".".RLC_ACTPRO_REV."</h2>";
echo "This web interface is used to administer the <i>RLM Activation Pro database</i>.";
echo "<br>rlc allows you to perform status and administration functions on the RLM activation database.";
if (!$session->logged_in)
{
echo "<br><br>To begin, please log in.  Then choose a tab at the top.";
}
echo "<br><br><hr>";

echo "<table>";
echo "<tr><td>ISV:&nbsp</td><td><b>".$isv."</b><br>";
echo "</td></tr><tr><td>Server host:&nbsp</td><td><b>".$_SERVER['HTTP_HOST'].
								"</b><br>";
echo "</td></tr><tr><td>Database Server host:&nbsp</td><td><b>".$dbhost."</b><br>";
/***/ echo "</td></tr><tr><td>Database:&nbsp</td><td><b>".$db."</b><br>"; /***/
if ($dbsize != 0) echo "</td></tr><tr><td>Database size (Mb):&nbsp</td><td><b>".
						$dbsize_print."</b><br>";
echo "</td></tr><tr><td>RLM Activation Pro version:&nbsp</td><td><b>v".
					RLC_ACTPRO_VERSION.".".
					RLC_ACTPRO_REV."BL".
					RLC_ACTPRO_BUILD."-p".RLC_ACTPRO_PATCH.
					" (".RLC_ACTPRO_DATE.")</b><br>";
$errlevel = rlc_turn_off_warnings();
echo "</td></tr><tr><td>Current Local Server Time:&nbsp</td><td><b>".
				date("G:i D, Y-m-d", time(0))."</b><br>";
if (array_key_exists('license-exp', $exp))
    echo "</td></tr><tr><td>License Generator Expiration:&nbsp</td><td><b>"
				.$exp['license-exp']."</b><br>";

error_reporting($errlevel);
echo "</td></tr></table>";
echo "<hr><br>";
echo "<a href=rlm_activation_pro.pdf target=new>View Activation Pro Manual</a>";
?>
<br><br><hr>
Reprise Software, Inc.
<BR>13388 Old Airline Highway
<BR>Paicines, CA 95043
<br>
<BR><A HREF="http://www.reprisesoftware.com/" TARGET="new">www.reprisesoftware.com</A>
<BR><A HREF="mailto:info@reprisesoftware.com"> info@reprisesoftware.com</A></P>
<?php
	finish_page(0, 0, 0);
