#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <list>
#include "card.hpp"
#include "deck.hpp"

class Player
{
private:
    const std::string name;
    std::list<Card> cards;
public:
    Player();
    Player(const std::string& name);
    virtual std::string round_progress() const;
    virtual std::string get_name() const;
    virtual void clear_cards() final;
    virtual int get_round_score() const final;
    virtual std::list<Card> get_cards() const final;
    virtual ~Player() = 0;
//private:
    virtual std::string round_initial_take(Deck* const deck) final;
    virtual std::string hit(Deck* const deck) final;

    friend std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);
};

std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);

#endif // PLAYER_HPP
