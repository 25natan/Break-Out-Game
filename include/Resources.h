#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <exception>
using std::exception;
using std::string;
using sf::Texture;
using sf::SoundBuffer;
using sf::Sound;

class Resources {
public:
	//game textures
	Texture brick, ball, gift, paddle, board, background, bullet, coin,
		openScrn, lavelBar, chooseLevelMsg, failedMsg, wonMsg, 
		helpBottom, backBottom,help;

	//game sounds
	SoundBuffer hitBuff, breakingBuff, takeGiftBuff, wonBuff, failedBuff, raiseBuff;
	Sound hit, breaking, takeGift, won, failed, raise;

	//return reference to the one and only instance of resources
	static Resources& instance();
private:

	//constructor that load data from files to all textures
	Resources();
};