#include <SFML/Graphics.hpp>
#include <string.h>
#include "../GameItem.h"

#ifndef SRC_OBJECTS_PLAYER_PLAYER_H_
#define SRC_OBJECTS_PLAYER_PLAYER_H_

class Player
{
	public:
		bool spaceIsPressed =false;

		Player ();
		Player (std::string texurePath, int x, int y);
		Player (sf::Texture& texture, int x, int y);
		virtual ~Player ();

		sf::Sprite sprite;

		sf::Sprite getSprite(); 

		void movePlayer (std::string);
};

#endif /* SRC_OBJECTS_PLAYER_PLAYER_H_ */
