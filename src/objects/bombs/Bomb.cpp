#include "Bomb.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>


Bomb::Bomb(sf::Texture& TEMP_Texture,float x,float y, int power, Player &o)
{
    sprite.setTexture(TEMP_Texture);
    sprite.setPosition(x,y);
    this->power = power;
    owner = &o;
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

sf::Sprite Bomb::getSprite() const 
{
    return sprite;
}

Player* Bomb::getOwner()
{
    return owner;
}

Bomb::~Bomb ()
{
}

