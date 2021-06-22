#pragma once
#include "MobileObject.h"
using sf::Clock;

class Gift: public MobileObject
{
public:
	//default constructor build gift with shape and position
	Gift(const Vector2f& pos);

	//move the gift down
	virtual void move(Board& board, Time delta);

	//activate the gift
	virtual void activate(Board& board) = 0;

	//return if the gift was activated
	bool activated();

	//virtual exists function
	virtual bool exists(Board& board);

	//virtual
	virtual ~Gift() = 0 {}
protected:
	//speed per seconds
	size_t m_speed;

	//activation flag
	bool m_activated;
};

