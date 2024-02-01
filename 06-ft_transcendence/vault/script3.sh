#!/bin/sh
echo "Welcome to the third and last script! You don't need to do any specific action on this one!"

echo "Just enjoy waiting, we enjoy it too ahah!"

vault write auth/approle/login role_id="$DJANGO_ROLE_ID" secret_id="$DJANGO_SECRET_ID"

vault kv put $SECRETDB

vault kv put $SECRETAPI

echo "Installation completed! You can now restart for the last time the docker and start playing in our fantastic single page application!"