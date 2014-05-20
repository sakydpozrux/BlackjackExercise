#include "croupier.hpp"

Croupier::Croupier(std::shared_ptr<Deck> deck, const std::string& name)
    : Player(deck, name)
{
}

Croupier::~Croupier()
{
}

std::string Croupier::use_own_strategy()
{
    return strategy_croupier_based();
}

void Croupier::update_total_score(int& total_player_score, int& total_croupier_score)
{
    if (get_name() == "CROUPIER") total_croupier_score += 1;
    else total_player_score += 1; // if player have chosen croupier strategy
}
