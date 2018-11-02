#include "GameItem.h"
#include <string>
#include <iostream>


GameItem::GameItem(std::string texturePath,int x,int y){

    this->x=x;
    this->y=y;

    texture = new sf::Texture;
    sprite = new sf::Sprite;

    if(!texture->loadFromFile("res/toad.png")){
        std::cout << "Nicht geladen" << std::endl;
    }

    sprite->setTexture(*texture);
    sprite->setPosition(x,y);

}