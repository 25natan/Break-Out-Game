#pragma once
#include "TimeOutGift.h"
#include "Shooting.h"
class ShootingGift :
    public TimeOutGift
{
public:
    //default constructor build gift with position and sprite
    ShootingGift(const Vector2f& pos);

    //activate - set shooting on
    void activate(Board& board);

    //validate in time - if time is still in 
    //then keeps load shootings, if time is out then stop loading shooting
    bool exists(Board& board);
};

