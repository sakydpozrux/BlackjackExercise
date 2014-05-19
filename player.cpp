#include "player.hpp"
#include <sstream>
#include <functional>

Player::Player()
    : name("PLAYER"), cards()
{
}

Player::Player(const std::string& name)
    : name(name), cards()
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
    output << get_name() << ": " << cards << ": " << get_round_score();
    return output.str();
}

void Player::clear_cards()
{
    cards.clear();
}

int Player::get_round_score() const
{
    int sum = 0;
    for(auto it = cards.begin(); it != cards.end(); ++it)
    {
        sum += it->get_value();
    }
    return sum;
}

std::list<Card> Player::get_cards() const
{
    return cards;
}

std::string Player::round_initial_take(Deck* const deck)
{
    cards.push_back(deck->take_next());
    cards.push_back(deck->take_next());
    return round_progress();
}

std::string Player::hit(Deck* const deck)
{
    cards.push_back(deck->take_next());
    return round_progress();
}

std::ostream& operator<<(std::ostream& stream, const std::list<Card>& cards)
{
    for (const Card& card : cards)
        stream << card << " ";
    return stream;
}
