#include <sstream>
#include "blackjack.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"
#include "round.hpp"

Blackjack::Blackjack(std::shared_ptr<Deck> deck, std::shared_ptr<Player> player)
    : player(player), croupier(new Croupier(deck)), deck(deck), total_player_score(0), total_croupier_score(0)
{
}

void Blackjack::start()
{
    while (deck->size() >= 4)
    {
        Round round(player, croupier, deck);

        std::cout << round.init_deal_cards();
        std::cout << round.let_players_play();

        update_scores_after_round(round.winner());
        std::cout << round.end_status(total_player_score, total_croupier_score);
    }
}

void Blackjack::update_scores_after_round(std::shared_ptr<Player> winner)
{
    winner->update_total_score(total_player_score, total_croupier_score);
}


