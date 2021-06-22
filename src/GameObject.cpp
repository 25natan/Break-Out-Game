#include "GameObject.h"
GameObject::GameObject(const Vector2f& pos)
	:m_exist(true)
{
	m_shape.setPosition(pos);
}

FloatRect GameObject::bounds() const
{
	return m_shape.getGlobalBounds();
}

void GameObject::draw(RenderWindow& window) const
{
	window.draw(m_shape);
}

bool GameObject::exists(Board& board)
{
	return m_exist;
}