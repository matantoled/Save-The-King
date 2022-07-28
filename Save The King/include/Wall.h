#pragma once
#include "StaticObjects.h"

class Wall : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(Player& gameObject);

private:

};