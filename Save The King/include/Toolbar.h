#pragma once
#include "Resources.h"

class Toolbar
{
public:
	Toolbar();
	~Toolbar() = default;

	void drawToolbarText(sf::RenderWindow&, const int);
	const int getLevelNum() const;
	void setLevelNum(const int num);

private:
	sf::Text m_levelText;		//to print text of level number 
	sf::Text m_timeText;		//to print text of level current time
	int m_levelNum = 1;			//to store level number

};