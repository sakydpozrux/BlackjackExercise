#ifndef CONST_HPP
#define CONST_HPP

#include <exception>
#include <list>

class Card;

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

#endif // CONST_HPP
