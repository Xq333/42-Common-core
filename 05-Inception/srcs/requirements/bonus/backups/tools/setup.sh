#!/bin/sh

while true
do
	mysqldump --all-databases -h ${DB_NAME} -P 3306 -u ${DB_USER} -p${DB_PASSWORD} > /backups/`date +%Y-%m-%d-%H-%M`.sql
	echo "new save `date +%Y-%m-%d-%H-%M`.sql" 
	sleep 30m
done
