FROM alpine:3.16.0

RUN apk update && apk add --no-cache vsftpd

COPY ./conf/vsftpd.conf /etc/vsftpd/

COPY ./tools/setup.sh /tmp

CMD ["/bin/sh", "/tmp/setup.sh"]
