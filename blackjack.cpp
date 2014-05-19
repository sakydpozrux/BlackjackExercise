#include "blackjack.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"
#include "round.hpp"
#include <sstream>

Blackjack::Blackjack(Deck& deck)
    : player(), croupier(), total_player_score(0), total_croupier_score(0), deck(deck)
{
    player.reset(new PlayerNeverBust);
    croupier.reset(new Croupier);
}

void Blackjack::start()
{
    while (deck.size() >= 4)
    {
        player->reset_round_score();
        croupier->reset_round_score();

        player->round_initial_take();
        std::cout << player->round_progress() << std::endl;


        croupier->round_initial_take();
        std::cout << croupier->round_progress() << std::endl;


        update_scores_after_round();
        std::cout << round_end_status() << std::endl;
    }
}

players_enum Blackjack::result() const
{
    if (player->get_round_score() <= 21 && player->get_round_score() > croupier->get_round_score())
        return PLAYER;
    else
        return CROUPIER;
}

void Blackjack::update_scores_after_round()
{
    switch (result())
    {
    case PLAYER:
        total_player_score += 1;
        break;
    case CROUPIER:
        total_croupier_score += 1;
        break;
    }
}

std::string Blackjack::round_end_status() const
{
    std::ostringstream stream;
    stream << "END OF ROUND: " << get_string_winner() << " WON, "
                 "SCORE(" << player->get_name() << ": " << total_player_score << ", " <<
                 croupier->get_name() << ": " << total_croupier_score << ")";
    return stream.str();
}

std::string Blackjack::get_string_winner() const
{
    std::string winner;
    switch (result())
    {
    case PLAYER:
        winner = "PLAYER";
        break;
    case CROUPIER:
        winner = "CROUPIER";
        break;
    }
    return winner;
}
