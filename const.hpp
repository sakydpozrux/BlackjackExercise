#ifndef CONST_HPP
#define CONST_HPP

#include <exception>
#include <list>

//#include "card.hpp"
class Card; // It's here because of cyclical includes problem.

typedef std::list<Card> CardList;

struct invalid_card_value : std::exception
{
    const char* what() const noexcept {return "Exception: card value is out of [1,10] range";}
};

struct initial_deck_size_is_not_52 : std::exception
{
    const char* what() const noexcept {return "Exception: deck size is not 52";}
};

struct deck_is_empty : std::exception
{
    const char* what() const noexcept {return "Exception: deck is empty. Player can\'t take more cards";}
};

enum players_enum
{
    CROUPIER = 0,
    PLAYER = 1
};


#endif // CONST_HPP
