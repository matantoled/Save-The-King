#pragma once
#include "Wall.h"

void Wall::handleCollision(Player& gameObject) {

	gameObject.handleCollision(*this);
}