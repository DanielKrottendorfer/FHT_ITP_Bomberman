#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bomberman.h"

#include "objects/GameItem.h"
#include "objects/battlefield/BattleField.h"
#include "objects/blocks/BuildingBlock.h"

Bomberman::Bomberman ()
{
}

void Bomberman::init ()
{
	battlefield = new BattleField ();
	player = battlefield->battlefieldPlayers.at (0); // 0 only for movement prototype
}

void Bomberman::input ()
{
	// TODO Also needs to be updated for joystick
	battlefield->procedeMove (&player);
}

void Bomberman::update ()
{
	battlefield->checkForExplosion();
}

void Bomberman::render (sf::RenderWindow *window)
{
	window->clear (sf::Color::Black);
	battlefield->draw (window);
}
