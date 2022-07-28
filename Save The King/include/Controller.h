#pragma once
#include "Board.h"
#include "Menu.h"
#include "Toolbar.h"

class Controller {

public:

	Controller();
	void draw();
	void run();
	void handleEvents() ; 
	void handleGameTime();
	void resetTimeLevel();
	void runGame();
	void runLevel();
	void printWinGame();
	const sf::Sprite getBackgroundSprite() const;
	~Controller() = default;

private:

	Board m_board;									//main board
	Menu m_menu;									//for menu
	Toolbar m_toolbar;							//for level information data
	std::unique_ptr<MovingObjects> m_currCharacter;	//to store current character
	sf::RenderWindow m_window;						//game render window
	sf::Time m_gameTime;							//for the time of the game 
	sf::Clock m_deltaTime,							//for delta time of game
		m_timeOfCurrLevel;							//for time of current level

	float m_dt = 0;									//to store delta time for movment
	int m_currChar = 0;								//for choose character 
	bool m_endOfTime = false;						//IF level time end
};