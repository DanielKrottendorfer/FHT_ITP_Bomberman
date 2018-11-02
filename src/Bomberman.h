#include <vector>
#include <algorithm>

#include ".\obj\GameItem.h"
#include ".\engine\IGameLogic.h"

class Bomberman : public IGameLogic{

    public:

        Bomberman();
        void init();
        void input();
        void update();
        void render(sf::RenderWindow* window);
        ~Bomberman();


    private:
        std::vector<GameItem> gameItems;
        std::vector<sf::Texture> textures;
};