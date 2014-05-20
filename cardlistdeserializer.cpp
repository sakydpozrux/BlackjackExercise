#include "cardlistdeserializer.hpp"
#include <fstream>
#include <string>
#include <list>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <exception>
#include "const.hpp"

CardList CardListDeserializer::create_card_list(std::string contents)
{
    boost::trim(contents);

    std::list<std::string> split_list_of_strings;
    boost::split(split_list_of_strings, contents, boost::is_any_of(" ,\t,\n"), boost::token_compress_on);

    CardList split_list_of_cards;

    try
    {
        for(std::string& a : split_list_of_strings)
        {
            int current = boost::lexical_cast<int>(a);
            split_list_of_cards.push_back(Card(current));
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Fatal error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    return split_list_of_cards;
}

std::string CardListDeserializer::file_contents(const std::string& path)
{
    std::ifstream file(path);

    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return contents;
}
