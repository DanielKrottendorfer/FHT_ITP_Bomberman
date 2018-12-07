#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>
#include <cmath>
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

	player1TextureBehind.loadFromFile ("res/Character/Char1_behind_walk_right.png");
	player1TextureBehindWalk.loadFromFile ("res/Character/Char1_behind_walk_left.png");
	player1TextureLeft.loadFromFile ("res/Character/Char1_left_walk.png");
	player1TextureLeftWalk.loadFromFile ("res/Character/Char1_left.png");
	player1TextureFront.loadFromFile ("res/Character/Char1_front_walk-right.png");
	player1TextureFrontWalk.loadFromFile ("res/Character/Char1_front_walk-left.png");
	player1TextureRight.loadFromFile ("res/Character/Char1_right_walk.png");
	player1TextureRightWalk.loadFromFile ("res/Character/Char1_right.png");
}

sf::Sprite Player::getSprite ()
{
	return sprite;
}

void Player::movePlayer (std::string direction, float playerPositionX, float playerPositionY)
{
	if (direction.compare ("up") == 0)
	{
		sprite.setPosition (round (playerPositionX / 64) * 64, playerPositionY - 4);
		if (isKeyPressed)
		{
			sprite.setTexture (player1TextureBehind);
			isKeyPressed = false;
		}
		else
		{
			sprite.setTexture (player1TextureBehindWalk);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("left") == 0)
	{
		sprite.setPosition (playerPositionX - 4, round (playerPositionY / 64) * 64);
		if (isKeyPressed)
		{
			sprite.setTexture (player1TextureLeft);
			isKeyPressed = false;
		}
		else
		{
			sprite.setTexture (player1TextureLeftWalk);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("down") == 0)
	{
		sprite.setPosition (round (playerPositionX / 64) * 64, playerPositionY + 4);
		if (isKeyPressed)
		{
			sprite.setTexture (player1TextureFront);
			isKeyPressed = false;
		}
		else
		{
			sprite.setTexture (player1TextureFrontWalk);
			isKeyPressed = true;
		}
	}
	else if (direction.compare ("right") == 0)
	{
		sprite.setPosition (playerPositionX + 4, round (playerPositionY / 64) * 64);
		if (isKeyPressed)
		{
			sprite.setTexture (player1TextureRight);
			isKeyPressed = false;
		}
		else
		{
			sprite.setTexture (player1TextureRightWalk);
			isKeyPressed = true;
		}
	}
}

Player::~Player ()
{
}

