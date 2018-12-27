#include "Help.h"

Help::Help(sf::RenderWindow *window)
{
    helpWindow = window;
    helpBackgroundTexture.loadFromFile("res/HelpBackground.png");
    helpBackgroundSprite.setTexture(helpBackgroundTexture);
    displayHelp();
}

void Help::displayHelp()
{
    sf::Event event;
    while (helpWindow->isOpen())
    {
        while (helpWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                helpWindow->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return; // -> goes to main menu
            }
        }
        helpWindow->clear();
        draw();
        helpWindow->display();
    }
}

void Help::draw()
{
    helpWindow->draw(helpBackgroundSprite);
}

Help::~Help(){};