<?php
/*****************************************************************************

	    COPYRIGHT (c) 2010, 2016 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_admin_debug.php,v 1.8 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_DEBUG);
?>
	<h3>Debug Logging</h3>

	<form enctype="multipart/form-data" action="rlc_debuglog.php" 
							method="POST">
	Select: <input type='text' name='select'> &nbsp;&nbsp;
	<input type='submit' value='View Debug Log'> </form>
	<br>
	<form enctype="multipart/form-data" action="rlc_debuglog.php" 
							method="POST">
	<input type='submit' value='Enable Debug Logging'> 
	<input type='hidden' name='turn_on_log' value='turn_on_log'> </form>
	<br>
	<form enctype="multipart/form-data" action="rlc_debuglog.php" 
							method="POST">
	<input type='submit' value='Disable Debug Logging'> 
	<input type='hidden' name='turn_off_log' value='turn_off_log'> </form>
<?php
   }
?>
