#pragma once
#include "Key.h"

void Key::handleCollision(Thief& gameObject) {

	if (!gameObject.checkKey()) {
		m_isDead = true;
		gameObject.setKey(true);
		gameObject.setTexture(Resources::instance().get(ObjectType::ThiefWithKey));
		Resources::instance().playSound(SoundType::KeySound);
	}
}