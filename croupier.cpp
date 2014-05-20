#include "croupier.hpp"
#include <sstream>

Croupier::Croupier(std::shared_ptr<Deck>& deck, const std::string& name)
    : Player(deck, name)
{
}

Croupier::~Croupier()
{
}

std::string Croupier::use_own_strategy()
{
    return strategy_croupier_based();
}
