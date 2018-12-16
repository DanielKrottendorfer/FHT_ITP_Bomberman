#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"

Player::Player()
{
}

Player::Player(std::string texturePath, int x, int y)
{
	sf::Texture texture;
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}
	sprite.setTexture(texture);
}

Player::Player(sf::Texture &texture, int x, int y)
{
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	player1TextureBehind.loadFromFile("res/Character/Char1_behind_walk_right.png");
	player1TextureBehindWalk.loadFromFile("res/Character/Char1_behind_walk_left.png");
	player1TextureLeft.loadFromFile("res/Character/Char1_left_walk.png");
	player1TextureLeftWalk.loadFromFile("res/Character/Char1_left.png");
	player1TextureFront.loadFromFile("res/Character/Char1_front_walk-right.png");
	player1TextureFrontWalk.loadFromFile("res/Character/Char1_front_walk-left.png");
	player1TextureRight.loadFromFile("res/Character/Char1_right_walk.png");
	player1TextureRightWalk.loadFromFile("res/Character/Char1_right.png");
}

sf::Sprite Player::getSprite()
{
	return sprite;
}

void Player::movePlayer(std::string direction, float playerPositionX, float playerPositionY)
{
	if (direction.compare("up") == 0)
	{
		goUp(playerPositionX, playerPositionY);
	}
	else if (direction.compare("left") == 0)
	{
		goLeft(playerPositionX, playerPositionY);
	}
	else if (direction.compare("down") == 0)
	{
		goDown(playerPositionX, playerPositionY);
	}
	else if (direction.compare("right") == 0)
	{
		goRight(playerPositionX, playerPositionY);
	}
}

sf::Vector2f Player::getHitbox()
{
	return hitbox;
}

sf::Vector2f Player::getHitboxOffset()
{
	return hitboxOffset;
}

void Player::goUp(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(round(playerPositionX / 64) * 64, playerPositionY - 4);
	if (upwalk < 9)
	{
		sprite.setTexture(player1TextureBehind);
		upwalk++;
	}
	else if (upwalk > 8)
	{
		sprite.setTexture(player1TextureBehindWalk);
		upwalk++;
		if (upwalk > 16)
		{
			upwalk = 0;
		}
	}
	else
	{
		upwalk++;
	}
}

void Player::goLeft(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(playerPositionX - 4, round(playerPositionY / 64) * 64);
	if (leftwalk < 9)
	{
		sprite.setTexture(player1TextureLeft);
		leftwalk++;
	}
	else if (leftwalk > 8)
	{
		sprite.setTexture(player1TextureLeftWalk);
		leftwalk++;
		if (leftwalk > 16)
		{
			leftwalk = 0;
		}
	}
	else
	{
		leftwalk++;
	}
}

void Player::goDown(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(round(playerPositionX / 64) * 64, playerPositionY + 4);
	if (downwalk < 9)
	{
		sprite.setTexture(player1TextureFront);
		downwalk++;
	}
	else if (downwalk > 8)
	{
		sprite.setTexture(player1TextureFrontWalk);
		downwalk++;
		if (downwalk > 16)
		{
			downwalk = 0;
		}
	}
	else
	{
		downwalk++;
	}
}

void Player::goRight(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(playerPositionX + 4, round(playerPositionY / 64) * 64);
	if (rightwalk < 9)
	{
		sprite.setTexture(player1TextureRight);
		rightwalk++;
	}
	else if (rightwalk > 8)
	{
		sprite.setTexture(player1TextureRightWalk);
		rightwalk++;
		if (rightwalk > 16)
		{
			rightwalk = 0;
		}
	}
	else
	{
		rightwalk++;
	}
}

Player::~Player()
{
}
