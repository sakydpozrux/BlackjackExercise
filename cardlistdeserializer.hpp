#ifndef CARDLISTDESERIALIZER_HPP
#define CARDLISTDESERIALIZER_HPP

#include <list>
#include "card.hpp"
#include <exception>


class CardListDeserializer
{
public:
    static std::list<Card> create_card_list(std::string contents);
    static std::string file_contents(const std::string& file_name);
private:
    CardListDeserializer() = delete;
    CardListDeserializer(CardListDeserializer& other) = delete;
    CardListDeserializer& operator=(CardListDeserializer& other) = delete;
};

#endif // CARDLISTDESERIALIZER_HPP
