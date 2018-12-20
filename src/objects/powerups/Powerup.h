#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SRC_OBJECTS_POWERUPS_POWERUP_H
#define SRC_OBJECTS_POWERUPS_POWERUP_H

class Powerup
{
  public:
    Powerup();
    Powerup(sf::Texture &, float x, float y, std::string t);
    ~Powerup();

    sf::Sprite getSprite() const;

    std::string getType();

  private:


    std::string type = "p2";

    sf::Sprite sprite;
    sf::Clock *timer;

};

#endif /*  SRC_OBJECTS_POWERUPS_POWERUP_H */
