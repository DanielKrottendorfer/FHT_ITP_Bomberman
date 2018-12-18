#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include ".\engine\GameEngine.h"
#include "Bomberman.h"
#include "objects/menu/Menu.h"

int main()
{

    sf::RenderWindow *menuWindow;
    menuWindow = new sf::RenderWindow(sf::VideoMode(1280, 704), "Bomberman++");
    Menu menu(menuWindow->getSize().x, menuWindow->getSize().y);

    menu.setMusic();
    menu.menuMusic();

    while (menuWindow->isOpen())
    {
        sf::Event event;
        while (menuWindow->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;

                case sf::Keyboard::Enter:
                    switch (menu.getPressedItem())
                    {
                    case 0: // Play
                    {
                        std::cout << "Play button pressed" << std::endl;
                        std::cout << "gameLogic" << std::endl;
                        menu.battleMusic();
                        IGameLogic *gameLogic = new Bomberman();
                        std::cout << "gameEngine" << std::endl;
                        GameEngine *gameEng = new GameEngine(menuWindow, gameLogic);
                        std::cout << "start" << std::endl;
                        gameEng->start();
                        std::cout << "end" << std::endl;
                        menu.menuMusic();
                        break;
                    }
                    case 1: // Options
                        std::cout << "Option button pressed" << std::endl;
                        break;

                    case 2: // End
                        menuWindow->close();
                        break;
                    }
                    break;
                }
                break;

            case sf::Event::Closed:
                menuWindow->close();
                break;
            }
        }

        menuWindow->clear();
        menu.draw(*menuWindow);
        menuWindow->display();
    }
}
