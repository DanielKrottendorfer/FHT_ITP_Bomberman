#include <SFML/Graphics.hpp>
#include <string.h>
#include "../GameItem.h"

#ifndef SRC_OBJECTS_PLAYER_PLAYER_H_
#define SRC_OBJECTS_PLAYER_PLAYER_H_

class Player
{
	public:
		Player ();
		Player (std::string texurePath, int x, int y);
		Player (sf::Texture* texure, int x, int y);
		virtual ~Player ();

		sf::Texture* texture;
		sf::Sprite* sprite;

		void movePlayer (std::string);
};

#endif /* SRC_OBJECTS_PLAYER_PLAYER_H_ */
