#pragma once
#include "Menu.h"

Menu::Menu() {

	// init menu bottuns
	m_buttons.resize(NUM_OF_MENU_BUTTONS);

	for (int i = 0, y = 555; i < NUM_OF_MENU_BUTTONS; i++, y += 100) {		
		m_buttons[i].setTexture(&Resources::instance().get(ObjectType(i)));
		m_buttons[i].setSize({ BUTTON_MENU_SIZE });
		m_buttons[i].setPosition(65.f, float(y + 40 * i));
		m_buttons[i].setOutlineColor(sf::Color::White);
		m_buttons[i].setOutlineThickness(THICKNESS_FRAME);
	}
};
//=========================================================
void Menu::drawMenu(sf::RenderWindow& window) {

	window.clear();
	auto sprite = sf::Sprite(Resources::instance().get(ObjectType::MenuBackground));
	window.draw(sprite);

	for (int i = 0; i < NUM_OF_MENU_BUTTONS - 1; i++)
		window.draw(m_buttons[i]);

	window.display();
}
//=========================================================
void Menu::drawHelp(sf::RenderWindow& window) {

	window.clear();
	auto sprite = sf::Sprite(Resources::instance().get(ObjectType::HelpBackground));
	window.draw(sprite);
	window.draw(m_buttons[BACK_BUTTON]);
	window.display();
}
//=========================================================
void Menu::runMenu(sf::RenderWindow& window) {

	bool inMenu = true;
	Resources::instance().playMusic(MusicType::MenuMusic);

	//menu loop
	while (window.isOpen() && inMenu) {
		drawMenu(window);

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				handleMouseMove(window);
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Button::Left)
					handleMenuClick(inMenu, window);
				break;
			}
		}
	}
}
//=========================================================
void Menu::helpButton(sf::RenderWindow& window)  {

	Resources::instance().playSound(HelpSound);

	//help loop
	while (window.isOpen())
	{
		drawHelp(window);

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:

				if (m_buttons[BACK_BUTTON].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					m_buttons[BACK_BUTTON].setOutlineColor(sf::Color::Magenta);
				else
					m_buttons[BACK_BUTTON].setOutlineColor(sf::Color::White);
				break;

			case sf::Event::MouseButtonReleased:

				if (event.mouseButton.button == sf::Mouse::Button::Left &&
					m_buttons[BACK_BUTTON].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					Resources::instance().playSound(SoundType::ClickSound);
					return;
				}
				break;
			}
		}
	}
}
//=========================================================
void Menu::handleMouseMove(const sf::RenderWindow& window)  {

	for (int i = 0; i < NUM_OF_MENU_BUTTONS - 1; i++) {
		if (m_buttons[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
			m_buttons[i].setOutlineColor(sf::Color::Magenta);
		}
		else
			m_buttons[i].setOutlineColor(sf::Color::White);
	}
}
//=========================================================
void Menu::handleMenuClick(bool& inMenu, sf::RenderWindow& window) {

	// start game -> user pressed start button
	if (m_buttons[START_BUTTON].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
		inMenu = false;
		Resources::instance().playSound(SoundType::ClickSound);
	}
	// help -> user pressed help button
	else if (m_buttons[HELP_BUTTON].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
		Resources::instance().playSound(SoundType::ClickSound);
		helpButton(window);
	}
	// quit -> user pressed quit button
	else if (m_buttons[QUIT_BUTTON].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		exit(EXIT_SUCCESS);
}
//=========================================================