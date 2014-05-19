#ifndef CARD_HPP
#define CARD_HPP

#include <exception>
#include <iostream>

struct invalid_card_value : std::exception
{
    const char* what() const noexcept {return "Exception: card value is out of [1,10] range";}
};

class Card
{
    int value;
public:
    Card(int value) throw(invalid_card_value);
    int get_value() const;
private:
    Card() = delete;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);
};

#endif // CARD_HPP
