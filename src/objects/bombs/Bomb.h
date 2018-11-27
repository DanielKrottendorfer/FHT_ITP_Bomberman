#include <SFML/Graphics.hpp>

#ifndef SRC_OBJECTS_BOMBS_BOMB_H
#define SRC_OBJECTS_BOMBS_BOMB_H

class Bomb
{
	private:

        int fuse = 1500; //ms
        sf::Clock* timer;

	public:
		static const int OBJECT_WIDTH_PX = 64;
		static const int OBJECT_HEIGHT_PX = 64;

		Bomb (std::string texurePath, int x, int y);
		Bomb (sf::Texture *texure, int x, int y);
		virtual ~Bomb ();

        void ignite();
        bool explodes();


		sf::Texture* texture;
		sf::Sprite* sprite;
};

#endif /*  SRC_OBJECTS_BOMBS_BOMB_H */
