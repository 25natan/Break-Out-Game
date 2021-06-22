#include "PlayerInfo.h"
PlayerInfo::PlayerInfo()
	:m_life(3), m_points(0),m_lifeSymbol(Resources::instance().gift)
	,m_pointsSymbol(Resources::instance().coin)
{
	m_lifeSymbol.setTextureRect({ 0,0,GIFT_WIDTH,GIFT_HEIGHT });
	m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	m_text[0].setFont(m_font);
	m_text[1].setFont(m_font);
	m_text[0].setFillColor(sf::Color(237, 28, 36));
	m_text[1].setFillColor(sf::Color(238, 155, 2));
	m_text[0].setCharacterSize(m_lifeSymbol.getGlobalBounds().height);
	m_text[1].setCharacterSize(m_pointsSymbol.getGlobalBounds().height);
	setText();
	locateInWindow();
}


PlayerInfo& PlayerInfo::instance()
{
	static PlayerInfo ins;
	return ins;
}

void PlayerInfo::setLife(int life)
{
	m_life = life;
	setText();
}

void PlayerInfo::setPoints(int points)
{
	m_points = points;
	setText();
}

int PlayerInfo::life()
{
	return m_life;
}

int PlayerInfo::points()
{
	return m_points;
 }

void PlayerInfo::draw(RenderWindow& window)
{
	window.draw(m_lifeSymbol);
	window.draw(m_text[0]);
	window.draw(m_pointsSymbol);
	window.draw(m_text[1]);
}
void PlayerInfo::reset()
{
	m_life = 3;
	m_points = 0;
	setText();
}

void PlayerInfo::setText()
{
	m_text[0].setString(": " + to_string(m_life));
	m_text[1].setString(": " + to_string(m_points));
}

void PlayerInfo::locateInWindow()
{
	float winWidth = GameWindow::instance().window.getSize().x;
	float space = 20;
	m_lifeSymbol.setPosition(winWidth / 4, space);
	m_text[0].setPosition(winWidth / 4 + 
		m_lifeSymbol.getGlobalBounds().width + space, space/2);
	m_pointsSymbol.setPosition(winWidth / 2, space);
	m_text[1].setPosition(winWidth / 2 +
		m_pointsSymbol.getGlobalBounds().width + space, space/2);
}