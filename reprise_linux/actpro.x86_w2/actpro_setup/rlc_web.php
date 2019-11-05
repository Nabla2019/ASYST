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

 	$Id: rlc_web.php,v 1.26 2017/08/09 20:54:11 matt Exp $

 *****************************************************************************/

/*
 *	RLC web interface
 */

/******************************************************************************
rlm_web_table.c
 */

function rlc_web_start_table() { echo"<table border=0>"; }

$bgcolor = "#ffffff";

function rlc_web_tableheader($firstxtra="", $secondxtra="")
{
    echo"<table $firstxtra border=1 cellpadding=2 cellspacing=0 $secondxtra>";
}

function rlc_web_tableheader_blank()
{
	  echo"<table border=0 cellpadding=2 cellspacing=2>";
}


function rlc_web_row_start()
{
	echo "<tr>";
}

function rlc_web_row_end()
{
	echo "</tr>";
}

function rlc_web_table_end($br=1)
{
  global $bgcolor;

	echo "</table></ul>";
	if ($br) echo "<br>";
	$bgcolor = "#ffffff";
}

function rlc_web_header_elem($text, $xtra, $col, $sc, $sd, $numeric=0)
{
	if ($numeric) 
	{
	    $plus = "%2B0";	/* +0 escaped */
	    $p = "+0";
	}
	else 
	{
	    $p = $plus = "";
	}
	$image = "";
	if ($col == "")
	{
	    echo "<td align=center>".$text."</td>";
	}
	else
	{
	    if ($col.$p != $sc)
	    {
		$aflags = "href=\"?".$xtra."&sc=".$col.$plus."&sd=a\">";
	    }
	    else if ($sd == "d")
	    {
		$aflags = "href=\"?".$xtra."&sc=".$col.$plus."&sd=a\">";
		$image = "<img src=\"images/arrow_down.png\" border=\"0\">";
	    }
	    else 
	    {
		$aflags = "href=\"?".$xtra."&sc=".$col.$plus."&sd=d\">";
		$image = "<img src=\"images/arrow_up.png\" border=\"0\">";
	    }
	    echo "<td align=center><a ".$aflags.$text." ".$image."</a></td>";
	}
}

function rlc_web_table_image($img)
{
	echo "<td><img src=\"$img\" alt=\"^\"></img></td>";
}

function rlc_web_row_elem($str)
{
  global $bgcolor;

	if (!$str || ($str == "") || $str == " ") $s = "&nbsp;";
	else			   $s = $str;
	echo "<td align=center bgcolor=$bgcolor>$s</td>";
}

function rlc_web_row_elem_bold($str)
{
  global $bgcolor;

	if ($str) $s = $str;
	else	   $s = "-";
	echo"<td align=center bgcolor=$bgcolor><b>$s</b></td>";
}

function rlc_web_row_elem_num($num)
{
  global $bgcolor;

	if (!$num || ($num == "") || $num == " ") $num = "0"; /* "&nbsp;"; */
	echo "<td align=center bgcolor=$bgcolor>$num</td>";
}

function rlc_web_grey_bg()
{
  global $bgcolor;

	$bgcolor = "#bbbbbb";
}

function rlc_web_light_grey_bg()
{
  global $bgcolor;

	$bgcolor = "#dddddd";
}

function rlc_web_normal_bg()
{
  global $bgcolor;

	$bgcolor = "#ffffff";
}

function rlc_web_button($target, $display, $extra, $table=0)
{
  global $bgcolor;

	if ($table) echo "<td bgcolor=".$bgcolor." align=center>";
	echo "<form action=\"".$target."\" method=POST>";
	echo $extra."<input class=button type=submit name=ok value=\"$display\">";
	echo "</form>";
	if ($table) echo "</td>";
}

function rlc_web_button_invis($table=0)
{
  global $bgcolor;

	if ($table) echo "<td bgcolor=".$bgcolor." align=center>";
	echo "<form action=\"\" method=POST>";
	echo "<input type=hidden class=button type=submit name=ok value=0>";
	echo "</form>";
	if ($table) echo "</td>";
}

function rlc_web_clickbutton($display, $onclick, $table=1, $id="")
{
  global $bgcolor;

	if ($table) echo "<td bgcolor=".$bgcolor." align=center>";
	echo "<input type=button value=\"$display\"";
	if ($id != "") echo " id=$id";
	echo ' onClick="'.$onclick.'";></input>';
	if ($table) echo "</td>";
}

/*
 *	Web button with an image
 */
function rlc_web_button_i($form, $display, $text, $extra, $table=0)
{
  global $bgcolor;
	
	if ($table) echo "<td bgcolor=".$bgcolor." align=center>";
	echo "<form action=$form method=POST>";
	$image = "img src=\"".$display."\" border=\"0\" alt=\"".$text."\"";
	echo $extra."<input class=button type=image name=ok ".$image."/>";
	echo "</form>";
	if ($table) echo "</td>";
}

/*
 *	Button inside a table
 */

function rlc_web_button_t($form, $display, $extra)
{
	rlc_web_button($form, $display, $extra, 1);
}

function rlc_web_checkbox($prompt, $name, $value, $on=0, $table=0)
{
  global $bgcolor;

	if ($on) $checked=" checked=true"; else $checked = "";
	if ($table) 
	{
	    if ($prompt != "")
		echo "<td bgcolor=".$bgcolor." align=center>";
	    $tab = "<td>";
	    $tabdataend = "</td>";
	    
	}
	else 
	{
	    $tab = "";
	    $tabdataend = "";
	}
	if ($prompt != "") echo "$prompt: $tabdataend";

	echo "$tab <input type=checkbox name=$name value=\"$value\"$checked>";
	echo $tabdataend;
}


/******************************************************************************
rlm_web_utils.c
 */

include 'rlc_menus.php';
include 'rlc_login.php';


function rlc_web_header($thismenu=0, $session=0)
{
	echo '<html>';
	echo '<Copyright &copy; Reprise Software Inc., 2006-2017. All Rights Reserved></copyright>';
	echo '<HEAD><LINK REL="stylesheet" HREF="rlc.css" TYPE="text/css">';

	echo '<script type="text/javascript"> function rlcFormClear(form) {';
	echo 'var i;  for(i=0; i< form.length; i++) { ';
	echo 'if (form.elements[i].type == "text") ';
	echo '	form.elements[i].value = ""; } } ';
	echo '</script>'; 

	echo '<script type="text/javascript">';
	echo ' function rlcCheckAll() {';
	echo 'var checkboxes = document.getElementsByTagName("input"); var i;';
	echo 'for (i=0; i<checkboxes.length; i++) { ';
	echo 'if (checkboxes[i].type.toUpperCase()=="CHECKBOX") {';
	echo '	checkboxes[i].checked = 1;  } } }';
	echo '</script>'; 

	echo '<script type="text/javascript">';
	echo ' function rlcClearAll() {';
	echo 'var checkboxes = document.getElementsByTagName("input"); var i;';
	echo 'for (i=0; i<checkboxes.length; i++) { ';
	echo 'if (checkboxes[i].type.toUpperCase()=="CHECKBOX") {';
	echo '	checkboxes[i].checked = 0;  } } }';
	echo '</script>'; 

	echo '</head>';

	echo '<title>rlc - RLM License Center for Activation Pro</title>';
	echo '<meta http-equiv="Content-type" content="text/html;charset=UTF-8">';
	echo '<body>';
	echo '<iframe id="logo" SRC="images/repriselogo.gif">Reprise Software, Inc.';
	echo '</iframe>';

	echo "<program_title>";
	echo "<h0>RLM License Center (RLM Activation Pro)</h0>";
	echo "<h5>Copyright &copy; 2006-2017, Reprise Software, Inc.  All Rights Reserved.</h5>";
	echo "</program_title>";

	/* echo '<iframe id="login" SRC="rlc_login.php"> </iframe>'; */
	rlc_login($session);
	rlc_main_menu($thismenu, $session);

	echo '<div id=disp>';
}

/*
 *	Version for the setup programs.
 */
function rlc_setup_header($pagetitle)
{
	echo '<html>';
	echo '<Copyright &copy; Reprise Software Inc., 2006-2017. All Rights Reserved></copyright>';
	echo '<HEAD><LINK REL="stylesheet" HREF="rlc.css" TYPE="text/css">';
	echo '</head>';

	echo '<title>rlc - RLM Activation Pro SETUP</title>';
	echo '<meta http-equiv="Content-type" content="text/html;charset=UTF-8">';
	echo '<body>';
	echo '<iframe id="logo" SRC="images/repriselogo.gif">Reprise Software, Inc.';
	echo '</iframe>';

	echo "<program_title>";
	echo "<h0>RLM Activation Pro SETUP</h0>";
	echo "<h5>Copyright &copy; 2006-2017, Reprise Software, Inc.  All Rights Reserved.</h5>";
	echo "</program_title>";

	if ($pagetitle != "") echo "<h2>$pagetitle</h2>";
	echo '<div id="disp">';
}

function rlc_web_title($text, $target, $id="")
{
	if ($text != "") echo "<h2>$text</h2>";
	if ($target)	 echo "<form $id action=$target method=POST>";
}

function rlc_web_form($target)
{
	echo "<form action=$target method=POST>";
}


function rlc_web_info($text)
{
	/* echo "<div id=\"info\">$text</div>"; */
	/* echo "<info><table><tr><td>$text</td></tr></table></info>"; */
	echo "<div id=info>$text</div>";
}

/******************************************************************************
rlm_web_form.c
 */


function finish_form($submitlabel, $extra)
{
	echo "</table>";
	echo "<br><input class=button type=submit name=ok value=\"$submitlabel\">$extra</form>\n";
}

function finish_page_extra($submitlabel, $canceltext, $cancel, $firstbutton, 
		$firstaction, $secondbutton, $secondaction, $extra, $extra2,
		$cancelextra = "")
{
	echo "</table>";


	if ($submitlabel)
	{
	    echo "<br>";
	    echo "<input class=button type=submit name=ok value=\"$submitlabel\">$extra";
	}
	echo "</form>\n";
	if ($firstbutton) 
	{
	    echo "<br>";
	    rlc_web_button($firstaction, $firstbutton, $extra);
	}
	if ($secondbutton) 
	{
	    echo "<br>";
	    rlc_web_button($secondaction, $secondbutton, $extra2);
	}
	if ($cancel)
	{
	    if (!$canceltext) $canceltext = "BACK";
	    echo "<br>";
	    if ($cancelextra != "") $extra = $cancelextra;
	    rlc_web_button($cancel, $canceltext, $extra);
	}
	echo "</div></body></html>";
}

function finish_page($submitlabel, $canceltext, $cancel)
{
	finish_page_extra($submitlabel, $canceltext, $cancel, 0, 0, 0, 0, "", 
									"");
}


function rlc_web_hidden_string($what, $val)
{
	return "<input type=hidden name=$what value=\"$val\">";
}

function rlc_web_hidden($what, $val)
{
	echo "<input type=hidden name=$what value=\"$val\">";
}


/*
 *	Routines for the buttons
 */


/*
 *	Delete button; it's own form
 */
function rlc_web_delete_button($form, $extra)
{
	rlc_web_button_i($form, "images/delete.png", "Delete", $extra, 1);
}

/*
 *	Delete button, within the enclosing form
 */

function rlc_web_delete_form_button($action, $extra, $table=1)
{
  global $bgcolor;
	
	if ($table) echo "<td bgcolor=".$bgcolor." align=center>";
	/* $image = "img src=\"images/delete.png\" border=\"0\" alt=\"Delete Checked\""; */
	$image = "img src=\"images/delete.png\" alt=\"Delete Checked\"";
	echo $extra."<input class=button type=image action=$action method=POST ".$image."/>";
	if ($table) echo "</td>";
}

function rlc_web_merge_form_button($action, $which, $text)
{
  global $bgcolor;
	
	echo "<td bgcolor=".$bgcolor." align=center>";
	echo "<input class=button type=submit name=$which value=\"$text\">";
	echo "</td>";
}

function edit_button($form, $extra)
{
	rlc_web_button_i($form, "images/edit.png", "Edit", $extra, 1);
}

function dummy_edit_button($form, $extra)
{
	echo "<form action=$form method=POST></form>";
}


function rlc_show_button($form, $extra)
{
	rlc_web_button_i($form, "images/show.png", "Show", $extra, 1);
}

/*
 *	Routines for prompting for data items
 */

function rlc_web_show_var($prompt, $val)
{
	echo "<tr><td>$prompt: </td> <td><b>$val</b></td></tr>";
}

function rlc_web_show_var_trailing($prompt, $trail, $val)
{
	echo "<tr><td>$prompt: </td> <td><b>$val</b>&nbsp $trail</td></tr>";
}

function rlc_web_start_prompt()
{
	echo "<br><table border=0 cellpadding=3 cellsapcing=3>";
}

function rlc_web_start_prompt_box()
{
	echo "<br><table border=1 cellpadding=\"3\" cellsapcing=\"3\">";
}

/*
 *	See if rpp is set, if so, set the cookie
 */

function _set_rpp($cookie_name, $rpp)
{
	if ((array_key_exists($cookie_name, $_COOKIE)) &&
	    ($rpp == $_COOKIE[$cookie_name])) return;
/*
 *	Either we don't have it, or it has changed - write it.
 */
	$val = "";
	$val = $val + $rpp;
	setcookie($cookie_name, $val, time() + 2592000);
				/* 30 days = 2592000 = 60*60*24*30 */
}

function rlc_web_rpp($cookie_name)
{
	if (array_key_exists('rpp', $_GET)) 
					_set_rpp($cookie_name, $_GET['rpp']);
	else if (array_key_exists('rpp', $_POST)) 
					_set_rpp($cookie_name, $_POST['rpp']);
}


/*
 *	Get the pagination parameters from either a GET or POST
 */

function rlc_web_get_pagination(&$r1, &$rpp, &$tr, &$sc, &$sd, $rppcookie)
{
	if (array_key_exists('r1', $_GET))
	{
 		$r1 = $_GET['r1'];
		if (array_key_exists('tr', $_GET)) $tr = $_GET['tr'];
		else				   $tr = 0;
		if (array_key_exists('sc', $_GET)) $sc = $_GET['sc'];
		else				   $sc = ""; 
		if (array_key_exists('sd', $_GET)) $sd = $_GET['sd'];
		else				   $sd = ""; 
		$get = 1;
	}
	else
	{
		$tr = 0;
		$r1 = 1;
		$sc = "";
		$sd = "";
		$get = 0;
	}
	if (array_key_exists('rpp', $_GET)) $rpp = $_GET['rpp'];
	else if (array_key_exists($rppcookie, $_COOKIE)) 
					    $rpp = $_COOKIE[$rppcookie];
	else				    $rpp = RLC_ROWS_PER_PAGE;


/*
 *	Force Row 1 to the top of the page.
 */
	$r1 = $r1 - (($r1 - 1) % $rpp);

	/****
	echo "<br>get: ".$get;
	echo "<br>r1: ".$r1;
	echo "<br>tr: ".$tr;
	echo "<br>rpp: ".$rpp;
	/***/

	return($get);
}

/*
 *	Put pagination links at the top/bottom of the list.
 */

function rlc_web_paginate($name, $extra, $pxtra, $rpp, $r1, $lr, $tr, $sc, $sd,
								$seldisp)
{
/*
 *	sc (sort column) may have a +0 for numeric sort.  need to quote it.
 */
	_rlc_html_quote_string($sc, $sort);
	if ($lr == 0)
		echo "<br> No Records to display";
	else if ($lr > 0)
		echo "Records ".$r1." to ".$lr." of (".$tr.") displayed";
	if ($seldisp != "")
		echo "<br>$seldisp<br>";
/*
 *	If it all fits on 1 page, we are done.
 */
	if ($rpp < $tr) 
	{
	    if ($rpp <= 0) $rpp = 1;
	    $pagenum = (int) ($r1/$rpp) + 1;
	    if (($r1 % $rpp) == 0) $pagenum--;
	    $firstpage = $pagenum - 4;
	    if ($firstpage <= 1) 
	    {
		$firstpage = 1;
		$prevpages = false;
	    }
	    else
		$prevpages = true;

	    $endpage = (int) ($tr/$rpp);
	    if ($tr % $rpp) $endpage++;
	    $lastpage = $firstpage + 9;
	    if ($lastpage > $endpage) 
	    {
		$lastpage = $endpage;
		$morepages = false;
		$firstpage = $lastpage - 9;
		if ($firstpage <= 1) 
		{
			$firstpage = 1;
			$prevpages = false;
		}
	    }
	    else
		$morepages = true;

	    /***
	    if ($lr > 0)
	    {
	    echo "<br>pagenum: ".$pagenum;
	    echo "<br>firstpage: ".$firstpage;
	    echo "<br>lastpage: ".$lastpage;
	    echo "<br>morepages: ".$morepages;
	    echo "<br>endpage: ".$endpage;
	    echo "<br>rpp: ".$rpp;
	    echo "<br>r1: ".$r1;
	    echo "<br>tr: ".$tr;
	    }
	    /***/

	    echo "<ul class=\"pages\">";
	    echo "<br><b>Pages:</b> ";
	    $fix = $extra."&sc=".$sort."&sd=".$sd."&tr=".$tr."&rpp=".$rpp."&";
	    _rlc_html_quote_string($fix, $fixed);		/* P254 */

	    /****
	    echo "Fixed data for buttons: $fixed<br>";
	    ****/

	    if ($firstpage > 1)
	    {
		$fr = 1;
		echo "<a href=\"?r1=1&".$fixed."\"><b>FIRST</b></a> ";
	    }
	    if ($prevpages) 
	    {
		$fr = (($firstpage-2)*$rpp)+1;
		echo "<a href=\"?r1=".$fr."&".$fixed."\"><b>&laquo;</b></a> ";
	    }
		
	    for ($page = $firstpage; $page <= $lastpage; $page++)
	    {
		$fr = (($page-1)*$rpp)+1;
		if ($page == $pagenum) 
			echo "<class=\"active\">".$page." ";
		else
			echo " <a href=\"?r1=".$fr."&".$fixed."\"><b>".$page.
								"</b></a> ";
	    }
	    if ($morepages) 
	    {
		$fr = ($lastpage*$rpp)+1;
		echo "<a href=\"?r1=".$fr."&".$fixed."\"><b>&raquo;</b></a> ";
		$fr = (($endpage-1)*$rpp)+1;
		echo "<a href=\"?r1=".$fr."&".$fixed."\"><b>LAST </b></a>";
	    }
	    echo "</ul>";
	}
	if ($lr > 0)
	{
		echo "<form action=$name><br>";
		echo "<ul class=\"pages\">";
		$fix =  $pxtra.
			"<input type=hidden name=r1 value=$r1>".
			"<input type=hidden name=tr value=$tr>".
			"<input type=hidden name=sc value=$sort>".
			"<input type=hidden name=sd value=$sd>";
		echo $fix;
		echo "Items to display: ";
		echo "<input type=text size=3 name=rpp value=$rpp>";
		echo "</ul></form>";
	}
	if ($lr < 0) echo "<br>";
}

/*
 *	Display the selection bar at the top of the browser.
 */

function rlc_web_browse_select($form, $sel_data, $head, $cols)
{
	echo "<div id='b-sel' class='browse-sel'>";
	echo "<form method='get' action=$form>";
    	echo "<table border='0' cellspacing='0' cellpadding='0' id='browser'>";
        echo "<tr> <td>&nbsp;</td>";
	foreach ($head as $h) echo "<td>&nbsp;$h</td>";
        echo "<td>&nbsp;</td> </tr> <tr>";
	echo "<td><b>Select:&nbsp;&nbsp;</b></td>";
	foreach ($cols as $col)
	{
		$z = "";
		_rlc_remove_dot("s-".$col, $name);
		if (array_key_exists($name, $sel_data)) $z = $sel_data[$name];
        	echo '<td><input type=text name='.$name.' size=14 maxlength=60';
		echo "	value='".$z."' style='padding: 2px; width: 110px;' /></td>";
	}
        echo ' <td><input type="submit" value="Show..." /></td>';
        echo ' <td><input type="button" onclick="rlcFormClear(this.form)" '.
			'value="Clear Selections" /></td>';
	echo '</tr></table></form></div>';
}

/*
 *	Retrieve the selection criteria from a POST or GET
 */
function rlc_web_get_select($cols, &$sel_data, &$xtra, &$pxtra)
{
	$gotone = 0;
	$select = $xtra = $pxtra = "";

	$data = $_POST;
	if (count($_GET) > 0) $data = $_GET;

	foreach ($cols as $col)
	{
	    _rlc_remove_dot("s-".$col, $name);
	    if (array_key_exists($name, $data) && ($data[$name] != ""))
	    {
		$sel = $data[$name];
		if ($sel == "*") continue;
		if ($sel[0] == '*') $sel = '.'.$sel;
		$sel_data[$name] = $sel;		/* Pass it back */

		if ($col == "product_id" && $data[$name] == "*all*") continue;

		$pxtra .= "<input type=hidden name=$name value='$sel'>";
		$xtra .= "$name=$sel&";

		if ($col == "product_id") $op = "=";	
		else $op = "REGEXP";

		if ($gotone) 
			$select = $select." AND $col $op '".$sel."'";
		else 
			$select = " WHERE $col $op '" . $sel . "'";
		$gotone = 1;
	    }
	}
	return($select);
}

function rlc_web_del_multiple($target, $tip="")
{
	rlc_web_tableheader_blank();
	rlc_web_row_start();
	rlc_web_table_image("images/arrow_left_up.png");
	rlc_web_clickbutton("Check All", "rlcCheckAll()");
	rlc_web_clickbutton("Clear All", "rlcClearAll()");
	rlc_web_delete_form_button($target,
		"<input type=hidden name=".DELETE_MULTIPLE." value=0>");
	rlc_web_row_elem($tip);
	rlc_web_row_end();
	rlc_web_table_end();
}

function rlc_web_sel_multiple($target, $tip="")
{
	rlc_web_tableheader_blank();
	rlc_web_row_start();
	rlc_web_row_elem("To merge, select 2 lines above: ");
	rlc_web_merge_form_button($target, MERGE_CONTACTS, "Merge Contacts");
	echo "&nbsp;";
	rlc_web_merge_form_button($target, MERGE_COMPANIES, "Merge Companies");
	rlc_web_row_elem($tip);
	rlc_web_row_end();
	rlc_web_table_end();
}
?>
