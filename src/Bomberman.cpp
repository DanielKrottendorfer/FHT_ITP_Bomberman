#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bomberman.h"

#include "objects/GameItem.h"
#include "objects/battlefield/BattleField.h"
#include "objects/blocks/BuildingBlock.h"

Bomberman::Bomberman ()
{
}

void Bomberman::init ()
{


	int xStart = 0;
	int yStart = 0;

	int blockCol = 11;
	int blockRow = 15;
	
	int blockSize = 64;

	for(int i = 1;i<blockCol-1;i++){

		GameItem gih ("res/BackgroundItems/leftEdge.png",xStart,yStart+i*blockSize);

		backGroundItems.push_back(gih);

	}
	

	for(int i = 1;i<blockCol-1;i++){

		GameItem gih ("res/BackgroundItems/rightEdge.png",xStart+(blockRow-1)*blockSize,yStart+i*blockSize);

		backGroundItems.push_back(gih);

	}
	

	for(int i = 1;i<blockRow-1;i++){

		GameItem gih ("res/BackgroundItems/topEdge.png",xStart+i*blockSize,yStart);

		backGroundItems.push_back(gih);

	}
	

	for(int i = 1;i<blockRow-1;i++){

		GameItem gih ("res/BackgroundItems/bottomEdge.png",xStart+i*blockSize,yStart+blockSize*(blockCol-1));

		backGroundItems.push_back(gih);

	}

	GameItem gitl ("res/BackgroundItems/leftTopCorner.png",xStart,yStart);
	backGroundItems.push_back(gitl);

	GameItem gitr ("res/BackgroundItems/rightTopCorner.png",xStart+blockSize*(blockRow-1),yStart);
	backGroundItems.push_back(gitr);

	GameItem gibl ("res/BackgroundItems/leftBottomCorner.png",xStart,yStart+blockSize*(blockCol-1));
	backGroundItems.push_back(gibl);

	GameItem gibr ("res/BackgroundItems/rightBottomCorner.png",xStart+blockSize*(blockRow-1),yStart+blockSize*(blockCol-1));
	backGroundItems.push_back(gibr);



	


}
void Bomberman::input ()
{


}

void Bomberman::update ()
{

}

void Bomberman::render (sf::RenderWindow* window)
{
	//std::cout << "render" << std::endl;
	sf::Color backgroundColor (41, 174, 74);
	window->clear (backgroundColor);

	for (GameItem s : backGroundItems)
	{
		window->draw (*s.sprite);
	}
	for (GameItem s : gameItems)
	{
		window->draw (*s.sprite);
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

Bomberman::~Bomberman ()
{
}
