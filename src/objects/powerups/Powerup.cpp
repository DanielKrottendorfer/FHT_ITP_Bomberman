#include "Powerup.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>


Powerup::Powerup(sf::Texture& TEMP_Texture,float x,float y, std::string t)
{
    sprite.setTexture(TEMP_Texture);
    sprite.setPosition(x,y);

    type = t;
}

Powerup::Powerup()
{
}

sf::Sprite Powerup::getSprite() const 
{
    return sprite;
}

std::string Powerup::getType()
{
    return type;
}

Powerup::~Powerup ()
{
}

