<?php
/**
 * Database.php
 * 
 * The Database class is meant to simplify the task of accessing
 * information from the website's database.
 *
 * Written by: Jpmaster77 a.k.a. The Grandmaster of C++ (GMC)
 * Last Updated: August 17, 2004
 */
include("login_constants.php");
      

function _turn_off_warnings()
{
        $e = error_reporting();
        $new = $e & ~(E_WARNING | E_NOTICE);
        error_reporting($new);
        return($e);
}

class MySQLDB
{
   var $connection;         //The MySQL database connection
   var $num_active_users;   //Number of active users viewing site
   var $num_members;        //Number of signed-up users
   /* Note: call getNumMembers() to access $num_members! */

   /* Class constructor */
   function MySQLDB(){
/* 
 *	Make a connection to the database - first read the db info
 *	from the actpro.php (or old rlmact.mysql) file.
 */

	$host = "localhost";
	$port = 3306;
	$db = "";
	$dbuser = "mysql";
	$dbpw = "mysql";
	$errlevel = _turn_off_warnings();
	$data = file(LOGIN_SQL_DBDESC);
	error_reporting($errlevel);
	$offset = 1;
	if ($data[0] == "") 
	{
	    $errlevel = _turn_off_warnings();
	    $data = file(LOGIN_SQL_DBDESC_OLD);
	    error_reporting($errlevel);
	    $offset = 0;
	}

	if ($data[$offset] != "") $host = rtrim($data[$offset]);
	if ($data[$offset+1] != "") $port = rtrim($data[$offset+1]);
	if ($data[$offset+2] != "") $db = rtrim($data[$offset+2]);
	if ($data[$offset+3] != "") $dbuser = rtrim($data[$offset+3]);
	if ($data[$offset+4] != "") $dbpw = rtrim($data[$offset+4]);

	if ($db == "")
	{
	   die("Can't open database description file ".LOGIN_SQL_DBDESC."<br>");
	}
	else
	{
	   $this->connection = mysqli_connect($host, $dbuser, $dbpw, $db, $port)
							or die(mysql_error());
	}
      
      /**
       * Only query database to find out number of members
       * when getNumMembers() is called for the first time,
       * until then, default value set.
       */
      $this->num_members = -1;
      
      if(TRACK_VISITORS){
         /* Calculate number of users at site */
         $this->calcNumActiveUsers();
      }
   }

   /**
    * confirmUserPass - Checks whether or not the given
    * username is in the database, if so it checks if the
    * given password is the same password in the database
    * for that user. If the user doesn't exist or if the
    * passwords don't match up, it returns an error code
    * (1 or 2). On success it returns 0.
    */
   function confirmUserPass($username, $password){
      /* Add slashes if necessary (for query) */
      if(!get_magic_quotes_gpc()) {
	      $username = addslashes($username);
      }

      /* Verify that user is in database */
      $q = "SELECT password FROM ".TBL_USERS." WHERE username = '$username'";
      $result = mysqli_query($this->connection, $q);
      if(!$result || (mysqli_num_rows($result) < 1)){
         return 1; //Indicates username failure
      }

      /* Retrieve password from result, strip slashes */
      $dbarray = mysqli_fetch_array($result);
      $dbarray['password'] = stripslashes($dbarray['password']);
      $password = stripslashes($password);

      /* Validate that password is correct */
      if($password == $dbarray['password']){
         return 0; //Success! Username and password confirmed
      }
      else{
         return 2; //Indicates password failure
      }
   }
   
   /**
    * confirmUserID - Checks whether or not the given
    * username is in the database, if so it checks if the
    * given userid is the same userid in the database
    * for that user. If the user doesn't exist or if the
    * userids don't match up, it returns an error code
    * (1 or 2). On success it returns 0.
    */
   function confirmUserID($username, $userid){
      /* Add slashes if necessary (for query) */
      if(!get_magic_quotes_gpc()) {
	      $username = addslashes($username);
      }

      /* Verify that user is in database */
      $q = "SELECT userid FROM ".TBL_USERS." WHERE username = '$username'";
      $result = mysqli_query($this->connection, $q);
      if(!$result || (mysqli_num_rows($result) < 1)){
         return 1; //Indicates username failure
      }

      /* Retrieve userid from result, strip slashes */
      $dbarray = mysqli_fetch_array($result);
      $dbarray['userid'] = stripslashes($dbarray['userid']);
      $userid = stripslashes($userid);

      /* Validate that userid is correct */
      if($userid == $dbarray['userid']){
         return 0; //Success! Username and userid confirmed
      }
      else{
         return 2; //Indicates userid invalid
      }
   }
   
   /**
    * usernameTaken - Returns true if the username has
    * been taken by another user, false otherwise.
    */
   function usernameTaken($username){
      if(!get_magic_quotes_gpc()){
         $username = addslashes($username);
      }
      $q = "SELECT username FROM ".TBL_USERS." WHERE username = '$username'";
      $result = mysqli_query($this->connection, $q);
      return (mysqli_num_rows($result) > 0);
   }
   
   /**
    * addNewUser - Inserts the given (username, password, email, level, name)
    * info into the database. Appropriate user level is set.
    * Returns true on success, false otherwise.
    */
   function addNewUser($username, $password, $email, $level, $contact_id,
   								$vistabs)
   {
      $time = time();
      $ulevel = $level;
      $q = "INSERT INTO ".TBL_USERS." (username, password, userid, userlevel, email, timestamp, contact_id, vistabs) VALUES ('$username', '$password', '0', $ulevel, '$email', $time, '$contact_id', '$vistabs')";
      return mysqli_query($this->connection, $q);
   }
   
   /**
    * updateUserField - Updates a field, specified by the field
    * parameter, in the user's row of the database.
    */
   function updateUserField($username, $field, $value){
      $q = "UPDATE ".TBL_USERS." SET ".$field." = '$value' WHERE username = '$username'";
      return mysqli_query($this->connection, $q);
   }
   
   /**
    * getUserInfo - Returns the result array from a mysql
    * query asking for all information stored regarding
    * the given username. If query fails, NULL is returned.
    */
   function getUserInfo($username){
      $q = "SELECT * FROM ".TBL_USERS." WHERE username = '$username'";
      $result = mysqli_query($this->connection, $q);
      /* Error occurred, return given name by default */
      if(!$result || (mysqli_num_rows($result) < 1)){
         return NULL;
      }
      /* Return result array */
      $dbarray = mysqli_fetch_array($result);
      return $dbarray;
   }
   
   /**
    * getNumMembers - Returns the number of signed-up users
    * of the website, banned members not included. The first
    * time the function is called on page load, the database
    * is queried, on subsequent calls, the stored result
    * is returned. This is to improve efficiency, effectively
    * not querying the database when no call is made.
    */
   function getNumMembers(){
      if($this->num_members < 0){
         $q = "SELECT * FROM ".TBL_USERS;
         $result = mysqli_query($this->connection, $q);
         $this->num_members = mysqli_num_rows($result);
      }
      return $this->num_members;
   }
   
   /**
    * calcNumActiveUsers - Finds out how many active users
    * are viewing site and sets class variable accordingly.
    */
   function calcNumActiveUsers(){
      /* Calculate number of users at site */
      $q = "SELECT * FROM ".TBL_ACTIVE_USERS;
      $result = mysqli_query($this->connection, $q);
      $this->num_active_users = mysqli_num_rows($result);
   }
   
   /**
    * addActiveUser - Updates username's last active timestamp
    * in the database, and also adds him to the table of
    * active users, or updates timestamp if already there.
    */
   function addActiveUser($username, $time){
      $q = "UPDATE ".TBL_USERS." SET timestamp = '$time' WHERE username = '$username'";
      mysqli_query($this->connection, $q);
      
      if(!TRACK_VISITORS) return;
      $q = "REPLACE INTO ".TBL_ACTIVE_USERS." VALUES ('$username', '$time')";
      mysqli_query($this->connection, $q);
      $this->calcNumActiveUsers();
   }
   
   /* These functions are self explanatory, no need for comments */
   
   /* removeActiveUser */
   function removeActiveUser($username){
      if(!TRACK_VISITORS) return;
      $q = "DELETE FROM ".TBL_ACTIVE_USERS." WHERE username = '$username'";
      mysqli_query($this->connection, $q);
      $this->calcNumActiveUsers();
   }
   
   /* removeInactiveUsers */
   function removeInactiveUsers(){
      if(!TRACK_VISITORS) return;
      $timeout = time()-USER_TIMEOUT*60;
      $q = "DELETE FROM ".TBL_ACTIVE_USERS." WHERE timestamp < $timeout";
      mysqli_query($this->connection, $q);
      $this->calcNumActiveUsers();
   }

   /**
    * query - Performs the given query on the database and
    * returns the result, which may be false, true or a
    * resource identifier.
    */
   function query($query){
      return mysqli_query($this->connection, $query);
   }
};

/* Create database connection */
$database = new MySQLDB;

?>
