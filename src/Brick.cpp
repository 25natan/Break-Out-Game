#include "Brick.h"


Brick::Brick(const Vector2f& pos, const int strength)
	:GameObject(pos),m_clock(), m_breakAnimIndx(0)
{
	m_shape.setTexture(Resources::instance().brick);
	if (strength < 2 || strength > 7)
		throw string("Strength of brick not in range!");
	m_strength = strength;
	m_type = strength - 2;
	m_shape.setTextureRect({ 0,m_type * BRICK_HEIGHT,BRICK_WIDTH,BRICK_HEIGHT });
}

void Brick::draw(RenderWindow& window) 
{
	animat();
	window.draw(m_shape);
}

bool Brick::isBroken() const
{
	return m_strength <= 0;
}

void Brick::hit()
{
	m_strength--;
	if (m_strength <= 0)
		breakIt();
}

void Brick::breakIt()
{
	Resources::instance().breaking.play();
	if (m_strength)
		m_strength = 0;
	m_clock.restart();
	m_shape.setTextureRect({ 2*BRICK_WIDTH,m_type * BRICK_HEIGHT,
			BRICK_WIDTH, BRICK_HEIGHT });
	m_breakAnimIndx = 0;
}

void Brick::animat()
{
	//brick is stable
	if (m_strength > 1)
		return;

	//one hit left to break the brick
	if (m_strength == 1)
	{
		m_shape.setTextureRect({ BRICK_WIDTH,m_type *BRICK_HEIGHT,
			BRICK_WIDTH, BRICK_HEIGHT });
		return;
	}

	//in breaking animation
	if (m_clock.getElapsedTime().asMilliseconds() < BREAK_ANIM_DELTA)
		return;
	m_breakAnimIndx++;
	if (m_breakAnimIndx < BREAK_ANIM_NUM)
	{
		m_shape.setTextureRect({ BRICK_WIDTH * (m_breakAnimIndx + 2),m_type * BRICK_HEIGHT,
			BRICK_WIDTH, BRICK_HEIGHT });
		m_clock.restart();
	}
	else if (m_breakAnimIndx >= BREAK_ANIM_NUM)
	{
		m_shape.setTextureRect({ 0,0,0,0 });
		m_exist = false;
	}
}

void Brick::holdGift(unique_ptr<Gift> giftPtr)
{
	m_giftPtr = std::move(giftPtr);
}

unique_ptr<Gift>& Brick::getGift()
{
	return m_giftPtr;
}