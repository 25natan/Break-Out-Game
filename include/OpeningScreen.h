#pragma once
#include "GameWindow.h"
#include "Resources.h"
#include  <SFML/Graphics.hpp>
using sf::Sprite;
class OpeningScreen
{
public:
	//show openning screen for some seconds
	void show();

	static OpeningScreen& instance();
private:
	OpeningScreen();

	//opennig screen massage sprite
	Sprite m_shape;

	//seconds to show
	size_t m_time;

	//reference to main window and event
	RenderWindow& m_window;
	Event& m_event;
};

