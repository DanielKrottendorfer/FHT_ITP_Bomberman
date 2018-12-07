#include <SFML/Graphics.hpp>

#ifndef SRC_OBJECTS_BOMBS_Explosion_H
#define SRC_OBJECTS_BOMBS_Explosion_H

class Explosion
{
  public:
    Explosion();
    Explosion(sf::Texture &, float x, float y, char dir, int pow);
    ~Explosion();

    sf::Sprite getSprite() const;

    bool doesSpread();
    bool doesExtinguish();

    int getPower();
    char getDirection();

  private:
    int timeToSpread = 100;
    int timeToExtinguish = 300;

    int power = 0;
    char direction = 'n';

    bool didSpread = false;


    sf::Sprite sprite;

    sf::Clock *timer;
};

#endif /*  SRC_OBJECTS_BOMBS_Explosion_H */
