#include "BallsGift.h"
#include "Board.h"
BallsGift::BallsGift(const Vector2f& pos)
	:Gift(pos),m_ballsNum(3)
{
	m_shape.setTextureRect({ BRICK_WIDTH,0,BRICK_WIDTH,BRICK_HEIGHT });
}

void BallsGift::activate(Board& board)
{
	if (m_activated)
		return;
	Gift::activate(board);
	if (board.mobileObjects.size() > 1 && typeid(*board.mobileObjects[1]) == typeid(Ball))
	{ 
		Ball* ball = (Ball*)board.mobileObjects[1].get();
		for (int i = 0;i < m_ballsNum;i++)
		{
			float angle = (rand() % 180) * PI / 180;
			board.mobileObjects.insert(board.mobileObjects.begin() + 1, make_unique<Ball>(*ball));
			((Ball*)board.mobileObjects[1].get())->setMovementVector({ cos(angle),-sin(angle) });
		}
	}
}
	