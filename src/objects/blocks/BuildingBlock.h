#ifndef SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_
#define SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_

class BuildingBlock
{
	public:
		static const int OBJECT_WIDTH_PX = 64;
		static const int OBJECT_HEIGHT_PX = 64;

		BuildingBlock ();
		virtual ~BuildingBlock ();

	private:
		bool isDestructible;
};

#endif /* SRC_OBJECTS_BLOCKS_BUILDINGBLOCK_H_ */
