path "secret/data/transcendence/data/*" {
  capabilities = ["read", "list"]
}

path "secret/data/transcendence/data/db" {
  capabilities = ["create", "read", "update", "delete", "list"]
}

path "secret/data/transcendence/data/api42" {
  capabilities = ["create", "read", "update", "delete", "list"]
}
