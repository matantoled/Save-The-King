#pragma once
#include "Player.h"

class Thief : public Player {

public:
	using Player::Player;

	void handleCollision(GameObjects& gameObject) override;
	const bool checkKey() const;
	void setKey(const bool key);

private:
	bool m_hasKey = false;		//if thief has a key

};