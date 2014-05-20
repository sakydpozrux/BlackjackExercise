#include "playerneverbust.hpp"
#include <sstream>

PlayerNeverBust::PlayerNeverBust(std::shared_ptr<Deck>& deck)
    : Player(deck)
{
}

PlayerNeverBust::~PlayerNeverBust()
{
}

std::string PlayerNeverBust::use_own_strategy()
{
    return strategy_croupier_based(12);
}
