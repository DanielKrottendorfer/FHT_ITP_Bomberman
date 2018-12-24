#include <iostream>
#include <string>
#include <random>
#include "BattleField.h"

BattleField::BattleField(int numberOfPlayers)
{
	this->numberOfPlayers = numberOfPlayers;
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
	player2Texture.loadFromFile("res/Character/Char2/Char2_front.png");
	player3Texture.loadFromFile("res/Character/Char3/Char3_front.png");
	player4Texture.loadFromFile("res/Character/Char4/Char4_front.png");

	bombTexture.loadFromFile("res/Bomb.png");
	//explosionTexture.loadFromFile("res/Explosion.png");

	explosionTextureCenter.loadFromFile("res/Bomb/fire_center.png");
	explosionTextureHorizontal.loadFromFile("res/Bomb/fire_horizontal.png");
	explosionTextureVertical.loadFromFile("res/Bomb/fire_vertical.png");

	explosionTextureLeft.loadFromFile("res/Bomb/fire_left.png");
	explosionTextureRight.loadFromFile("res/Bomb/fire_right.png");
	explosionTextureUp.loadFromFile("res/Bomb/fire_up.png");
	explosionTextureDown.loadFromFile("res/Bomb/fire_down.png");

	powerupTextureF1.loadFromFile("res/Powerup/Power_Up_Flame1.png");
	powerupTextureF2.loadFromFile("res/Powerup/Power_Up_Flame2.png");
	powerupTextureB1.loadFromFile("res/Powerup/Power_Up_bomb1.png");
	powerupTextureB2.loadFromFile("res/Powerup/Power_Up_bomb2.png");
	powerupTextureS1.loadFromFile("res/Powerup/Power_Up_Speed1.png");
	powerupTextureS2.loadFromFile("res/Powerup/Power_Up_Speed2.png");

	createFrameBlocks();
	createIndestructibleFieldBlocks();
	generateDestructibleFieldBlocks();
	distributePowerups();

	generatePlayers(); // temp function initialisation

	int count = 0;
	for (BuildingBlock b : battlefieldBlocks)
	{
		sf::Vector2f v = b.getSprite().getPosition();
		std::cout << "x: " << v.x << "; y: " << v.y << "; textaddress:" << b.getSprite().getTexture() << " " << b.getPowerupDrop() << std::endl;
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

void BattleField::distributePowerups()
{

	std::srand(std::time(nullptr));
	int counter = 0;
	for (int i = 0;; i++)
	{

		if (i == battlefieldBlocks.size())
			i = 0;

		if (battlefieldBlocks[i].getIsBuildingBlockDestructible() && battlefieldBlocks[i].getPowerupDrop() == "n")
		{

			int random_variable = std::rand();

			random_variable %= 12;

			switch (random_variable)
			{
			case 0:
				battlefieldBlocks[i].setPowerupDrop("f1");
				counter++;
				break;
			case 1:
				battlefieldBlocks[i].setPowerupDrop("f2");
				counter++;
				break;
			case 2:
				battlefieldBlocks[i].setPowerupDrop("b1");
				counter++;
				break;
			case 3:
				battlefieldBlocks[i].setPowerupDrop("b2");
				counter++;
				break;
			case 4:
				battlefieldBlocks[i].setPowerupDrop("s1");
				counter++;
				break;
			case 5:
				battlefieldBlocks[i].setPowerupDrop("s2");
				counter++;
				break;
			}

			if (counter == POWERUP_COUNT)
				return;
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

void BattleField::generatePlayers()
{
	for (int i = 1; i <= numberOfPlayers; i++)
	{
		switch (i)
		{
		case 1:
		{
			Player player1(player1Texture, BLOCK_SIZE, BLOCK_SIZE);
			battlefieldPlayers.push_back(player1);
			break;
		}
		case 2:
		{
			Player player2(player2Texture, (NUMBER_OF_HORIZONTAL_BLOCKS - 2) * BLOCK_SIZE,
						   BLOCK_SIZE);
			battlefieldPlayers.push_back(player2);
			break;
		}
		case 3:
		{
			Player player3(player3Texture, BLOCK_SIZE,
						   (NUMBER_OF_VERTICAL_BLOCKS - 2) * BLOCK_SIZE);
			battlefieldPlayers.push_back(player3);
			break;
		}
		case 4:
		{
			Player player4(player4Texture, (NUMBER_OF_HORIZONTAL_BLOCKS - 2) * BLOCK_SIZE,
						   (NUMBER_OF_VERTICAL_BLOCKS - 2) * BLOCK_SIZE);
			battlefieldPlayers.push_back(player4);
			break;
		}
		}
	}
}

bool BattleField::isXAxisCollision(float blockPosX, float playerPosX)
{
	// return true means that moving is blocked
	float playerCenterPos = playerPosX + BLOCK_SIZE / 2;
	if (playerCenterPos - 15 > blockPosX - BLOCK_SIZE / 2 && playerCenterPos + 15 < blockPosX + 1.5 * BLOCK_SIZE)
	{
		return true;
	}
	return false;
}

bool BattleField::isYAxisCollision(float blockPosY, float playerPosY)
{
	// return true means that moving is blocked
	float playerCenterPos = playerPosY + BLOCK_SIZE / 2;
	if (playerCenterPos - 15 > blockPosY - BLOCK_SIZE / 2 && playerCenterPos + 15 < blockPosY + 1.5 * BLOCK_SIZE)
	{
		return true;
	}
	return false;
}

bool BattleField::checkObjectCollision(std::string movingDirection, sf::Vector2f objectPosition, float playerPosX, float playerPosY)
{
	if (movingDirection.compare("up") == 0)
	{
		if (objectPosition.y == playerPosY - BLOCK_SIZE && isXAxisCollision(objectPosition.x, playerPosX))
		{
			return false;
		}
	}
	else if (movingDirection.compare("left") == 0)
	{
		if (objectPosition.x == playerPosX - BLOCK_SIZE && isYAxisCollision(objectPosition.y, playerPosY))
		{
			return false;
		}
	}
	else if (movingDirection.compare("down") == 0)
	{
		if (objectPosition.y == playerPosY + BLOCK_SIZE && isXAxisCollision(objectPosition.x, playerPosX))
		{
			return false;
		}
	}
	else if (movingDirection.compare("right") == 0 && isYAxisCollision(objectPosition.y, playerPosY))
	{
		if (objectPosition.x == playerPosX + BLOCK_SIZE)
		{
			return false;
		}
	}
	return true;
}

bool BattleField::checkBlockCollision(std::string movingDirection, float playerPosX, float playerPosY)
{
	for (BuildingBlock block : battlefieldBlocks)
	{
		sf::Vector2f blockPosition = block.getSprite().getPosition();
		if (!checkObjectCollision(movingDirection, blockPosition, playerPosX, playerPosY))
		{
			return false;
		}
	}
	return true;
}

bool BattleField::checkBombCollision(std::string movingDirection, float playerPosX, float playerPosY)
{
	for (Bomb bomb : battlefieldBombs)
	{
		sf::Vector2f bombPosition = bomb.getSprite().getPosition();
		if (!checkObjectCollision(movingDirection, bombPosition, playerPosX, playerPosY))
		{
			return false;
		}
	}
	return true;
}

bool BattleField::checkCollision(std::string movingDirection, float playerPositionX, float playerPositionY)
{
	bool isBlockColliding = checkBlockCollision(movingDirection, playerPositionX, playerPositionY);
	bool isBombColliding = checkBombCollision(movingDirection, playerPositionX, playerPositionY);
	if (isBlockColliding && isBombColliding)
	{
		return true;
	}
	return false;
}

void BattleField::procedeMove()
{
	float playerPositionX = battlefieldPlayers.at(0).getSprite().getPosition().x;
	float playerPositionY = battlefieldPlayers.at(0).getSprite().getPosition().y;

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
		addBomb(v, battlefieldPlayers[0].bombPower, &battlefieldPlayers[0]);
	}

	// Check is possible to go in some direction and move if yes
	if (this->checkCollision(movingDirection, playerPositionX, playerPositionY) == true)
	{
		//std::cout << playerPositionX << " " << playerPositionY << std::endl;
		battlefieldPlayers[0].movePlayer(movingDirection, playerPositionX, playerPositionY);
	}
}

void BattleField::addBomb(sf::Vector2f v, int power, Player *p)
{
	if (p->getBombC() > 0)
	{
		v.x += BLOCK_SIZE / 2;
		v.y += BLOCK_SIZE / 2;

		v = getRasterPoint(v);

		sf::Vector2f vb;
		float tolerance = 0.1;

		for (Bomb b : battlefieldBombs)
		{
			vb = b.getSprite().getPosition();

			if (abs(v.x - vb.x) < tolerance && abs(v.y - vb.y) < tolerance)
				return;
		}

		Bomb b(bombTexture, v.x, v.y, power, *p);
		p->decBomb();

		b.ignite();

		battlefieldBombs.push_back(b);
	}
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

		Explosion e(explosionTextureCenter, v.x, v.y, dir, power);

		battlefieldExplosions.push_back(e);
	}
}

void BattleField::addPowerup(sf::Vector2f v, std::string powerUp)
{
	Powerup p;

	if (powerUp == "f1")
	{
		p = Powerup(powerupTextureF1, v.x, v.y, powerUp);
	}
	if (powerUp == "f2")
	{
		p = Powerup(powerupTextureF2, v.x, v.y, powerUp);
	}
	if (powerUp == "s1")
	{
		p = Powerup(powerupTextureS1, v.x, v.y, powerUp);
	}
	if (powerUp == "s2")
	{
		p = Powerup(powerupTextureS2, v.x, v.y, powerUp);
	}
	if (powerUp == "b1")
	{
		p = Powerup(powerupTextureB1, v.x, v.y, powerUp);
	}
	if (powerUp == "b2")
	{
		p = Powerup(powerupTextureB2, v.x, v.y, powerUp);
	}
	battlefieldPowerups.push_back(p);
}

void BattleField::collectPowerups()
{

	for (int i = 0; i < battlefieldPlayers.size(); i++)
	{

		for (int y = 0; y < battlefieldPowerups.size(); y++)
		{
			//Top Left Explosion
			sf::Vector2f tle = battlefieldPowerups[y].getSprite().getPosition();

			for (int x = 0; x < 4; x++)
			{
				//Top Left PlayerHitbox
				sf::Vector2f tlp = battlefieldPlayers[i].getSprite().getPosition();

				switch (x)
				{
				case 0:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y;
					break;
				case 1:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x + battlefieldPlayers[i].getHitbox().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y;
					break;
				case 2:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y + battlefieldPlayers[i].getHitbox().y;
					break;
				case 3:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x + battlefieldPlayers[i].getHitbox().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y + battlefieldPlayers[i].getHitbox().y;
					break;
				}

				if ((tle.y < tlp.y && tle.y + 64 > tlp.y) && (tle.x < tlp.x && tle.x + 64 > tlp.x))
				{

					std::string powerUp = battlefieldPowerups[y].getType();
					if (powerUp == "f1")
					{
						battlefieldPlayers[i].incBombPower(2);
					}
					if (powerUp == "f2")
					{
						battlefieldPlayers[i].incBombPower(3);
					}
					if (powerUp == "s1")
					{
						// TODO STEFAN - 6 cannot be speed also
						battlefieldPlayers[i].addSpeed(4);
					}
					if (powerUp == "s2")
					{
						battlefieldPlayers[i].addSpeed(4);
					}
					if (powerUp == "b1")
					{
						battlefieldPlayers[i].addBomb();
					}
					if (powerUp == "b2")
					{
						battlefieldPlayers[i].addBomb();
						battlefieldPlayers[i].addBomb();
					}

					battlefieldPowerups.erase(battlefieldPowerups.begin() + y);
					return;
				}
			}
		}
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
			battlefieldBombs[i].getOwner()->addBomb();
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

						if (battlefieldBlocks[y].getPowerupDrop() != "n")
						{
							addPowerup(vb, battlefieldBlocks[y].getPowerupDrop());
						}

						battlefieldBlocks.erase(battlefieldBlocks.begin() + y);

						Explosion e;
						switch (battlefieldExplosions[i].getDirection())
						{
						case 'n':
							e = Explosion(explosionTextureUp, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
							break;
						case 'e':
							e = Explosion(explosionTextureRight, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
							break;
						case 's':
							e = Explosion(explosionTextureDown, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
							break;
						case 'w':
							e = Explosion(explosionTextureLeft, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
							break;
						}
						battlefieldExplosions.push_back(e);
						return;
					}
					else
					{
						return;
					}
				}
			}
			Explosion e;

			if (power - 1 == 0)
			{
				switch (battlefieldExplosions[i].getDirection())
				{
				case 'n':
					e = Explosion(explosionTextureUp, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
					break;
				case 'e':
					e = Explosion(explosionTextureRight, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
					break;
				case 's':
					e = Explosion(explosionTextureDown, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
					break;
				case 'w':
					e = Explosion(explosionTextureLeft, ve.x, ve.y, battlefieldExplosions[i].getDirection(), 0);
					break;
				}
			}
			else
			{
				switch (battlefieldExplosions[i].getDirection())
				{
				case 'n':
					e = Explosion(explosionTextureVertical, ve.x, ve.y, battlefieldExplosions[i].getDirection(), power - 1);
					break;
				case 'e':
					e = Explosion(explosionTextureHorizontal, ve.x, ve.y, battlefieldExplosions[i].getDirection(), power - 1);
					break;
				case 's':
					e = Explosion(explosionTextureVertical, ve.x, ve.y, battlefieldExplosions[i].getDirection(), power - 1);
					break;
				case 'w':
					e = Explosion(explosionTextureHorizontal, ve.x, ve.y, battlefieldExplosions[i].getDirection(), power - 1);
					break;
				}
			}
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

void BattleField::checkForPlayerDeath()
{

	for (int i = 0; i < battlefieldPlayers.size(); i++)
	{

		for (Explosion e : battlefieldExplosions)
		{
			//Top Left Explosion
			sf::Vector2f tle = e.getSprite().getPosition();

			bool hit = false;

			for (int x = 0; x < 4; x++)
			{
				//Top Left PlayerHitbox
				sf::Vector2f tlp = battlefieldPlayers[i].getSprite().getPosition();

				switch (x)
				{
				case 0:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y;
					break;
				case 1:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x + battlefieldPlayers[i].getHitbox().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y;
					break;
				case 2:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y + battlefieldPlayers[i].getHitbox().y;
					break;
				case 3:
					tlp.x = tlp.x + battlefieldPlayers[i].getHitboxOffset().x + battlefieldPlayers[i].getHitbox().x;
					tlp.y = tlp.y + battlefieldPlayers[i].getHitboxOffset().y + battlefieldPlayers[i].getHitbox().y;
					break;
				}

				if ((tle.y < tlp.y && tle.y + 64 > tlp.y) && (tle.x < tlp.x && tle.x + 64 > tlp.x))
				{
					std::cout << "player: " << i + 1 << "died" << std::endl;
					hit = true;
					break;
				}
			}

			if (hit)
				break;
		}
	}
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

	for (Powerup powerup : battlefieldPowerups)
	{
		window->draw(powerup.getSprite());
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
