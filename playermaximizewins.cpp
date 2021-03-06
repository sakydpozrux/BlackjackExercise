#include <string>
#include <memory>
#include "playermaximizewins.hpp"
#include "deck.hpp"

PlayerMaximizeWins::PlayerMaximizeWins(std::shared_ptr<Deck> deck)
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
