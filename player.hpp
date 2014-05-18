#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
    Player();
    virtual ~Player() = 0;
private:
    int hit();
    void strand();
};

#endif // PLAYER_HPP
