#pragma once
#include "Player.h"

class Mage : public Player {

public:
	using Player::Player;

	void handleCollision(GameObjects& gameObject) override;

private:

};