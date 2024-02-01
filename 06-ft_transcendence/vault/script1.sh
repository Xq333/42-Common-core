#!/bin/sh
echo "Welcome to this first initialisation of Vault in our breathtaking transcendence!"

vault operator init

echo "Those are your keys, please replace the first 3 tokens (VAULT_UNSEAL_KEY_1, 2 and 3) of your .env file with those 3 tokens!"

echo "After that, please copy your main token (The one starting with hvs) into the VAULT_TOKEN variable in your .env file"

echo "Once all of that completed, you can restart your docker and launch the second script! (script2.sh)"