#pragma once
#include <vector>
#include "GameWindow.h"
#include "Resources.h"
#include "BoardMacros.h"
using sf::Sprite;
using std::vector;
using sf::Vector2f;

class Help
{
public:
	static Help& instance();

	//show help sprite until user press back
	void show();
private:
	//set help sprite
	Help();

	//choose level massge
	Sprite m_help, m_backBottom;

	//reference to main window and event
	RenderWindow& m_window;
	Event& m_event;
};

