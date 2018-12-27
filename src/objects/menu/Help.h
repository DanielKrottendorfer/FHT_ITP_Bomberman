#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#ifndef SRC_OBJECTS_MENU_HELP_H_
#define SRC_OBJECTS_MENU_HELP_H_

class Help
{
private:
  void draw();
  sf::Texture helpBackgroundTexture;
  sf::Sprite helpBackgroundSprite;

public:
  Help(sf::RenderWindow *);
  virtual ~Help();
  void displayHelp();
  sf::RenderWindow *helpWindow;
};

#endif