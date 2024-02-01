FROM alpine:3.16.0

RUN apk update && apk add --no-cache mariadb mariadb-client

RUN mkdir -p backups

COPY ./tools/setup.sh /tmp

CMD ["/bin/sh", "/tmp/setup.sh"]
