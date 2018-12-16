#include "BuildingBlock.h"
#include "../GameItem.h"

#include <iostream>
#include <string>

BuildingBlock::BuildingBlock (std::string texturePath, int x, int y, bool isDestructible)
{

	sf::Texture texture;

	if (!texture.loadFromFile (texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}

	sprite.setTexture (texture);
	sprite.setPosition (x, y);
	isDestructible = isDestructible;
}

BuildingBlock::BuildingBlock (sf::Texture& texture, int x, int y, bool isDestr)
{

	sprite.setTexture (texture);
	sprite.setPosition (x, y);
	isDestructible = isDestr;
}

sf::Sprite BuildingBlock::getSprite() const 
{
    return sprite;
}

char BuildingBlock::getPowerupDrop()
{
	return powerupDrop;
}

void BuildingBlock::setPowerupDrop(char p)
{
	powerupDrop = p;
}


BuildingBlock::~BuildingBlock ()
{
}

