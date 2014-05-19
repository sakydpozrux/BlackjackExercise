#include "card.hpp"

Card::Card(int value) throw(invalid_card_value)
    : value(value)
{
    invalid_card_value e;
    if (value < 1 || value > 10) throw e;
}

int Card::get_value()
{
    return value;
}
