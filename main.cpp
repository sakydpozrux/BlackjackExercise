#include <memory>
#include <iostream>
#include <list>
#include "blackjack.hpp"
#include "deck.hpp"
#include "cardlistdeserializer.hpp"
#include "card.hpp"
#include "playerfactory.hpp"



void use_correct_input(int argc, char* argv[], CardList& cards);
std::shared_ptr<Player> choose_player(std::shared_ptr<Deck> deck);

int main(int argc, char* argv[])
{
    CardList cards;
    use_correct_input(argc, argv, cards);

    std::shared_ptr<Deck> deck(new Deck(cards));
    std::shared_ptr<Player> player = PlayerFactory::choose_player(deck);

    Blackjack game(deck, player);
    game.start();

    return EXIT_SUCCESS;
}


void use_correct_input(int argc, char* argv[], CardList& cards)
{
    if (argc < 2)
    {
        std::cout << "Missing argument. Using example deck." << std::endl;
        std::string hardcoded_input = "10 4 10 3 10 2 3 6 9 9 5 1 9 10 10 "
                                      "5 1 8 8 8 10 6 5 6 10 10 3 10 1 7 4 "
                                      "2 3 7 10 2 7 1 5 10 8 10 7 2 10 10 "
                                      "10 6 9 10 4 4\n";
        cards = CardListDeserializer::create_card_list(hardcoded_input);
    }
    else
    {
        std::string file_contents = CardListDeserializer::file_contents(std::string(argv[1]));
        cards = CardListDeserializer::create_card_list(file_contents);
    }
}



