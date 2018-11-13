#include <vector>
#include <SFML/Graphics.hpp>
#include "..\blocks\BuildingBlock.h"

#ifndef SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_
#define SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_

class BattleField
{
	private:
		std::vector<BuildingBlock> inDestructibleBlocks;
		std::vector<sf::Texture*> battleFieldTextures;
		void createBattleField ();
		void createFrameBlocks ();
		void createIndestructibleFieldBlocks ();
		void generateDestructibleFieldBlocks ();
		bool isPositionAvailable (int, int);
		bool checkRedCorners (int, int);

	public:
		static const int NUMBER_OF_HORIZONTAL_BLOCKS = 15;
		static const int NUMBER_OF_VERTICAL_BLOCKS = 11;
		static const int NUMBER_OF_BLOCKS_TO_DESTROY = 50;
		static const int BLOCK_SIZE = 64;

		BattleField ();
		virtual ~BattleField ();
		void draw (sf::RenderWindow *window);
};

#endif /* SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_ */
