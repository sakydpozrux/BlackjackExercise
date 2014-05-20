#include "blackjack.hpp"
#include "deck.hpp"
#include <memory>
#include "player.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"
#include "playermaximizewins.hpp"
#include "cardlistdeserializer.hpp"
#include <list>
#include "card.hpp"
#include <iostream>


void use_correct_input(int argc, char* argv[], std::list<Card>& cards);
void choose_player(std::shared_ptr<Deck>& deck, std::shared_ptr<Player>& player);

int main(int argc, char* argv[])
{
    std::list<Card> cards;
    use_correct_input(argc, argv, cards);

    std::shared_ptr<Deck> deck(new Deck(cards));
    std::shared_ptr<Player> player;
    choose_player(deck, player);

    Blackjack game(deck, player);
    game.start();

    return EXIT_SUCCESS;
}


void use_correct_input(int argc, char* argv[], std::list<Card>& cards)
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

void choose_player(std::shared_ptr<Deck>& deck, std::shared_ptr<Player>& player)
{
    std::cout << "Which strategy do you want to use? \n" <<
                 "0    --> Never Bust \n" <<
                 "1    --> Maximize Wins \n" <<
                 "else --> Croupier Strategy" << std::endl;

    char choose;
    std::cin >> choose;

    switch(choose)
    {
    case '0':
        std::cout << "Chosen player: Never Bust" << std::endl;
        player.reset(new PlayerNeverBust(deck));
        break;
    case '1':
        std::cout << "Chosen player: Maximize Wins" << std::endl;
        player.reset(new PlayerMaximizeWins(deck));
        break;
    default:
        std::cout << "Chosen player: Croupier Strategy" << std::endl;
        player.reset(new Croupier(deck, "CROUPIER2"));
        break;
    }
}

