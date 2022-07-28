#pragma once
#include "StaticObjects.h"

class Gift : public StaticObjects {

public:
	using StaticObjects::StaticObjects;

	void handleCollision(King& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(Thief& gameObject) override;

	virtual ~Gift() = default;
private:

};