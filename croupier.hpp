#ifndef CROUPIER_HPP
#define CROUPIER_HPP

#include <player.hpp>

class Croupier : public Player
{
public:
    Croupier();
    virtual ~Croupier() final;

    virtual std::string use_own_strategy(Deck* const deck) final;
};

#endif // CROUPIER_HPP
