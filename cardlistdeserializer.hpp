#ifndef CARDLISTDESERIALIZER_HPP
#define CARDLISTDESERIALIZER_HPP

#include <list>
#include "card.hpp"
#include "const.hpp"


class CardListDeserializer
{
public:
    static CardList create_card_list(std::string contents);
    static std::string file_contents(const std::string& file_name);

private:
    CardListDeserializer() = delete;
    CardListDeserializer(const CardListDeserializer& other) = delete;
    CardListDeserializer& operator=(const CardListDeserializer& other) = delete;
};

#endif // CARDLISTDESERIALIZER_HPP
