#pragma once
#include "MovingObjects.h"
#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Teleport.h"
#include "Dwarf.h"

MovingObjects::MovingObjects(sf::Texture& texture, const sf::Vector2f location):GameObjects( texture, location) {

	m_prevLocation = getSprite().getPosition();
}
//=========================================================
void MovingObjects::handleCollision(Teleport& gameObject) {

	//Dwarf and Mage cant enter teleport
	if (typeid(*this) == typeid(Dwarf) || typeid(*this) == typeid(Mage))
		return;

	//handle teleport collision
	if (gameObject.getTeleportExit()->getIsFree()) {
		setCurrPos(gameObject.getExitPos());
		gameObject.setTeleportExit(false);
		gameObject.setTeleportFree(true);
		Resources::instance().playSound(SoundType::TeleportSound);
	}

}
//=========================================================
void MovingObjects::move(const sf::Vector2f& loc)  {

	setCurrPos(loc);
}
//=========================================================
sf::Vector2f MovingObjects::getPrevLoc() const { 

	return m_prevLocation; 
}
//=========================================================
void MovingObjects::setPrevLoc(const sf::Vector2f prevLoc) { 

	m_prevLocation = prevLoc; 
}
//=========================================================