#pragma once
#include "Gift.h"
using sf::Clock;

class TimeOutGift :
    public Gift
{
public:
    //default constructor build gift with position and sprite
    TimeOutGift(const Vector2f& pos) :Gift(pos),m_time(0) {}
protected:
    //timer out clock
    Clock m_clock;

    //time limit in seconds
    time_t m_time;
};

