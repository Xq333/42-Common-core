#!/bin/bash

vault server -config=/config.hcl &

until [ "$(vault status -format=json | jq -r '.initialized')" == "true" ]; do
    echo "Waiting for Vault to be initialized..."
    sleep 1
done

echo 'Unsealing...'
vault operator unseal $VAULT_UNSEAL_KEY_1
vault operator unseal $VAULT_UNSEAL_KEY_2
vault operator unseal $VAULT_UNSEAL_KEY_3

echo 'Connecting...'
vault login $VAULT_TOKEN

secret_path="secret"
if ! vault secrets list | grep -q "^${secret_path}/"; then
    echo "Activation du chemin des secrets '${secret_path}'."
    vault secrets enable -path=${secret_path} kv-v2
fi

if ! vault auth list | grep -q "^approle/"; then
    echo "Activation de approle."
    vault auth enable approle
fi

policy_name="application-policy-dev"
if ! vault policy list | grep -q "^${policy_name}$"; then
    echo "Création de la politique '${policy_name}'."
    vault policy write ${policy_name} /application-policy-DEV.hcl
fi
wait $!



# TODO : split in 2 scripts, init and process. The init will vault operator init, write the policies and enable secrets and approle
# It will also get the unseal keys and root token and somehow secure them
# The process will unseal, login and write the secrets
# For now, I'm using the same script for both, and the role-id and secret-id are written in the container manually

# I wrote those manually in the container to get the credentials for the application

# vault operator init

# Create a role for the application
# vault write auth/approle/role/django-website \
#     token_ttl=1h \
#     token_max_ttl=4h \
#     policies="application-policy-dev"
#
# Create a role-id and secret-id for the application
# vault read auth/approle/role/django-website/role-id --> public, to store in env
# vault write -f auth/approle/role/django-website/secret-id --> secret-id, to store in env
#
# To test the role-id and secret-id inside the container
# vault write auth/approle/login role_id="$DJANGO_ROLE_ID" secret_id="$DJANGO_SECRET_ID"
#
# To put secrets : 
# vault kv put secret/transcendence/data/db user=ed password=ed name=db

#
# Here is the template for your .env
# VAULT_UNSEAL_KEY_1=bA0T8Iza8EUmdX1Y0SD3MYvISAE7HYeMtwSfuxigGpNP
# VAULT_UNSEAL_KEY_2=zdAzu5xk4PNkux11GI/SkBIZjWQQJARM3pmLXLMH4iXZ
# VAULT_UNSEAL_KEY_3=xMkuNGoVNLc2YSCBlwJlqr/RcvnOPELadJhRo/1ADEEr
# VAULT_TOKEN=hvs.toTMWvBcBKoTma3ggcF8Q9kQ
#
# DJANGO_ROLE_ID=3d7c032a-77b4-bb5c-20bd-caa6667f72c8
# DJANGO_SECRET_ID=b374e458-00aa-972a-a485-835eccf8344a
#
# DJANGO_ACCESSOR=d0c30e29-ce8c-b91f-837f-04c927abd98c
# DJANGO_TOKEN=hvs.CAESIKDVnjUDtbNwz7kRnuBD2o-sz83l_H8a6Khin0UY5J0IGh4KHGh2cy5ZUXpoSG5UVk5ZZ0VUaGNoWFhWVXZPUHU

