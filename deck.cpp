#include "cardlist.hpp"
#include "deck.hpp"
#include <exception>

Deck::Deck(const CardList& cards_list) throw(initial_deck_size_is_not_52)
    : cards(cards_list)
{
    initial_deck_size_is_not_52 e;
    if (cards.size() != 52) throw e;
    //assert cards.size = 52
    //std::cout << "CardList.size() == " << cards.size() << std::endl;
}



unsigned int Deck::size() const
{
    return cards.size();
}
