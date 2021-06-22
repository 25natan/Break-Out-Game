#include "WonMsg.h"

WonMsg::WonMsg()
	:m_window(GameWindow::instance().window), m_event(GameWindow::instance().event)
	, m_time(2), m_shape(Resources::instance().wonMsg)
{
	m_shape.scale(m_window.getSize().x / m_shape.getGlobalBounds().width,
		m_window.getSize().y / m_shape.getGlobalBounds().height);
}

void WonMsg::show()
{
	sf::Clock clock;
	Resources::instance().won.play();
	while (m_window.isOpen() && Resources::instance().won.getStatus() != sf::SoundSource::Status::Stopped)
	{
		m_window.clear();
		m_window.draw(GameWindow::instance().background);
		if ((clock.getElapsedTime().asMilliseconds() / 300) % 2 == 0)
			m_window.draw(m_shape);
		m_window.display();
		if (m_window.pollEvent(m_event) && m_event.type == sf::Event::Closed)
			m_window.close();
	}
}