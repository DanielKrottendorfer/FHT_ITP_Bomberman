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

    sf::Clock clock;

    float elapsedTime;
    float interval = 1000 / UPS;
    
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

            if(!gameLogic->running)
                return;
            
        }

        elapsedTime = clock.getElapsedTime().asMilliseconds();

        input();
        update();
        render();

        while(elapsedTime <= interval)
        {
            elapsedTime = clock.getElapsedTime().asMilliseconds();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        clock.restart();
            
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