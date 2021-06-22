#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include "Gift.h"
#include "LifeGift.h"
#include "Shooting.h"
#include "ShootingGift.h"
#include "FireBallGift.h"
#include "BallsGift.h"
#include "MobileObject.h"
#include "Brick.h"
#include "ResizeGift.h"
#include "SpeedGift.h"
#include "PointsGift.h"
#include "GameWindow.h"
#include "Resources.h"
#include "Paddle.h"
#include "Ball.h"
using std::ifstream;
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;


//size constants

struct Board
{
public:
	//default constructor
	Board();
	//load stage board from file
	bool loadFromFile(const string& fileName);

	//bricks vector
	vector<unique_ptr<Brick>> bricks;

	//balls and shooting in polymorphic vector
	vector<unique_ptr<MobileObject>> mobileObjects;

	//board sprite
	Sprite board;

	//board size and position
	Vector2f boardSize, boardPos;

	//set paddle and ball in the middle-bottom of the window
	void setPaddleAndBall();
private:
	//check input file
	vector<string> checkInput(const string& fileName);

	//load board and set objects
	void setBoard(const vector<string>& charBoard);
};

