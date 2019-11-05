<?php

include "login_session.php";
include "rlc.php";
include "portal_mysql.php";

rlc_web_header(RLC_MENU_ABOUT, $session);

rlc_get_isvname($session, $isv, $db, $dbhost);
$sql = portal_mysql_init(-1, $isv);
$dbsize = rlc_mysql_get_db_size($sql, $db);
$dbsize_print = sprintf("%.3f", $dbsize);
rlc_mysql_read_rlc_setup($sql, "portal-name", $name);
portal_mysql_close(-1, $sql);

if (array_key_exists('portal-name', $name))
	$pname = $name['portal-name'];
else
	$pname = "RLM Activation Pro Customer Portal";

/* echo "<center>"; */
echo "<h2>".$pname.", v".RLC_ACTPRO_VERSION.".".RLC_ACTPRO_REV."</h2>";
echo "This web interface is used to view the <i>RLM Activation Pro database</i>.";
echo "<br>The portal allows you to view information on your licenses and activation keys.";
echo "<br><br>To begin, please log in.  Then choose a tab at the top.";
echo "<br><br><hr>";

echo "<table>";
echo "<tr><td>ISV:&nbsp</td><td><b>".$isv."</b><br>";
echo "</td></tr><tr><td>Database:&nbsp</td><td><b>".$db."</b><br>";
if ($dbsize != 0) echo "</td></tr><tr><td>Database size (Mb):&nbsp</td><td><b>".
						$dbsize_print."</b><br>";
echo "</td></tr><tr><td>RLM Activation Pro version:&nbsp</td><td><b>v".
					RLC_ACTPRO_VERSION.".".
					RLC_ACTPRO_REV."BL".
					RLC_ACTPRO_BUILD."-p".RLC_ACTPRO_PATCH.
					" (".RLC_ACTPRO_DATE.")</b><br>";
echo "</td></tr></table><hr>";
?>
</div>
</body>
</html>
