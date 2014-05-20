#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <list>
#include "card.hpp"
#include "deck.hpp"
#include "const.hpp"
#include <memory>


class Player
{
private:
    const std::string name;
    std::list<Card> cards;
    std::shared_ptr<Deck> deck;
public:
    Player(std::shared_ptr<Deck>& deck, const std::string& name = "PLAYER");
    virtual std::string round_progress() const;
    virtual std::string get_name() const;
    virtual void clear_cards() final;
    virtual int get_round_score() const final;
    virtual std::list<Card> get_cards() const final;

    virtual std::string use_own_strategy() = 0;

    virtual ~Player();

    virtual std::string round_initial_take() final;

protected:
    virtual std::string hit() throw(deck_is_empty) final;
    virtual std::string strategy_croupier_based(int limit = 17) final;

    friend std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);
private:
    Player() = delete;
};

std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);

#endif // PLAYER_HPP
