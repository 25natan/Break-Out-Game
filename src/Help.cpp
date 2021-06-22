#include "Help.h"
Help::Help()
	:m_window(GameWindow::instance().window),m_event(GameWindow::instance().event),
	m_help(Resources::instance().help),m_backBottom(Resources::instance().backBottom)
{
	m_help.scale(m_window.getSize().x / m_help.getGlobalBounds().width,
		m_window.getSize().y / m_help.getGlobalBounds().height);
	m_backBottom.setPosition(m_window.getSize().x - m_backBottom.getGlobalBounds().width - 50,
		m_window.getSize().y - m_backBottom.getGlobalBounds().height - 100);
}

void Help::show()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(GameWindow::instance().background);
		m_window.draw(m_help);
		m_window.draw(m_backBottom);
		m_window.display();
		if (m_window.pollEvent(m_event))
			if (m_event.type == sf::Event::Closed)
				m_window.close();
			else if (m_event.type == sf::Event::MouseButtonPressed)
				if (m_backBottom.getGlobalBounds().contains(
					m_event.mouseButton.x, m_event.mouseButton.y))
					return;
	}
}

Help& Help::instance()
{
	static Help ins;
	return ins;
}