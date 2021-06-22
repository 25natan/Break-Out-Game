#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
using sf::RenderWindow;
using sf::Sprite;
using sf::VideoMode;
using sf::Event;

class GameWindow
{
public:
	//main window of the game
	RenderWindow window;

	//main event handle
	Event event;

	//main background 
	Sprite background;

	//return reference to the only instance of GameWindow
	static GameWindow& instance();

private:
	//default constructor build the window of the game
	GameWindow();
};

