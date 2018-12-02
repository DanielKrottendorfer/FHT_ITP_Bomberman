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
		std::vector<Bomb> battlefieldBombs;

		void createBattleField ();
		void createFrameBlocks ();
		void createIndestructibleFieldBlocks ();
		void generateDestructibleFieldBlocks ();
		bool isPositionAvailable (int, int);
		bool checkRedCorners (int, int);
		bool checkOverlapping (std::string, float, float);
		bool isXAxisCollision (float, float);
		bool isYAxisCollision (float, float);

		sf::Vector2f getRasterPoint(sf::Vector2f v);


		sf::Texture tSideTexture;
		sf::Texture rSideTexture;
		sf::Texture lSideTexture;
		sf::Texture bSideTexture;

		sf::Texture tlCornerTexture;
		sf::Texture trCornerTexture;
		sf::Texture blCornerTexture;
		sf::Texture brCornerTexture;
		
		sf::Texture dBlockTexture;
		sf::Texture idBlockTexture;

		sf::Texture player1Texture;

		sf::Texture bombTexture;

	public:
		static const int NUMBER_OF_HORIZONTAL_BLOCKS = 15;
		static const int NUMBER_OF_VERTICAL_BLOCKS = 11;
		static const int NUMBER_OF_BLOCKS_TO_DESTROY = 50;
		static const int BLOCK_SIZE = 64;

		std::vector<Player> battlefieldPlayers;

		BattleField ();
		virtual ~BattleField ();
		void draw (sf::RenderWindow* window);
		void generatePlayer ();
		void procedeMove ();
		void checkForExplosion();
		void addBomb(sf::Vector2f v);
};

#endif /* SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_ */
