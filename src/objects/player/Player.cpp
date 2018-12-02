#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>
#include "windows.h"

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

sf::Sprite Player::getSprite ()
{
	return sprite;
}

void Player::movePlayer (std::string direction)
{
	if (direction.compare ("up") == 0)
	{
		sprite.move (0.f, -4.f);
		if (isKeyPressed)
		{
			player1TextureBehind.loadFromFile ("res/Character/Char1_behind_walk_right.png");
			sprite.setTexture (player1TextureBehind);
			isKeyPressed = false;
		}
		else
		{
			player1TextureBehind.loadFromFile ("res/Character/Char1_behind_walk_left.png");
			sprite.setTexture (player1TextureBehind);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("left") == 0)
	{
		sprite.move (-4.f, 0.f);
		if (isKeyPressed)
		{
			player1TextureLeft.loadFromFile ("res/Character/Char1_left_walk.png");
			sprite.setTexture (player1TextureLeft);
			isKeyPressed = false;
		}
		else
		{
			player1TextureLeft.loadFromFile ("res/Character/Char1_left.png");
			sprite.setTexture (player1TextureLeft);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("down") == 0)
	{
		sprite.move (0.f, 4.f);
		if (isKeyPressed)
		{
			player1TextureFront.loadFromFile ("res/Character/Char1_front_walk-right.png");
			sprite.setTexture (player1TextureFront);
			isKeyPressed = false;
		}
		else
		{
			player1TextureFront.loadFromFile ("res/Character/Char1_front_walk-left.png");
			sprite.setTexture (player1TextureFront);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("right") == 0)
	{
		sprite.move (4.f, 0.f);
		if (isKeyPressed)
		{
			player1TextureRight.loadFromFile ("res/Character/Char1_right_walk.png");
			sprite.setTexture (player1TextureRight);
			isKeyPressed = false;
		}
		else
		{
			player1TextureRight.loadFromFile ("res/Character/Char1_right.png");
			sprite.setTexture (player1TextureRight);
			isKeyPressed = true;
		}
	}
}

Player::~Player ()
{
}

