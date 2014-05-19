#ifndef PLAYERNEVERBUST_HPP
#define PLAYERNEVERBUST_HPP

#include "player.hpp"

class PlayerNeverBust : public Player
{
public:
    PlayerNeverBust();
    virtual ~PlayerNeverBust() final;

    virtual std::string use_own_strategy(Deck* const deck) final;
};

#endif // PLAYERNEVERBUST_HPP
