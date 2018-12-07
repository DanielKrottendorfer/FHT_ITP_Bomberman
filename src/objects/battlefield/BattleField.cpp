#include <iostream>
#include <string>
#include <random>
#include "BattleField.h"

BattleField::BattleField()
{
	createBattleField();
}

void BattleField::createBattleField()
{
	/*
	 *	ADDING INDESTRUCTIBLE BLOCKS
	 */

	/*
	 std::cout << "BattleField createBattleField Begin" << std::endl;

	 sf::Texture left;
	 sf::Texture right;
	 sf::Texture top;
	 sf::Texture bottom;

	 left.loadFromFile("res/BackgroundItems/leftEdge.png");
	 right.loadFromFile("res/BackgroundItems/rightEdge.png");
	 top.loadFromFile("res/BackgroundItems/topEdge.png");
	 bottom.loadFromFile("res/BackgroundItems/bottomEdge.png");

	 battleFieldTextures.push_back(&left);
	 battleFieldTextures.push_back(&right);
	 battleFieldTextures.push_back(&top);
	 battleFieldTextures.push_back(&bottom);
	 */

	tSideTexture.loadFromFile("res/BackgroundItems/topEdge.png");
	rSideTexture.loadFromFile("res/BackgroundItems/rightEdge.png");
	lSideTexture.loadFromFile("res/BackgroundItems/leftEdge.png");
	bSideTexture.loadFromFile("res/BackgroundItems/bottomEdge.png");

	tlCornerTexture.loadFromFile("res/BackgroundItems/LeftTopCorner.png");
	trCornerTexture.loadFromFile("res/BackgroundItems/RightTopCorner.png");
	blCornerTexture.loadFromFile("res/BackgroundItems/LeftBottomCorner.png");
	brCornerTexture.loadFromFile("res/BackgroundItems/RightBottomCorner.png");

	dBlockTexture.loadFromFile("res/BackgroundItems/destructibleBlocks.png");
	idBlockTexture.loadFromFile("res/BackgroundItems/indestructibleBlocks.png");

	player1Texture.loadFromFile("res/Character/Char1_front.png");

	bombTexture.loadFromFile("res/Bomb.png");
	explosionTexture.loadFromFile("res/Explosion.png");

	createFrameBlocks();
	createIndestructibleFieldBlocks();
	generateDestructibleFieldBlocks();

	generatePlayer(); // temp function initialisation

	for (BuildingBlock b : battlefieldBlocks)
	{
		sf::Vector2f v = b.getSprite().getPosition();
		std::cout << "x: " << v.x << "; y: " << v.y << "; textaddress:" << b.getSprite().getTexture() << std::endl;
	}
}

void BattleField::createFrameBlocks()
{
	int xStart = 0;
	int yStart = 0;

	for (int i = 1; i < NUMBER_OF_VERTICAL_BLOCKS - 1; i++)
	{
		//std::cout << "start" << std::endl;

		//std::cout << i << std::endl;
		BuildingBlock leftEdge(lSideTexture, xStart, yStart + i * BLOCK_SIZE,
							   false);
		//std::cout << i << std::endl;

		battlefieldBlocks.push_back(leftEdge);
		//std::cout << &battlefieldBlocks[battlefieldBlocks.size()-1] << std::endl;
		//std::cout << i << std::endl;
		//std::cout << "end" << std::endl;

		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	std::cout << "end" << std::endl;
	for (int i = 1; i < NUMBER_OF_VERTICAL_BLOCKS - 1; i++)
	{

		BuildingBlock rightEdge(rSideTexture,
								xStart + (NUMBER_OF_HORIZONTAL_BLOCKS - 1) * BLOCK_SIZE, yStart + i * BLOCK_SIZE,
								false);

		battlefieldBlocks.push_back(rightEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	for (int i = 1; i < NUMBER_OF_HORIZONTAL_BLOCKS - 1; i++)
	{
		BuildingBlock topEdge(tSideTexture, xStart + i * BLOCK_SIZE, yStart,
							  false);
		battlefieldBlocks.push_back(topEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	for (int i = 1; i < NUMBER_OF_HORIZONTAL_BLOCKS - 1; i++)
	{
		BuildingBlock bottomEdge(bSideTexture, xStart + i * BLOCK_SIZE,
								 yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
		battlefieldBlocks.push_back(bottomEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	BuildingBlock leftTopCorner(tlCornerTexture, xStart, yStart, false);
	battlefieldBlocks.push_back(leftTopCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock rightTopCorner(trCornerTexture,
								 xStart + BLOCK_SIZE * (NUMBER_OF_HORIZONTAL_BLOCKS - 1), yStart, false);
	battlefieldBlocks.push_back(rightTopCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock leftBottomCorner(blCornerTexture, xStart,
								   yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
	battlefieldBlocks.push_back(leftBottomCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock rightBottomCorner(brCornerTexture,
									xStart + BLOCK_SIZE * (NUMBER_OF_HORIZONTAL_BLOCKS - 1),
									yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
	battlefieldBlocks.push_back(rightBottomCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
}

void BattleField::createIndestructibleFieldBlocks()
{
	for (int i = 2; i < NUMBER_OF_HORIZONTAL_BLOCKS - 2; i += 2)
	{
		for (int j = 2; j < NUMBER_OF_VERTICAL_BLOCKS - 2; j += 2)
		{
			BuildingBlock indestructBlock(idBlockTexture,
										  i * BLOCK_SIZE, j * BLOCK_SIZE, false);
			battlefieldBlocks.push_back(indestructBlock);
		}
	}
}

void BattleField::generateDestructibleFieldBlocks()
{
	std::random_device rd;
	std::mt19937 eng(time(NULL));
	std::uniform_int_distribution<> rangeX(1, NUMBER_OF_HORIZONTAL_BLOCKS - 2);
	std::uniform_int_distribution<> rangeY(1, NUMBER_OF_VERTICAL_BLOCKS - 2);
	int i = 0;
	while (i != NUMBER_OF_BLOCKS_TO_DESTROY)
	{
		int randomPositionX = rangeX(eng);
		int randomPositionY = rangeY(eng);
		if (isPositionAvailable(randomPositionX, randomPositionY) == true)
		{
			BuildingBlock destructiveBlock(dBlockTexture,
										   randomPositionX * BLOCK_SIZE, randomPositionY * BLOCK_SIZE, true);
			battlefieldBlocks.push_back(destructiveBlock);
			i++;
		}
		else
		{
			continue;
		}
	}
}

bool BattleField::isPositionAvailable(int xPos, int yPos)
{
	for (BuildingBlock block : battlefieldBlocks)
	{
		sf::Vector2f position = block.getSprite().getPosition();
		bool isPositionOnRedCorners = checkRedCorners(xPos, yPos);
		if ((position.x == xPos * BLOCK_SIZE && position.y == yPos * BLOCK_SIZE) || !isPositionOnRedCorners)
		{
			return false;
		}
	}
	return true;
}

bool BattleField::checkRedCorners(int xPos, int yPos)
{
	// first row
	if ((xPos == 1 && yPos == 1) || (xPos == 2 && yPos == 1))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == 1) || (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == 1))
	{
		return false;
	}

	// second row
	if ((xPos == 1 && yPos == 2) || (xPos == 2 && yPos == 2))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == 2) || (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == 2))
	{
		return false;
	}

	// before last row
	if ((xPos == 1 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3) || (xPos == 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3) || (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3))
	{
		return false;
	}

	// last row
	if ((xPos == 1 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2) || (xPos == 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2) || (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2))
	{
		return false;
	}
	return true;
}

void BattleField::generatePlayer()
{
	Player player(player1Texture, BLOCK_SIZE, BLOCK_SIZE);
	battlefieldPlayers.push_back(player);
}

bool BattleField::isXAxisCollision (float blockPosX, float playerPosX)
{
	// return true means that moving is blocked
	float playerCenterPos = playerPosX + BLOCK_SIZE / 2;
	if (playerCenterPos - 15 > blockPosX - BLOCK_SIZE / 2
			&& playerCenterPos + 15 < blockPosX + 1.5 * BLOCK_SIZE)
	{
		return true;
	}
	return false;
}

bool BattleField::isYAxisCollision (float blockPosY, float playerPosY)
{
	// return true means that moving is blocked
	float playerCenterPos = playerPosY + BLOCK_SIZE / 2;
	if (playerCenterPos - 15 > blockPosY - BLOCK_SIZE / 2
			&& playerCenterPos + 15 < blockPosY + 1.5 * BLOCK_SIZE)
	{
		return true;
	}
	return false;
}

bool BattleField::checkOverlapping(std::string movingDirection, float playerPosX, float playerPosY)
{
	for (BuildingBlock block : battlefieldBlocks)
	{
		sf::Vector2f blockPosition = block.getSprite().getPosition();
		if (movingDirection.compare("up") == 0)
		{
			if (blockPosition.y == playerPosY - BLOCK_SIZE && isXAxisCollision(blockPosition.x, playerPosX))
			{
				return false;
			}
		}
		else if (movingDirection.compare("left") == 0)
		{
			if (blockPosition.x == playerPosX - BLOCK_SIZE && isYAxisCollision(blockPosition.y, playerPosY))
			{
				return false;
			}
		}
		else if (movingDirection.compare("down") == 0)
		{
			if (blockPosition.y == playerPosY + BLOCK_SIZE && isXAxisCollision(blockPosition.x, playerPosX))
			{
				return false;
			}
		}
		else if (movingDirection.compare("right") == 0 && isYAxisCollision(blockPosition.y, playerPosY))
		{
			if (blockPosition.x == playerPosX + BLOCK_SIZE)
			{
				return false;
			}
		}
	}
	return true;
}

void BattleField::procedeMove()
{
	float playerPositionX = battlefieldPlayers[0].getSprite().getPosition().x;
	float playerPositionY = battlefieldPlayers[0].getSprite().getPosition().y;

	std::string movingDirection = "";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movingDirection = "up";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movingDirection = "left";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movingDirection = "down";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movingDirection = "right";
	}
	else
	{
		battlefieldPlayers[0].sprite.setTexture(player1Texture);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sf::Vector2f v = sf::Vector2f(playerPositionX, playerPositionY);
		addBomb(v, battlefieldPlayers[0].bombPower);
	}

	// Check is possible to go in some direction and move if yes
	if (this->checkOverlapping(movingDirection, playerPositionX, playerPositionY) == true)
	{
		std::cout << playerPositionX << " " << playerPositionY << std::endl;
		battlefieldPlayers[0].movePlayer(movingDirection, playerPositionX, playerPositionY);
	}
}

void BattleField::addBomb(sf::Vector2f v, int power)
{

	v.x += BLOCK_SIZE / 2;
	v.y += BLOCK_SIZE / 2;

	v = getRasterPoint(v);

	Bomb b(bombTexture, v.x, v.y, power);

	b.ignite();

	battlefieldBombs.push_back(b);
}

void BattleField::addExplosion(sf::Vector2f v, int power)
{

	for (int i = 0; i < 4; i++)
	{
		char dir;
		switch (i)
		{
		case 0:
			dir = 'n';
			break;
		case 1:
			dir = 'e';
			break;
		case 2:
			dir = 's';
			break;
		case 3:
			dir = 'w';
			break;
		}

		Explosion e(explosionTexture, v.x, v.y, dir, power);

		battlefieldExplosions.push_back(e);
	}
}

void BattleField::checkForExplosion()
{

	for (int i = 0; i < battlefieldBombs.size(); i++)
	{

		if (battlefieldBombs[i].explodes())
		{
			sf::Vector2f v = battlefieldBombs[i].getSprite().getPosition();
			addExplosion(v, battlefieldBombs[i].power);
			battlefieldBombs.erase(battlefieldBombs.begin() + i);
		}
	}
}

void BattleField::checkForExplosionSpread()
{

	for (int i = 0; i < battlefieldExplosions.size(); i++)
	{

		int power = battlefieldExplosions[i].getPower();
		if (battlefieldExplosions[i].doesSpread() && power > 0)
		{

			sf::Vector2f ve = battlefieldExplosions[i].getSprite().getPosition();

			switch (battlefieldExplosions[i].getDirection())
			{
			case 'n':
				ve.y = ve.y - BLOCK_SIZE;
				break;
			case 'e':
				ve.x = ve.x + BLOCK_SIZE;
				break;
			case 's':
				ve.y = ve.y + BLOCK_SIZE;
				break;
			case 'w':
				ve.x = ve.x - BLOCK_SIZE;
				break;
			}


			float tolerance = 0.1;

			for (int y = 0; y < battlefieldBlocks.size(); y++)
			{
				sf::Vector2f vb = battlefieldBlocks[y].getSprite().getPosition();
				if (std::abs(vb.x - ve.x) < tolerance && std::abs(vb.y - ve.y) < tolerance)
				{

					if (battlefieldBlocks[y].getIsBuildingBlockDestructible())
					{

						battlefieldBlocks.erase(battlefieldBlocks.begin() + y);
						Explosion e(explosionTexture,ve.x,ve.y,battlefieldExplosions[i].getDirection(),0);
						battlefieldExplosions.push_back(e);
						return;
					}
					else
					{
						return;
					}
				}
			}
			Explosion e(explosionTexture,ve.x,ve.y,battlefieldExplosions[i].getDirection(),power-1);
			battlefieldExplosions.push_back(e);
		}
	}
}

void BattleField::checkForExplosionExtinguish()
{

	for (int i = 0; i < battlefieldExplosions.size(); i++)
		if (battlefieldExplosions[i].doesExtinguish())
			battlefieldExplosions.erase(battlefieldExplosions.begin() + i);
}

sf::Vector2f BattleField::getRasterPoint(sf::Vector2f v)
{

	int x = v.x;
	int y = v.y;

	x /= BLOCK_SIZE;
	y /= BLOCK_SIZE;

	x *= BLOCK_SIZE;
	y *= BLOCK_SIZE;

	sf::Vector2f h(x, y);

	return h;
}

void BattleField::draw(sf::RenderWindow *window)
{
	for (BuildingBlock buildingBlock : battlefieldBlocks)
	{
		window->draw(buildingBlock.getSprite());
	}

	for (Bomb bomb : battlefieldBombs)
	{
		window->draw(bomb.getSprite());
	}

	for (Player player : battlefieldPlayers)
	{
		window->draw(player.getSprite());
	}

	for (Explosion exp : battlefieldExplosions)
	{
		window->draw(exp.getSprite());
	}
}

BattleField::~BattleField()
{
}
