FROM alpine:3.16.0

RUN apk add --no-cache \
    php8 \
    php8-fpm \
    php8-mysqli \
    php8-phar \
    php8-iconv \
    php8-session \
    wget

RUN mkdir -p /var/www

WORKDIR /var/www

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php 

RUN mv adminer-4.8.1.php index.php

EXPOSE 8080

CMD ["php", "-t", "/var/www", "-S", "0.0.0.0:8080"]
