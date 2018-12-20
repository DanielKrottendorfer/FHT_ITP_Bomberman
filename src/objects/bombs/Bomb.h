#include <SFML/Graphics.hpp>
#include "../player/Player.h"

#ifndef SRC_OBJECTS_BOMBS_BOMB_H
#define SRC_OBJECTS_BOMBS_BOMB_H

class Bomb
{
  public:
    Bomb();
    Bomb(sf::Texture &, float x, float y, int pow, Player &);
    ~Bomb();

    void ignite();
    bool explodes();

    sf::Sprite getSprite() const;
    int power = 0;

    Player* getOwner();
    

  private:
    float fuse = 1500;
    sf::Sprite sprite;

    Player *owner;

    sf::Clock *timer;
};

#endif /*  SRC_OBJECTS_BOMBS_BOMB_H */
