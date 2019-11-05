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

 	$Id: rlc_admin_black.php,v 1.8 2016/04/08 02:55:45 matt Exp $

 *****************************************************************************/

include 'rlc.php';
include 'rlc_mysql.php';
include 'login_session.php';

    rlc_web_header(RLC_MENU_ADMIN, $session);

    if ($session->isAdmin())
    {
	rlc_admin_menu(RLC_ADMIN_MENU_BLACKLIST);

/*
 *	The list of blacklisted hosts
 */
	$count = 0;

	rlc_web_rpp("rlc-rpp-blk");
	rlc_web_title("Activation BLACKLISTED domains", 0);

	$get = rlc_web_get_pagination($r1, $rpp, $tr, $sc, $sd, "rlc-rpp-blk");

	rlc_web_info("These domains will not be able to perform any activation functions on your activation server.<br><br>Note: The blacklist code does not require an exact domain name match, the name on<br>the blacklist only need match a substring of the actual domain name.  Therefore,<br>placing \"foo.bar\" on the blacklist will blacklist not only \"foo.bar\" but also \"xyz.foo.bar\", etc.<br><br>The auto-blacklisting parameters are specified in the \"Database\" tab, above.");

	$sql = rlc_mysql_init($isv);
	$stat = rlc_mysql_get_black($sql, $black, $sc, $sd);

	if ($stat != 0)
	{
	    rlc_web_info("There are no domains in the blacklist<br>Activation Blacklist database is empty.<br>");
	    $tmp = sprintf("Status: %d<br>", $stat);
	    rlc_web_info($tmp);
	    finish_page(0, 0, 0);
	    rlc_mysql_close($sql);
	    return;
	}
	if ($tr == 0)
	{
	    $tr = mysqli_num_rows($black);
	}
	if ($r1 > 1)
	{
	    mysqli_data_seek($black, $r1-1);
	}
	rlc_web_tableheader();
	rlc_web_row_start();
	$xtra = "rpp=".$rpp."&tr=".$tr;
	rlc_web_header_elem("Blacklisted domains", $xtra, "domain", $sc, $sd);
	rlc_web_row_end();
	$numdisp = 0;

	while ($row = mysqli_fetch_array($black, MYSQLI_ASSOC))
	{
	    $count++;
	    rlc_web_row_start();
	    rlc_web_row_elem($row['domain']);

/*
 *	    The buttons
 */
	    $extra = "<input type=hidden name=black_id value=".$row['id'].
				"><input type=hidden name=black_domain value='"
				.$row['domain']."'>";
	    rlc_web_delete_button("rlc_del_black.php", $extra);
	    rlc_web_row_end();
	    $numdisp++;
	    if ($numdisp >= $rpp) break;
	}
/*
 *	The add field
 */
	echo "<form action=rlc_add_black.php method=POST>";
	echo "<tr><td><input type=text name=newblack size=64></td>";
	$image = "img src=\"images/add.png\" border=\"0\" alt=\"Add\"";
	echo "<td><input class=button type=image name=Add ".$image.
					" /> </tr></td></form>";
	rlc_web_table_end();
	mysqli_free_result($black);
	rlc_mysql_close($sql);

	rlc_web_paginate("rlc_show_black.php", "", "", $rpp, $r1, 
					$r1 + $numdisp - 1, $tr, $sc, $sd, "");
	finish_page(0, 0, 0);
    }
?>
