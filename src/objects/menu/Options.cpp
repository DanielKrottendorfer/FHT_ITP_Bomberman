#include "Options.h"

Options::Options(sf::RenderWindow *window)
{
    optionsWindow = window;
    optionsBackgroundTexture.loadFromFile("res/OptionsBackground.png");
    optionsBackgroundSprite.setTexture(optionsBackgroundTexture);
    displayOptions();
}

void Options::displayOptions()
{
    sf::Event event;
    while (optionsWindow->isOpen())
    {
        while (optionsWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                optionsWindow->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return; // -> goes to main menu
            }
        }
        optionsWindow->clear();
        draw();
        optionsWindow->display();
    }
}

void Options::draw()
{
    optionsWindow->draw(optionsBackgroundSprite);
}

Options::~Options(){};