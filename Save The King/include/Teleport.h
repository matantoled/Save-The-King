#pragma once
#include "StaticObjects.h"

class Teleport : public StaticObjects {

public:
	using StaticObjects::StaticObjects;
	//using StaticObjects::handleCollision;

	void handleCollision(Mage& gameObject) {}
	void setTeleportFree(const bool isFree);
	bool getIsFree() const;
	const Teleport* getTeleportExit();
	const sf::Vector2f getExitPos() const;
	void setTeleportExit(const bool isFree);
	void setTeleportOddMatch(Teleport& teleport);
	void setTeleportEvenMatch(Teleport& teleport);
	
private:
	Teleport* m_teleportExit;		//the exit teleport of this teleport (the friend teleport)
	bool m_teleportFree = true;		//if teleport is free

};