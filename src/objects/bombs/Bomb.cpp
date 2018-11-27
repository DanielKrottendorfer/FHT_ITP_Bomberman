#include "Bomb.h"

#include <iostream>
#include <string>

Bomb::Bomb (std::string texturePath, int x, int y)
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

Bomb::Bomb (sf::Texture *texure, int x, int y)
{
	this->texture = new sf::Texture;
	this->sprite = new sf::Sprite;

	this->sprite->setTexture (*texture);
	this->sprite->setPosition (x, y);
}

void Bomb::ignite()
{
   timer = new sf::Clock;
}


bool Bomb::explodes()
{
    int elapsedTime = timer->getElapsedTime().asMilliseconds();

    if(elapsedTime>=fuse)
        return true;
    
    return false;
}

Bomb::~Bomb ()
{
    delete(texture);
    delete(sprite);
    delete(timer);
}

