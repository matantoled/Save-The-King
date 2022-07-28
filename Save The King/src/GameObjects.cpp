#pragma once
#include "GameObjects.h"

//=========================================================
void GameObjects::setCurrPos(sf::Vector2f loc) {

	m_sprite.setPosition(loc);
}
//=========================================================
void GameObjects::setTexture(sf::Texture& texture) {

	m_sprite.setTexture(texture);
}
//=========================================================
GameObjects::GameObjects(sf::Texture& texture, sf::Vector2f location) {

	m_sprite.setTexture(texture);
	m_sprite.setPosition(location);
}
//=========================================================
bool GameObjects::checkCollision(const GameObjects& other) const {

	if (&other == this) 
		return false;
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}
//=========================================================
sf::Sprite GameObjects::getSprite() const {

	return m_sprite; 
}
//=========================================================