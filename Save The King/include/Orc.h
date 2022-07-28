#pragma once
#include "StaticObjects.h"

class Orc : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(Warrior& gameObject)override;

private:

};