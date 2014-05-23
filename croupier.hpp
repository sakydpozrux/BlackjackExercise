#ifndef CROUPIER_HPP
#define CROUPIER_HPP

#include <player.hpp>
#include <string>

class Croupier : public Player
{
public:
    Croupier(std::shared_ptr<Deck> deck, const std::string& name = "CROUPIER");
    virtual ~Croupier() final;

    virtual std::string use_own_strategy() final;
    virtual void update_total_score(int& total_player_score, int& total_croupier_score) final;
};

#endif // CROUPIER_HPP
