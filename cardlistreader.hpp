#ifndef CARDLISTREADER_HPP
#define CARDLISTREADER_HPP

#include <list>
#include "card.hpp"
#include <exception>


class CardListReader
{
public:
    static std::list<Card> create_card_list(std::string contents);
    static std::string file_contents(const std::string& file_name);
private:
    CardListReader() = delete;
    CardListReader(CardListReader& other) = delete;
    CardListReader& operator=(CardListReader& other) = delete;
};

#endif // CARDLISTREADER_HPP
