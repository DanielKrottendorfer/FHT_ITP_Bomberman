#include "../objects/GameItem.h"

#include <string>
#include <iostream>

GameItem::GameItem (std::string texturePath, int x, int y)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	if (!texture->loadFromFile (texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
}

GameItem::GameItem (sf::Texture *texture, int x, int y)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
}