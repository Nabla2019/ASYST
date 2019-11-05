<?php
/**
 * rlc_menus.php
 *
 * This is the main menu for the RLM Activation Pro activation page,
 *  and also the admin menu.
 * The menus appear on tabs near the top of the page.
 *
 */

define ("RLC_MENU_PROD", 1);
define ("RLC_MENU_KEY", 2);
define ("RLC_MENU_FULFILL", 3);
define ("RLC_MENU_CUST", 4);
define ("RLC_MENU_REPORTS", 5);
define ("RLC_MENU_ADMIN", 6);
define ("RLC_MENU_PROFILE", 7);
define ("RLC_MENU_ABOUT", 8);

define ("RLC_ADMIN_MENU_LICENSE", 1);
define ("RLC_ADMIN_MENU_AUDIT", 2);
define ("RLC_ADMIN_MENU_BLACKLIST", 3);
define ("RLC_ADMIN_MENU_DB", 4);
define ("RLC_ADMIN_MENU_DEBUG", 5);
define ("RLC_ADMIN_MENU_GENERATOR", 6);
define ("RLC_ADMIN_MENU_USERS", 7);
define ("RLC_ADMIN_MENU_PORTAL", 8);

    function rlc_main_menu($menu, $session)
    {

	if (!$menu && !$session) return;
	$p = $k = $f = $c = $r = $a = $prof = $about = "";
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
	    case RLC_MENU_CUST:
      		$c = "id=menu-select";
		break;
	    case RLC_MENU_REPORTS:
      		$r = "id=menu-select";
		break;
	    case RLC_MENU_ADMIN:
      		$a = "id=menu-select";
		break;
	    case RLC_MENU_PROFILE:
      		$prof = "id=menu-select";
		break;
	    case RLC_MENU_ABOUT:
      		$about = "id=menu-select";
		break;
	}
	echo '<div class="rlc_menu"> <nav> <ul>';
	if ($session->logged_in)
	{
	    if ($session->vistabs & PRODUCTS_TAB)
	        echo "<li><a $p href=rlc_show_prod.php>Products</a></li>";
	    if ($session->vistabs & KEYS_TAB)
	        echo "<li><a $k href=rlc_show_key.php>Activation Keys</a></li>";
	    if ($session->vistabs & FULFILLMENTS_TAB)
	       echo "<li><a $f href=rlc_show_fulfill.php>Fulfillments</a></li>";
	    if ($session->vistabs & CUSTOMERS_TAB)
	        echo "<li><a $c href=rlc_show_cust.php>Customers</a></li>";
	    if ($session->vistabs & REPORTS_TAB)
	        echo "<li><a $r href=rlc_report.php>Reports</a></li>";
	    if ($session && $session->isAdmin())
		echo "<li><a $a href=rlc_admin.php>Admin</a></li>";
	    if ($session->vistabs & PROFILE_TAB)
	        echo "<li><a $prof href=rlc_profile.php>Profile</a></li>";
	}
	echo "<li><a $about href=rlc_info.php>About</a></li>";
	echo "</ul></nav></div>";
    }

    function rlc_admin_menu($menu)
    {
	echo "<h2>Administer Activation Pro System</h2>";
	$a = $u = $g = $l = $db = $b = $p = $debug = "";
	switch ($menu)
	{
	    case RLC_ADMIN_MENU_AUDIT:
      		$a = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_BLACKLIST:
      		$b = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_DB:
      		$db = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_DEBUG:
      		$debug = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_GENERATOR:
      		$g = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_LICENSE:
      		$l = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_PORTAL:
      		$p = "id=menu-select";
		break;
	    case RLC_ADMIN_MENU_USERS:
      		$u = "id=menu-select";
		break;
	}
	echo '<div id=admin_menu class="rlc_menu"> <nav> <ul>';
	echo "<li><a $l href=rlc_admin_license.php>ActPro License</a></li>";
	echo "<li><a $a href=rlc_audit.php>Audit Trail</a></li>";
	echo "<li><a $b href=rlc_admin_black.php>Blacklist</a></li>";
	echo "<li><a $db href=rlc_admin_db.php>Database</a></li>";
	echo "<li><a $debug href=rlc_admin_debug.php>Debugging</a></li>";
	echo "<li><a $g href=rlc_admin_generator.php>Generator Settings</a></li>";
	echo "<li><a $p href=rlc_admin_portal.php>Portal</a></li>";
	echo "<li><a $u href=login_admin.php>Users</a></li>";
	echo "</ul></nav></div>";
    }
?>
