#ifndef CARD_HPP
#define CARD_HPP

#include <exception>

struct invalid_card_value : std::exception
{
    const char* what() const noexcept {return "Exception: card value is out of [1,10] range";}
};

class Card
{
    int value;
public:
    Card(int value) throw(invalid_card_value);
    int get_value();
private:
    Card() = delete;
};

#endif // CARD_HPP
