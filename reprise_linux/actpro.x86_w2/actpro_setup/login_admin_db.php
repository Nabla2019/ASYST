<?php
/**
 * admin_db.php
 *
 *	Administer the RLC database.
 *
 *	M. Christiano
 *	4/21/10
 *
 */
include("login_session.php");


/**
 * User not an administrator, redirect to main page
 * automatically.
 */
if(!$session->isAdmin()){
   /* header("Location: rlc_menu.php"); */
   header("Location: rlc_info.php");
}
else{
/**
 * Administrator is viewing page, so display all
 * forms.
 */
?>
<html>
<title>Administer RLC Database</title>
<body class=info>
<h2>Administer RLC Database</h2>
<hr>
<table align="left" border="0" cellspacing="1" cellpadding="1">
<?php
if($form->num_errors > 0){
   echo "<font size=\"4\" color=\"#ff0000\">"
       ."!*** Error with request, please fix</font><br><br>";
}
?>
<table align="left" border="0" cellspacing="5" cellpadding="5">
<tr>
<td>

<?php
/*
 *	RLC database adminstration
 */
include("rlc_admin_db.php");
?>

</td></tr> 


<?php
finish_page(0, 0, 0);
}
?>
