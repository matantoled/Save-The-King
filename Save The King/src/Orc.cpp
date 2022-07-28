#pragma once
#include "Orc.h"

void Orc::handleCollision(Warrior& gameObject) {

	m_isDead = true;
	Resources::instance().playSound(SoundType::OrcSound);
}