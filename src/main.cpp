#include "objects/menu/Menu.h"

int main()
{
    sf::RenderWindow *menuWindow;
    menuWindow = new sf::RenderWindow(sf::VideoMode(1280, 704), "Bomberman++");
    Menu menu(menuWindow->getSize().x, menuWindow->getSize().y);

    // menu.setMusic();
    // menu.menuMusic();

    while (menuWindow->isOpen())
    {
        sf::Event event;
        while (menuWindow->pollEvent(event))
        {
            menu.handleEventListener(event, menuWindow);
        }

        menuWindow->clear();
        menu.draw(*menuWindow);
        menuWindow->display();
    }
}
