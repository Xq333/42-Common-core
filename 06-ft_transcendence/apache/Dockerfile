FROM debian:latest

RUN apt-get update && \
    apt-get install -y apache2 vim \
    libapache2-mod-security2 git

RUN rm -rf /usr/share/modsecurity-crs/ && \
    git clone https://github.com/coreruleset/coreruleset.git /usr/share/modsecurity-crs/ && \
    mv /usr/share/modsecurity-crs/crs-setup.conf.example /usr/share/modsecurity-crs/crs-setup.conf

RUN a2enmod headers && \
    a2enmod ssl && \
    a2enmod rewrite && \
    a2enmod security2 && \
    a2enmod proxy && \
    a2enmod proxy_wstunnel && \
    a2enmod proxy_http

COPY modsecurity.conf /etc/modsecurity/
COPY apache2.conf /etc/apache2/apache2.conf
COPY 000-default.conf /etc/apache2/sites-enabled/000-default.conf
COPY unicode.mapping /etc/modsecurity/
COPY localhost.crt /etc/apache2/localhost.crt
COPY localhost.key /etc/apache2/localhost.key
COPY crs-setup.conf /usr/share/modsecurity-crs/crs-setup.conf

RUN service apache2 restart

CMD ["apache2ctl", "-D", "FOREGROUND"]
