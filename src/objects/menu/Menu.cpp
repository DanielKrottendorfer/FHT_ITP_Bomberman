#include "Menu.h"

Menu::Menu(float width, float height)
{   
    if ( !font.loadFromFile ("res/fonts/reem.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}

    title.setFont(font);
    title.setCharacterSize(96);
    title.setFillColor(sf::Color::White);
    title.setString("Bomberman++");
    sf::FloatRect textRectTitle = title.getLocalBounds();
    title.setOrigin(textRectTitle.left + textRectTitle.width/2.0f,
    textRectTitle.top  + textRectTitle.height/2.0f);
    title.setPosition(sf::Vector2f(width/2.0f,height/2.0f - (32+2*96) ));

    menu[0].setFont(font);
    menu[0].setCharacterSize(64);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    sf::FloatRect textRect = menu[0].getLocalBounds();
    menu[0].setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top  + textRect.height/2.0f);
    menu[0].setPosition(sf::Vector2f(width/2.0f,height/2.0f - 64 ));

    menu[1].setFont(font);
    menu[1].setCharacterSize(64);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    sf::FloatRect textRect1 = menu[1].getLocalBounds();
    menu[1].setOrigin(textRect1.left + textRect1.width/2.0f,
    textRect1.top  + textRect1.height/2.0f);
    menu[1].setPosition(sf::Vector2f(width/2.0f,height/2.0f + 32));

    menu[2].setFont(font);
    menu[2].setCharacterSize(64);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    sf::FloatRect textRect2 = menu[2].getLocalBounds(); 
    menu[2].setOrigin(textRect2.left + textRect2.width/2.0f,
    textRect2.top  + textRect2.height/2.0f);
    menu[2].setPosition(sf::Vector2f(width/2.0f,height/2.0f + 128 )); 

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}
//setmusic damit die Lieder gesetzt werden
void Menu::setmusic()
{
    menmusic.openFromFile("res\\sound\\Komiku_menu.ogg");
    battlmusic.openFromFile("res\\sound\\Komiku_Battle.ogg");
}
//menumusic und battlemusic damit diese funktionen in der main ausgeführt werden können
void Menu::menumusic()
{
    battlmusic.stop();
    menmusic.play();
    menmusic.setLoop(true);
}

void Menu::battlemusic()
{
    menmusic.stop();
    battlmusic.play();
    battlmusic.setLoop(true);
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(title);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
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