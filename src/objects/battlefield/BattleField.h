#include <vector>
#include <SFML/Graphics.hpp>
#include "../blocks/BuildingBlock.h"
#include "../player/Player.h"
#include "../bombs/Bomb.h"
#include "../bombs/Explosion.h"
#include "../powerups/Powerup.h"

#ifndef SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_
#define SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_

class BattleField
{
	private:
		std::vector<BuildingBlock> battlefieldBlocks;
		std::vector<Powerup> battlefieldPowerups;
		std::vector<Bomb> battlefieldBombs;
		std::vector<Explosion> battlefieldExplosions;

		void createBattleField ();
		void createFrameBlocks ();
		void createIndestructibleFieldBlocks ();
		void generateDestructibleFieldBlocks ();
		void distributePowerups();
		bool isPositionAvailable (int, int);
		bool checkRedCorners (int, int);
		bool checkObjectCollision (std::string, sf::Vector2f, float, float);
		bool checkBlockCollision (std::string, float, float);
		bool checkBombCollision (std::string, float, float);
		bool checkCollision (std::string, float, float);
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
		sf::Texture explosionTexture;
			
		sf::Texture explosionTextureCenter;
		sf::Texture explosionTextureHorizontal;
		sf::Texture explosionTextureVertical;
		
		sf::Texture explosionTextureLeft;
		sf::Texture explosionTextureRight;
		sf::Texture explosionTextureUp;
		sf::Texture explosionTextureDown;

		sf::Texture powerupTextureF1;
		sf::Texture powerupTextureF2;
		sf::Texture powerupTextureS1;
		sf::Texture powerupTextureS2;
		sf::Texture powerupTextureB1;
		sf::Texture powerupTextureB2;

	public:
		static const int NUMBER_OF_HORIZONTAL_BLOCKS = 15;
		static const int NUMBER_OF_VERTICAL_BLOCKS = 11;
		static const int NUMBER_OF_BLOCKS_TO_DESTROY = 50;
		static const int BLOCK_SIZE = 64;
		static const int POWERUP_COUNT = 20;

		std::vector<Player> battlefieldPlayers;

		BattleField ();
		virtual ~BattleField ();
		void draw (sf::RenderWindow* window);
		void generatePlayer ();
		void procedeMove ();
		void checkForExplosion();
		void checkForExplosionSpread();
		void checkForPlayerDeath();
		void addBomb(sf::Vector2f v, int power ,Player *p);
		void addExplosion(sf::Vector2f v, int power);
		void addPowerup(sf::Vector2f vb, std::string  poweerUp);
		void checkForExplosionExtinguish();
		void collectPowerups();
};

#endif /* SRC_OBJECTS_BATTLEFIELD_BATTLEFIELD_H_ */
