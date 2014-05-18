#include "cardlist.hpp"
#include "boost/algorithm/string.hpp"
#include <string>
#include <list>
#include <boost/lexical_cast.hpp>

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


std::list<int> CardList::init_cards(const std::string& input_str)
{
    std::string str = std::string(input_str);
    boost::trim(str);

    std::list<std::string> split_list_of_strings;
    boost::split(split_list_of_strings, str, boost::is_any_of(" ,\t,\n"), boost::token_compress_on);

    std::list<int> split_list_of_ints;
    std::cout << "PUSHING BACK:" << std::endl;
    try
    {
        for(std::string& a : split_list_of_strings)
        {
            std::cout << boost::lexical_cast<int>(a) << std::endl;
            split_list_of_ints.push_back(boost::lexical_cast<int>(a));
        }
    }
    catch(boost::bad_lexical_cast& e)
    {
        std::cout << "TODO:" << e.what() << std::endl;
    }

    return split_list_of_ints;
}
