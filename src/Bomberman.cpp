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
	battlefield = new BattleField();
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
	
	battlefield->draw(window);

	//    BattleField bf;
	//    std::vector<BuildingBlock> firstRow = bf.generateBattleField();
	//    for (BuildingBlock bb : firstRow)
	//    {
	//    	sf::Sprite sp;
	//    	sp.setTexture(bb.getBuildingBlock());
	//    	window->draw(sp);
	//    }
}

