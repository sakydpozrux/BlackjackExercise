#include "playermaximizewins.hpp"
#include <sstream>

PlayerMaximizeWins::PlayerMaximizeWins()
{
}

PlayerMaximizeWins::~PlayerMaximizeWins()
{
}

std::string PlayerMaximizeWins::use_own_strategy(Deck* const deck)
{
    return strategy_croupier_based(deck, 17);
}
