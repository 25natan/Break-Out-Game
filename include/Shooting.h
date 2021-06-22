#pragma once
#include "MobileObject.h"
#include "Resources.h"
#include <utility>

class Shooting :
    public MobileObject
{
public:
    //default constructor - build one bullet with sprite and position
    Shooting(const Vector2f& pos);

    //move and handle brick breaking
    void move(Board& board, Time delta);

    //exists - bullet break after hitting brick 
    //or walls
    bool exists(Board& board);
private:
    //existing flags
    bool m_exists;

    //speed - units per seconds
    size_t m_speed;
};

