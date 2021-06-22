#pragma once
#include <vector>
#include "GameWindow.h"
#include "Resources.h"
#include "BoardMacros.h"
#include "Help.h"
using sf::Sprite;
using std::vector;
using sf::Vector2f;

class LevelMenu
{
public:
	static LevelMenu& instance(size_t numOfLevels);

	//show levels menu and return the choosen level number
	size_t show();
private:
	//set levels bars 
	LevelMenu(size_t numOfLevels);

	//shapes of the number
	vector<Sprite> m_shapes;

	//choose level massge
	Sprite m_chooseLevelMsg, m_helpBottom;

	//reference to main window and event
	RenderWindow& m_window;
	Event& m_event;
};

