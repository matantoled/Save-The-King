#pragma once
#include "Toolbar.h"

Toolbar::Toolbar() {
	
	//set font
	m_levelText.setFont(Resources::instance().get());
	m_timeText.setFont(Resources::instance().get());

	//set text size
	m_levelText.setCharacterSize(SIZE_OF_TEXT);
	m_timeText.setCharacterSize(SIZE_OF_TEXT);

	//set text color
	m_levelText.setFillColor(sf::Color::Blue);
	m_timeText.setFillColor(sf::Color::Blue);

	//set text position
	m_levelText.setPosition(LEVEL_TEXT_POS);
	m_timeText.setPosition(TIME_TEXT_POS);

}
//=========================================================
void Toolbar::drawToolbarText (sf::RenderWindow& window, const int time) {

	//draw level number
	m_levelText.setString(std::to_string(m_levelNum));
	window.draw(m_levelText);
	
	//draw level time
	m_timeText.setString(std::to_string(time));
	window.draw(m_timeText);
}
//=========================================================
const int Toolbar::getLevelNum() const {

	return m_levelNum;
}
//=========================================================
void Toolbar::setLevelNum(const int num) {

	m_levelNum = num;
}
//=========================================================