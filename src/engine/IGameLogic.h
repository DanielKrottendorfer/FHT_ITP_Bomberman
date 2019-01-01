#include <SFML/Graphics.hpp>

#ifndef GAMELOGIC_H
#define GAMELOGIC_H
class IGameLogic {
    public:
        virtual void init() = 0;
        virtual void input() = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderWindow* window) = 0;
        bool running = true;
};
#endif