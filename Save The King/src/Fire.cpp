#pragma once
#include "Fire.h"

void Fire::handleCollision(Mage& gameObject)  {

	m_isDead = true;
	Resources::instance().playSound(SoundType::FireSound);
}