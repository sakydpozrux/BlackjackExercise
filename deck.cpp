#include "cardlist.hpp"
#include "deck.hpp"

#include <iostream>

Deck::Deck(const CardList& cards_list)
    : cards(cards_list)
{
    //assert cards.size = 52

    std::cout << "SIZE [TODO]:" << cards.size() << std::endl;
}



unsigned int Deck::size() const
{
    return cards.size();
}
