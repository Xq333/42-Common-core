FROM alpine:3.16.0

RUN apk update && apk add --no-cache nodejs npm

RUN mkdir -p /public

COPY ./conf/server.js /

COPY ./conf/public /public/

CMD ["node", "server.js"]
