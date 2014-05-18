#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "boost/scoped_ptr.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "croupier.hpp"

class Blackjack
{
private:
    boost::scoped_ptr<Player> player;
    boost::scoped_ptr<Player> croupier;
    Deck deck;
public:
    Blackjack(Deck& deck);
    void start();

private:
    Blackjack() = delete;
    Blackjack& operator=(Blackjack& other) = delete;
    Blackjack(Blackjack& other) = delete;
};

#endif // BLACKJACK_HPP
