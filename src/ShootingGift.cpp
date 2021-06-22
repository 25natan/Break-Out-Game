#include "ShootingGift.h"
#include "Board.h"

ShootingGift::ShootingGift(const Vector2f& pos)
	:TimeOutGift(pos)
{
	m_time = 6;
	m_shape.setTextureRect({ 4 * GIFT_WIDTH,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT });
}

void ShootingGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	((Paddle*)board.mobileObjects.front().get())->setShoot(true, board);
	m_clock.restart();
}

bool ShootingGift::exists(Board& board)
{
	if (m_activated && m_clock.getElapsedTime().asSeconds() > m_time)
	{
		((Paddle*)board.mobileObjects.front().get())->setShoot(false, board);
		return false;
	}
	return true;
}