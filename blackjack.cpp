#include "blackjack.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"

Blackjack::Blackjack(Deck& deck)
    : player(), croupier(), deck(deck)
{
    player.reset(new PlayerNeverBust);
    croupier.reset(new Croupier);
}

void Blackjack::start()
{
}
