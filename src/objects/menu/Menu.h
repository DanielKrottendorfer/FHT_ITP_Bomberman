#include <SFML/Graphics.hpp>
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
    
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text title;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
