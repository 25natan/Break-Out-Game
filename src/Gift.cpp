#include "Gift.h"
#include "Board.h"

Gift::Gift(const Vector2f& pos)
	:MobileObject(pos), m_activated(false), m_speed(500)
{
	m_shape.setTexture(Resources::instance().gift);
}

void Gift::move(Board& board, Time delta)
{
	if (m_activated)
		return;
	m_shape.move(0, m_speed * delta.asSeconds());
	//check going down
	if (m_shape.getGlobalBounds().top + m_shape.getGlobalBounds().height > board.boardPos.y + board.boardSize.y)
	{
		m_exist = false;
		m_shape.setTextureRect({ 0,0,0,0 });
	}
}

void Gift::activate(Board& board)
{
	if (m_activated)
		return;
	Resources::instance().takeGift.play();
	m_activated = true;
	m_shape.setTextureRect({ 0,0,0,0 });
}

bool Gift::activated()
{
	return m_activated;
}

bool Gift::exists(Board& board)
{
	return m_exist && !m_activated;
}
