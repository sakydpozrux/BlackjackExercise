#include "deck.hpp"
#include <exception>

Deck::Deck(const CardList& cards_list) throw(initial_deck_size_is_not_52)
    : cards(cards_list), take_card_mutex()
{
    initial_deck_size_is_not_52 e;
    if (cards.size() != 52) throw e;
}

Deck::Deck(const Deck& other)
    : cards(other.cards), take_card_mutex()
{
}

Deck& Deck::operator=(const Deck& other)
{
    if (this != &other)
    {
        cards = other.cards;
    }
    return *this;
}


unsigned int Deck::size() const
{
    return cards.size();
}

Card Deck::take_next()
{
    take_card_mutex.lock();
    Card next_card_val = cards.front();
    cards.pop_front();
    take_card_mutex.unlock();

    return next_card_val;
}
