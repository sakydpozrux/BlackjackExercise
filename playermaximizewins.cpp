#include "playermaximizewins.hpp"
#include <sstream>

PlayerMaximizeWins::PlayerMaximizeWins(std::shared_ptr<Deck>& deck)
    : Player(deck)
{
}

PlayerMaximizeWins::~PlayerMaximizeWins()
{
}

std::string PlayerMaximizeWins::use_own_strategy()
{
    return strategy_croupier_based(17);
}
