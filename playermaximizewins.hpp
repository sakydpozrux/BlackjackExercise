#ifndef PLAYERMAXIMIZEWINS_HPP
#define PLAYERMAXIMIZEWINS_HPP

#include "player.hpp"

class PlayerMaximizeWins : public Player
{
public:
    PlayerMaximizeWins();
    virtual ~PlayerMaximizeWins() final;

    virtual std::string use_own_strategy(Deck* const deck) final;
};

#endif // PLAYERMAXIMIZEWINS_HPP
