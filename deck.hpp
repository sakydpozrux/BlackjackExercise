#ifndef DECK_HPP
#define DECK_HPP

#include <mutex>
#include <list>
#include "card.hpp"
#include "const.hpp"



class Deck
{
private:
    CardList cards;
    mutable std::mutex take_card_mutex;

public:
    Deck(const CardList& cards_list) throw(initial_deck_size_is_not_52);
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);

    unsigned int size() const;
    Card take_next();
};

#endif // DECK_HPP
