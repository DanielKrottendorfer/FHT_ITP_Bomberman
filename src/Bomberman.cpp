#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bomberman.h"

#include "objects/GameItem.h"
#include "objects/battlefield/BattleField.h"
#include "objects/blocks/BuildingBlock.h"
#include "objects/info/Info.h"

Info gameInfos;

Bomberman::Bomberman(int numberOfPlayers)
{
	this->numberOfPlayers = numberOfPlayers;
}

void Bomberman::init()
{
	battlefield = new BattleField(numberOfPlayers);
	//player = battlefield->battlefieldPlayers.at(0); // 0 only for movement prototype
	gameInfos.setNumberOfPlayers(&battlefield->numberOfPlayers);
	gameInfos.reset();
}

void Bomberman::input()
{
	// TODO Also needs to be updated for joystick
	battlefield->procedeMove();
}

void Bomberman::update()
{
	battlefield->checkForExplosion();
	battlefield->checkForExplosionSpread();
	battlefield->checkForExplosionExtinguish();
	battlefield->checkForPlayerDeath();

	battlefield->collectPowerups();

	if(battlefield->numberOfPlayers==1)		
		running=false;

}

void Bomberman::render(sf::RenderWindow *window)
{
	window->clear(sf::Color::Black);
	battlefield->draw(window);
	gameInfos.draw(window);
}
