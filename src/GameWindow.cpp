#include "GameWindow.h"
GameWindow& GameWindow::instance()
{
	static GameWindow ins;
	return ins;
}

GameWindow::GameWindow()
	:window(VideoMode::getDesktopMode(), "Breakout Game"), event(),background(Resources::instance().background)
{
	window.setPosition({ -9,0 });
	background.scale(window.getSize().x/ background.getGlobalBounds().width,
		window.getSize().y / background.getGlobalBounds().height);
}