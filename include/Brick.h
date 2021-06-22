#pragma once
#include "GameObject.h"
#include "BoardMacros.h"
#include "Resources.h"
#include "Gift.h"
#include <string>
#include <memory>
using std::unique_ptr;
using sf::Clock;
using std::string;

const int BREAK_ANIM_NUM = 5;
const int BREAK_ANIM_DELTA = 80;

class Brick :public GameObject {
public:
	//constructor build brick with sprite position and strength
	//and set first rect in texture
	Brick(const Vector2f& pos, const int strength);

	//draw and in case of broken brick
	//send to animate before drawing
	void draw(RenderWindow& window);

	//returns if this brick broken already
	bool isBroken() const;

	//hit the brick - not necessarily break it, it depends on the strength
	void hit();

	//break the brick
	void breakIt();

	//hold gift
	void holdGift(unique_ptr<Gift> giftPtr);

	//return hidden gift
	unique_ptr<Gift>& getGift();
private:
	//break animation handling
	void animat();

	//index for breraking animation
	uint8_t m_breakAnimIndx;

	//brick's strength and type by strength
	uint8_t m_strength, m_type;

	//animation clock
	Clock m_clock;

	//pointer to a gift hidden in  brick
	unique_ptr<Gift> m_giftPtr;
};