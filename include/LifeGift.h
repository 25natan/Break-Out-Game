#pragma once
#include "Gift.h"
#include "BoardMacros.h"
#include "PlayerInfo.h"
class LifeGift :
    public Gift
{
public:
    //default constructor build gift with position and sprite
    LifeGift(const Vector2f& pos);

    //add one life to player
    void activate(Board& board);
};

