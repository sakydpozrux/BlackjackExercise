#ifndef DECK_HPP
#define DECK_HPP

#include "cardlist.hpp"

struct initial_deck_size_is_not_52 : std::exception
{
    const char* what() const noexcept {return "Exception: deck size is not 52";}
};

class Deck
{
    CardList cards;
public:
    Deck(const CardList& cards) throw(initial_deck_size_is_not_52);
    unsigned int size() const;
private:
    Deck() = delete;
};

#endif // DECK_HPP
