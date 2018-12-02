#include <SFML/Graphics.hpp>

#ifndef SRC_OBJECTS_BOMBS_BOMB_H
#define SRC_OBJECTS_BOMBS_BOMB_H

class Bomb
{
    public:
        Bomb(); 
        Bomb(sf::Texture&, float x,float y); 
        ~Bomb(); 

		void ignite();
		bool explodes();


		sf::Sprite getSprite() const; 

    private:

		float fuse = 1500;
        sf::Sprite sprite; 

		sf::Clock* timer;
		
};

#endif /*  SRC_OBJECTS_BOMBS_BOMB_H */