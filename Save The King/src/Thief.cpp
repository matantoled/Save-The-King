#pragma once
#include "Thief.h"

void Thief::handleCollision(GameObjects& gameObject) {

	// double dispatch
	gameObject.handleCollision(*this);
}
//=========================================================
const bool Thief::checkKey() const {
    
    return m_hasKey; 
}
//=========================================================
void Thief::setKey(const bool key) {

    m_hasKey = key; 
}
//=========================================================