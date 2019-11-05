<?php
/**
 * login_edit_user.php
 * Adapted from: login_create_user.php
 * From: Register.php
 * 
 * Displays the registration form if the user needs to sign-up,
 * or lets the user know, if he's already logged in, that he
 * can't register another name.
 *
 * Written by: Jpmaster77 a.k.a. The Grandmaster of C++ (GMC)
 * Last Updated: August 19, 2004
 */
include "rlc.php";
include "rlc_mysql.php";
include "rlc_prompts.php";
include("login_session.php");

    /* global $form; */
/*
 *  The user is not logged in or not an administrator, not allowed to register.
 */
    if(!$session->logged_in || !$session->isAdmin())
    {
	echo "<h1>Not available</h1>";
	echo "You must log in as an administrator to perform this function.<br>";
	return true;
    }

    rlc_web_header(RLC_MENU_ADMIN, $session);
    rlc_admin_menu(RLC_ADMIN_MENU_USERS);

    if (isset($_SESSION['editsuccess']))
    {
/* 
 *	Edit was successful 
 */
	if($_SESSION['editsuccess'])
	{
	    echo "<h2>User <i>".$_SESSION['edituser']."</i> Edited</h2>";
	    echo "<p>Back to the <a href=\"login_admin.php\">Admin Page</a>.</p>";
	}
	else
	{
/*
 *	Edit failed 
 */
	    echo "<h2>User Edit of ".$_SESSION['edituser']." Failed</h2>";
	    echo "<p>Back to the <a href=\"login_admin.php\">Admin Page</a>.</p>";
	}
	unset($_SESSION['editsuccess']);
	unset($_SESSION['edituser']);
	finish_page(0, 0, 0);
    }
    else
    {

/*
 *	The user has not filled out the edit form yet.
 *	Below is the page with the sign-up form, the names
 *	of the input fields are important and should not
 *	be changed.
 */
	rlc_web_title("Edit User", "login_adminprocess.php");
	/* rlc_web_title("Edit User", "login_process.php"); */

	if ($form->num_errors > 0)
	{
	    echo "<td><font size=\"2\" color=\"#ff0000\">".$form->num_errors." error(s) found</font></td>";
	    $edituser = $_SESSION['edituser'];
	    if (array_key_exists('contact', $_SESSION))
	        $contact = $_SESSION['contact'];
	    else
	        $contact = 0;
	    $email = $_SESSION['email'];
	    if (array_key_exists('level', $_SESSION))
		$level = $_SESSION['level'];
	    else
		$level = 0;
	    $vistabs = $_SESSION['vistabs'];
	}
	else
	{
	    $edituser = $_POST['edituser'];
	    $contact = $_POST['contact'];
	    $email = $_POST['email'];
	    $vistabs = $_POST['vistabs'];
	    $level = $_POST['level'];
	    unset($_SESSION['edituser']);
	    unset($_SESSION['contact']);
	    unset($_SESSION['email']);
	    unset($_SESSION['vistabs']);
	    unset($_SESSION['level']);
	}
	$sql = rlc_mysql_init($isv);
	rlc_mysql_get_contacts($sql, $contacts);
	rlc_mysql_close($sql);
	rlc_web_info("Passwords must be at ".
		"least 4 characters and consist of lower and uppercase letters".
		"and numbers only.");
	echo "<table border=\"0\">";
	echo "<tr><td>Username:</td><td>$edituser</td></tr>";
	rlc_web_hidden("edituser", $edituser);
	rlc_web_prompt_contact($contacts, $contact);
	echo "<tr><td>Email:</td><td><input type=text name=\"email\" ".
		  	"maxlength=\"80\" value=\"".$email.
		  	"\"></td><td>".$form->error("email")."</td></tr>";
?>
	<tr><td>Password:</td><td>
	<input type="password" name="pass" maxlength="30" 
		value="<?php echo $form->value("pass"); ?>">
	&nbsp;<b>If left blank, old password will be unchanged</b>
	</td><td><?php echo $form->error("pass"); ?>
	</tr>
	<tr><td>Access:<ht></td><td>
<?php
	$s1 = $s2 = $s3 = $s9 = "";
	if ($level == 2) $s2 = "selected=\"selected\"";
	else if ($level == 3) $s3 = "selected=\"selected\"";
	else if ($level == 9) $s9 = "selected=\"selected\"";
	else $s1 = "selected=\"selected\"";

	echo "<select name=\"updlevel\">".
		"<option value=\"1\" $s1>View".
		"<option value=\"2\" $s2>Edit".
		"<option value=\"3\" $s3>Portal".
		"<option value=\"9\" $s9>Admin".
		"</select></td></tr>".
		"</td></tr>";

	if ($vistabs & PRODUCTS_TAB)     $p = 1; else $p = 0;
	if ($vistabs & KEYS_TAB)         $k = 1; else $k = 0;
	if ($vistabs & FULFILLMENTS_TAB) $f = 1; else $f = 0;
	if ($vistabs & CUSTOMERS_TAB)    $c = 1; else $c = 0;
	if ($vistabs & REPORTS_TAB)      $r = 1; else $r = 0;
	if ($vistabs & PROFILE_TAB)      $x = 1; else $x = 0;

	echo "<tr><td>Visible Tabs:</td><td>";
	echo "&nbsp;";
	rlc_web_checkbox("Products", "products", 1, $p, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Keys", "keys", 1, $k, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Fulfillments", "fulfill", 1, $f, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Customers", "customers", 1, $c, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Reports", "reports", 1, $r, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Profile", "profile", 1, $x, 0);
	echo "</td></tr>";
	echo "</table>";

	echo "</td></tr></table>";
	rlc_web_hidden("subedituser", 1);

	finish_page("Edit User", "Back", "login_admin.php");
	echo "</table></form>";
    }
?>

