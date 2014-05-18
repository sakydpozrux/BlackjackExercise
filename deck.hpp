#ifndef DECK_HPP
#define DECK_HPP

#include "cardlist.hpp"

class Deck
{
    CardList cards;
public:
    Deck(const CardList& cards);
    unsigned int size() const;
private:
    Deck() = delete;
};

#endif // DECK_HPP
