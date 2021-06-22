#include "OpeningScreen.h"
OpeningScreen::OpeningScreen()
	:m_time(2),m_shape(Resources::instance().openScrn)
	,m_window(GameWindow::instance().window),m_event(GameWindow::instance().event)
{
	m_shape.scale(m_window.getSize().x / m_shape.getGlobalBounds().width,
		m_window.getSize().y / m_shape.getGlobalBounds().height);
}

void OpeningScreen::show()
{
	sf::Clock clock;
	while (m_window.isOpen() && clock.getElapsedTime().asSeconds() < m_time)
	{
		m_window.clear();
		m_window.draw(GameWindow::instance().background);
		m_window.draw(m_shape);
		m_window.display();
		if (m_window.pollEvent(m_event) && m_event.type == sf::Event::Closed)
			m_window.close();
	}
}

OpeningScreen& OpeningScreen::instance()
{
	static OpeningScreen ins;
	return ins;
}