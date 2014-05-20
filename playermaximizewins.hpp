#ifndef PLAYERMAXIMIZEWINS_HPP
#define PLAYERMAXIMIZEWINS_HPP

#include "player.hpp"

class PlayerMaximizeWins : public Player
{
public:
    PlayerMaximizeWins(std::shared_ptr<Deck> deck);
    virtual ~PlayerMaximizeWins() final;

    virtual std::string use_own_strategy() final;
private:
    PlayerMaximizeWins() = delete;
};

#endif // PLAYERMAXIMIZEWINS_HPP
