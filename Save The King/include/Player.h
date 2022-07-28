#pragma once
#include "MovingObjects.h"

class Player : public MovingObjects {

public:
	using MovingObjects::MovingObjects;
	using MovingObjects::handleCollision;

	void handleCollision(King& gameObject) override;
	void handleCollision(Dwarf& gameObject) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Thief& gameObject) override;

	virtual ~Player() = default;

private:

};
