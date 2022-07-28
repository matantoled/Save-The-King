#pragma once

#include "Board.h"

//=========================================================
Board::Board() {

	// init frame (markCurrChar) of selected character 
	m_markCurrChar.setSize(CHAR_SIZE);
	m_markCurrChar.setFillColor(sf::Color::Transparent);
	m_markCurrChar.setOutlineColor(sf::Color::Red);
	m_markCurrChar.setOutlineThickness(THICKNESS_FRAME);
}
//=========================================================
void Board::initObjects() {

	m_staticObjects.clear();
	m_players.clear();
	m_dwarfs.clear();
	m_teleports.clear();
}
//=========================================================
void Board::setBoard(const int levelNum) {

	initObjects();	//reset all objects

	// set level name
	std::string levelName = LEVEL_NAME;
	levelName += std::to_string(levelNum);
	levelName += FILE_EXTENSION;

	std::ifstream file = std::ifstream(levelName);	//open level file
	if (file)
		readLevelFile(file);
	else
		m_winGame = true;		// no more levels to read

	m_winLevel = false;		//for next level/game
}
//=========================================================
void Board::readLevelFile(std::ifstream& file) {

	auto line = std::string();			// to reads lines from the file

	if (!std::getline(file, line)) {
		std::cerr << "Can't read from file\n";
		exit(EXIT_FAILURE);
	}

	auto readSize = std::istringstream(line);
	readSize >> m_rows >> m_cols >> m_timeLevel;

	// read the level from the file and create the objects
	for (int i = 0; i < m_rows; i++) {
		if (!std::getline(file, line)) {
			std::cerr << "Can't read from file\n";
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < line.size(); j++)
			createObject(ObjectType(line[j]), findLocation(i, j));
	}
}
//=========================================================
void Board::createObject(const ObjectType type, const sf::Vector2f location) {

	switch (type)
	{
		// characters
	case ObjectType::KingChar:
		m_players.push_back(std::make_unique<King>(Resources::instance().get(ObjectType::KingChar), location));
		break;
	case ObjectType::MageChar:
		m_players.push_back(std::make_unique<Mage>(Resources::instance().get(ObjectType::MageChar), location));
		break;
	case ObjectType::WarriorChar:
		m_players.push_back(std::make_unique<Warrior>(Resources::instance().get(ObjectType::WarriorChar), location));
		break;
	case ObjectType::ThiefChar:
		m_players.push_back(std::make_unique<Thief>(Resources::instance().get(ObjectType::ThiefChar), location));
		break;

		// static objects
	case ObjectType::WallChar:
		m_staticObjects.push_back(std::make_unique<Wall>(Resources::instance().get(ObjectType::WallChar), location));
		break;
	case ObjectType::FireChar:
		m_staticObjects.push_back(std::make_unique<Fire>(Resources::instance().get(ObjectType::FireChar), location));
		break;
	case ObjectType::GateChar:
		m_staticObjects.push_back(std::make_unique<Gate>(Resources::instance().get(ObjectType::GateChar), location));
		break;
	case ObjectType::OrcChar:
		m_staticObjects.push_back(std::make_unique<Orc>(Resources::instance().get(ObjectType::OrcChar), location));
		break;
	case ObjectType::KeyChar:
		m_staticObjects.push_back(std::make_unique<Key>(Resources::instance().get(ObjectType::KeyChar), location));
		break;
	case ObjectType::TeleportChar:
		m_teleports.push_back(std::make_unique<Teleport>(Resources::instance().get(ObjectType::TeleportChar), location));
		if (m_teleports.size() % 2 == 0)
			m_teleports[m_teleports.size() - 1]->setTeleportEvenMatch(*m_teleports[m_teleports.size() - 2]);
		break;
	case ObjectType::ThroneChar:
		m_staticObjects.push_back(std::make_unique<Throne>(Resources::instance().get(ObjectType::ThroneChar), location));
		break;
	case ObjectType::TimeGiftChar:
		m_staticObjects.push_back(std::make_unique<TimeGift>(Resources::instance().get(ObjectType::TimeGiftChar), location));
		break;
	case ObjectType::DwarfesEliminateGiftChar:
		m_staticObjects.push_back(std::make_unique<DwarfesEliminateGift>(Resources::instance().get(ObjectType::DwarfesEliminateGiftChar), location));
		break;

		// dwarfs
	case ObjectType::DwarfChar:
		m_dwarfs.push_back(std::make_unique<Dwarf>(Resources::instance().get(ObjectType::DwarfChar), location));
		m_dwarfs[m_dwarfs.size() - 1]->setDirection(getRandomDirection());
		break;
	}
}
//=========================================================
void Board::moveObjects(const float dt, const int charNum) {

	//set current character previos position
	m_players[charNum]->setPrevLoc(m_players[charNum]->getSprite().getPosition());

	movePlayers(dt, charNum);
	moveDwarfs(dt);
	handleStaticObjects();
	eraseStaticObjects();
}
//=========================================================
void Board::movePlayers(const float dt, const int charNum) {

	sf::Vector2f newLoc;	//new location after movment

	//get new location and move current character 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		inBounds(newLoc = findNewLoc(sf::Keyboard::Up, dt, charNum)))
		m_players[charNum]->move(newLoc);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		inBounds(newLoc = findNewLoc(sf::Keyboard::Down, dt, charNum)))
		m_players[charNum]->move(newLoc);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		inBounds(newLoc = findNewLoc(sf::Keyboard::Left, dt, charNum)))
		m_players[charNum]->move(newLoc);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
		inBounds(newLoc = findNewLoc(sf::Keyboard::Right, dt, charNum)))
		m_players[charNum]->move(newLoc);

	handleCollisions(*m_players[charNum]);
}
//=========================================================
void Board::moveDwarfs(const float dt) {

	for (auto& dwarf : m_dwarfs) {
		dwarf->setPrevLoc(dwarf->getSprite().getPosition());		//set previos location
		sf::Vector2f newLoc = dwarf->getPrevLoc() + getRandomDirection() * (MOVMENT_SPEED * dt);	//get new location
		if (inBounds(newLoc))	//if in board bounds
			dwarf->move(newLoc);
		handleCollisions(*dwarf);
	}
}
//=========================================================
bool Board::inBounds(const sf::Vector2f direction) {

	//if in game borad bounds 
	if (direction.y < 0 ||
		direction.x < 0 ||
		direction.y > HEIGHT_LIMIT ||
		direction.x > WIDTH_LIMIT)
		return false;

	return true;
}
//=========================================================
void Board::handleCollisions(MovingObjects& movingObject) {

	//check & handel collision of movingObject with static objects
	for (auto& unmovable : m_staticObjects)
		if (movingObject.checkCollision(*unmovable))
			movingObject.handleCollision(*unmovable);

	//check & handel collision of movingObject with teleports
	for (auto& teleport : m_teleports) {
		if (movingObject.checkCollision(*teleport) && teleport->getIsFree() &&
			teleport->getTeleportExit()->getIsFree())
			movingObject.handleCollision(*teleport);
		else {		// set current teleport status
			teleport->setTeleportFree(true);
			for (auto& player : m_players)
				if (teleport->checkCollision(*player))
					teleport->setTeleportFree(false);
		}
	}

	//check & handel collision of movingObject with players
	for (auto& player : m_players)
		if (movingObject.checkCollision(*player))
			player->handleCollision(movingObject);

	//check & handel collision of movingObject with dwarfs
	for (auto& dwarf : m_dwarfs)
		if (movingObject.checkCollision(*dwarf))
			dwarf->handleCollision(movingObject);
}
//=========================================================
void Board::handleStaticObjects() {

	//going over all static object and update status
	for (auto& staticObject : m_staticObjects)
		if (staticObject->isDead() && typeid(*staticObject) == typeid(Orc))
			m_staticObjects.push_back(std::make_unique<Key>(Resources::instance().get(ObjectType::KeyChar),
				staticObject->getSprite().getPosition()));
		else if (staticObject->isDead() && typeid(*staticObject) == typeid(TimeGift))
			setTimeGift(NEW_TIME_GIFT);
		else if (staticObject->isDead() && typeid(*staticObject) == typeid(DwarfesEliminateGift))
			m_dwarfs.clear();
		else if (staticObject->isDead() && typeid(*staticObject) == typeid(Throne))
			m_winLevel = true;
}
//=========================================================
void Board::eraseStaticObjects() {

	std::erase_if(m_staticObjects, [](auto& staticObject) {
		return staticObject->isDead();
		});
}
//=========================================================
const sf::Vector2f Board::findNewLoc(const sf::Keyboard::Key key, const float dt, const int charNum) const{

	//find player new location and return it
	switch (key) {
	case sf::Keyboard::Up:
		return { m_players[charNum]->getSprite().getPosition().x,
			m_players[charNum]->getSprite().getPosition().y + -MOVMENT_SPEED * dt };
	case sf::Keyboard::Down:
		return { m_players[charNum]->getSprite().getPosition().x,
		m_players[charNum]->getSprite().getPosition().y + MOVMENT_SPEED * dt };
	case sf::Keyboard::Left:
		return { m_players[charNum]->getSprite().getPosition().x - MOVMENT_SPEED * dt,
		m_players[charNum]->getSprite().getPosition().y };
	case sf::Keyboard::Right:
		return { m_players[charNum]->getSprite().getPosition().x + MOVMENT_SPEED * dt,
			m_players[charNum]->getSprite().getPosition().y };
	}
	throw std::runtime_error("Error");
}
//=========================================================
void Board::setTimeGift(const int num) {

	if (num == NEW_TIME_GIFT) {	//if new time gift set random time for time gift
		srand((unsigned int)time(NULL));
		m_timeGift = rand() % 10 + 10;
		if (m_timeGift % 2 == 0)
			m_timeGift *= (-1);
	}
	else
		m_timeGift = num;	//set gift used
}
//=========================================================
const sf::Vector2f Board::getRandomDirection() const {

	srand((unsigned int)time(NULL));
	int randNum = rand() % 4;

	switch (randNum)	
	{
	case 0:
		return(sf::Vector2f(LEFT));
	case 1:
		return(sf::Vector2f(RIGHT));
	case 2:
		return(sf::Vector2f(DOWN));
	case 3:
		return(sf::Vector2f(UP));
	}
	throw std::runtime_error("Error");
}
//=========================================================
void Board::drawObjects(sf::RenderWindow& window, const char charNum) {

	// marking the selected character
	m_markCurrChar.setPosition(m_players[charNum]->getSprite().getPosition());

	for (auto& staticObject : m_staticObjects)
		window.draw(staticObject->getSprite());

	for (auto& teleport : m_teleports)
		window.draw(teleport->getSprite());

	window.draw(m_markCurrChar);
	for (auto& player : m_players)
		window.draw(player->getSprite());
	
	for (auto& dwarf : m_dwarfs)
		window.draw(dwarf->getSprite());
}
//=========================================================
const sf::Vector2f Board::findLocation(const int row, const int col) const {

	sf::Vector2f location;
	location.x = OBJECTSIZE * col;
	location.y = OBJECTSIZE * row;
	return location;
}
//=========================================================
int Board::getTime() const {

	return m_timeLevel;
}
//=========================================================
void Board::setTime(const int time) {

	m_timeLevel = time;
}
//=========================================================
int Board::getTimeGift() const {

	return m_timeGift;
}
//=========================================================
bool Board::getWinGame() const {

	return m_winGame;
}
//=========================================================
void Board::setWinGame(const bool win) {

	m_winGame = win;
}
//=========================================================
bool Board::getWinLevel() const {

	return m_winLevel;
}
//=========================================================