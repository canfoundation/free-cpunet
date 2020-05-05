#include <eosio/eosio.hpp>

using namespace eosio;

class [[eosio::contract]] cpunet : public contract {
  public:
      using contract::contract;

      [[eosio::action]]
      void freecpunet( name to, const std::string& memo ) {
      }
};

EOSIO_DISPATCH(cpunet, (freecpunet))
