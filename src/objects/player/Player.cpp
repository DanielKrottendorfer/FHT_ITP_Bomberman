#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>

Player::Player ()
{
}

Player::Player (std::string texturePath, int x, int y)
{
	
	sf::Texture texture;

	if (!texture.loadFromFile (texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}
	sprite.setTexture (texture);

}

Player::Player (sf::Texture& texture, int x, int y)
{

	sprite.setTexture (texture);
	sprite.setPosition (x, y);
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

void Player::movePlayer (std::string direction)
{
	if (direction.compare ("up") == 0)
	{
		sprite.move (0.f, -4.f);
	}
	else if (direction.compare ("left") == 0)
	{
		sprite.move (-4.f, 0.f);
	}
	else if (direction.compare ("down") == 0)
	{
		sprite.move (0.f, 4.f);
	}
	else if (direction.compare ("right") == 0)
	{
		sprite.move (4.f, 0.f);
	}
}

Player::~Player ()
{
}

