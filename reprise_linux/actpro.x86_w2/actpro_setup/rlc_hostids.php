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

 	$Id: rlc_hostids.php,v 1.13 2017/09/07 18:22:06 matt Exp $

 *****************************************************************************/


/*
 *	Display/decode the allowed hostids
 */


define("ACTPRO_ALLOW_REHOST", 0x1);	/* Rehostable hostids */
define("ACTPRO_ALLOW_ISV",    0x2); 	/* ISV-defined hostids */
define("ACTPRO_ALLOW_RLMID",  0x4);	/* RLMID hostids */
define("ACTPRO_ALLOW_ETHER",  0x8);	/* Ethernet hostids */
define("ACTPRO_ALLOW_32",     0x10);	/* 32-bit hostids */
define("ACTPRO_ALLOW_DISKSN", 0x20);	/* Disk Serial number hostid */
define("ACTPRO_ALLOW_IP",     0x40);	/* IP address hostids */
define("ACTPRO_ALLOW_USER",   0x80);	/* Username hostid */
define("ACTPRO_ALLOW_HOST",   0x100);	/* Hostname hostid */
define("ACTPRO_ALLOW_SN",     0x200);	/* Serial Number hostid */
define("ACTPRO_ALLOW_STRING", 0x400);	/* String hostid */
define("ACTPRO_ALLOW_DEMO",   0x1000);	/* "DEMO" hostid */
define("ACTPRO_ALLOW_ANY",    0x2000);	/* "ANY" hostid */
define("ACTPRO_ALLOW_ASH",    0x4000);	/* Alternate Server/Nodelock hostid */
define("ACTPRO_ALLOW_ISVDEF", 0x8000);	/* ISV-defined string */
define("ACTPRO_ALLOW_IPV6",   0x10000);	/* IPv6 hostid (12.1?) */
define("ACTPRO_ALLOW_UUID",   0x20000);	/* UUID hostid (12.2) */

function rlc_hostid_checkbox($prompt, $name, $on=0, $table=0, $tdname="",
						$dispname="")
{
	if ($on) $checked=" checked=true"; else $checked = "";
	if ($table) 
	{
	    if ($prompt != "") echo "<td align=center>";
	    $tab = "</td><td $tdname>";
	}
	else $tab = "";

	if ($prompt != "")
	  echo "$prompt: $tab <input type=checkbox name=$name value=\"y\"$checked>";
	else
	  echo "$tab <input type=checkbox name=$name value=\"y\"$checked>";
	if ($dispname != "") echo $dispname; else echo $name;  
	echo "&nbsp";
	if ($table) echo "</td>";
}

function rlc_set_hostids($post)
{
	$val = 0;

	if (array_key_exists('rehostable', $post) && ($post['rehostable']=='y'))
						$val |= ACTPRO_ALLOW_REHOST;
	if (array_key_exists('isv-defined', $post) && 
			($post['isv-defined'] == 'y'))
						$val |= ACTPRO_ALLOW_ISV;
	if (array_key_exists('isv-string', $post) && 
			($post['isv-string'] == 'y'))
						$val |= ACTPRO_ALLOW_ISVDEF;
	if (array_key_exists('rlmid', $post) && ($post['rlmid'] == 'y'))
						$val |= ACTPRO_ALLOW_RLMID;
	if (array_key_exists('ethernetMACaddr', $post) && 
			($post['ethernetMACaddr'] == 'y'))
						$val |= ACTPRO_ALLOW_ETHER;
	if (array_key_exists('32-bit', $post) && ($post['32-bit'] == 'y'))
						$val |= ACTPRO_ALLOW_32;
	if (array_key_exists('diskSerial#', $post) && 
			($post['diskSerial#'] == 'y'))
						$val |= ACTPRO_ALLOW_DISKSN;
	if (array_key_exists('IPaddress', $post) && ($post['IPaddress'] == 'y'))
						$val |= ACTPRO_ALLOW_IP;
	if (array_key_exists('username', $post) && ($post['username'] == 'y'))
						$val |= ACTPRO_ALLOW_USER;
	if (array_key_exists('hostname', $post) && ($post['hostname'] == 'y'))
						$val |= ACTPRO_ALLOW_HOST;
	if (array_key_exists('serial#', $post) && ($post['serial#'] == 'y'))
						$val |= ACTPRO_ALLOW_SN;
	if (array_key_exists('string', $post) && ($post['string'] == 'y'))
						$val |= ACTPRO_ALLOW_STRING;
	if (array_key_exists('demo', $post) && ($post['demo'] == 'y'))
						$val |= ACTPRO_ALLOW_DEMO;
	if (array_key_exists('any', $post) && ($post['any'] == 'y'))
						$val |= ACTPRO_ALLOW_ANY;
	if (array_key_exists('AlternateServerHostid', $post) && 
			     ($post['AlternateServerHostid'] == 'y'))
						$val |= ACTPRO_ALLOW_ASH;
	if (array_key_exists('UUID', $post) && ($post['UUID'] == 'y'))
						$val |= ACTPRO_ALLOW_UUID;
	return($val);
}

?>
