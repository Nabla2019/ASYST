<?php
/**
 * Process.php
 * 
 * The Process class is meant to simplify the task of processing
 * user submitted forms, redirecting the user to the correct
 * pages if errors are found, or if form is successful, either
 * way. Also handles the logout procedure.
 *
 * Written by: Jpmaster77 a.k.a. The Grandmaster of C++ (GMC)
 * Last Updated: August 19, 2004
 */

include "rlc.php";
include "login_session.php";

class Process
{
   /* Class constructor */
   function Process()
   {
      global $session;
     
      if (isset($_POST['sublogin']))    /* User submitted login form */
      {
         $this->procLogin();
      }
      else if(isset($_POST['subjoin'])) /* User submitted registration form */
      {
         $this->procRegister();
      }
      else if(isset($_POST['subforgot'])) /* User submitted forgot pw form */
      {
         $this->procForgotPass();
      }
      else if (isset($_POST['subedit']))  /* User submitted edit account form */
      {
         $this->procEditAccount();
      }

      /**
       * The only other reason user should be directed here
       * is if he wants to logout, which means user is
       * logged in currently.
       */
      else if ($session->logged_in)
      {
         $this->procLogout();
      }
      /*
       * Should not get here, which means user is viewing this page
       * by mistake and therefore is redirected.
       */
       else
       {
   	  rlc_web_header(0, $session);
	  finish_page(0, 0, 0);
       }
   }

   /*
    * procLogin - Processes the user submitted login form, if errors
    * are found, the user is redirected to correct the information,
    * if not, the user is effectively logged in to the system.
    */
   function procLogin()
   {
      global $session, $form;
      /* Login attempt */
      $retval = $session->login($_POST['user'], $_POST['pass'], 
						isset($_POST['remember']));
      
      $session->startSession();	/* Make it happen NOW */
      if ($retval)	/* Login successful */
      {
	 rlc_web_header(RLC_MENU_ABOUT, $session);
	 rlc_web_title("", "rlc_info.php");
	 finish_page(0, 0, 0);  /**/
      }
      else 		/* Login failed */
      {
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
         header("Location: ".$session->referrer);
      }
   }
   
   /*
    * procLogout - Simply attempts to log the user out of the system
    * given that there is no logout form to process.
    */
   function procLogout()
   {
      global $session, $form;
      $retval = $session->logout();
      rlc_web_header(0, $session);
      finish_page(0, 0, 0);
   }
   
   /*
    * procRegister - Processes the user submitted registration form,
    * if errors are found, the user is redirected to correct the
    * information, if not, the user is effectively registered with
    * the system and an email is (optionally) sent to the newly
    * created user.
    */
   function procRegister()
   {
      global $session, $form;
      /* Convert username to all lowercase (by option) */
      if (ALL_LOWERCASE) $_POST['user'] = strtolower($_POST['user']);

      /* Registration attempt */
      $vistabs = 0;
      if (array_key_exists('products', $_POST) && ($_POST['products'] == 1))
      	$vistabs |= PRODUCTS_TAB;
      if (array_key_exists('keys', $_POST) && ($_POST['keys'] == 1))
      	$vistabs |= KEYS_TAB;
      if (array_key_exists('fulfill', $_POST) && ($_POST['fulfill'] == 1))
      	$vistabs |= FULFILLMENTS_TAB;
      if (array_key_exists('customers', $_POST) && ($_POST['customers'] == 1))
      	$vistabs |= CUSTOMERS_TAB;
      if (array_key_exists('reports', $_POST) && ($_POST['reports'] == 1))
      	$vistabs |= REPORTS_TAB;
      if (array_key_exists('profile', $_POST) && ($_POST['profile'] == 1))
      	$vistabs |= PROFILE_TAB;

      $retval = $session->register($_POST['user'], $_POST['pass'], 
		      $_POST['updlevel'],$_POST['email'], $_POST['contact_id'],
		      	$vistabs);
      
      if ($retval == 0)    /* Registration Successful */
      {
         $_SESSION['reguname'] = $_POST['user'];
         $_SESSION['regsuccess'] = true;
         header("Location: ".$session->referrer);
	 echo "User ".$_POST['user']." created.<br>";
      }
      else if ($retval == 1)    /* Error found with form */
      {
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
         header("Location: ".$session->referrer);
	 $x = "User ".$_POST['user']." creation form has errors";
	 /* rlc_web_title($x, "login_create_user.php"); */
	 /* rlc_web_hidden("form", $form); */
	/* finish_page("Back to form", 0, 0); */
      }
      else if ($retval == 2)    /* Registration attempt failed */
      {
         $_SESSION['reguname'] = $_POST['user'];
         $_SESSION['regsuccess'] = false;
	 $x =  "User ".$_POST['user']." creation failed";
	 rlc_web_title($x, "login_create_user.php");
         /* header("Location: ".$session->referrer); */
	 rlc_web_hidden("reguname", $_SESSION['reguname']);
	 rlc_web_hidden("regsuccess", false);
	 finish_page("Back to form", 0, 0);
      }
   }
   
   /*
    * procForgotPass - Validates the given username then if
    * everything is fine, a new password is generated and
    * emailed to the address the user gave on sign up.
    */
   function procForgotPass()
   {
      global $database, $session, $mailer, $form;
      /* Username error checking */
      $subuser = $_POST['user'];
      $field = "user";  //Use field name for username
      if(!$subuser || strlen($subuser = trim($subuser)) == 0){
         $form->setError($field, "* login incorrect<br>");
      }
      else{
         /* Make sure username is in database */
         $subuser = stripslashes($subuser);
         if(strlen($subuser) < 4 || strlen($subuser) > 30 ||
            !preg_match("/^([0-9a-z])+$/", $subuser) ||
            (!$database->usernameTaken($subuser))){
            $form->setError($field, "* login incorrect<br>");
         }
      }
      
      /* Errors exist, have user correct them */
      if($form->num_errors > 0){
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
      }
      /* Generate new password and email it to user */
      else{
         /* Generate new password */
         $newpass = $session->generateRandStr(8);
         
         /* Get email of user */
         $usrinf = $database->getUserInfo($subuser);
         $email  = $usrinf['email'];
         
         /* Attempt to send the email with new password */
         if($mailer->sendNewPass($subuser,$email,$newpass)){
            /* Email sent, update database */
            $database->updateUserField($subuser, "password", md5($newpass));
            $_SESSION['forgotpass'] = true;
         }
         /* Email failure, do not change password */
         else{
            $_SESSION['forgotpass'] = false;
         }
      }
      
      header("Location: ".$session->referrer);
   }
   
   /*
    * procEditAccount - Attempts to edit the user's account
    * information, including the password, which must be verified
    * before a change is made.
    */
   function procEditAccount()
   {
      global $session, $form;
      /* Account edit attempt */
      $retval = $session->editAccount($_POST['curpass'], $_POST['newpass'], 
					$_POST['newpass2'],
					$_POST['email'], $_POST['contact_id']);

      if ($retval)    /* Account edit successful */
      {
         $_SESSION['useredit'] = true;
	 rlc_web_header(RLC_MENU_PROFILE, $session);
	 rlc_web_title("Account Edit", "rlc_profile.php");
	 rlc_web_info("Account Edit Successful");
	 finish_page("BACK", 0, 0);
      }
      else    /* Error found with form */
      {
         $_SESSION['value_array'] = $_POST;
         $_SESSION['error_array'] = $form->getErrorArray();
         header("Location: ".$session->referrer);
      }
   }
};

/* Initialize process */
$process = new Process;

?>
