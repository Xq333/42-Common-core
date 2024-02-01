#!/bin/sh

chown -R mysql:mysql /var/lib/mysql

mysql_install_db --user=mysql --ldata=/var/lib/mysql 

mysqld_safe --datadir='/var/lib/mysql' &

sleep 10

mysql -u root -e "DELETE FROM mysql.user WHERE User='';"
mysql -u root -e "DROP DATABASE IF EXISTS test;"
mysql -u root -e "FLUSH PRIVILEGES;"

mysql -u root -e "CREATE DATABASE ${DB_NAME};"
mysql -u root -e "CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';"
mysql -u root -e "FLUSH PRIVILEGES;"

mysqladmin shutdown

/usr/bin/mysqld_safe --datadir=/var/lib/mysql
