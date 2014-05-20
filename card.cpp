#include "card.hpp"
#include "const.hpp"

Card::Card(int value) throw(invalid_card_value)
    : value(value)
{
    invalid_card_value e;
    if (value < 1 || value > 10) throw e;
}

int Card::get_value() const
{
    return value;
}

std::ostream& operator<<(std::ostream& stream, const Card& card)
{
    return stream << card.get_value();
}
