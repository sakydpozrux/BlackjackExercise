#ifndef ROUND_HPP
#define ROUND_HPP

enum players_enum
{
    CROUPIER = 0,
    PLAYER = 1
};

class Round
{
private:
    int player_score;
    int croupier_score;

public:
    Round();


    int get_player_score() const;
    int get_croupier_score() const;
};

#endif // ROUND_HPP
