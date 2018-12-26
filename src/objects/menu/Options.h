#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#ifndef SRC_OBJECTS_MENU_OPTIONS_H_
#define SRC_OBJECTS_MENU_OPTIONS_H_

class Options
{
  private:
    void draw ();
    sf::Texture optionsBackgroundTexture;
    sf::Sprite optionsBackgroundSprite;
  public:
    Options(sf::RenderWindow *);
    virtual ~Options();
    void displayOptions();
    sf::RenderWindow *optionsWindow;
};

#endif