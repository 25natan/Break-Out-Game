#pragma once
#include "Stage.h"
#include "OpeningScreen.h"
#include "LevelMenu.h"
#include "FailedMsg.h"
#include "WonMsg.h"
#include "PlayerInfo.h"
#include <fstream>
#include <vector>
#include <string>
using std::ifstream;
using std::vector;


class Controller
{
public:
	Controller();
	void run();
private:
	//number of levels - updated in the constructor
	size_t m_levelsNum;
};

