#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <vector>

const float OBJECTSIZE = 80.f;
const float MENU_SONG_VOLUME = 35.f, GAME_SONG_VOLUME = 50.f;
const int DEFAULT_ROWS = 12;
const int DEFAULT_COLS = 24;
const int MOVMENT_SPEED = 150;
const int NUM_OF_TEXTURES = 24;
const int NUM_OF_SOUNDS = 11;
const int NUM_OF_MENU_BUTTONS = 4;
const int FPS = 60;
const int NUM_OF_CHARACTERS = 4, START_OVER = 0;
const int HEIGHT_LIMIT = 870, WIDTH_LIMIT = 1850;
const int START_BUTTON = 0, HELP_BUTTON = 1, QUIT_BUTTON = 2, BACK_BUTTON = 3;
const int SIZE_OF_TEXT = 40;
const int NEW_TIME_GIFT = 1;
const int THICKNESS_FRAME = 3;
const int FIRST_LEVEL = 1;
const sf::Vector2f LEVEL_TEXT_POS = { 312.f, 996.f }, TIME_TEXT_POS = { 698.f, 996.f };
const sf::Vector2f BUTTON_MENU_SIZE = { 315.f, 90.f };
const sf::Vector2f LEFT = { -1.f,0.f }, RIGHT = { 1.f,0.f }, DOWN = { 0.f,-1.f }, UP = { 0.f,1.f };
const std::string LEVEL_NAME = "Board", FILE_EXTENSION = ".txt";
const sf::Vector2f CHAR_SIZE = { 70.f, 70.f };

enum ObjectType
{
	Start,
	Help,
	Quit,
	Back,
	MenuBackground,
	HelpBackground,
	Background1,
	Background2,
	Background3,
	ThiefWithKey,
	WinBackground,

	KingChar = 'K',
	MageChar = 'M',
	WarriorChar = 'W',
	ThiefChar = 'T',
	DwarfChar = '^',

	DwarfesEliminateGiftChar = '&',
	TimeGiftChar = '$',
	WallChar = '=',
	GateChar = '#',
	FireChar = '*',
	OrcChar = '!',
	KeyChar = 'F',
	TeleportChar = 'X',
	ThroneChar = '@'

};

enum SoundType {

	GateSound,
	FireSound,
	KeySound,
	OrcSound,
	TeleportSound,
	LoseSound,
	WinSound,
	ClickSound,
	GiftSound,
	WinGameSound,
	HelpSound
};

enum MusicType {
	MenuMusic,
	GameMusic
};

class Resources {

public:
	static Resources & instance() {
		static auto resources = Resources(); // static in function!
		return resources;
	}
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;
	sf::Texture & get(const ObjectType type);
	sf::Font& get();
	void playSound(const SoundType type);
	void playMusic(const MusicType type);

private:
	Resources();
	std::vector<sf::Texture> m_textures;	//to store all game textures
	sf::Music m_menuMusic;					//to store menu music
	sf::Music m_gameMusic;					//to store game music
	sf::Font m_font;						//to store game font
	std::vector<sf::SoundBuffer> m_buffers;	//to store game sounds
	sf::Sound m_sound;						//to play current sound
};
