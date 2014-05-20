#ifndef CROUPIER_HPP
#define CROUPIER_HPP

#include <player.hpp>
#include <string>

class Croupier : public Player
{
public:
    Croupier(std::string name = "CROUPIER");
    virtual ~Croupier() final;

    virtual std::string use_own_strategy(Deck* const deck) final;
};

#endif // CROUPIER_HPP
