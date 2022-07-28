#pragma once
#include "Gift.h"

void Gift::handleCollision(King& gameObject) {

	m_isDead = true;
	Resources::instance().playSound(SoundType::GiftSound);
}
//=========================================================
void Gift::handleCollision(Warrior& gameObject) {

	m_isDead = true;
	Resources::instance().playSound(SoundType::GiftSound);
}
//=========================================================
void Gift::handleCollision(Mage& gameObject) {

	m_isDead = true;
	Resources::instance().playSound(SoundType::GiftSound);
}
//=========================================================
void Gift::handleCollision(Thief& gameObject) {

	m_isDead = true;
	Resources::instance().playSound(SoundType::GiftSound);
}
//=========================================================