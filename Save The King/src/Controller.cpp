#pragma once
#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(1920, 1080), "Save The King") {

	m_window.setFramerateLimit(FPS);
}
//=========================================================
void Controller::run() {

	//main loop
	while (true) {

		m_menu.runMenu(m_window);
		m_board.setBoard(m_toolbar.getLevelNum());
		runGame();
		printWinGame();
	}
}
//=========================================================
void Controller::runGame() {

	Resources::instance().playMusic(MusicType::GameMusic);

	while (!m_board.getWinGame()) {

		resetTimeLevel();
		runLevel();
		if (!m_endOfTime) {	//if level time not end and got here set next level
			m_toolbar.setLevelNum(m_toolbar.getLevelNum() + 1);
			Resources::instance().playSound(SoundType::WinSound);
		}
		m_board.setBoard(m_toolbar.getLevelNum());
	}
	m_toolbar.setLevelNum(FIRST_LEVEL);
	m_board.setWinGame(false);
}
//=========================================================
void Controller::runLevel() {

	while (!m_board.getWinLevel()) {

		draw();
		handleGameTime();
		if (m_gameTime.asSeconds() < 0) {	// if level time ends
			m_endOfTime = true;
			Resources::instance().playSound(SoundType::LoseSound);
			break;
		}
		handleEvents();
		m_board.moveObjects(m_dt, m_currChar);
	}
}
//=========================================================
void Controller::handleGameTime() {

	m_dt = m_deltaTime.restart().asSeconds();

	if (m_board.getTime() > 0) {	//if >0 time is factor in level
		m_gameTime -= m_timeOfCurrLevel.getElapsedTime();
		m_timeOfCurrLevel.restart();
		if (m_board.getTimeGift() != 0) {	//if !=0 there is a time gift we need to add to game time
			m_gameTime = m_gameTime + sf::seconds(float(m_board.getTimeGift()));
			m_board.setTimeGift(0);	//set time gift as used
		}
	}
}
//=========================================================
void Controller::handleEvents() {

	for (auto event = sf::Event{}; m_window.pollEvent(event);) {
		switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::P) {
				m_currChar++;
				m_currChar %= NUM_OF_CHARACTERS;
			}
			break;
		default:break;
		}
	}
}
//=========================================================
void Controller::draw() {

	m_window.clear();

	m_window.draw(getBackgroundSprite());
	m_board.drawObjects(m_window, char(m_currChar));
	
	if (m_board.getTime() == 0)
		m_toolbar.drawToolbarText(m_window, int(m_timeOfCurrLevel.getElapsedTime().asSeconds()));
	else
		m_toolbar.drawToolbarText(m_window, int(m_gameTime.asSeconds()));
	m_window.display();
}
//=========================================================
const sf::Sprite Controller::getBackgroundSprite() const{

	// choose background level from 3 backgounds (by %3)
	if (m_toolbar.getLevelNum() % 3 == 1)
		return sf::Sprite(Resources::instance().get(ObjectType::Background1));
	else if (m_toolbar.getLevelNum() % 3 == 2)
		return sf::Sprite(Resources::instance().get(ObjectType::Background2));
	else
		return sf::Sprite(Resources::instance().get(ObjectType::Background3));
}
//=========================================================
void Controller::printWinGame() {

	m_window.clear();
	sf::Sprite winSprite(Resources::instance().get(ObjectType::WinBackground));
	m_window.draw(winSprite);
	m_window.display();
	Resources::instance().playSound(SoundType::WinGameSound);
	while (true) //wating for user press enter to continue
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			break;
}
//=========================================================
void Controller::resetTimeLevel() {

	m_timeOfCurrLevel.restart();
	m_gameTime = sf::seconds(float(m_board.getTime()));
	m_endOfTime = false;
}
//=========================================================