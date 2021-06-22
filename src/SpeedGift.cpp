#include "SpeedGift.h"
#include "Board.h"
SpeedGift::SpeedGift(const Vector2f& pos,SpeedOperate operate)
	:TimeOutGift(pos),m_operate(operate)
{
	operate == SpeedUp ? m_shape.setTextureRect({ 0,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT }) :
		m_shape.setTextureRect({ GIFT_WIDTH,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT });
	m_time = 6;
	m_factor = 3.0/2;
}

void SpeedGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	for (size_t i(1);i<board.mobileObjects.size() && typeid(*board.mobileObjects[i]) == typeid(Ball);i++)
		{
			Ball* ball = (Ball*)board.mobileObjects[i].get();
			ball->setSpeed(m_operate == SpeedUp ? ball->getSpeed() * m_factor : ball->getSpeed() * (1 / m_factor));
		}
	m_clock.restart();
}

bool SpeedGift::exists(Board& board)
{
	if (m_activated && m_clock.getElapsedTime().asSeconds() > m_time)
	{
		for (size_t i(1);i < board.mobileObjects.size() && typeid(*board.mobileObjects[i]) == typeid(Ball);i++)
			{
				Ball* ball = (Ball*)board.mobileObjects[i].get();
				ball->setSpeed(m_operate == SpeedUp ? ball->getSpeed() * (1 / m_factor) : ball->getSpeed() * m_factor);
			}
		return false;
	}
	return true;
}