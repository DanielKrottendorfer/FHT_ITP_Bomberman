#include "Explosion.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

Explosion::Explosion(sf::Texture &TEMP_Texture, float x, float y, char dir, int p)
{
    sprite.setTexture(TEMP_Texture);
    sprite.setPosition(x, y);

    timer = new sf::Clock();
    direction = dir;
    power = p;
}

bool Explosion::doesExtinguish()
{

    int elapsedTime = timer->getElapsedTime().asMilliseconds();

    if (elapsedTime >= timeToExtinguish)
        return true;

    return false;
}

bool Explosion::doesSpread()
{

    int elapsedTime = timer->getElapsedTime().asMilliseconds();

    if (elapsedTime >= timeToSpread && !didSpread)
    {
        didSpread = true;
        return true;
    }

    return false;
}

sf::Sprite Explosion::getSprite() const
{
    return sprite;
}

char Explosion::getDirection()
{
    return direction;
}

int Explosion::getPower()
{
    return power;
}

Explosion::~Explosion()
{
}
