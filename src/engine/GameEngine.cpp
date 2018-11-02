#include <SFML/Graphics.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "GameEngine.h"


sf::RenderWindow* window;
IGameLogic* gameLogic;

// Updates per second
const int UPS = 60;

GameEngine::GameEngine(std::string windowTitle, int width, int height, IGameLogic* gameLogic){
    window = new sf::RenderWindow(sf::VideoMode(width, height), windowTitle);
    this->gameLogic = gameLogic;
}

void GameEngine::init()
{
    gameLogic->init();
}

void GameEngine::gameLoop(){

    
    sf::Event event;
    //int loopC = 0;
    while (window->isOpen())
    {
        //loopC++;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();

            
        }

        input();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/UPS));
            
        //std::cout << loopC << std::endl;
    }
    


}

void GameEngine::input(){
    gameLogic->input();
}

void GameEngine::update(){
    gameLogic->update();
}


void GameEngine::start(){
    init();
    gameLoop();
}

void GameEngine::render(){
    gameLogic->render(window);
    window->display();
}


GameEngine::~GameEngine(){
    delete gameLogic;
    delete window;
}