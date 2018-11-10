#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bomberman.h"

#include "objects/GameItem.h"
#include "objects/battlefield/BattleField.h"
#include "objects/blocks/BuildingBlock.h"

Bomberman::Bomberman()
{
}

void Bomberman::init()
{

	sf::Texture left;
	sf::Texture right;
	sf::Texture top;
	sf::Texture bottom;

	left.loadFromFile("res/BackgroundItems/leftEdge.png");
	right.loadFromFile("res/BackgroundItems/rightEdge.png");
	top.loadFromFile("res/BackgroundItems/topEdge.png");
	bottom.loadFromFile("res/BackgroundItems/bottomEdge.png");

	backGroundTextures.push_back(left);
	backGroundTextures.push_back(right);
	backGroundTextures.push_back(top);
	backGroundTextures.push_back(bottom);

	int xStart = 0;
	int yStart = 0;

	int blockCol = 11;
	int blockRow = 15;

	int blockSize = 64;

	for (int i = 1; i < blockCol - 1; i++)
	{

		GameItem gih(&backGroundTextures[0], xStart, yStart + i * blockSize);

		backGroundItems.push_back(gih);
	}

	for (int i = 1; i < blockCol - 1; i++)
	{

		GameItem gih(&backGroundTextures[1], xStart + (blockRow - 1) * blockSize, yStart + i * blockSize);

		backGroundItems.push_back(gih);
	}

	for (int i = 1; i < blockRow - 1; i++)
	{

		GameItem gih(&backGroundTextures[2], xStart + i * blockSize, yStart);

		backGroundItems.push_back(gih);
	}

	for (int i = 1; i < blockRow - 1; i++)
	{

		GameItem gih(&backGroundTextures[3], xStart + i * blockSize, yStart + blockSize * (blockCol - 1));

		backGroundItems.push_back(gih);
	}

	GameItem gitl("res/BackgroundItems/leftTopCorner.png", xStart, yStart);
	backGroundItems.push_back(gitl);

	GameItem gitr("res/BackgroundItems/rightTopCorner.png", xStart + blockSize * (blockRow - 1), yStart);
	backGroundItems.push_back(gitr);

	GameItem gibl("res/BackgroundItems/leftBottomCorner.png", xStart, yStart + blockSize * (blockCol - 1));
	backGroundItems.push_back(gibl);

	GameItem gibr("res/BackgroundItems/rightBottomCorner.png", xStart + blockSize * (blockRow - 1), yStart + blockSize * (blockCol - 1));
	backGroundItems.push_back(gibr);
}
void Bomberman::input()
{
}

void Bomberman::update()
{
}

void Bomberman::render(sf::RenderWindow *window)
{
	//std::cout << "render" << std::endl;
	sf::Color backgroundColor(41, 174, 74);
	window->clear(backgroundColor);

	for (GameItem s : backGroundItems)
	{
		window->draw(*s.sprite);
	}
	for (GameItem s : gameItems)
	{
		window->draw(*s.sprite);
	}

	//    BattleField bf;
	//    std::vector<BuildingBlock> firstRow = bf.generateBattleField();
	//    for (BuildingBlock bb : firstRow)
	//    {
	//    	sf::Sprite sp;
	//    	sp.setTexture(bb.getBuildingBlock());
	//    	window->draw(sp);
	//    }
}

Bomberman::~Bomberman()
{
}
