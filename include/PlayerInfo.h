#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"
#include "GameWindow.h"
#include "BoardMacros.h"
using std::to_string;
using sf::Font;
using sf::Text;
using sf::Sprite;
using sf::RenderWindow;
using sf::Vector2f;


class PlayerInfo{
public:
    //the one and only instance of this class
    static PlayerInfo& instance();

    //reset life to 3 and points to 0
    void reset();

    //set life
    void setLife(int life);

    //set points
    void setPoints(int points);

    //get life 
    int life();

    //get points
    int points();

    //draw info on board
    void draw(RenderWindow& window);
private:
    //default constructor build player info with points = 0 and life = 3
   //in the given position
    PlayerInfo();

    //locate every thing in the middle top
    //of the main window
    void locateInWindow();

    //set text string by the current points and life
    void setText();

    //font for writing
    Font m_font;

    //text for writing - points and life
    Text m_text[2];

    //player's points
    int m_points;

    //player's life
    int m_life;
    
    //symbol
    Sprite m_lifeSymbol;
    Sprite m_pointsSymbol;
};

