#pragma once
#pragma warning(disable: 4100)
#include "GameObjects.h"

class MovingObjects : public GameObjects {

public:
	MovingObjects(sf::Texture& texture, const sf::Vector2f location);

	// moving objects
	virtual void handleCollision(GameObjects& gameObject) = 0;
	virtual void handleCollision(King& gameObject) {}
	virtual void handleCollision(Warrior& gameObject) {}	
	virtual void handleCollision(Mage& gameObject) {}	
	virtual void handleCollision(Thief& gameObject) {}	
	virtual void handleCollision(Dwarf& gameObject) {}	

	// static objects
	virtual void handleCollision(Wall& gameObject) {}	
	virtual void handleCollision(Gate& gameObject) {}	
	virtual void handleCollision(Key& gameObject) {}
	virtual void handleCollision(Fire& gameObject) {}	
	virtual void handleCollision(Orc& gameObject) {}	
	virtual void handleCollision(Throne& gameObject) {}		
	virtual void handleCollision(Teleport& gameObject);
	virtual void handleCollision(Gift& gameObject) {}
	virtual void handleCollision(TimeGift& gameObject) {}
	virtual void handleCollision(DwarfesEliminateGift& gameObject) {}

	void move(const sf::Vector2f& loc) ;
	void setPrevLoc(const sf::Vector2f prevLoc);
	sf::Vector2f getPrevLoc() const;
	virtual ~MovingObjects() = default;

private:
	sf::Vector2f m_prevLocation;	//to store previos location
};