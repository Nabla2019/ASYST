<?php
/*****************************************************************************

	    COPYRIGHT (c) 2010, 2017 by Reprise Software, Inc.
	This software has been provided pursuant to a License Agreement
	containing restrictions on its use.  This software contains
	valuable trade secrets and proprietary information of 
	Reprise Software Inc and is protected by law.  It may not be 
	copied or distributed in any form or medium, disclosed to third 
	parties, reverse engineered or used in any manner not provided 
	for in said License Agreement except with the prior written 
	authorization from Reprise Software Inc.

 	$Id: rlc_custom_cust.php,v 1.7 2017/03/07 01:02:41 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_DB);

	$sql = rlc_mysql_init($isv);	/* Get ISV name */
	for ($i=1; $i <= 10; $i++)
	{
	    rlc_mysql_read_rlc_setup($sql, 'u'.$i.'_def', $u);
	    rlc_mysql_read_rlc_setup($sql, 'u'.$i.'_numeric', $u);
	    $u[$i] = "";
	    $num[$i] = 0;
	    if (array_key_exists('u'.$i.'_def', $u)) $u[$i] = $u['u'.$i.'_def'];
	    if (array_key_exists('u'.$i.'_numeric', $u)) $num[$i] = 
	    						$u['u'.$i.'_numeric'];
	}
?>
	<table>
	<tr><td><hr></td><td><hr></td><td><hr></td></tr>


	<tr><td></td><td>

	<h3>Setup Custom Fields for Company</h3>
	</td></tr> 
	<tr><td></td><td colspan=2>
	Any non-blank field below will define the user-defined
	</td></tr><tr><td></td><td colspan=2>
	data for that position.  Defined fields appear in the
	</td></tr><tr><td></td><td colspan=2>
	customer list and company editor.
	</td></tr><tr><td></td><td>
	<form enctype='multipart/form-data' action='rlc_set_custom.php' method='POST'>
	<tr><td>
	first user defined field:
	</td><td> <input name='u1' size=20 value='<?php echo $u[1]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u1-num' value=1<?php if ($num[1] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	second user defined field:
	</td><td> <input name='u2' size=20 value='<?php echo $u[2]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u2-num' value=1<?php if ($num[2] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	third user defined field:
	</td><td> <input name='u3' size=20 value='<?php echo $u[3]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u3-num' value=1<?php if ($num[3] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	fourth user defined field:
	</td><td> <input name='u4' size=20 value='<?php echo $u[4]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u4-num' value=1<?php if ($num[2] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	fifth user defined field:
	</td><td> <input name='u5' size=20 value='<?php echo $u[5]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u5-num' value=1<?php if ($num[5] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	sixth user defined field:
	</td><td> <input name='u6' size=20 value='<?php echo $u[6]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u6-num' value=1<?php if ($num[6] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	seventh user defined field:
	</td><td> <input name='u7' size=20 value='<?php echo $u[7]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u7-num' value=1<?php if ($num[7] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	eigth user defined field:
	</td><td> <input name='u8' size=20 value='<?php echo $u[8]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u8-num' value=1<?php if ($num[8] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	ninth user defined field:
	</td><td> <input name='u9' size=20 value='<?php echo $u[9]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u9-num' value=1<?php if ($num[9] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>
	tenth user defined field:
	</td><td> <input name='u10' size=20 value='<?php echo $u[10]; ?>' > </td>
	<td>
	Numeric sort?
	</td><td>
	<input type=checkbox name='u10-num' value=1<?php if ($num[10] == 1) echo " checked=true"; ?> >
	</td></tr>
	<tr><td>&nbsp;</td><td>
	<input type='submit' value='Set User-Defined Customization'>
	</form></td></tr>
	</table>
<?php
    }
?>
