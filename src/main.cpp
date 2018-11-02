
#include <string>
#include <iostream>

#include ".\engine\GameEngine.h"
#include "Bomberman.h"

int main(){


    //std::cout << "gameLogic" << std::endl;
    IGameLogic* gameLogic = new Bomberman();

    //std::cout << "gameEngine" << std::endl;

    GameEngine* gameEng = new GameEngine("Bomberman++", 800 , 500, gameLogic);

    gameEng->start();

    //std::cout << "end" << std::endl;
}