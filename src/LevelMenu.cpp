#include "LevelMenu.h"
LevelMenu::LevelMenu(size_t numOfLevels)
	:m_shapes(numOfLevels,Sprite(Resources::instance().lavelBar)),m_chooseLevelMsg(Resources::instance().chooseLevelMsg),
	m_window(GameWindow::instance().window),	m_event(GameWindow::instance().event),
	m_helpBottom(Resources::instance().helpBottom)
{
	m_chooseLevelMsg.scale(m_window.getSize().x / m_chooseLevelMsg.getGlobalBounds().width,
		m_window.getSize().y / m_chooseLevelMsg.getGlobalBounds().height);
	int barsInRow = 5;
	int space = (m_window.getSize().x - barsInRow * BAR_SIZE) / (barsInRow + 1);
	Vector2f startPos = Vector2f( space,5.0 / 9 * m_window.getSize().y );
	for (size_t i(0);i < numOfLevels;i++)
	{
		m_shapes[i].setTextureRect({int(i) * BAR_SIZE,0,BAR_SIZE,BAR_SIZE });
		m_shapes[i].setPosition(startPos.x+i*(BAR_SIZE+space), startPos.y);
	}
	m_helpBottom.setPosition(m_window.getSize().x - m_helpBottom.getGlobalBounds().width -50,
		m_window.getSize().y - m_helpBottom.getGlobalBounds().height - 100);
}

size_t LevelMenu::show()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(GameWindow::instance().background);
		m_window.draw(m_chooseLevelMsg);
		for (auto& bar : m_shapes)
			m_window.draw(bar);
		m_window.draw(m_helpBottom);
		m_window.display();
		if (m_window.pollEvent(m_event))
			if (m_event.type == Event::Closed)
				m_window.close();
			else if (m_event.type == Event::MouseButtonPressed)
			{
				for (size_t i(0);i < m_shapes.size();i++)
					if (m_shapes[i].getGlobalBounds().contains(m_event.mouseButton.x, m_event.mouseButton.y))
						return i + 1;
				if (m_helpBottom.getGlobalBounds().contains(
					m_event.mouseButton.x, m_event.mouseButton.y))
					Help::instance().show();
			}
	}
}

LevelMenu& LevelMenu::instance(size_t numOfLevels)
{
	static LevelMenu ins(numOfLevels);
	return ins;
}