#include <sstream>
#include <memory>
#include "player.hpp"
#include "deck.hpp"
#include "const.hpp"
#include "deck.hpp"

Player::Player(std::shared_ptr<Deck> deck, const std::string& name)
    : deck(deck), cards(), name(name)
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
    output << get_name() << ": " << cards << ": " << get_round_score() << std::endl;
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

CardList Player::get_cards() const
{
    return cards;
}

std::string Player::round_initial_take()
{
    // I assume that there are at least 4 cards in the deck.
    cards.push_back(deck->take_next());
    cards.push_back(deck->take_next());
    return round_progress();
}

void Player::update_total_score(int& total_player_score, int& total_croupier_score)
{
    total_player_score += 1;
}

std::string Player::hit() throw(deck_is_empty)
{
    deck_is_empty e;
    if (deck->size() < 1) throw e;
    cards.push_back(deck->take_next());
    return round_progress();
}

std::string Player::strategy_croupier_based(int limit)
{
    std::ostringstream stream;

    while(get_round_score() < limit)
    {
        try
        {
            stream << hit();
        }
        catch (deck_is_empty& e)
        {
            return stream.str();
        }
    }
    return stream.str();
}

std::ostream& operator<<(std::ostream& stream, const CardList& cards)
{
    for (const Card& card : cards)
        stream << card << " ";
    return stream;
}
