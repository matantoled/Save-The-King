#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <iostream>
#include <cstdlib>

Resources::Resources() {

	m_textures.resize(NUM_OF_TEXTURES);
	m_buffers.resize(NUM_OF_SOUNDS);
	// characters
	m_textures[0].loadFromFile("king.png");
	m_textures[1].loadFromFile("mage.png");
	m_textures[2].loadFromFile("warrior.png");
	m_textures[3].loadFromFile("thief.png");
	m_textures[4].loadFromFile("thief2.png");
	m_textures[5].loadFromFile("dwarf.png");

	// static
	m_textures[6].loadFromFile("gift.png");
	m_textures[7].loadFromFile("wall.png");
	m_textures[8].loadFromFile("gate.png");
	m_textures[9].loadFromFile("fire.png");
	m_textures[10].loadFromFile("orc.png");
	m_textures[11].loadFromFile("key.png");
	m_textures[12].loadFromFile("teleport.png");
	m_textures[13].loadFromFile("throne.png");

	// menu
	m_textures[14].loadFromFile("menu.png");	
	m_textures[15].loadFromFile("start.png");
	m_textures[16].loadFromFile("help.png");
	m_textures[17].loadFromFile("quit.png");
	m_textures[18].loadFromFile("back.png");
	m_textures[19].loadFromFile("helpBackground.png");
	
	// back
	m_textures[20].loadFromFile("background1.png");
	m_textures[21].loadFromFile("background2.png");
	m_textures[22].loadFromFile("background3.png");
	m_textures[23].loadFromFile("winBackground.png");

	// sounds
	m_buffers[0].loadFromFile("clickSound.wav");
	m_buffers[1].loadFromFile("gateSound.ogg");
	m_buffers[2].loadFromFile("fireSound.ogg");
	m_buffers[3].loadFromFile("keySound.ogg");
	m_buffers[4].loadFromFile("orcSound.ogg");
	m_buffers[5].loadFromFile("teleportSound.ogg");
	m_buffers[6].loadFromFile("loseSound.ogg");
	m_buffers[7].loadFromFile("winLevelSound.ogg");
	m_buffers[8].loadFromFile("giftSound.ogg");
	m_buffers[9].loadFromFile("win.ogg");
	m_buffers[10].loadFromFile("helpSound.wav");

	m_menuMusic.openFromFile("menuSong.ogg");
	m_gameMusic.openFromFile("gameSong.ogg");
	m_menuMusic.setVolume(MENU_SONG_VOLUME);
	m_gameMusic.setVolume(GAME_SONG_VOLUME);

	m_font.loadFromFile("arial.ttf");
}
//=========================================================
sf::Texture& Resources::get(const ObjectType type) {

	switch (type)
	{
		// characters
	case ObjectType::KingChar:
		return m_textures[0];
	case ObjectType::MageChar:
		return m_textures[1];
	case ObjectType::WarriorChar:
		return m_textures[2];
	case ObjectType::ThiefChar:
		return m_textures[3];
	case ObjectType::ThiefWithKey:
		return m_textures[4];
	case ObjectType::DwarfChar:
		return m_textures[5];

		// static
	case ObjectType::TimeGiftChar:
	case ObjectType::DwarfesEliminateGiftChar:
		return m_textures[6];
	case ObjectType::WallChar:
		return m_textures[7];
	case ObjectType::GateChar:
		return m_textures[8];
	case ObjectType::FireChar:
		return m_textures[9];
	case ObjectType::OrcChar:
		return m_textures[10];
	case ObjectType::KeyChar:
		return m_textures[11];
	case ObjectType::TeleportChar:
		return m_textures[12];
	case ObjectType::ThroneChar:
		return m_textures[13];

		// menu
	case ObjectType::MenuBackground:
		return m_textures[14];
	case ObjectType::Start:
		return m_textures[15];
	case ObjectType::Help:
		return m_textures[16];
	case ObjectType::Quit:
		return m_textures[17];
	case ObjectType::Back:
		return m_textures[18];
	case ObjectType::HelpBackground:
		return m_textures[19];

		// backgrounds
	case ObjectType::Background1:
		return m_textures[20];
	case ObjectType::Background2:
		return m_textures[21];
	case ObjectType::Background3:
		return m_textures[22];
	case ObjectType::WinBackground:
		return m_textures[23];
	}
	throw std::runtime_error("No Texture of that type");
}
//=========================================================
sf::Font& Resources::get() {

	return m_font;
}
//=========================================================
void Resources::playSound(const SoundType type){

	switch (type)
	{
		// sounds
	case SoundType::ClickSound:
		m_sound.setBuffer(m_buffers[0]);
		break;
	case SoundType::GateSound:
		m_sound.setBuffer(m_buffers[1]);
		break;
	case SoundType::FireSound:
		m_sound.setBuffer(m_buffers[2]);
		break;
	case SoundType::KeySound:
		m_sound.setBuffer(m_buffers[3]);
		break;
	case SoundType::OrcSound:
		m_sound.setBuffer(m_buffers[4]);
		break;
	case SoundType::TeleportSound:
		m_sound.setBuffer(m_buffers[5]);
		break;
	case SoundType::LoseSound:
		m_sound.setBuffer(m_buffers[6]);
		break;
	case SoundType::WinSound:
		m_sound.setBuffer(m_buffers[7]);
		break;
	case SoundType::GiftSound:
		m_sound.setBuffer(m_buffers[8]);
		break;
	case SoundType::WinGameSound:
		m_sound.setBuffer(m_buffers[9]);
		break;
	case SoundType::HelpSound:
		m_sound.setBuffer(m_buffers[10]);
		break;
	}

	m_sound.play();
}
//=========================================================
void Resources::playMusic(const MusicType type) {

	if (type == MenuMusic) {
		m_gameMusic.stop();
		m_menuMusic.play();
		m_menuMusic.setLoop(true);
	}
	else {
		m_menuMusic.stop();
		m_gameMusic.play();
		m_gameMusic.setLoop(true);
	}
}
//=========================================================