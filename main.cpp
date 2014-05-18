#include "blackjack.hpp"
#include "deck.hpp"
#include "cardlist.hpp"

#include <iostream>

#define IM_DEBUGGING 1

int main()
{
    std::string input_str;
    if (IM_DEBUGGING)
        input_str = std::string("\n1 10\n10 5\t a 2  ");
    else
        std::getline(std::cin, input_str);

    CardList input_deck = CardList(input_str);
    Deck d = Deck(input_deck);

    Blackjack game = Blackjack(d);
    game.start();

    return 0;
}

