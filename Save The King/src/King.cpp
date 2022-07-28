#pragma once
#include "King.h"

void King::handleCollision(GameObjects& gameObject)  {

	// double dispatch
	gameObject.handleCollision(*this);
}