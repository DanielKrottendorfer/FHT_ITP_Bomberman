#include <SFML/Graphics.hpp>
#include "../GameItem.h"

#ifndef SRC_OBJECTS_PLAYER_PLAYER_H_
#define SRC_OBJECTS_PLAYER_PLAYER_H_

class Player
{
	private:
		void movePlayer (float, float);

	public:
		Player ();
		Player (std::string texurePath, int x, int y);
		Player (sf::Texture* texure, int x, int y);
		virtual ~Player ();

		sf::Texture* texture;
		sf::Sprite* sprite;

		void setEventType ();
};

#endif /* SRC_OBJECTS_PLAYER_PLAYER_H_ */
