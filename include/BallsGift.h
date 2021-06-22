#pragma once
#include "Gift.h"
#include "Ball.h"
#include <memory>
using std::make_unique;

class BallsGift :
    public Gift
{
public:
    //default constructor
    BallsGift(const Vector2f& pos);

    //activate - add n balls to the balls vector
    void activate(Board& board);
private:
    //number of additional balls
    int m_ballsNum;
};

