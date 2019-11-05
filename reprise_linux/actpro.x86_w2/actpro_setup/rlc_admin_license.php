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

 	$Id: rlc_admin_license.php,v 1.6 2016/03/27 21:12:50 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_LICENSE);
?>

	<h3>Upload Activation PRO License File (.lic)</h3>
	<table><tr><td></td><td>
	Note: Activation PRO License files are always < 1kb.  Anything larger will fail.<br>
	</td></tr><td>
	<form enctype="multipart/form-data" action="rlc_upload_license.php" 
							method="POST">
     	<input type="hidden" name="MAX_FILE_SIZE" value="1000">
	License File: 
	</td><td>
	<input name="licensefile" size=70 type="file">
	</td><td>
	<input type="submit" value="Upload File">
	</form>
	</td></tr></table>
<?php
    }
?>
