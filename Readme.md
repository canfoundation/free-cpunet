FREE CPU+NET
-----------------

Example game session using cleos
-------
#### Prerequisites


* Endpoint network:

https://testnet-migration.canfoundation.io


##### Set contract 
````bash

eosio-cpp -I include -o cpunet.wasm cpunet.cpp --abigen


cleos -u https://testnet-migration.canfoundation.io set contract cpu.can . cpunet.wasm cpunet.abi -p cpu.can

$ cleos -u https://testnet-migration.canfoundation.io  get account cpu.can
created: 2020-05-05T02:58:18.000
permissions: 
     owner     1:    1 EOS8SXu3rxcijvAqeuKXHEp9sQcdV8LLHCZJdVUdhVYcP49sduzBB
        active     1:    1 EOS8SXu3rxcijvAqeuKXHEp9sQcdV8LLHCZJdVUdhVYcP49sduzBB
memory: 
     quota:     1.623 MiB    used:      39.5 KiB
````

##### push action

````bash
# test transaction
cleos -u https://testnet-migration.canfoundation.io push action cpu.can freecpunet '["quoc.dev.can", "testing free CPU+NET for an account"]' -p cpu.can

# The freecpunet action should be included in the first action.
cleos -u https://testnet-migration.canfoundation.io push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"cpu.can","name":"freecpunet","data":{"to":"quoc.dev.can","memo":"testing free cpu+net"},"authorization":[{"actor":"cpu.can","permission":"active"}]},{"account":"eosio.token","name":"transfer","data":{"from":"can","to":"eosio","quantity":"0.0001 CAT","memo":"testing free cpu+net"},"authorization":[{"actor":"can","permission":"active"}]}]}'

````

Please refer detail at [here](https://local.bloks.io/transaction/78fece4840d1c38406f49f7044a5a369b7a44fbff9902d08f2323677595d92e1?nodeUrl=history.testnet-migration.canfoundation.io&coreSymbol=CAT&systemDomain=eosio&hyperionUrl=https%3A%2F%2Fhistory.testnet-migration.canfoundation.io&tab=traces)

##### Check CPU+NET

````bash
# CPU+NET of cpu.can account before exec the transaction
$ cleos -u https://testnet-migration.canfoundation.io  get account cpu.can
created: 2020-05-05T02:58:18.000
net bandwidth: 
     used:              2.55 KiB  

cpu bandwidth:
     used:             1.244 ms   

# CPU+NET of can account before exec the transaction

$ cleos -u https://testnet-migration.canfoundation.io  get account can
created: 2020-03-31T04:29:39.500
net bandwidth: 
     used:             1.337 KiB  

cpu bandwidth:
     used:             5.622 ms   

# CPU+NET of cpu.can account has increased after exec the transaction

$ cleos -u https://testnet-migration.canfoundation.io  get account cpu.can
created: 2020-05-05T02:58:18.000 
net bandwidth: 
     used:             2.761 KiB  

cpu bandwidth:
     used:             1.561 ms   

# CPU+NET of can account has no changes after exec the transaction

$ cleos -u https://testnet-migration.canfoundation.io  get account can
created: 2020-03-31T04:29:39.500

net bandwidth: 
     used:             1.337 KiB  

cpu bandwidth:
     used:             5.622 ms    
````