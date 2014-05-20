#include "blackjack.hpp"
#include "croupier.hpp"
#include "playerneverbust.hpp"
#include <sstream>
#include "round.hpp"

Blackjack::Blackjack(std::shared_ptr<Deck>& deck, std::shared_ptr<Player>& player)
    : player(player), croupier(), deck(deck), total_player_score(0), total_croupier_score(0)
{
    croupier.reset(new Croupier(deck));
}

void Blackjack::start()
{
    while (deck->size() >= 4)
    {
        Round round(player, croupier, deck);

        std::cout << round.init_deal_cards();
        std::cout << round.let_players_play();

        update_scores_after_round(round.result());
        std::cout << round.end_status(total_player_score, total_croupier_score);
    }
}



void Blackjack::update_scores_after_round(players_enum result)
{
    switch (result)
    {
    case PLAYER:
        total_player_score += 1;
        break;
    case CROUPIER:
        total_croupier_score += 1;
        break;
    }
}


