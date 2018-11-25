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

void Player::movePlayer (float x, float y)
{
	this->sprite->move (x, y);
}

void Player::setEventType ()
{
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::W))
	{
		movePlayer (0.f, -2.f);
	}
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))
	{
		movePlayer (-2.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::S))
	{
		movePlayer (0.f, 2.f);
	}
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::D))
	{
		movePlayer (2.f, 0.f);
	}
}

Player::~Player ()
{
}

