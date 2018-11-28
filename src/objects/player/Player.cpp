#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>

Player::Player ()
{
}

Player::Player (std::string texturePath, int x, int y)
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

Player::Player (sf::Texture *texure, int x, int y)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
}

void Player::movePlayer (std::string direction)
{
	if (direction.compare ("up") == 0)
	{
		this->sprite->move (0.f, -4.f);
	}
	else if (direction.compare ("left") == 0)
	{
		this->sprite->move (-4.f, 0.f);
	}
	else if (direction.compare ("down") == 0)
	{
		this->sprite->move (0.f, 4.f);
	}
	else if (direction.compare ("right") == 0)
	{
		this->sprite->move (4.f, 0.f);
	}
}

Player::~Player ()
{
}

