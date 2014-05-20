#include <sstream>
#include "round.hpp"

Round::Round(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::shared_ptr<Deck> deck)
    : player(player), croupier(croupier), deck(deck)
{
    player->clear_cards();
    croupier->clear_cards();
}

std::string Round::init_deal_cards()
{
    std::ostringstream stream;
    stream << player->round_initial_take();
    stream << croupier->round_initial_take();
    return stream.str();
}

std::string Round::let_players_play()
{
    std::ostringstream stream;

    stream << player->use_own_strategy();
    if (player->get_round_score() <= 21)
        stream << croupier->use_own_strategy();

    return stream.str();
}

std::string Round::end_status(int total_player_score, int total_croupier_score) const
{
    std::ostringstream stream;
    stream << "END OF ROUND: " << get_string_winner() << " WON, "
                 "SCORE(" << player->get_name() << ": " << total_player_score << ", " <<
                 croupier->get_name() << ": " << total_croupier_score << ")" << std::endl;
    return stream.str();
}

players_enum Round::result() const
{
    bool player_has_more_than_21 = player->get_round_score() > 21;
    bool croupier_has_more_than_21 = croupier->get_round_score() > 21;
    bool player_has_more_than_croupier = (player->get_round_score() > croupier->get_round_score());

    if (player_has_more_than_21) return CROUPIER;
    if (!player_has_more_than_21 && croupier_has_more_than_21) return PLAYER;
    if (!player_has_more_than_21 && player_has_more_than_croupier) return PLAYER;
    return CROUPIER;
}

std::string Round::get_string_winner() const
{
    std::string winner;
    switch (result())
    {
    case PLAYER:
        winner = player->get_name();
        break;
    case CROUPIER:
        winner = croupier->get_name();
        break;
    }
    return winner;
}
