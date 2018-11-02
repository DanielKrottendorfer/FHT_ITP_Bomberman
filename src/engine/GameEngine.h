#include <SFML/Graphics.hpp>
#include <string>
#include "IGameLogic.h"


class GameEngine {

    public:
        
        void start();
        void init();
        ~GameEngine();

        GameEngine(std::string windowTitle, int width, int height, IGameLogic* gameLogic);

    private:
        void input();
        void update();
        void render();

        void gameLoop();

        sf::RenderWindow* window;
        IGameLogic* gameLogic;

};