#pragma once
#include "Teleport.h"

void Teleport::setTeleportEvenMatch(Teleport& teleport) {

    m_teleportExit = &teleport;
    teleport.setTeleportOddMatch(*this);
}
//=========================================================
void Teleport::setTeleportOddMatch(Teleport& teleport) {

    m_teleportExit = &teleport;
}
//=========================================================
const Teleport* Teleport::getTeleportExit() {

    return m_teleportExit;
}
//=========================================================
const sf::Vector2f Teleport::getExitPos() const {

    return m_teleportExit->getSprite().getPosition();
}
//=========================================================
void Teleport::setTeleportExit(bool isFree) {

    m_teleportExit->m_teleportFree = isFree;
}
//=========================================================
bool Teleport::getIsFree() const {

    return m_teleportFree;
}
//=========================================================
void Teleport::setTeleportFree(const bool isFree) {

    m_teleportFree = isFree;
}
//=========================================================