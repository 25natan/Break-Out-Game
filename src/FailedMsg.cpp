#include "FailedMsg.h"

FailedMsg::FailedMsg()
	:m_window(GameWindow::instance().window),m_event(GameWindow::instance().event)
	,m_time(2),m_shape(Resources::instance().failedMsg)
{
	m_shape.scale(m_window.getSize().x / m_shape.getGlobalBounds().width,
		m_window.getSize().y / m_shape.getGlobalBounds().height);
}

void FailedMsg::show()
{
	Resources::instance().failed.play();
	while (m_window.isOpen() && Resources::instance().failed.getStatus()!=sf::SoundSource::Status::Stopped)
	{
		m_window.clear();
		m_window.draw(GameWindow::instance().background);
		m_window.draw(m_shape);
		m_window.display();
		if (m_window.pollEvent(m_event) && m_event.type == sf::Event::Closed)
			m_window.close();
	}
}