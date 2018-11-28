#include <SFML/Graphics.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "GameEngine.h"

// Updates per second

GameEngine::GameEngine(sf::RenderWindow* menuWindow, IGameLogic* gameLogic){
    //window = new sf::RenderWindow(sf::VideoMode(width, height), windowTitle);
    window = menuWindow;
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
                //window->close();
                //std::this_thread::sleep_for(std::chrono::milliseconds(500));
                return; // -> main.cpp

            
        }

        //std::cout << "input" << std::endl;
        input();
        //std::cout << "update" << std::endl;
        update();
        //std::cout << "render" << std::endl;
        render();
        //std::cout << "sleep" << std::endl;
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
    std::cout << "gameEngine Init" << std::endl;
    init();
    std::cout << "gameEngine GameLoop" << std::endl;
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