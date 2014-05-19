#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "cardlist.hpp"
#include <string>

class Player
{
protected:
    const std::string name;
    int round_score;
    CardList cards;
public:
    Player();
    Player(const std::string& name);
    virtual std::string round_progress() const;
    virtual std::string get_name() const;
    virtual void reset_round_score() final;
    virtual int get_round_score() final;
    virtual CardList& get_cards() final;
    virtual ~Player() = 0;
//private:
    virtual void round_initial_take() final;
    virtual void hit() final;
};

#endif // PLAYER_HPP
