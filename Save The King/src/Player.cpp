#pragma once
#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

//=========================================================
void Player::handleCollision(Dwarf& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Player::handleCollision(King& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Player::handleCollision(Mage& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Player::handleCollision(Warrior& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================
void Player::handleCollision(Thief& gameObject) {

	setCurrPos(getPrevLoc());
}
//=========================================================