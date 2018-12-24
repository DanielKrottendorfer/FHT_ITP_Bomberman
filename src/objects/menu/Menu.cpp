#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("res/fonts/reem.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }

    menuBackgroundTexture.loadFromFile("res/MenuBackground.png");
    menuBackgroundSprite.setTexture(menuBackgroundTexture);

    menu[0].setFont(font);
    menu[0].setCharacterSize(64);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    sf::FloatRect textRect = menu[0].getLocalBounds();
    menu[0].setOrigin(textRect.left + textRect.width / 2.0f,
                      textRect.top + textRect.height / 2.0f);
    menu[0].setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 64));
    menu[0].setOutlineColor(sf::Color::Black);
    menu[0].setOutlineThickness(2.0);

    menu[1].setFont(font);
    menu[1].setCharacterSize(64);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    sf::FloatRect textRect1 = menu[1].getLocalBounds();
    menu[1].setOrigin(textRect1.left + textRect1.width / 2.0f,
                      textRect1.top + textRect1.height / 2.0f);
    menu[1].setPosition(sf::Vector2f(width / 2.0f, height / 2.0f + 32));
    menu[1].setOutlineColor(sf::Color::Black);
    menu[1].setOutlineThickness(2.0);

    menu[2].setFont(font);
    menu[2].setCharacterSize(64);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    sf::FloatRect textRect2 = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect2.left + textRect2.width / 2.0f,
                      textRect2.top + textRect2.height / 2.0f);
    menu[2].setPosition(sf::Vector2f(width / 2.0f, height / 2.0f + 128));
    menu[2].setOutlineColor(sf::Color::Black);
    menu[2].setOutlineThickness(2.0);

    selectedItemIndex = 0;
}

//setmusic damit die Lieder gesetzt werden
void Menu::setMusic()
{
    menMusic.openFromFile("res\\sound\\Komiku_menu.ogg");
    battlMusic.openFromFile("res\\sound\\Komiku_Battle.ogg");
}
//menumusic und battlemusic damit diese funktionen in der main ausgeführt werden können
void Menu::menuMusic()
{
    battlMusic.stop();
    menMusic.play();
    menMusic.setLoop(true);
}

void Menu::battleMusic()
{
    menMusic.stop();
    battlMusic.play();
    battlMusic.setLoop(true);
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(menuBackgroundSprite);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }

    if (isPopupCreated)
    {
        window.draw(popupNewGame->drawFrame());
        window.draw(popupNewGame->drawDialogTitle());
        sf::RectangleShape *buttons = popupNewGame->drawButtons();
        for (int i = 0; i < popupNewGame->POPUP_DIALOG_BUTTONS_NUM; i++)
        {
            window.draw(buttons[i]);
        }
        sf::Text *buttonsText = popupNewGame->drawButtonsText();
        for (int i = 0; i < popupNewGame->POPUP_DIALOG_BUTTONS_NUM; i++)
        {
            window.draw(buttonsText[i]);
        }
    }
}

void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::startGame(sf::RenderWindow *menuWindow, int numberOfPlayers)
{
    if (!isPopupCreated && numberOfPlayers == -1)
    {
        sf::Vector2f size;
        size.x = 350;
        size.y = 450;
        popupNewGame = new Dialog(size, sf::Vector2f(menuWindow->getSize().x / 2 - size.x / 2,
                                                     menuWindow->getSize().y / 2 - size.y / 2));
        isPopupCreated = true;
        hasMenuFocus = false;
    }
    else if (!isPopupCreated && numberOfPlayers >= 0)
    {
        std::cout << "Play button pressed" << std::endl;
        std::cout << "gameLogic" << std::endl;
        battleMusic();
        IGameLogic *gameLogic = new Bomberman();
        std::cout << "gameEngine" << std::endl;
        GameEngine *gameEng = new GameEngine(menuWindow, gameLogic);
        std::cout << "start" << std::endl;
        gameEng->start();
        std::cout << "end" << std::endl;
        menuMusic();
    }
}

void Menu::handleEventListener(sf::Event event, sf::RenderWindow *menuWindow)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            if (hasMenuFocus)
            {
                moveUp();
            }
            else
            {
                popupNewGame->moveUp();
            }
            break;
        case sf::Keyboard::Down:
            if (hasMenuFocus)
            {
                moveDown();
            }
            else
            {
                popupNewGame->moveDown();
            }
            break;
        case sf::Keyboard::Enter:
            switch (getPressedItem())
            {
            case 0: // Play
            {
                if (isPopupCreated)
                {
                    switch (popupNewGame->getSelectedIndex())
                    {
                    case 0: // one player game
                    {
                        delete popupNewGame;
                        isPopupCreated = false;
                        hasMenuFocus = true;
                        startGame(menuWindow, 0);
                        break;
                    }
                    case 1: // two players game
                    {
                        delete popupNewGame;
                        isPopupCreated = false;
                        hasMenuFocus = true;
                        startGame(menuWindow, 1);
                        break;
                    }
                    case 2: // three players game
                    {
                        delete popupNewGame;
                        isPopupCreated = false;
                        hasMenuFocus = true;
                        startGame(menuWindow, 2);
                        break;
                    }
                    case 3: // four players game
                    {
                        delete popupNewGame;
                        isPopupCreated = false;
                        hasMenuFocus = true;
                        startGame(menuWindow, 3);
                        break;
                    }
                    case 4: // close dialog
                    {
                        delete popupNewGame;
                        isPopupCreated = false;
                        hasMenuFocus = true;
                        break;
                    }
                    }
                }
                else
                {
                    startGame(menuWindow, -1);
                }
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

Menu::~Menu()
{
}
