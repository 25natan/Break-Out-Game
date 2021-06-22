#include "Ball.h"
#include "Board.h"


Ball::Ball(const Vector2f& pos, size_t speed)
	:MobileObject(pos),m_speed(speed), m_fireBall(false)
{
	m_shape.setTexture(Resources::instance().ball);
	float angle = (rand() % 30 + 40) * PI / 180;
	m_movementVector = { cos(angle),-sin(angle) };
	m_shape.setTextureRect({ 0,0,BALL_SIZE ,BALL_SIZE });
}

void Ball::setMovementVector(const Vector2f& movementVector)
{
	m_movementVector = movementVector;
}

void Ball::move(Board& board, Time delta)
{
	m_shape.move(m_movementVector * (m_speed * delta.asSeconds()));
	handlePaddleCollision(board, delta);
	handleBricksCollision(board, delta);
	handleWallsCollision(board, delta);
}

void Ball::hit(Surface surface)
{
	Resources::instance().hit.play();
	if (surface == Verticl || surface == Corner)
		m_movementVector.x *= -1;
	if (surface == Horizental || surface == Corner)
		m_movementVector.y *= -1;
}

void Ball::setFireBall(bool flag)
{
	if (flag && m_fireBall || !flag && !m_fireBall)
		return;
	m_fireBall = flag;
	if (m_fireBall)
	{
		m_shape.setTextureRect({ 2 * BALL_SIZE,0,BALL_SIZE,BALL_SIZE });
		m_speed *= 3.0 / 2;
	}
	else
	{
		m_shape.setTextureRect({0,0,BALL_SIZE,BALL_SIZE });
		m_speed *= 2.0 / 3;
	}
}

void Ball::setSpeed(size_t speed)
{
	m_speed = speed;
}

size_t Ball::getSpeed()
{
	return m_speed;
}
bool Ball::isFireBall()
{
	return m_fireBall;
}

void Ball::handlePaddleCollision(Board& board, Time delta)
{
	FloatRect rect;
	if (board.mobileObjects.front()->bounds().intersects(m_shape.getGlobalBounds(), rect))
	{
		if (abs(rect.width - rect.height) && (m_shape.getGlobalBounds().left < board.mobileObjects.front()->bounds().left &&
			m_movementVector.x>0 || m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width >
			board.mobileObjects.front()->bounds().left + board.mobileObjects.front()->bounds().width && m_movementVector.x < 0))
			hit(Corner);
		else if (rect.width > rect.height)
			hit(Horizental);
		else
			hit(Verticl);
		while (board.mobileObjects.front()->bounds().intersects(m_shape.getGlobalBounds()))
			m_shape.move(m_movementVector * (m_speed * delta.asSeconds()));
		return;
	}
}

void Ball::handleBricksCollision(Board& board, Time delta)
{
	FloatRect rect;
	Surface surface;
	float maxHitSize = 0;
	for (auto& brick : board.bricks)
		if (!brick->isBroken() && brick->bounds().intersects(m_shape.getGlobalBounds(), rect))
		{
			if (!m_fireBall)
			{
				if (rect.width > rect.height && rect.width > maxHitSize)
				{
					surface = Horizental;
					maxHitSize = rect.width;
				}
				if (rect.height >= rect.width && rect.height > maxHitSize)
				{
					surface = Verticl;
					maxHitSize = rect.height;
				}
			}
			m_fireBall ? brick->breakIt() : brick->hit();
		}
	if (maxHitSize > 0)
	{
		hit(surface);
		m_shape.move(m_movementVector * (m_speed * delta.asSeconds()));
	}
}

void Ball::handleWallsCollision(Board& board, Time delta)
{
	if (m_shape.getGlobalBounds().left < board.boardPos.x ||
		m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width>board.boardPos.x + board.boardSize.x)
	{
		hit(Verticl);
		m_shape.move(m_movementVector * (m_speed * delta.asSeconds()));
	}
	if (m_shape.getGlobalBounds().top < board.boardPos.y)
	{
		hit(Horizental);
		m_shape.move(m_movementVector * (m_speed * delta.asSeconds()));
	}
	else if (m_shape.getGlobalBounds().top + m_shape.getGlobalBounds().height >
		board.boardPos.y + board.boardSize.y)
	{
		m_exist = false;
		m_shape.setTextureRect({ 0,0,0,0 });
	}
}