#include "Board.h"
#include <exception>

Board::Board()
	:board(Resources::instance().board),boardSize(board.getGlobalBounds().width, board.getGlobalBounds().height)
	,boardPos((GameWindow::instance().window.getSize().x- boardSize.x)/2, (GameWindow::instance().window.getSize().y - boardSize.y) / 2)
{
	board.setPosition(boardPos);
}

bool Board::loadFromFile(const string& fileName)
{
	setBoard(checkInput(fileName));
	setPaddleAndBall();
	return true;
}

void Board::setPaddleAndBall()
{
	Vector2f paddlePos(boardPos.x+(boardSize.x - PADDLE_WIDTH) / 2,
		boardPos.y+ boardSize.y - PADDLE_HEIGHT);
	Vector2f ballPos(paddlePos.x + (PADDLE_WIDTH - BALL_SIZE) / 2,
		paddlePos.y - BALL_SIZE);
	mobileObjects.insert(mobileObjects.begin(), make_unique<Paddle>(paddlePos));
	mobileObjects.insert(mobileObjects.begin() + 1, make_unique<Ball>(ballPos));
}

vector<string> Board::checkInput(const string& fileName)
{
	ifstream input(fileName);
	vector<string> charBoard;
	auto i = 0; 
	for (auto line = string();i < ROWS&& std::getline(input, line);i++)
	{
		if (line.length() < COLS || line.length() > COLS)
			throw std::exception("Invalid input - one or more lines are not in the correct length!");
		for (int j = 0;j < line.length();j++)
			if ((line[j] < BRICK2 || line[j] > BRICK8) && line[j] != ' ')
				throw std::exception("Invalid input - one or more characters are not correct!");
		charBoard.push_back(line);
	}
	if (i < ROWS)
		throw std::exception("number of rows is not correct!");
	i = 0;
	for (auto line = string();i < ROWS && std::getline(input, line);i++)
	{
		for (int j = 0;j < line.length();j++)
			if (j >= COLS)
				throw std::exception("Invalid input - one or more lines are not in the correct length!");
			else if ((line[j] <LIFE_GIFT || line[j]>FIRE_BALL_GIFT) && line[j] != ' ' || line[j] != ' '&& charBoard[i][j] == ' ')
				throw std::exception("Invalid input - one or more characters are not correct!");
		charBoard.push_back(line);
	}
	if (i == ROWS && !input.eof())
		throw std::exception("Invalid input - too many rows of intput!");
	return charBoard;
}

void Board::setBoard(const vector<string>& charBoard)
{
	for (int i = 0;i < ROWS;i++)
		for (int j = 0;j < COLS;j++)
		{
			if (charBoard[i][j] != ' ')
			{
				Vector2f pos(boardPos.x + SPACE + j * BRICK_WIDTH, boardPos.y + SPACE + i * BRICK_HEIGHT);
				bricks.push_back(make_unique<Brick>(pos, charBoard[i][j] - '0'));
				if (i + ROWS < charBoard.size() && j < charBoard[i + ROWS].size())
					switch (charBoard[i + ROWS][j])
					{
					case LIFE_GIFT:
						bricks.back()->holdGift(make_unique<LifeGift>(pos));
						break;
					case BALLS_GIFT:
						bricks.back()->holdGift(make_unique<BallsGift>(pos));
						break;
					case POINTS_GIFT:
						bricks.back()->holdGift(make_unique<PointsGift>(pos));
						break;
					case SPEED_UP_GIFT:
						bricks.back()->holdGift(make_unique<SpeedGift>(pos, SpeedUp));
						break;
					case SLOW_DOWN_GIFT:
						bricks.back()->holdGift(make_unique<SpeedGift>(pos, SlowDown));
						break;
					case INCREASE_GIFT:
						bricks.back()->holdGift(make_unique<ResizeGift>(pos, Increase));
						break;
					case DECREASE_GIFT:
						bricks.back()->holdGift(make_unique<ResizeGift>(pos, Decrease));
						break;
					case SHOOTING_GIFT:
						bricks.back()->holdGift(make_unique<ShootingGift>(pos));
						break;
					case FIRE_BALL_GIFT:
						bricks.back()->holdGift(make_unique<FireBallGift>(pos));
						break;
					}
			}
		}
}
