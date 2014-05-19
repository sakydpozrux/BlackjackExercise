#include "blackjack.hpp"
#include "deck.hpp"
#include <memory>
#include "playerneverbust.hpp"
#include "cardlistreader.hpp"

#include <list>
#include "card.hpp"
#include <iostream>

#define USE_HARDCODED_INPUT true

int main(int argc, char* argv[])
{
    std::list<Card> cards;

    if (USE_HARDCODED_INPUT)
    {
        std::string hardcoded_input = "10 4 10 3 10 2 3 6 9 9 5 1 9 10 10 "
                                      "5 1 8 8 8 10 6 5 6 10 10 3 10 1 7 4 "
                                      "2 3 7 10 2 7 1 5 10 8 10 7 2 10 10 "
                                      "10 6 9 10 4 4\n";
        cards = CardListReader::create_card_list(hardcoded_input);
    }
    else
    {
        if (argc < 2) EXIT_FAILURE;
        std::string file_contents = CardListReader::file_contents(std::string(argv[1]));
        cards = CardListReader::create_card_list(file_contents);
    }

    Deck d(cards);

    Blackjack game(d);
    game.start();

    return EXIT_SUCCESS;
}

