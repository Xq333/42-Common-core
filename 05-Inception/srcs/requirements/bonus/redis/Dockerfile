FROM alpine:3.16.0

RUN apk update && apk add --no-cache redis

RUN sed -i "s/bind 127.0.0.1/#bind 127.0.0.1/g" /etc/redis.conf

EXPOSE 6379

CMD ["redis-server", "/etc/redis.conf", "--protected-mode no"]
