#pragma once
#include "Resources.h"

class Menu {

public:
	Menu();

	void drawHelp(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void runMenu(sf::RenderWindow& window);
	void handleMenuClick(bool& inMenu, sf::RenderWindow& window);
	void handleMouseMove(const sf::RenderWindow& window);
	void helpButton(sf::RenderWindow& window);

private:
	std::vector<sf::RectangleShape> m_buttons;		//for menu buttons

};