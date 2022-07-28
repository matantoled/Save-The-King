#pragma once
#pragma warning(disable: 4100)
#include "Resources.h"

class MovingObjects;
class StaticObjects;

class Player;
class Warrior;
class King;
class Mage;
class Thief;
class Dwarf;

class Wall;
class Gate;
class Key;
class Fire;
class Orc;
class Throne;
class Teleport;

class Gift;
class TimeGift;
class DwarfesEliminateGift;

class GameObjects {

public:

	GameObjects(sf::Texture& texture, sf::Vector2f location);
	bool checkCollision(const GameObjects& other) const;

	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Dwarf& gameObject) = 0;

	void setCurrPos(sf::Vector2f loc);
	void setTexture(sf::Texture& texture);
	sf::Sprite getSprite() const;
	virtual ~GameObjects() = default;

private:
	sf::Sprite m_sprite;

};