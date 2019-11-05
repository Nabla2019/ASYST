<?php
/**
 * portal_menu.php
 *
 * This is the main menu for the RLM Activation Pro customer portal page.
 * The menu appears on tabs near the top of the page.
 *
 */

define ("RLC_MENU_PROD", 1);
define ("RLC_MENU_KEY", 2);
define ("RLC_MENU_FULFILL", 3);
define ("RLC_MENU_ABOUT", 7);

    function portal_main_menu($menu)
    {

	echo '<div class="rlc_menu"> <nav> <ul>';
	$p = $k = $f = $c = $r = $a = $about = "";
	switch ($menu)
	{
	    case RLC_MENU_PROD:
      		$p = "id=menu-select";
		break;
	    case RLC_MENU_KEY:
      		$k = "id=menu-select";
		break;
	    case RLC_MENU_FULFILL:
      		$f = "id=menu-select";
		break;
	    case RLC_MENU_ABOUT:
      		$about = "id=menu-select";
		break;
	}
/*
 *	Uncomment this next line to enable product definitions in the
 *	customer portal
 */
/*
	echo "<li><a $p href=portal_show_prod.php target=_self>Products</a></li>";
*/
	echo "<li><a $k href=portal_show_key.php target=_self>Activation Keys</a></li>";
	echo "<li><a $f href=portal_show_fulfill.php target=_self>Fulfillments</a></li>";
	echo "<li><a $about href=portal_info.php target=_self>About</a></li>";
	echo "</ul></nav></div>";
    }

?>
