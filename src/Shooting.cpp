#include "Shooting.h"
#include "Board.h"

Shooting::Shooting(const Vector2f& pos)
	:MobileObject(pos), m_exists(true), m_speed(600)
{
	m_shape.setTexture(Resources::instance().bullet);
}

void Shooting::move(Board& board, Time delta)
{
	if (!m_exists)
		return;
	m_shape.move(0,m_speed * -delta.asSeconds());
	bool hit = false;
	for (auto& brick : board.bricks)
		if (!brick->isBroken() &&
			brick->bounds().intersects(m_shape.getGlobalBounds()))
		{
			brick->breakIt();
			hit = true;
		}

	if (!hit && m_shape.getGlobalBounds().top < board.boardPos.y)
		hit = true;
	
	if (hit)
	{
		m_exists = false;
		m_shape.setTextureRect({ 0,0,0,0 });
	}
}

bool Shooting::exists(Board& board)
{
	return m_exists;
}