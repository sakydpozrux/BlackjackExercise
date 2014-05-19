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
    std::ostringstream stream;
    try
    {
        stream << hit(deck);
    }
    catch (std::exception& e)
    {
        return stream.str();
    }
    return stream.str();
}
