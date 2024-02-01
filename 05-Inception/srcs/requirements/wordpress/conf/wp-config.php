<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'dbnametochange');

/** Database username */
define( 'DB_USER', 'dbusertochange');

/** Database password */
define( 'DB_PASSWORD', 'dbpwtochange');

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('FS_METHOD', 'direct');

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* Add any custom values between this line and the "stop editing" line. */

define('AUTH_KEY',         'B}Mn@yom.ZuNQ|<R{1j-,ov8SzS*9;OPu|Dd,tI~.V,]Cv&h/?O9W)f+M|EC)kJ3');
define('SECURE_AUTH_KEY',  'x4k4?-?z<.oFC8O~E65l|>O`NqRpV]Y]|7MIkR-Xg)vR@HRjD{qdw.+R+[uATG{G');
define('LOGGED_IN_KEY',    'Ij~[0|#&v7@+L]DpPm9XH;=i4s_=-O7L&;d|5-Bf#g6T6:FLrA|URM0zA_#^KCKw');
define('NONCE_KEY',        '|L>rI1h-6|{-zHt&CF4).|;1E<72D)_D}h+q^H^OoU`r4~b5zEl+p`s=|VHMK4OH');
define('AUTH_SALT',        '8}W>RCHi2d#0;uH:^T~]N3|1#x;m5JxM;_vW:L<A|npCrlBbDq2?>%p=m-T@2=/(');
define('SECURE_AUTH_SALT', '`6Z~-wZ7V+R+}_d`+o!,`K8*]BbX@_H|9FuM;Or%Jkzgav=OQp#E`$Jd>|a_6i`l');
define('LOGGED_IN_SALT',   'T(Z)_Z#i|B5b#}2@*B|<{L&:yjS>#pOgmJU/c%lf>nlR8`|:4#Pf2DHPM/mxo&+]');
define('NONCE_SALT',       'LD7#W=vfAF5eE{^;^AxyQ]/5-m4T+sgI[.f@!wzFWg-]+dQ_oDMEf<GU+kl7m#Yp');
define('WP_CACHE', true);
define('WP_REDIS_HOST', 'redis');
define('WP_REDIS_PORT', '6379');
define('WP_REDIS_COMPRESSION', 'on');
define('WP_REDIS_MAXTTL', 3600);
define('WP_REDIS_DATABASE', '0');


/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
