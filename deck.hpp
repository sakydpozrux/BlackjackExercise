#ifndef DECK_HPP
#define DECK_HPP

#include <mutex>
#include <list>
#include "card.hpp"

struct initial_deck_size_is_not_52 : std::exception
{
    const char* what() const noexcept {return "Exception: deck size is not 52";}
};

class Deck
{
    std::list<Card> cards;
    mutable std::mutex take_card_mutex;
public:
    Deck(const std::list<Card>& cards_list) throw(initial_deck_size_is_not_52);
    Deck(const Deck& other);
    Deck& operator=(const Deck& other);
    unsigned int size() const;
    Card take_next();
private:
    Deck() = delete;
};

#endif // DECK_HPP
