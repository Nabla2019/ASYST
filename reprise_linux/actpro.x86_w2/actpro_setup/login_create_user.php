<?php
/**
 * login_create_user.php
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

/*
 *  The user is not logged in or not an administrator, not allowed to register.
 */
    if(!$session->logged_in || !$session->isAdmin())
    {
	echo "<h1>Not available</h1>";
	echo "You must log in as an administrator to perform this function.<br>";
	return true;
    }


/**
 * The user has submitted the registration form and the
 * results have been processed.
 */
    rlc_web_header(RLC_MENU_ADMIN, $session);
    rlc_admin_menu(RLC_ADMIN_MENU_USERS);

    if(isset($_SESSION['regsuccess']))
    {
/* 
 *	Registration was successful 
 */
	if($_SESSION['regsuccess'])
	{
	    echo "<h2>User <i>".$_SESSION['reguname']."</i> Created</h2>";
	    echo "<p>Back to the <a href=\"login_admin.php\">Admin Page</a>.</p>";
	}
	else
	{
/*
 *	Registration failed 
 */
	    echo "<h1>Registration Failed</h1>";
	    echo "<p>We're sorry, but an error has occurred and your registration for the username <b>".$_SESSION['reguname']."</b>, "
          ."could not be completed.<br>Please try again at a later time.</p>";
	}
	unset($_SESSION['regsuccess']);
	unset($_SESSION['reguname']);
	finish_page(0, 0, 0);
    }
    else
    {
/*
 *	The user has not filled out the registration form yet.
 *	Below is the page with the sign-up form, the names
 *	of the input fields are important and should not
 *	be changed.
 */
	rlc_web_title("Create New User", "login_process.php");

	if($form->num_errors > 0)
	{
	    echo "<td><font size=\"2\" color=\"#ff0000\">".$form->num_errors." error(s) found</font></td>";
	}
	$sql = rlc_mysql_init($isv);
	rlc_mysql_get_contacts($sql, $contacts);
	rlc_mysql_close($sql);
	rlc_web_info("Usernames must be at least 4 characters and consist of ".
		"lowercase letters and numbers only.<br>Passwords must be at ".
		"least 4 characters and consist of lower and uppercase letters".
		" and numbers only.");
?>
	<table border="0">
	<tr><td>Username:</td><td><input type="text" name="user" maxlength="30"
		 value="<?php echo $form->value("user"); ?>"></td><td>
		<?php echo $form->error("user"); ?></td></tr>
<?php
	rlc_web_prompt_contact($contacts, 0);
?>
	<tr><td>Email:</td><td><input type=text name="email" 
		  maxlength="80" value="<?php echo $form->value("email"); ?>"
		  </td>
		<td><?php echo $form->error("email"); ?></td></tr>
	<tr><td>Password:</td><td>
	<input type="password" name="pass" maxlength="30" 
		value="<?php echo $form->value("pass"); ?>">
	</td><td><?php echo $form->error("pass"); ?></td></tr>
	<tr><td>Access:<ht></td><td>
	<select name="updlevel">
	<option value="1">View
	<option value="2">Edit
	<option value="3">Portal
	<option value="9">Admin
	</select>
	</td></tr><tr><td>Visible Tabs:</td><td>
<?php

	echo "&nbsp;";
	rlc_web_checkbox("Products", "products", 1, 1, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Keys", "keys", 1, 1, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Fulfillments", "fulfill", 1, 1, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Customers", "customers", 1, 1, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Reports", "reports", 1, 1, 0);
	echo "&nbsp;";
	rlc_web_checkbox("Profile", "profile", 1, 1, 0);
	echo "</td></tr>";
	echo "<input type=\"hidden\" name=\"subjoin\" value=\"1\"></td></tr>".
		"</table>";
	finish_page("Create User", "Back", "login_admin.php");
    }
?>
	</table>
	</form>
