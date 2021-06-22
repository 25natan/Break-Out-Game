#pragma once
#include "GameWindow.h"
#include "Resources.h"

class FailedMsg
{
public:
	FailedMsg();
	void show();
private:
	//game over massage sprite
	Sprite m_shape;

	//reference to main window and event
	RenderWindow& m_window;
	Event& m_event;
	
	//time to show this massage
	size_t m_time;
};

