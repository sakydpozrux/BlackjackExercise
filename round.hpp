#ifndef ROUND_HPP
#define ROUND_HPP

enum round_result
{
    CROUPIER_WON = 0,
    PLAYER_WON = 1
};

class Round
{
private:
    int player_score;
    int croupier_score;

public:
    Round();

private:
    round_result result() const;
    void print_round_progress(round_result res) const;
    void print_round_end() const;
};

#endif // ROUND_HPP
