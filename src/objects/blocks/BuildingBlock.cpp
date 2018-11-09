#include "BuildingBlock.h"

#include <iostream>

BuildingBlock::BuildingBlock (sf::Texture* buildingBlockTexture,
		bool isDestructible)
{
	this->buildingBlockTexture = buildingBlockTexture;
	this->isDestructible = isDestructible;
}

BuildingBlock::~BuildingBlock ()
{

}

