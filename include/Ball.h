#pragma once
#include "MobileObject.h"
#include "BoardMacros.h"
#include "Resources.h"
#include <cmath>
#include <vector>
using std::abs;
using std::vector;
using std::cos;
using std::acos;
using std::sin;
using sf::Time;
const double PI = 3.14159265358979323846;
enum Surface { Verticl, Horizental ,Corner};



class Ball:public MobileObject
{
public:
	//constructor build a ball with sprite position and strength
	//and set first rect in texture
	Ball(const Vector2f& pos, size_t speed = 700);

	//set movement vector - if it's not a unit vector it
	//will be normalized 
	void setMovementVector(const Vector2f& movementVector);

	//move by movement vector
	void move(Board& board,Time delta);

	//set ball to be fire ball - will multiply the speed in a constant factor
	void setFireBall(bool flag);

	//return if the ball is on fireball status
	bool isFireBall();

	//set speed
	void setSpeed(size_t speed);

	//get speed
	size_t getSpeed();
private:
	//ball hit some stable surface - the movement vector will be changed
	//and go back from the surface which is vertical or horizental
	void hit(Surface surface);

	//collision handling functions
	void handlePaddleCollision(Board& board, Time delta);
	void handleBricksCollision(Board& board, Time delta);
	void handleWallsCollision(Board& board, Time delta);

	//movement vector - unit vector
	Vector2f m_movementVector;

	//speed - per seconds
	size_t m_speed;

	//fire ball flag
	bool m_fireBall;
};

