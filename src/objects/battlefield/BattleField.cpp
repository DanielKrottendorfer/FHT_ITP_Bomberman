#include <iostream>
#include <string>
#include "BattleField.h"

BattleField::BattleField()
{
	createBattleField();
}

void BattleField::createBattleField()
{

	/*
		ADDING INDESTRUCTIBLE BLOCKS
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
	int xStart = 0;
	int yStart = 0;

	int blockCol = NUMBER_OF_VERTICAL_BLOCKS;

	int blockRow = NUMBER_OF_HORIZONTAL_BLOCKS;
	int blockSize = 64;

	for (int i = 1; i < blockCol - 1; i++)
	{
		//std::cout << "start" << std::endl;
		
		//std::cout << i << std::endl;
		BuildingBlock bb("res/BackgroundItems/leftEdge.png", xStart, yStart + i * blockSize, false);
		//std::cout << i << std::endl;

		inDestructibleBlocks.push_back(bb);
		//std::cout << &inDestructibleBlocks[inDestructibleBlocks.size()-1] << std::endl;
		//std::cout << i << std::endl;
		//std::cout << "end" << std::endl;

		//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);
	}

		std::cout << "end" << std::endl;
	for (int i = 1; i < blockCol - 1; i++)
	{

		BuildingBlock bb("res/BackgroundItems/rightEdge.png", xStart + (blockRow - 1) * blockSize, yStart + i * blockSize, false);

		inDestructibleBlocks.push_back(bb);
		//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);
	}

	for (int i = 1; i < blockRow - 1; i++)
	{

		BuildingBlock bb("res/BackgroundItems/topEdge.png", xStart + i * blockSize, yStart, false);

		inDestructibleBlocks.push_back(bb);
		//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);
	}

	for (int i = 1; i < blockRow - 1; i++)
	{

		BuildingBlock bb("res/BackgroundItems/bottomEdge.png", xStart + i * blockSize, yStart + blockSize * (blockCol - 1), false);

		inDestructibleBlocks.push_back(bb);
		//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);
	}

	BuildingBlock bbtl("res/BackgroundItems/leftTopCorner.png", xStart, yStart, false);
	inDestructibleBlocks.push_back(bbtl);
	//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);

	BuildingBlock bbtr("res/BackgroundItems/rightTopCorner.png", xStart + blockSize * (blockRow - 1), yStart, false);
	inDestructibleBlocks.push_back(bbtr);
	//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);

	BuildingBlock bbbl("res/BackgroundItems/leftBottomCorner.png", xStart, yStart + blockSize * (blockCol - 1), false);
	inDestructibleBlocks.push_back(bbbl);
	//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);

	BuildingBlock bbbr("res/BackgroundItems/rightBottomCorner.png", xStart + blockSize * (blockRow - 1), yStart + blockSize * (blockCol - 1), false);
	inDestructibleBlocks.push_back(bbbr);
	//battleField2D.push_back(&inDestructibleBlocks[inDestructibleBlocks.size()-1]);
	
	for(BuildingBlock b: inDestructibleBlocks){
		sf::Vector2f v = b.sprite->getPosition();
		std::cout << "x: " << v.x << "y: " << v.y << "textaddress:" << b.texture << std::endl;
	}

}

void BattleField::draw(sf::RenderWindow *window)
{	
	//std::cout << "render" << std::endl;
	for (BuildingBlock b : inDestructibleBlocks)
	{
		
		window->draw(*b.sprite);
	}
}

BattleField::~BattleField()
{
}
