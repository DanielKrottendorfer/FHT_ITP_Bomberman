#include <SFML/Graphics.hpp>
#include <string.h>
#include "../GameItem.h"

#ifndef SRC_OBJECTS_PLAYER_PLAYER_H_
#define SRC_OBJECTS_PLAYER_PLAYER_H_

class Player
{
	public:
		bool spaceIsPressed = false;

		Player ();
		Player (std::string texurePath, int x, int y);
		Player (sf::Texture& texture, int x, int y);
		virtual ~Player ();

		sf::Sprite sprite;

		sf::Sprite getSprite ();

		void movePlayer (std::string, float, float);

		int bombPower = 2;

	private:
		bool isKeyPressed = false;
		int upwalk = 0;
		int downwalk = 0;
		int rightwalk = 0;
		int leftwalk = 0;

		sf::Texture player1TextureRight;
		sf::Texture player1TextureRightWalk;
		sf::Texture player1TextureFront;
		sf::Texture player1TextureFrontWalk;
		sf::Texture player1TextureLeft;
		sf::Texture player1TextureLeftWalk;
		sf::Texture player1TextureBehind;
		sf::Texture player1TextureBehindWalk;

		void goUp (float, float);
		void goLeft (float, float);
		void goDown (float, float);
		void goRight (float, float);
};

#endif /* SRC_OBJECTS_PLAYER_PLAYER_H_ */
