#include "Stage.h"

Stage::Stage(size_t num)
	:m_window(GameWindow::instance().window),m_event(GameWindow::instance().event)
{
	m_board.loadFromFile("stage" + string(to_string(num)) + ".txt");
}

bool Stage::play()
{
	static bool called = false;
	if (called)
		reset();
	called = true;
	while(m_window.isOpen() && !((Paddle*)m_board.mobileObjects.front().get())->started())
		draw();
	m_clock.restart();
	while (m_window.isOpen() && m_board.bricks.size() && !failed())
	{
		move();
		draw();
		update();
	}
	return m_board.bricks.size() == 0;
}

void Stage::draw()
{
	m_window.clear();
	m_window.draw(GameWindow::instance().background);
	m_window.draw(m_board.board);
	PlayerInfo::instance().draw(m_window);
	for (auto& brick : m_board.bricks)
		brick->draw(m_window);
	for (auto& mobileObject : m_board.mobileObjects)
		mobileObject->draw(m_window);
	m_window.display();
}

void Stage::move()
{
	Time delta = m_clock.restart();
	for (size_t i(0);i<m_board.mobileObjects.size();i++)
		m_board.mobileObjects[i]->move(m_board, delta);
}

bool Stage::failed()
{
	return m_board.mobileObjects.size() < 2 ||
		typeid(*m_board.mobileObjects[1]) != typeid(Ball);
}

void Stage::update()
{
	for (auto it(m_board.bricks.begin());it != m_board.bricks.end();)
		if (!(*it)->exists(m_board))
		{
			if ((*it)->getGift())
				m_board.mobileObjects.push_back(std::move((*it)->getGift()));
			it = m_board.bricks.erase(it);
		}
		else
			it++;

	for (auto it(m_board.mobileObjects.begin() + 1);it != m_board.mobileObjects.end();)
		if (!(*it)->exists(m_board))
			it = m_board.mobileObjects.erase(it);
		else
			it++;
}

void Stage::reset()
{
	m_board.mobileObjects.clear();
	for (auto it(m_board.bricks.begin());it != m_board.bricks.end();)
		if (!(*it)->exists(m_board) || (*it)->isBroken())
			it = m_board.bricks.erase(it);
		else
			it++;
	m_board.setPaddleAndBall();
}