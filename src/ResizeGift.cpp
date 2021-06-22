#include "ResizeGift.h"
#include "Board.h"
ResizeGift::ResizeGift(const Vector2f& pos, ResizeOperate operate)
	:TimeOutGift(pos), m_operate(operate)
{
	operate == SpeedUp ? m_shape.setTextureRect({ 2 * GIFT_WIDTH,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT }) :
	m_shape.setTextureRect({ 3 * GIFT_WIDTH,GIFT_HEIGHT,GIFT_WIDTH,GIFT_HEIGHT });
	m_time = 6;
	m_factor = 3.0 / 2;
}

void ResizeGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	((Paddle*)board.mobileObjects.front().get())->resizeWidth(m_operate == Increase ? m_factor : 1 / m_factor, board);
	m_clock.restart();
}

bool ResizeGift::exists(Board& board)
{
	if (m_activated && m_clock.getElapsedTime().asSeconds() > m_time)
	{
		((Paddle*)board.mobileObjects.front().get())->resizeWidth(m_operate == Increase ? 1 / m_factor : m_factor, board);
		return false;
	}
	return true;
}