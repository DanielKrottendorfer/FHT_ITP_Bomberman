#include <SFML/Graphics.hpp>
#include <string>

#ifndef GAMEITEM_H
#define GAMEITEM_H
class GameItem
{

	public:
		GameItem (std::string texurePath, int x, int y);

		sf::Texture* texture;
		sf::Sprite* sprite;

		int x = 0;
		int y = 0;
};
#endif
