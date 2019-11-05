<?php
/**
 * rlc_login.php
 *
 * This is the login menu for the RLM Activation Pro activation page.
 * This menu appears on the top at the right.
 *
 */

function rlc_login($session)
{
  global $form;
/*
 * User logged in
 */
	if ($session->logged_in)
	{

		$priv = array("NONE", "View", "Edit", "Portal", "portal", 
			      "portal", "portal", "portal", "portal", "Admin");

		$level = $session->userlevel;
		echo "<div id=login class=loginarea>";
		echo "<table class=loginarea>";
		echo "<tr><td class=login>Username: </td>";
		echo "<td><b>$session->username</b></td>";
		echo "<td>&nbsp;&#x7C;&nbsp;</td>";
		echo "<td>Access: <i>$priv[$level]</i></td>";
		echo "<td>&nbsp;&#x7C;&nbsp;</td>";
   		echo "<td><a href=\"login_process.php\">logout</a></td>";
		echo "</tr></table>";
		echo "</div>";
		/***
?>
		document.getElementById("disp").contentDocument.location.reload(true);
<?php
		***/
	}
	else
	{
/*
 * 		User not logged in, display the login form.
 */
		echo "<div id=login class=loginarea>";
		if ($form && ($form->num_errors > 0))
		{
   			echo "<font size=\"2\" color=\"#ff0000\">".
				$form->num_errors." error(s) found</font>";
		}
		?>
		<form action="login_process.php" method="POST">
		<table class=loginarea> 
		<tr><td class=login>Please log in</td></tr>
		<td class=loginarea>Username:</td><td> <input type="text" 
			name="user" size=18 maxlength="30" 
			value="<?php echo $form->value("user"); ?>">
			<?php echo $form->error("user"); ?>
		</td></tr><tr><td>
		Password: </td><td><input type="password" name="pass" size=18 
			maxlength="30" 
			value="<?php echo $form->value("pass"); ?>">
			<?php echo $form->error("pass"); ?>
		</td><td>
		<input type="hidden" name="sublogin" value="1">
		<input type="submit" value="Login">
		</td></tr></table>
		</form>
		</div>
<?php
	}
}
?>
