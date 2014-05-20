#include "playerneverbust.hpp"
#include <sstream>

PlayerNeverBust::PlayerNeverBust()
{
}

PlayerNeverBust::~PlayerNeverBust()
{
}

std::string PlayerNeverBust::use_own_strategy(Deck* const deck)
{
    return strategy_croupier_based(deck, 12);
}
