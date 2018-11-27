#include <vector>
#include <SFML/Graphics.hpp>
#include "../blocks/BuildingBlock.h"
#include "../player/Player.h"
#include "../bombs/Bomb.h"

#ifndef SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_
#define SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_

class BattleField
{
	private:
		std::vector<BuildingBlock> battlefieldBlocks;
		std::vector<sf::Texture*> battleFieldTextures;
		std::vector<Bomb*> battlefieldBombs;

		void createBattleField ();
		void createFrameBlocks ();
		void createIndestructibleFieldBlocks ();
		void generateDestructibleFieldBlocks ();
		bool isPositionAvailable (int, int);
		bool checkRedCorners (int, int);
		bool checkOverlapping (std::string, float, float);

		sf::Vector2f getRasterPoint(sf::Vector2f v);

	public:
		static const int NUMBER_OF_HORIZONTAL_BLOCKS = 15;
		static const int NUMBER_OF_VERTICAL_BLOCKS = 11;
		static const int NUMBER_OF_BLOCKS_TO_DESTROY = 50;
		static const int BLOCK_SIZE = 64;

		std::vector<Player> battlefieldPlayers;

		BattleField ();
		virtual ~BattleField ();
		void draw (sf::RenderWindow *window);
		void generatePlayer ();
		void procedeMove (Player*);
		void checkForExplosion();
		void addBomb(sf::Vector2f v);
};

#endif /* SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_ */
