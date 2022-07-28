#pragma once
#include "StaticObjects.h"

class Gate : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(Thief& gameObject) override;

private:

};