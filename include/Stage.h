#pragma once
#include "Board.h"
#include "GameWindow.h"
#include "PlayerInfo.h"
#include <typeinfo>
#include <cstdint>
#include <string>
using sf::Clock;
using std::string;
using std::to_string;
using std::uint8_t;


class Stage
{
public:
	//constructor build stage from file stageN.txt
	Stage(size_t num);

	//play stage
	bool play();

private:
	//draw board on window
	void draw();

	//move all mobile objects
	void move();

	//update - clear broken bricks
	void update();

	//check if the main ball went down - user failed
	bool failed();

	//reset board in second playing attempt (or more)
	//set ball and paddle as the beginning and remove anything
	//except stable bricks
	void reset();

	//stage gameboard
	Board m_board;

	//reference to main window
	RenderWindow& m_window;

	//reference to main event handler
	Event& m_event;

	//game clock
	Clock m_clock;
};

