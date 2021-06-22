#include "FireBallGift.h"
#include "Board.h"
FireBallGift::FireBallGift(const Vector2f& pos)
	:TimeOutGift(pos) 
{
	m_time = 6;
	m_shape.setTextureRect({ 5 * GIFT_WIDTH,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT });
}

void FireBallGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	for (size_t i(1);typeid(*board.mobileObjects[i]) == typeid(Ball);i++)
	{
		Ball* ball = (Ball*)board.mobileObjects[i].get();
		if (!ball->isFireBall())
			ball->setFireBall(true);
	}
	m_clock.restart();
}

bool FireBallGift::exists(Board& board)
{
	if (m_activated && m_clock.getElapsedTime().asSeconds() > m_time)
	{
		for(size_t i(1);typeid(*board.mobileObjects[i]) == typeid(Ball);i++)
			((Ball*)board.mobileObjects[i].get())->setFireBall(false);
		return false;
	}
	else if(m_activated)
		for (size_t i(1);typeid(*board.mobileObjects[i]) == typeid(Ball);i++)
		{
			Ball* ball = (Ball*)board.mobileObjects[i].get();
			if (!ball->isFireBall())
				ball->setFireBall(true);
		}
	return true;
}