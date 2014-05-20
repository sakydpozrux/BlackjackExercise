#ifndef ROUND_HPP
#define ROUND_HPP

#include <memory>
#include "player.hpp"
#include "deck.hpp"
#include "const.hpp"

class Round
{
    std::shared_ptr<Player> player;
    std::shared_ptr<Player> croupier;
    std::shared_ptr<Deck> deck;

public:
    Round(std::shared_ptr<Player>& player, std::shared_ptr<Player>& croupier, std::shared_ptr<Deck>& deck);
    std::string init_deal_cards();
    std::string let_players_play();
    void print_player_round_progress() const;
    void print_croupier_round_progress() const;
    std::string end_status(int total_player_score, int total_croupier_score) const;
    players_enum result() const;
private:
    std::string get_string_winner() const;
    Round() = delete;
};

#endif // ROUND_HPP
