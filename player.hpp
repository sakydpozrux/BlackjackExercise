#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <string>
#include <list>
#include "card.hpp"
#include "deck.hpp"
#include "const.hpp"


class Player
{
private:
    std::shared_ptr<Deck> deck;
    CardList cards;
    const std::string name;

public:
    Player(std::shared_ptr<Deck> deck, const std::string& name = "PLAYER");

    virtual std::string get_name() const;

    virtual std::string hit() throw(deck_is_empty) final;
    virtual std::string round_initial_take() final;
    virtual std::string use_own_strategy() = 0;
    virtual std::string strategy_croupier_based(int limit = 17) final;
    virtual void update_total_score(int& total_player_score, int& total_croupier_score);

    virtual CardList get_cards() const final;
    virtual int get_round_score() const final;
    virtual std::string round_progress() const;

    virtual void clear_cards() final;

    virtual ~Player();

private:
    Player() = delete;

    friend std::ostream& operator<<(std::ostream& stream, const CardList& cards);
};

std::ostream& operator<<(std::ostream& stream, const CardList& cards);

#endif // PLAYER_HPP
