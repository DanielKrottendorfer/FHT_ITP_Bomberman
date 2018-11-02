#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bomberman.h"
#include "obj/GameItem.h"

Bomberman::Bomberman(){}


void Bomberman::init(){

    std::cout << "init1" << std::endl;

    GameItem gi("res/toad.png",100,100);

    std::cout << "push" << std::endl;

    gameItems.push_back(gi);

}
void Bomberman::input(){



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        gameItems[0].y=(gameItems[0].y-1);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        gameItems[0].x=gameItems[0].x-1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        gameItems[0].y=gameItems[0].y+1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        gameItems[0].x=gameItems[0].x+1;
    }
}

void Bomberman::update(){

    for(GameItem s : gameItems){
        s.sprite->setPosition(s.x,s.y);
    }

}
void Bomberman::render(sf::RenderWindow* window){
    //std::cout << "render" << std::endl;

    window->clear(sf::Color::Blue);

    for(GameItem s : gameItems){
        window->draw(*s.sprite);

    }
}


Bomberman::~Bomberman(){

}