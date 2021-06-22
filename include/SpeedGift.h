#pragma once
#include "TimeOutGift.h"
#include "BoardMacros.h"
enum SpeedOperate{ SpeedUp, SlowDown };
class SpeedGift :
    public TimeOutGift
{
public:
    //default constructor build gift with position and sprite
    SpeedGift(const Vector2f& pos, SpeedOperate operate);

    //activate - add points to player info
    void activate(Board& board);

    //validate in time
    bool exists(Board& board);
private:
    float m_factor;
    SpeedOperate m_operate;
};