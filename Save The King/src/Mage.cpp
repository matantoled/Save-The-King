#pragma once
#include "Mage.h"

void Mage::handleCollision(GameObjects& gameObject)  {

	// double dispatch
	gameObject.handleCollision(*this);
}