#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();

        void draw (sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getPressedItem() {return selectedItemIndex;}
        
        void setMusic();
        void battleMusic();
        void menuMusic();
        sf::Music menMusic;
        sf::Music battlMusic;

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Texture menuBackgroundTexture;
        sf::Sprite menuBackgroundSprite;
};
