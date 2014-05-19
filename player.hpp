#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <list>
#include "card.hpp"

class Player
{
private:
    const std::string name;
    int round_score;
    std::list<Card> cards;
public:
    Player();
    Player(const std::string& name);
    virtual std::string round_progress() const;
    virtual std::string get_name() const;
    virtual void reset_round_score() final;
    virtual int get_round_score() final;
    virtual std::list<Card>& get_cards() final;
    virtual ~Player() = 0;
//private:
    virtual void round_initial_take() final;
    virtual void hit() final;

    friend std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);
};

std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards);

#endif // PLAYER_HPP
