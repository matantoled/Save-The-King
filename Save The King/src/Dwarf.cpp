#pragma once
#include "Dwarf.h"

void Dwarf::handleCollision(GameObjects& gameObject)  {

	gameObject.handleCollision(*this);
}
//=========================================================
void Dwarf::handleCollision(King& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Dwarf::handleCollision(Mage& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Dwarf::handleCollision(Thief& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Dwarf::handleCollision(Warrior& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Dwarf::handleCollision(Dwarf& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
const sf::Vector2f Dwarf::getDirection() const {

	return m_direction;
}
//=========================================================
void Dwarf::setDirection(const sf::Vector2f newDirection) {

	m_direction = newDirection;
}
//=========================================================