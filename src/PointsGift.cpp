#include "PointsGift.h"
PointsGift::PointsGift(const Vector2f& pos)
	:Gift(pos)
{
	int type = rand() % 4;
	switch (type)
	{
	case 0:m_points = 50;
		m_shape.setTextureRect({ 2 * GIFT_WIDTH,0,GIFT_WIDTH ,GIFT_HEIGHT });
		break;
	case 1:m_points = 100;
		m_shape.setTextureRect({ 3 * GIFT_WIDTH,0,GIFT_WIDTH ,GIFT_HEIGHT });
		break;
	case 2:m_points = 250;
		m_shape.setTextureRect({ 4 * GIFT_WIDTH,0,GIFT_WIDTH ,GIFT_HEIGHT });
		break;
	case 3:m_points = 500;
		m_shape.setTextureRect({ 5 * GIFT_WIDTH,0,GIFT_WIDTH ,GIFT_HEIGHT });
		break;
	}
}

void PointsGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	PlayerInfo::instance().setPoints(PlayerInfo::instance().points() + m_points);
	Resources::instance().raise.play();
}