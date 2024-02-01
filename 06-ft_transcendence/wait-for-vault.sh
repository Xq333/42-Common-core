#!/bin/bash

# wait-for-vault.sh

set -e

host="$1"
shift
cmd="$@"

until $(curl --output /dev/null --silent --head --fail http://$host/v1/sys/health); do
  >&2 echo "Vault n'est pas encore prêt - en attente..."
  sleep 1
done
# until [ "$(curl -s http://$host/v1/sys/seal-status | jq '.sealed')" == "false" ]; do
#   >&2 echo "Vault n'est pas encore prêt ou est scellé - en attente..."
#   sleep 1
# done


>&2 echo "Vault est opérationnel - exécution de la commande"
exec $cmd
