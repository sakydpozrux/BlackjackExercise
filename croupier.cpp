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
