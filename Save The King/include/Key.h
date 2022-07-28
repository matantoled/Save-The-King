#pragma once
#include "StaticObjects.h"

class Key : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(Thief& gameObject) override;
	void handleCollision(King& gameObject)override {}
	void handleCollision(Warrior& gameObject)override {}
	void handleCollision(Mage& gameObject)override {}

private:

};