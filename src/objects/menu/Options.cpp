#include "Options.h"

Options::Options(sf::RenderWindow *window, float menuSoundLevel, float battlefieldSoundLevel)
{
    if (!font.loadFromFile("res/fonts/reem.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    optionsWindow = window;
    optionsBackgroundTexture.loadFromFile("res/OptionsBackground.png");
    optionsBackgroundSprite.setTexture(optionsBackgroundTexture);

    this->menuSoundLevel = menuSoundLevel;
    this->battlefieldSoundLevel = battlefieldSoundLevel;

    isSaved = false;

    displayButtons();
    displayText();
    displaySliders();
    displayOptions();
}

void Options::displayOptions()
{
    while (optionsWindow->isOpen())
    {
        sf::Event event;
        while (optionsWindow->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp();
                    break;
                case sf::Keyboard::Down:
                    moveDown();
                    break;
                case sf::Keyboard::Left:
                    toneDown();
                    break;
                case sf::Keyboard::Right:
                    toneUp();
                    break;
                case sf::Keyboard::Enter:
                    if (selectedItemIndex == NUMBER_OF_OPTIONS - 1)
                    {
                        isSaved = true;
                        return;
                    }
                    break;
                case sf::Keyboard::Escape:
                    return;
                    break;
                }
                break;
            case sf::Event::Closed:
                optionsWindow->close();
                break;
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
    optionsWindow->draw(saveAndExitButton);
    for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
    {
        optionsWindow->draw(optionsTexts[i]);
    }
    for (int i = 0; i < NUMBER_OF_SLIDERS; i++)
    {
        optionsWindow->draw(optionsSliders[i]);
        optionsWindow->draw(sliderHelper[i]);
    }
}

void Options::displayText()
{
    sf::Color color(219, 219, 219);
    optionsTexts[0].setFont(font);
    optionsTexts[0].setString("Menu Sound Level:");
    optionsTexts[0].setFillColor(color);
    optionsTexts[0].setCharacterSize(32);
    optionsTexts[0].setPosition(sf::Vector2f(100, 200));
    optionsTexts[0].setOutlineColor(sf::Color::Red);
    optionsTexts[0].setOutlineThickness(1);

    optionsTexts[1].setFont(font);
    optionsTexts[1].setString("Battlefield Sound Level:");
    optionsTexts[1].setFillColor(color);
    optionsTexts[1].setCharacterSize(32);
    optionsTexts[1].setPosition(sf::Vector2f(100, 270));
    optionsTexts[1].setOutlineColor(sf::Color::Black);
    optionsTexts[1].setOutlineThickness(1);

    optionsTexts[2].setFont(font);
    optionsTexts[2].setString("Save and Exit");
    optionsTexts[2].setFillColor(sf::Color::Black);
    optionsTexts[2].setCharacterSize(32);
    optionsTexts[2].setOutlineColor(sf::Color::Black);
    optionsTexts[2].setPosition(sf::Vector2f(optionsWindow->getSize().x / 2.0f - 60,
                                             optionsWindow->getSize().y / 2.0f + 220));
}

void Options::displayButtons()
{
    sf::Color bgColor(219, 219, 219);
    saveAndExitButton.setSize(sf::Vector2f(250, 50));
    saveAndExitButton.setPosition(optionsWindow->getSize().x / 2.0f - 88,
                                  optionsWindow->getSize().y / 2.0f + 217);
    saveAndExitButton.setFillColor(bgColor);
    saveAndExitButton.setOutlineColor(sf::Color::Black);
    saveAndExitButton.setOutlineThickness(3);
}

void Options::displaySliders()
{
    optionsSliders[0].setFillColor(sf::Color::White);
    optionsSliders[0].setSize(sf::Vector2f(500, 5));
    optionsSliders[0].setPosition(optionsTexts[0].getPosition().x + 400,
                                  optionsTexts[0].getPosition().y + 20);

    sliderHelper[0].setFillColor(sf::Color::Red);
    sliderHelper[0].setSize(sf::Vector2f(10, 30));
    sliderHelper[0].setPosition(optionsSliders[0].getPosition().x + menuSoundLevel * 4.9,
                                optionsSliders[0].getPosition().y - 13);

    optionsSliders[1].setFillColor(sf::Color::White);
    optionsSliders[1].setSize(sf::Vector2f(500, 5));
    optionsSliders[1].setPosition(optionsTexts[1].getPosition().x + 400,
                                  optionsTexts[1].getPosition().y + 20);

    sliderHelper[1].setFillColor(sf::Color::Red);
    sliderHelper[1].setSize(sf::Vector2f(10, 30));
    sliderHelper[1].setPosition(optionsSliders[1].getPosition().x + battlefieldSoundLevel * 4.9,
                                optionsSliders[1].getPosition().y - 13);
}

void Options::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        saveAndExitButton.setOutlineColor(sf::Color::Black);
        optionsTexts[selectedItemIndex].setOutlineColor(sf::Color::Black);
        selectedItemIndex--;
        optionsTexts[selectedItemIndex].setOutlineColor(sf::Color::Red);
    }
}

void Options::moveDown()
{
    if (selectedItemIndex + 1 < NUMBER_OF_OPTIONS)
    {
        optionsTexts[selectedItemIndex].setOutlineColor(sf::Color::Black);
        selectedItemIndex++;
        if (selectedItemIndex == NUMBER_OF_OPTIONS - 1)
        {
            saveAndExitButton.setOutlineColor(sf::Color::Red);
        }
        else
        {
            optionsTexts[selectedItemIndex].setOutlineColor(sf::Color::Red);
        }
    }
}

void Options::toneUp()
{
    switch (selectedItemIndex)
    {
    case 0:
    {
        if (menuSoundLevel <= 90)
        {
            menuSoundLevel += 10;
            sliderHelper[0].setPosition(optionsSliders[0].getPosition().x + menuSoundLevel * 4.9,
                                        optionsSliders[0].getPosition().y - 13);
        }
        break;
    }
    case 1:
    {
        if (battlefieldSoundLevel <= 90)
        {
            battlefieldSoundLevel += 10;
            sliderHelper[1].setPosition(optionsSliders[1].getPosition().x + battlefieldSoundLevel * 4.9,
                                        optionsSliders[1].getPosition().y - 13);
        }
        break;
    }
    }
}

void Options::toneDown()
{
    switch (selectedItemIndex)
    {
    case 0:
    {
        if (menuSoundLevel > 9)
        {
            menuSoundLevel -= 10;
            sliderHelper[0].setPosition(optionsSliders[0].getPosition().x + menuSoundLevel * 4.9,
                                        optionsSliders[0].getPosition().y - 13);
        }
        break;
    }
    case 1:
    {
        if (battlefieldSoundLevel > 9)
        {
            battlefieldSoundLevel -= 10;
            sliderHelper[1].setPosition(optionsSliders[1].getPosition().x + battlefieldSoundLevel * 4.9,
                                        optionsSliders[1].getPosition().y - 13);
        }
        break;
    }
    }
}

float Options::getMenuSoundLevel()
{
    return this->menuSoundLevel;
}

float Options::getBattlefieldSoundLevel()
{
    return this->battlefieldSoundLevel;
}

Options::~Options(){};