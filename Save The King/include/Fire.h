#pragma once
#include "StaticObjects.h"

class Fire : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(Mage& gameObject)override;

};