#include "cardlist.hpp"
#include "boost/algorithm/string.hpp"
#include <string>
#include <list>
#include <boost/lexical_cast.hpp>
#include <exception>

#include <iostream>


CardList::CardList(const std::list<int>& list_of_ints)
    : cards(list_of_ints)
{
}

CardList::CardList(const std::string& input_str)
    : cards(init_cards(input_str))
{
}

unsigned int CardList::size() const
{
    return cards.size();
}

int CardList::front() const
{
    return cards.front();
}

void CardList::pop_front()
{
    cards.pop_front();
}


std::list<int> CardList::init_cards(const std::string& input_str) throw(boost::bad_lexical_cast, invalid_card_value)
{
    std::string str = std::string(input_str);
    boost::trim(str);

    std::list<std::string> split_list_of_strings;
    boost::split(split_list_of_strings, str, boost::is_any_of(" ,\t,\n"), boost::token_compress_on);

    std::list<int> split_list_of_ints;

    invalid_card_value e_invalid_card_value;

    for(std::string& a : split_list_of_strings)
    {
        int current = boost::lexical_cast<int>(a);

        if (current < 1 || current > 10) throw e_invalid_card_value;
        split_list_of_ints.push_back(current);
    }


    return split_list_of_ints;
}

