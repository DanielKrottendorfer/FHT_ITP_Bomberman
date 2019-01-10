#include "objects/menu/Menu.h"

int main()
{
    sf::RenderWindow *menuWindow;
    menuWindow = new sf::RenderWindow(sf::VideoMode(1280, 704), "Bomberman++");
    Menu menu(menuWindow->getSize().x, menuWindow->getSize().y);

    sf::Image icon;
    if (icon.loadFromFile("res/Bomb/bomb_tick_1.png"))
    {
        menuWindow->setIcon(64, 64, icon.getPixelsPtr());
    }
    menu.setMusic();
    menu.menuMusic();

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
