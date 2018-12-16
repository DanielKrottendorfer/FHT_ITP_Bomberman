#include "Powerup.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>


Powerup::Powerup(sf::Texture& TEMP_Texture,float x,float y, char t)
{
    sprite.setTexture(TEMP_Texture);
    sprite.setPosition(x,y);

    type = t;
}

sf::Sprite Powerup::getSprite() const 
{
    return sprite;
}

Powerup::~Powerup ()
{
}

