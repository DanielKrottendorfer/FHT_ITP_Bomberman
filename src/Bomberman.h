#include <vector>
#include <algorithm>

#include ".\engine\IGameLogic.h"
#include "objects/GameItem.h"

class Bomberman : public IGameLogic{

    public:

        Bomberman();
        void init();
        void input();
        void update();
        void render(sf::RenderWindow* window);
        virtual ~Bomberman();


    private:
        std::vector<GameItem> backGroundItems;
        std::vector<sf::Texture> backGroundTextures;
        std::vector<GameItem> gameItems;
};
