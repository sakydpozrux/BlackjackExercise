#include "round.hpp"
#include <iostream>
#include <string>

Round::Round()
    : player_score(0), croupier_score(0)
{
}

round_result Round::result() const
{
    return CROUPIER_WON;
}

void Round::print_round_progress(round_result res) const
{

}

void Round::print_round_end() const
{
    std::string winner;
    if (result()) winner = "PLAYER";
    else winner = "CROUPIER";

    std::cout << "END OF ROUND: " << winner << " WON, "
                 "SCORE(PLAYER: " << player_score << ", " <<
                 "CROUPIER: " << croupier_score << ")" << std::endl;
}
