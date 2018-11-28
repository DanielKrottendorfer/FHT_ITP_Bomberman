#include <SFML/Graphics.hpp>
#include <string>
#include "IGameLogic.h"


class GameEngine {

    public:
        
        void start();
        void init();
        ~GameEngine();

        GameEngine(sf::RenderWindow* menuWindow, IGameLogic* gameLogic);

        
        const int UPS = 60;

    private:
        void input();
        void update();
        void render();

        void gameLoop();

        sf::RenderWindow* window;
        IGameLogic* gameLogic;

};