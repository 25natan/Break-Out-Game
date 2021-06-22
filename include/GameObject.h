#pragma once
#include <SFML/Graphics.hpp>
using sf::Sprite;
using sf::FloatRect;
using sf::Vector2f;
using sf::RenderWindow;
struct Board;

class GameObject
{
public:
	//constructor builds shape sprite and set its position
	GameObject(const Vector2f& pos);

	//bounds of shape
	virtual FloatRect bounds() const;

	//draw shape sprite on the given window
	virtual void draw(RenderWindow& window) const;

	//return if this object exists
	virtual bool exists(Board& board);

	//virtual d-tor
	virtual ~GameObject() = 0 {}
protected:
	//drawble shape
	Sprite m_shape;

	//existance flag
	bool m_exist;
};

