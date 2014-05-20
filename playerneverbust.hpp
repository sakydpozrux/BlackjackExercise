#ifndef PLAYERNEVERBUST_HPP
#define PLAYERNEVERBUST_HPP

#include "player.hpp"

class PlayerNeverBust : public Player
{
public:
    PlayerNeverBust(std::shared_ptr<Deck> deck);
    virtual ~PlayerNeverBust() final;

    virtual std::string use_own_strategy() final;

private:
    PlayerNeverBust() = delete;
};

#endif // PLAYERNEVERBUST_HPP
