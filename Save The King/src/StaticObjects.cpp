#pragma once
#include "StaticObjects.h"

void StaticObjects::handleCollision(King& gameObject) {

	gameObject.setCurrPos(gameObject.getPrevLoc());
}
//=========================================================
void StaticObjects::handleCollision(Warrior& gameObject) {

	gameObject.setCurrPos(gameObject.getPrevLoc());
}
//=========================================================
void StaticObjects::handleCollision(Mage& gameObject) {

	gameObject.setCurrPos(gameObject.getPrevLoc());
}
//=========================================================
void StaticObjects::handleCollision(Thief& gameObject) { 

	gameObject.setCurrPos(gameObject.getPrevLoc()); 
}
//=========================================================
bool StaticObjects::isDead() const { 

	return m_isDead;
}
//=========================================================
void StaticObjects::setIsDead(const bool isDead) { 

	m_isDead = isDead;
}
//=========================================================