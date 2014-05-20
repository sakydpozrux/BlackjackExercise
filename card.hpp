#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include "const.hpp"


class Card
{
private:
    int value;

public:
    Card(int value) throw(invalid_card_value);
    int get_value() const;

private:
    Card() = delete;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);
};

#endif // CARD_HPP
