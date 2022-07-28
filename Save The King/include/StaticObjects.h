#pragma once
#pragma warning(disable: 4100)
#include "King.h"
#include "Warrior.h"
#include "Mage.h"
#include "Thief.h"

class StaticObjects : public GameObjects {

public:
	using GameObjects::GameObjects;

	// moving objects
	virtual void handleCollision(King& gameObject);
	virtual void handleCollision(Warrior& gameObject);
	virtual void handleCollision(Mage& gameObject);
	virtual void handleCollision(Thief& gameObject);
	virtual void handleCollision(Dwarf& gameObject) {}

	virtual ~StaticObjects() = default;
	bool isDead() const;
	void setIsDead(const bool isDead);

protected:
	bool m_isDead = false;		//to store if obgect is dead (if need to delete him)

};
