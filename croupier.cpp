#include "croupier.hpp"
#include <sstream>

Croupier::Croupier()
    : Player("CROUPIER")
{
}

Croupier::~Croupier()
{
}

std::string Croupier::use_own_strategy(Deck* const deck)
{
    return strategy_croupier_based(deck);
}
