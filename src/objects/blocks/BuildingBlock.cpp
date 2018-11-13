#include "BuildingBlock.h"
#include "../GameItem.h"

#include <iostream>
#include <string>

BuildingBlock::BuildingBlock (std::string texturePath, int x, int y, bool isDestructible)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	if (!texture->loadFromFile (texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
	this->isDestructible = isDestructible;
}

BuildingBlock::BuildingBlock (sf::Texture *texure, int x, int y, bool isDestructible)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
	this->isDestructible = isDestructible;
}

BuildingBlock::~BuildingBlock ()
{
}

