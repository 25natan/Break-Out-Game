#pragma once
#include "MobileObject.h"
#include "GameWindow.h"
#include "BoardMacros.h"
#include "Shooting.h"
#include <utility>
using sf::Keyboard;
using sf::Clock;
using std::pair;
const int MOVE = 30;
const int SHOOT_DELTA = 400;



class Paddle:public MobileObject
{
public:
	//default constructor build paddle with shape and position
	Paddle(const Vector2f& pos);

	//user move paddle
	void move(Board& board, Time delta);

	//let size menipulation
	void resizeWidth(float fact,Board& board);

	//set shooting on or off
	void setShoot(bool flag,Board& board);

	//wait for user to start
	bool started();
private:
	//try to take gifts
	void handlGiftsCollision(Board& board);

	//set two new shootings
	void loadNewShootings(Board& board);

	//check move - can't go out of window
	bool checkMove(Board& board, float move);
	
	//handle shooting - load more as long as shooting is on
	void handleShooting(Board& board);

	//reference to main window
	RenderWindow& m_window;

	//reference to main event handler
	Event& m_event;

	//movement in proccess flag
	//and shooting flag
	bool m_moving, m_shooting;

	//mouse position - used for movements
	float m_mousePos;

	//clock for the shooting
	Clock m_clock;
};

