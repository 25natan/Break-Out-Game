#include "LifeGift.h"
LifeGift::LifeGift(const Vector2f& pos)
	:Gift(pos)
{
	m_shape.setTextureRect({ 0,0,GIFT_WIDTH,GIFT_HEIGHT });
}

void LifeGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	PlayerInfo::instance().setLife(PlayerInfo::instance().life() + 1);
	Resources::instance().raise.play();
}