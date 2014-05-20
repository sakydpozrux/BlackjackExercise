#include <memory>
#include "playerfactory.hpp"
#include "player.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"
#include "playermaximizewins.hpp"

std::shared_ptr<Player> PlayerFactory::choose_player(std::shared_ptr<Deck> deck)
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
        return std::shared_ptr<Player>(new PlayerNeverBust(deck));
    case '1':
        std::cout << "Chosen player: Maximize Wins" << std::endl;
        return std::shared_ptr<Player>(new PlayerMaximizeWins(deck));
    default:
        std::cout << "Chosen player: Croupier Strategy" << std::endl;
        return std::shared_ptr<Player>(new Croupier(deck, "CROUPIER2"));
    }
}
