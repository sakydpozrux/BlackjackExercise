#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "deck.hpp"

class Blackjack
{
private:
    Deck deck;
public:
    Blackjack(Deck& deck);
    void start();

private:
    Blackjack() = delete;
};

#endif // BLACKJACK_HPP
