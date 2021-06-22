#include "Paddle.h"
#include "Board.h"

Paddle::Paddle(const Vector2f& pos)
	:MobileObject(pos),m_window(GameWindow::instance().window),m_moving(false)
	,m_event(GameWindow::instance().event),m_mousePos(0),m_shooting(false)
{
	m_shape.setTexture(Resources::instance().paddle);
}

void Paddle::move(Board& board, Time delta)
{
	if (m_window.pollEvent(m_event))
		switch (m_event.type)
		{
		case Event::Closed:
			m_window.close();
			return;///move paddle by arrows
		case Event::KeyPressed:
			if (m_event.key.code == Keyboard::Left && checkMove(board ,-MOVE))
				m_shape.move(-MOVE, 0);
			else if(m_event.key.code == Keyboard::Right && checkMove(board,MOVE))
				m_shape.move(MOVE, 0);
			break;//move paddle by mouse
		case Event::MouseButtonPressed:
			if (m_shape.getGlobalBounds().contains(m_event.mouseButton.x, m_event.mouseButton.y))
			{
				m_moving = true;
				m_mousePos = m_event.mouseButton.x;
			}
			break;
		case Event::MouseButtonReleased:
			m_moving = false;
			break;
		case Event::MouseMoved:
			if (m_moving)
			{
				if(checkMove(board, m_event.mouseMove.x - m_mousePos))
					m_shape.move(m_event.mouseMove.x - m_mousePos, 0);
				m_mousePos = m_event.mouseMove.x;
			}
		}
	handlGiftsCollision(board);
	if (m_shooting)
		handleShooting(board);
}

bool Paddle::checkMove(Board& board, float move)
{
	return m_shape.getGlobalBounds().left + move > board.boardPos.x &&
		m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width + move < board.boardPos.x + board.boardSize.x;
}

void Paddle::resizeWidth(float fact,Board& board)
{
	m_shape.scale(fact, 1);
	if (m_shape.getGlobalBounds().left < board.board.getGlobalBounds().left)
		m_shape.setPosition(board.board.getGlobalBounds().left, m_shape.getGlobalBounds().top);
	else if (m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width >
		board.board.getGlobalBounds().left + board.board.getGlobalBounds().width)
		m_shape.setPosition(board.board.getGlobalBounds().left + board.board.getGlobalBounds().width - m_shape.getGlobalBounds().width
			, m_shape.getGlobalBounds().top);
}

void Paddle::setShoot(bool flag, Board& board)
{
	m_shooting = flag;
	if (m_shooting)
	{
		loadNewShootings(board);
		m_clock.restart();
	}
}

void Paddle::handleShooting(Board& board)
{
	if (!m_shooting)
		return;
	if (m_clock.getElapsedTime().asMilliseconds() > SHOOT_DELTA)
	{
		loadNewShootings(board);
		m_clock.restart();
	}
}

void Paddle::loadNewShootings(Board& board)
{
	//push left bullet
	board.mobileObjects.push_back(make_unique<Shooting>
		(Vector2f(m_shape.getGlobalBounds().left, m_shape.getGlobalBounds().top -
			Resources::instance().bullet.getSize().y)));
	//push right bullet
	board.mobileObjects.push_back(make_unique<Shooting>
		(Vector2f(m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width -
			Resources::instance().bullet.getSize().x,
			board.mobileObjects.back()->bounds().top)));
	m_clock.restart();
}

bool Paddle::started()
{
	if (m_window.pollEvent(m_event))
		if (m_event.type == Event::Closed)
			m_window.close();
		else if (m_event.type == Event::MouseButtonPressed)
			if (m_shape.getGlobalBounds().contains(m_event.mouseButton.x, m_event.mouseButton.y))
				return m_moving = true;
	return false;
}

void Paddle::handlGiftsCollision(Board& board)
{
	//check meeting gift
	for (size_t i(1);i < board.mobileObjects.size();i++)
		if (typeid(*board.mobileObjects[i]) != typeid(Ball) &&
			board.mobileObjects[i]->bounds().intersects(m_shape.getGlobalBounds()))
			((Gift*)board.mobileObjects[i].get())->activate(board);
}