#include <iostream>
#include <string>
#include <random>
#include "BattleField.h"

BattleField::BattleField ()
{
	createBattleField ();
}

void BattleField::createBattleField ()
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

	createFrameBlocks ();
	createIndestructibleFieldBlocks ();
	generateDestructibleFieldBlocks ();

	generatePlayer (); // temp function initialisation

	for (BuildingBlock b : battlefieldBlocks)
	{
		sf::Vector2f v = b.sprite->getPosition ();
		std::cout << "x: " << v.x << "; y: " << v.y << "; textaddress:" << b.texture << std::endl;
	}
}

void BattleField::createFrameBlocks ()
{
	int xStart = 0;
	int yStart = 0;

	for (int i = 1; i < NUMBER_OF_VERTICAL_BLOCKS - 1; i++)
	{
		//std::cout << "start" << std::endl;

		//std::cout << i << std::endl;
		BuildingBlock leftEdge ("res/BackgroundItems/leftEdge.png", xStart, yStart + i * BLOCK_SIZE,
				false);
		//std::cout << i << std::endl;

		battlefieldBlocks.push_back (leftEdge);
		//std::cout << &battlefieldBlocks[battlefieldBlocks.size()-1] << std::endl;
		//std::cout << i << std::endl;
		//std::cout << "end" << std::endl;

		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	std::cout << "end" << std::endl;
	for (int i = 1; i < NUMBER_OF_VERTICAL_BLOCKS - 1; i++)
	{

		BuildingBlock rightEdge ("res/BackgroundItems/rightEdge.png",
				xStart + (NUMBER_OF_HORIZONTAL_BLOCKS - 1) * BLOCK_SIZE, yStart + i * BLOCK_SIZE,
				false);

		battlefieldBlocks.push_back (rightEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	for (int i = 1; i < NUMBER_OF_HORIZONTAL_BLOCKS - 1; i++)
	{
		BuildingBlock topEdge ("res/BackgroundItems/topEdge.png", xStart + i * BLOCK_SIZE, yStart,
				false);
		battlefieldBlocks.push_back (topEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	for (int i = 1; i < NUMBER_OF_HORIZONTAL_BLOCKS - 1; i++)
	{
		BuildingBlock bottomEdge ("res/BackgroundItems/bottomEdge.png", xStart + i * BLOCK_SIZE,
				yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
		battlefieldBlocks.push_back (bottomEdge);
		//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
	}

	BuildingBlock leftTopCorner ("res/BackgroundItems/leftTopCorner.png", xStart, yStart, false);
	battlefieldBlocks.push_back (leftTopCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock rightTopCorner ("res/BackgroundItems/rightTopCorner.png",
			xStart + BLOCK_SIZE * (NUMBER_OF_HORIZONTAL_BLOCKS - 1), yStart, false);
	battlefieldBlocks.push_back (rightTopCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock leftBottomCorner ("res/BackgroundItems/leftBottomCorner.png", xStart,
			yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
	battlefieldBlocks.push_back (leftBottomCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);

	BuildingBlock rightBottomCorner ("res/BackgroundItems/rightBottomCorner.png",
			xStart + BLOCK_SIZE * (NUMBER_OF_HORIZONTAL_BLOCKS - 1),
			yStart + BLOCK_SIZE * (NUMBER_OF_VERTICAL_BLOCKS - 1), false);
	battlefieldBlocks.push_back (rightBottomCorner);
	//battleField2D.push_back(&battlefieldBlocks[battlefieldBlocks.size()-1]);
}

void BattleField::createIndestructibleFieldBlocks ()
{
	for (int i = 2; i < NUMBER_OF_HORIZONTAL_BLOCKS - 2; i += 2)
	{
		for (int j = 2; j < NUMBER_OF_VERTICAL_BLOCKS - 2; j += 2)
		{
			BuildingBlock indestructBlock ("res/BackgroundItems/indestructibleBlocks.png",
					i * BLOCK_SIZE, j * BLOCK_SIZE, false);
			battlefieldBlocks.push_back (indestructBlock);
		}
	}
}

void BattleField::generateDestructibleFieldBlocks ()
{
	std::random_device rd;
	std::mt19937 eng (time (NULL));
	std::uniform_int_distribution<> rangeX (1, NUMBER_OF_HORIZONTAL_BLOCKS - 2);
	std::uniform_int_distribution<> rangeY (1, NUMBER_OF_VERTICAL_BLOCKS - 2);
	int i = 0;
	while (i != NUMBER_OF_BLOCKS_TO_DESTROY)
	{
		int randomPositionX = rangeX (eng);
		int randomPositionY = rangeY (eng);
		if (isPositionAvailable (randomPositionX, randomPositionY) == true)
		{
			BuildingBlock destructiveBlock ("res/BackgroundItems/destructibleBlocks.png",
					randomPositionX * BLOCK_SIZE, randomPositionY * BLOCK_SIZE, true);
			battlefieldBlocks.push_back (destructiveBlock);
			i++;
		}
		else
		{
			continue;
		}
	}
}

bool BattleField::isPositionAvailable (int xPos, int yPos)
{
	for (BuildingBlock block : battlefieldBlocks)
	{
		sf::Vector2f position = block.sprite->getPosition ();
		bool isPositionOnRedCorners = checkRedCorners (xPos, yPos);
		if ((position.x == xPos * BLOCK_SIZE && position.y == yPos * BLOCK_SIZE)
				|| !isPositionOnRedCorners)
		{
			return false;
		}
	}
	return true;
}

bool BattleField::checkRedCorners (int xPos, int yPos)
{
	// first row
	if ((xPos == 1 && yPos == 1) || (xPos == 2 && yPos == 1))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == 1)
			|| (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == 1))
	{
		return false;
	}

	// second row
	if ((xPos == 1 && yPos == 2) || (xPos == 2 && yPos == 2))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == 2)
			|| (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == 2))
	{
		return false;
	}

	// before last row
	if ((xPos == 1 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3)
			|| (xPos == 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3)
			|| (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 3))
	{
		return false;
	}

	// last row
	if ((xPos == 1 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2)
			|| (xPos == 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2))
	{
		return false;
	}
	if ((xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 3 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2)
			|| (xPos == NUMBER_OF_HORIZONTAL_BLOCKS - 2 && yPos == NUMBER_OF_VERTICAL_BLOCKS - 2))
	{
		return false;
	}
	return true;
}

void BattleField::generatePlayer ()
{
	Player player ("res/Character/Char1_front.png", BLOCK_SIZE, BLOCK_SIZE);
	battlefieldPlayers.push_back (player);
}

void BattleField::draw (sf::RenderWindow *window)
{
	for (BuildingBlock buildingBlock : battlefieldBlocks)
	{
		window->draw (*buildingBlock.sprite);
	}

	for (Player player : battlefieldPlayers)
	{
		window->draw (*player.sprite);
	}
}

BattleField::~BattleField ()
{
}
