#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include <memory>
#include "player.hpp"

class PlayerFactory
{
public:
    static std::shared_ptr<Player> choose_player(std::shared_ptr<Deck> deck);

private:
    PlayerFactory() = delete;
    PlayerFactory(PlayerFactory& other) = delete;
    PlayerFactory& operator=(PlayerFactory& other) = delete;
};

#endif // PLAYERFACTORY_HPP
