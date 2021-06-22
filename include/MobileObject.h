#pragma once
#include "GameObject.h"
struct Board;
using sf::Time;

class MobileObject:public GameObject {
public:
	MobileObject(const Vector2f& pos)
		:GameObject(pos) {}
	virtual void move(Board& board, Time delta) = 0 {}
};