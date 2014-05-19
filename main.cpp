#include "blackjack.hpp"
#include "deck.hpp"
#include "cardlist.hpp"
#include <memory>
#include <playerneverbust.hpp>

#include <iostream>

#define IM_USING_HARDCODED_STRING 1

int main()
{
    std::string input_str;
    if (IM_USING_HARDCODED_STRING)
        input_str = std::string("10 4 10 3 10 2 3 6 9 9 5 1 9 10 10 5 1 8 8 8 10 6 5 6 10 10"
                                " 3 10 1 7 4 2 3 7 10 2 7 1 5 10 8 10 7 2 10 10 10 6 9 10 4 4\n");
    else
        std::getline(std::cin, input_str);

    std::unique_ptr<CardList> input_deck;
    try
    {
        input_deck.reset(new CardList(input_str));
    }
    catch(const std::bad_exception& e)
    {
        // Here I have a leak. Not sure if I should take care of it.
        // Program exits and system frees memory despite of it.
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::unique_ptr<Deck> d;
    try
    {
        d.reset(new Deck(*input_deck));
    }
    catch(const initial_deck_size_is_not_52& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Blackjack game(*d);
    game.start();

    return EXIT_SUCCESS;
}

