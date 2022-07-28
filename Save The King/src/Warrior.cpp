#pragma once
#include "Warrior.h"

void Warrior::handleCollision(GameObjects& gameObject)  {

	// double dispatch
	gameObject.handleCollision(*this);
}