#pragma once
#include "Gift.h"
#include "PlayerInfo.h"
#include "BoardMacros.h"
class PointsGift :
    public Gift
{
public:
    //default constructor build gift with position and sprite
    //and decide randomly on the amount of points
    PointsGift(const Vector2f& pos);

    //activate - add points to player info
    void activate(Board& board);
private:
    //possible points gift
    int m_points;
};

