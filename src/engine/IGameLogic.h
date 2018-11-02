#include <SFML/Graphics.hpp>

#ifndef CONTROLLER_H
#define CONTROLLER_H
class IGameLogic {
    public:
        virtual void init() = 0;
        virtual void input() = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderWindow* window) = 0;
};
#endif