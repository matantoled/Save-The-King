#pragma once
#include "Player.h"

class King : public Player {

public:
	using Player::Player;
	
	void handleCollision(GameObjects& gameObject) override;

private:

};
