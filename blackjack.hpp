#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <memory>
#include "boost/scoped_ptr.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "const.hpp"

class Blackjack
{
private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Player> croupier;
    std::shared_ptr<Deck> deck;

    int total_player_score;
    int total_croupier_score;

public:
    Blackjack(std::shared_ptr<Deck> deck, std::shared_ptr<Player> player);
    void start();
    void update_scores_after_round(players_enum result);

private:
    Blackjack() = delete;
    Blackjack& operator=(Blackjack& other) = delete;
    Blackjack(Blackjack& other) = delete;

};

#endif // BLACKJACK_HPP
