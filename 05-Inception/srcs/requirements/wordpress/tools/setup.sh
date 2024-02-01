#!/bin/sh

sed -i "s/dbnametochange/$DB_NAME/g" /var/www/wp-config.php

sed -i "s/dbusertochange/$DB_USER/g" /var/www/wp-config.php

sed -i "s/dbpwtochange/$DB_PASSWORD/g" /var/www/wp-config.php

chmod -R 777 /var/www/*

php-fpm8 -F
