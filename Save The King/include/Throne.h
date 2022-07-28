#pragma once
#include "StaticObjects.h"

class Throne : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(King& gameObject)override;

private:

};