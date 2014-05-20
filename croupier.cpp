#include "croupier.hpp"
#include <sstream>

Croupier::Croupier(std::string name)
    : Player(name)
{
}

Croupier::~Croupier()
{
}

std::string Croupier::use_own_strategy(Deck* const deck)
{
    return strategy_croupier_based(deck);
}
