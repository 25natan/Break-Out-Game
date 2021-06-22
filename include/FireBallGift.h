#pragma once
#include "TimeOutGift.h"
#include "BoardMacros.h"
class FireBallGift :
    public TimeOutGift
{
public:
    //default constructor build gift with position and sprite
    FireBallGift(const Vector2f& pos);

    //activate - set every ball to be a fire ball
    void activate(Board& board);

    //validate in time
    bool exists(Board& board);
};