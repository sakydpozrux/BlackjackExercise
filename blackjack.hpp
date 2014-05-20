#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <memory>
#include "boost/scoped_ptr.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "croupier.hpp"

class Blackjack
{
private:
    std::shared_ptr<Player> player;
    boost::scoped_ptr<Player> croupier;

    int total_player_score;
    int total_croupier_score;

    Deck deck;
public:
    Blackjack(Deck& deck, std::shared_ptr<Player>& player);
    void start();
    players_enum result() const;
    void print_player_round_progress() const;
    void print_croupier_round_progress() const;
    void update_scores_after_round();
    std::string round_end_status() const;

private:
    Blackjack() = delete;
    Blackjack& operator=(Blackjack& other) = delete;
    Blackjack(Blackjack& other) = delete;
    std::string get_string_winner() const;
};

#endif // BLACKJACK_HPP
