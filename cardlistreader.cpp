#include "cardlistreader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <exception>

std::list<Card> CardListReader::create_card_list(std::string contents)
{
    boost::trim(contents);

    std::list<std::string> split_list_of_strings;
    boost::split(split_list_of_strings, contents, boost::is_any_of(" ,\t,\n"), boost::token_compress_on);

    std::list<Card> split_list_of_cards;

    for(std::string& a : split_list_of_strings)
    {
        int current = boost::lexical_cast<int>(a);
        split_list_of_cards.push_back(Card(current));
    }

    return split_list_of_cards;
}

std::string CardListReader::file_contents(const std::string& path)
{
    std::ifstream file(path);

    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return contents;
}