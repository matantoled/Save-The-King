#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <iostream>

#include "GameObjects.h"
#include "MovingObjects.h"
#include "StaticObjects.h"

#include "Player.h"
#include "Dwarf.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"

#include "Fire.h"
#include "Gate.h"
#include "Gift.h"
#include "Key.h"
#include "Orc.h"
#include "Teleport.h"
#include "Throne.h"
#include "TimeGift.h"
#include "Wall.h"
#include "DwarfesEliminateGift.h"

class Board {

public:
	Board();

	void setBoard(const int LevelNum);
	void handleCollisions(MovingObjects& movingObject);
	void createObject(const ObjectType type, const sf::Vector2f location);
	void drawObjects(sf::RenderWindow& window, const char charNum);
	void moveObjects(const float dt, const int charNum);
	bool inBounds(const sf::Vector2f direction);
	int getTime() const;
	void setTime(const int time);
	void setTimeGift(const int num);
	int getTimeGift() const;
	bool getWinLevel() const;
	bool getWinGame() const;
	void setWinGame(const bool win);
	void moveDwarfs(const float dt);
	void movePlayers(const float dt, const int charNum);
	void handleStaticObjects() ;
	void eraseStaticObjects();
	void initObjects();
	void readLevelFile(std::ifstream& file);
	const sf::Vector2f findLocation(const int row,const int col) const;
	const sf::Vector2f getRandomDirection() const;
	const sf::Vector2f findNewLoc(const sf::Keyboard::Key key, const float dt, const int charNum) const;

private:
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;	//store static objects
	std::vector<std::unique_ptr<Player>> m_players;		//store the players characters
	std::vector<std::unique_ptr<Dwarf>> m_dwarfs;		//store dwarfs
	std::vector<std::unique_ptr<Teleport>> m_teleports;	//store teleports
	sf::RectangleShape m_markCurrChar;	// to mark the current character playing

	int m_rows = DEFAULT_ROWS;		//num of rows in board
	int m_cols = DEFAULT_COLS;		//num of cols in board
	int m_timeLevel = 0;			//time for current level
	int m_timeGift = 0;				//time from gift
	bool m_winLevel = false;		//if win level
	bool m_winGame = false;			//if win game

};