#include <SFML/Graphics.hpp>

#ifndef SRC_OBJECTS_POWERUPS_POWERUP_H
#define SRC_OBJECTS_POWERUPS_POWERUP_H

class Powerup
{
  public:
    Powerup();
    Powerup(sf::Texture &, float x, float y, char t);
    ~Powerup();

    sf::Sprite getSprite() const;

  private:


    char type = 'p';

    sf::Sprite sprite;
    sf::Clock *timer;

};

#endif /*  SRC_OBJECTS_POWERUPS_POWERUP_H */
