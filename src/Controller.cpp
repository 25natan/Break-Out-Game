#include "Controller.h"
Controller::Controller()
	:m_levelsNum(0)
{
	srand(time(NULL));
	while (ifstream("stage" + std::to_string(m_levelsNum + 1) + ".txt").good())
		m_levelsNum++;
	if (m_levelsNum == 0)
		throw exception("There are no stages files!");
}

void Controller::run()
{
	OpeningScreen::instance().show();
	while (GameWindow::instance().window.isOpen())
	{
		size_t level = LevelMenu::instance(m_levelsNum).show();
		Stage stage(level);
		while (GameWindow::instance().window.isOpen() && !stage.play())
		{
			PlayerInfo::instance().setLife(PlayerInfo::instance().life() - 1);
			if (!PlayerInfo::instance().life())
				break;
		}
		if (PlayerInfo::instance().life() == 0)
		{
			FailedMsg().show();
			PlayerInfo::instance().reset();
			OpeningScreen::instance().show();
		}
		else
			WonMsg().show();
	}
}