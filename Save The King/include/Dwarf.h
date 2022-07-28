#pragma once
#include "MovingObjects.h"

class Dwarf : public MovingObjects {

public:
	using MovingObjects::MovingObjects;

	void handleCollision(GameObjects& gameObject) override;
	void handleCollision(King& gameObject) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Thief& gameObject) override;
	void handleCollision(Dwarf& gameObject) override;

	void setDirection(const sf::Vector2f newDirection);
	const sf::Vector2f getDirection() const;
	
private:
	sf::Vector2f m_direction;		//to set dwarf movment direction

};