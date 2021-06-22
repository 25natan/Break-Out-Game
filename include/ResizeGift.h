#pragma once
#include "TimeOutGift.h"
#include "BoardMacros.h"
enum ResizeOperate { Increase, Decrease };
class ResizeGift :
    public TimeOutGift
{
public:
    //default constructor build gift with position and sprite
    ResizeGift(const Vector2f& pos, ResizeOperate operate);

    //activate - add points to player info
    void activate(Board& board);

    //validate in time
    bool exists(Board& board);
private:
    float m_factor;
    ResizeOperate m_operate;
};