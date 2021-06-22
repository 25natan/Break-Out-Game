#include "Resources.h"
Resources::Resources()
{
	if (!brick.loadFromFile("brick.png"))
		throw exception("cannot load brick image from file!");
	if (!ball.loadFromFile("ball.png"))
		throw exception("cannot load ball image from file!");
	if (!background.loadFromFile("background.png"))
		throw exception("cannot load background image from file!");
	if (!board.loadFromFile("board.png"))
		throw exception("cannot load board image from file!");
	if (!paddle.loadFromFile("paddle.png"))
		throw exception("cannot load paddle image from file!");
	if (!gift.loadFromFile("gift.png"))
		throw exception("cannot load gift image from file!");
	if (!bullet.loadFromFile("bullet.png"))
		throw exception("cannot load bullet image from file!");
	if (!coin.loadFromFile("coin.png"))
		throw exception("cannot load coin image from file!");
	if (!openScrn.loadFromFile("openingScreen.png"))
		throw exception("cannot load opening screen image from file!");
	if (!lavelBar.loadFromFile("levelBar.png"))
		throw exception("cannot load lavel bar image from file!");
	if (!chooseLevelMsg.loadFromFile("chooseLevelMsg.png"))
		throw exception("cannot load choose level massge image from file!");
	if (!failedMsg.loadFromFile("failedMsg.png"))
		throw exception("cannot load choose failed massge image from file!");
	if (!wonMsg.loadFromFile("wonMsg.png"))
		throw exception("cannot load winning massge image from file!");
	if (!helpBottom.loadFromFile("helpBottom.png"))
		throw exception("cannot load help bottom image from file!");
	if (!backBottom.loadFromFile("backBottom.png"))
		throw exception("cannot load back bottom image from file!");
	if (!help.loadFromFile("help.png"))
		throw exception("cannot load help image from file!");
	if (!hitBuff.loadFromFile("hit.wav"))
		throw exception("cannot load hit sound from file!");
	if (!breakingBuff.loadFromFile("break.wav"))
		throw exception("cannot load breaking sound from file!");
	if (!takeGiftBuff.loadFromFile("takeGift.wav"))
		throw exception("cannot load breaking sound from file!");
	if (!wonBuff.loadFromFile("won.wav"))
		throw exception("cannot load won sound from file!");
	if (!failedBuff.loadFromFile("failed.wav"))
		throw exception("cannot load failed sound from file!");
	if (!raiseBuff.loadFromFile("raise.wav"))
		throw exception("cannot load raise sound from file!");
	hit.setBuffer(hitBuff);
	breaking.setBuffer(breakingBuff);
	takeGift.setBuffer(takeGiftBuff);
	won.setBuffer(wonBuff);
	failed.setBuffer(failedBuff);
	raise.setBuffer(raiseBuff);
}

Resources& Resources::instance()
{
	static Resources ins;
	return ins;
}