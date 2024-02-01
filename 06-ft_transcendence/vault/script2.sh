#!/bin/sh
echo "Welcome to the second part of this script."

vault write auth/approle/role/django-website \
     token_ttl=1h \
     token_max_ttl=4h \
     policies="application-policy-dev"

vault read auth/approle/role/django-website/role-id
vault write -f auth/approle/role/django-website/secret-id

echo "Write the frist key into the .env file on the DJANGO_ROLE_ID variable"

echo "And the second key into the DJANGO_SECRET_ID variable"

echo "Once it's done, you can restart the docker and launch the third script!"