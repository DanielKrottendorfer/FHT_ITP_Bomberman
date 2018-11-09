#include <SFML/Graphics.hpp>

#ifndef SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_
#define SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_

class BuildingBlock
{
	private:
		sf::Texture* buildingBlockTexture;
		bool isDestructible; // for later ...

	public:
		static const int OBJECT_WIDTH_PX = 64;
		static const int OBJECT_HEIGHT_PX = 64;

		BuildingBlock (sf::Texture*, bool);
		virtual ~BuildingBlock ();

		sf::Texture getBuildingBlock ()
		{
			return *(this->buildingBlockTexture);
		}

		void setBuildingBlock (sf::Texture* buildingBlockTexture)
		{
			this->buildingBlockTexture = buildingBlockTexture;
		}

		bool getIsBuildingBlockDestructible ()
		{
			return this->isDestructible;
		}
};

#endif /* SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_ */