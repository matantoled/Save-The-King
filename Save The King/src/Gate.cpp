#pragma once
#include "Gate.h"

void Gate::handleCollision(Thief& gameObject) {

	if (gameObject.checkKey()) {
		setIsDead(true);
		gameObject.setKey(false);
		gameObject.setTexture(Resources::instance().get(ObjectType::ThiefChar));
		Resources::instance().playSound(SoundType::GateSound);
	}
	else
		gameObject.setCurrPos(gameObject.getPrevLoc());
}