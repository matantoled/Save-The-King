#pragma once
#include "Player.h"

class Warrior : public Player {

public:
	using Player::Player;

	void handleCollision(GameObjects& gameObject) override;

private:

};