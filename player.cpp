#include "player.hpp"

Player::Player()
    : name("PLAYER"), round_score(0), cards()
{
}

Player::Player(const std::string& name)
    : name(name), round_score(0), cards()
{
}

Player::~Player()
{
}

std::string Player::get_name() const
{
    return name;
}

std::string Player::round_progress() const
{
    std::ostringstream output;
    output << get_name() << ": " << cards << ": " << round_score;
    return output.str();
}

void Player::reset_round_score()
{
    round_score = 0;
}

int Player::get_round_score()
{
    return round_score;
}

CardList& Player::get_cards()
{
    return cards;
}

void Player::round_initial_take()
{
    hit();
    hit();
}

void Player::hit()
{
    //cards;
}
