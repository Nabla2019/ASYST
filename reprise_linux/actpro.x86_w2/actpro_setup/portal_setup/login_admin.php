<?php
/**
 * Admin.php
 *
 * This is the Admin Center page. Only administrators
 * are allowed to view this page. This page displays the
 * database table of users and banned users. Admins can
 * choose to delete specific users, delete inactive users,
 * ban users, update user levels, etc.
 *
 * Written by: Jpmaster77 a.k.a. The Grandmaster of C++ (GMC)
 * Last Updated: August 26, 2004
 */
include "rlc.php";
include "portal_mysql.php";
include "login_session.php";

/**
 * displayUsers - Displays the users database table in
 * a nicely formatted html table.
 */

define("QUERY_ONE_CONTACT", "SELECT * FROM `contact` LEFT JOIN `company` USING (company_id) WHERE (contact_id = %d)");

function displayUsers()
{
   global $database;
   $priv = array("NONE", "View", "Edit", "Portal", "portal", "portal", "portal",
		 "portal", "portal", "Admin");
   $q = "SELECT username,userlevel,email,timestamp,contact_id,vistabs "
       ."FROM ".TBL_USERS." ORDER BY username";
   $result = $database->query($q);
   $num_rows = mysqli_num_rows($result); 
   /* Error occurred, return given name by default */
   if(!$result){
      echo "Error displaying info";
      return;
   }
   if($num_rows == 0){
      echo "Empty user table";
      return;
   }
   /* Display table contents */

   echo "<table border=1 cellpadding=2 cellspacing=0>";

   echo "<tr><td><b>Username</b></td><td><b>Access</b></td>".
	  "<td><b>Name</b></td>".
	  "<td><b>Company</b></td>".
	  "<td><b>Email</b></td>".
	  "<td><b>Last Active</b></td></tr>\n";
   while ($r = mysqli_fetch_array($result, MYSQLI_ASSOC))
   {
      $contact = NULL;
      $temp = sprintf(QUERY_ONE_CONTACT, $r['contact_id']);
      $res = mysqli_query($database->connection, $temp);
      if ($res)
      {
	if (mysqli_num_rows($res) > 0)
	{
		$contact = mysqli_fetch_array($res);
	}
      }
      $uname = $r['username'];
      $ulevel = $r['userlevel'];
      $level = $priv[$ulevel];
      $time = $r['timestamp'];
      $ltime = localtime($time, true);
      $dtime = sprintf("%d/%02d/%02d %02d:%02d", $ltime["tm_mon"]+1, 
      				$ltime['tm_mday'], $ltime['tm_year']+1900, 
				$ltime['tm_hour'], $ltime['tm_min']);

      echo "<tr><td>$uname</td><td>$level</td>";
      if ($contact)
      {
	  echo "<td>".$contact['contact']."</td><td>".$contact['company'].
									"</td>";
	  $email = $contact['email'];
	  if ($r['email']) $email = $r['email'];
      }
      else
      {
	  echo "<td>&nbsp;</td><td>&nbsp;</td>";
          $email = $r['email'];
      }

      echo "<td>$email</td>";
      echo "<td>$dtime</td>";
      echo "<form action=\"login_adminprocess.php\" method=\"POST\"><td>".
        "<input type=\"hidden\" name=\"deluser\" value=$uname>".
        "<input type=\"hidden\" name=\"subdeluser\" value=\"1\">".
	"<input class=button type=\"submit\" value=\"Delete User: $uname\">".
	"</td></form>";
	/*  Old "change access to:" selection.
        "<form action=\"login_adminprocess.php\" method=\"POST\"><td>".
	"Change Access to: <select name=\"updlevel\">".
		"<option value=\"1\">View".
		"<option value=\"2\">Edit".
		"<option value=\"3\">Portal".
		"<option value=\"9\">Admin".
		"</select>".
	"<input type=\"hidden\" name=\"subupdlevel\" value=\"1\">".
	"<input type=\"hidden\" name=\"upduser\" value=\"$uname\">".
	"<input type=\"submit\" value=\"Update Access\"></td></form>".
	*/
	echo "<form action=\"login_edit_user.php\" method=\"POST\"><td>".
        "<input type=\"hidden\" name=\"edituser\" value=$uname>".
        "<input type=\"hidden\" name=\"contact\" value=".$r['contact_id'].">".
        "<input type=\"hidden\" name=\"email\" value=\"$email\">".
        "<input type=\"hidden\" name=\"vistabs\" value=\"".$r['vistabs']."\">".
        "<input type=\"hidden\" name=\"level\" value=\"$ulevel\">".
	"<input class=button type=\"submit\" value=\"Edit User: $uname\">".
	"</td></form>".
	"</tr>";
   }
   echo "</table><br>\n";
}

    rlc_web_header(RLC_MENU_ADMIN, $session);
    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_USERS);

?>
	<h3>Administer RLC Users</h3>
<?php
	if($form->num_errors > 0){
		echo "<font size=\"4\" color=\"#ff0000\">"
	       ."!*** Error with request, please fix (".
	       $form->num_errors." errors)</font><br><br>";
	}
?>
	<table align="left" border="0" cellspacing="5" cellpadding="5">
	<tr><td>
<?php
/**
 * Registered Users
 */
?>
	<h3>Registered Users:</h3>
	<font size=small> (You are logged in as: <b>
<?php echo $session->username; 
?>
	)</b><br><br></font>
<?php
	displayUsers();
?>
	</td></tr>
	<tr>
	<td>
	<form action="login_create_user.php" method="POST">
	<input type="submit" value="Create New User">
	</form>
	</td></tr>

<?php
    }
    finish_page(0, 0, 0);
?>
