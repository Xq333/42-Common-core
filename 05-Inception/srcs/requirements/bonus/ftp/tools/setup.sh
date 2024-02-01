#!/bin/sh

adduser "$FTP_USER" --disabled-password

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

echo "$FTP_USER" > /etc/userlist.ftp

mkdir -p /var/www

chown -R "$FTP_USER:$FTP_USER" /var/www

vsftpd /etc/vsftpd/vsftpd.conf
