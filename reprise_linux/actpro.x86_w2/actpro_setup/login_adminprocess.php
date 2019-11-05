<?php
/**
 * AdminProcess.php
 * 
 * The AdminProcess class is meant to simplify the task of processing
 * admin submitted forms from the admin center, these deal with
 * member system adjustments.
 *
 * Written by: Jpmaster77 a.k.a. The Grandmaster of C++ (GMC)
 * Last Updated: August 15, 2004
 */

include ("rlc.php");
include("login_session.php");

class AdminProcess
{
   /* Class constructor */
   function AdminProcess()
   {
      global $session;
      /* Make sure administrator is accessing page */
      if (!$session->isAdmin())
      {
         /* Replaced this with next line: header("Location: main.php"); */
         header("Location: ".$session->referrer);
         return;
      }
      /* Admin submitted edit user form */
      if (isset($_POST['subedituser']))
      {
         $this->procEditUser();
      }
      /* Admin submitted update user level form */
      if (isset($_POST['subupdlevel']))
      {
         $this->procUpdateLevel();
      }
      /* Admin submitted delete user form */
      else if (isset($_POST['subdeluser']))
      {
         $this->procDeleteUser();
      }
      /* Should not get here, redirect to home page */
      else
      {
         /* Replaced this with next line header("Location: main.php"); */
         /* replace this in v11: header("Location: ".$session->referrer); */
	 /* header("Location: login_admin.php"); */
         header("Location: ".$session->referrer);
      }
   }

   /**
    * procUpdateLevel - If the submitted username is correct,
    * their user level is updated according to the admin's
    * request.
    */
   function procUpdateLevel()
   {
      global $session, $database, $form;
      /* Username error checking */
      $subuser = $this->checkUsername("upduser");
      
      /* Errors exist, have user correct them */
      if($form->num_errors > 0){
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
         header("Location: ".$session->referrer);
      }
      /* Update user level */
      else{
         $database->updateUserField($subuser, "userlevel", (int)$_POST['updlevel']);
         header("Location: ".$session->referrer);
      }
   }
   
   /**
    * procEditUser - If the submitted username is correct,
    * edit their information.
    */
   function procEditUser()
   {
      global $session, $database, $form;
      /* Username error checking */
      $subuser = $this->checkUsername("edituser");
      
      /* Errors exist, have user correct them */
	if ($form->num_errors > 0){
	    $_SESSION['value_array'] = $_POST;
	    $_SESSION['error_array'] = $form->getErrorArray();
	    $_SESSION['edituser'] = $_POST['edituser'];
	    $_SESSION['email'] = $_POST['email'];
	    $_SESSION['contact'] = $_POST['contact'];
	    $_SESSION['vistabs'] = 0;
	    $_SESSION['level'] = $_POST['level'];
	    header("Location: ".$session->referrer);
	}
	/* Update all user fields */
	else
	{
	    $database->updateUserField($subuser, "userlevel", 
	 					(int)$_POST['updlevel']);
	    $database->updateUserField($subuser, "email", $_POST['email']);
	    $database->updateUserField($subuser, "contact_id", 
	 					(int)$_POST['contact_id']);
/*
 *	     If they specified a password, update it.
 */
	    if (array_key_exists('pass', $_POST) && ($_POST['pass'] != ""))
	    {
	    	$subpass = $_POST['pass'];
		/* New Password error checking */
		$field = "pass";  //Use field name for new password
		/* Spruce up password and check length*/
		$subp = stripslashes($subpass);
		if (strlen($subpass) < 4)
		{
		    $form->setError($field, " New Password too short");
		}
		/* Check if password is not alphanumeric */
		else if (!preg_match("/^([0-9a-zA-Z])+$/", 
					($subpass = trim($subpass))))
		{
		    $form->setError($field, " New Password not alphanumeric");
		}
		if ($form->num_errors == 0) 
		{
		   $database->updateUserField($subuser, "password", md5($subp));
		}
	    }
            $vistabs = 0;

            if (array_key_exists('products', $_POST) &&
	    					($_POST['products'] == 1))
		$vistabs |= PRODUCTS_TAB;
	    if (array_key_exists('keys', $_POST) && ($_POST['keys'] == 1))
		$vistabs |= KEYS_TAB;
	    if (array_key_exists('fulfill', $_POST) && ($_POST['fulfill'] == 1))
		$vistabs |= FULFILLMENTS_TAB;
	    if (array_key_exists('customers', $_POST) &&
	    					($_POST['customers'] == 1))
		$vistabs |= CUSTOMERS_TAB;
	    if (array_key_exists('reports', $_POST) && ($_POST['reports'] == 1))
		$vistabs |= REPORTS_TAB;
	    if (array_key_exists('profile', $_POST) && ($_POST['profile'] == 1))
		$vistabs |= PROFILE_TAB;
	    $database->updateUserField($subuser, "vistabs", $vistabs);

	    if ($form->num_errors > 0)
	    {
		$_SESSION['value_array'] = $_POST;
		$_SESSION['error_array'] = $form->getErrorArray();
		$_SESSION['edituser'] = $_POST['edituser'];
		$_SESSION['email'] = $_POST['email'];
		$_SESSION['vistabs'] = $vistabs;
		$_SESSION['contact'] = $_POST['contact_id'];
		$_SESSION['level'] = $_POST['updlevel'];
	    }
	    else
	    {
	    	$_SESSION['edituser'] = $subuser;
	    	$_SESSION['editsuccess'] = true;
	    }
	    header("Location: ".$session->referrer);
	}
   }
   
   /**
    * procDeleteUser - If the submitted username is correct,
    * the user is deleted from the database.
    */
   function procDeleteUser()
   {
      global $session, $database, $form;
      /* Username error checking */
      $subuser = $this->checkUsername("deluser");
      
      /* Errors exist, have user correct them */
      if($form->num_errors > 0){
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
         header("Location: ".$session->referrer);
      }
      /* Delete user from database */
      else{
         $q = "DELETE FROM ".TBL_USERS." WHERE username = '$subuser'";
         $database->query($q);
         header("Location: ".$session->referrer);
      }
   }
   
   /**
    * checkUsername - Helper function for the above processing,
    * it makes sure the submitted username is valid, if not,
    * it adds the appropritate error to the form.
    */
   function checkUsername($uname, $ban=false){
      global $database, $form;
      /* Username error checking */
      $subuser = $_POST[$uname];
      $field = $uname;  //Use field name for username
      if(!$subuser || strlen($subuser = trim($subuser)) == 0){
         $form->setError($field, "* login incorrect<br>");
      }
      else{
         /* Make sure username is in database */
         $subuser = stripslashes($subuser);
         if(strlen($subuser) < 4 || strlen($subuser) > 30 ||
            !preg_match("/^([0-9a-z])+$/", $subuser) ||
            (!$ban && !$database->usernameTaken($subuser))){
            $form->setError($field, "* login incorrect<br>");
         }
      }
      return $subuser;
   }
};

/* Initialize process */
$adminprocess = new AdminProcess;

?>
