#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#ifndef SRC_OBJECTS_MENU_OPTIONS_H_
#define SRC_OBJECTS_MENU_OPTIONS_H_

#define NUMBER_OF_OPTIONS 3
#define NUMBER_OF_SLIDERS 2

class Options
{
private:
  void draw();
  void displayText();
  void displaySliders();
  void displayButtons();

  void moveUp();
  void moveDown();
  void toneUp();
  void toneDown();

  int selectedItemIndex = 0;
  float menuSoundLevel = 100;
  float battlefieldSoundLevel = 100;

  sf::Texture optionsBackgroundTexture;
  sf::Sprite optionsBackgroundSprite;
  sf::Text optionsTexts[NUMBER_OF_OPTIONS];
  sf::RectangleShape optionsSliders[NUMBER_OF_SLIDERS];
  sf::RectangleShape sliderHelper[NUMBER_OF_SLIDERS];
  sf::RectangleShape saveAndExitButton;

public:
  Options(sf::RenderWindow *, float, float);
  virtual ~Options();
  void displayOptions();

  float getMenuSoundLevel();
  float getBattlefieldSoundLevel();

  bool isSaved = false;

  sf::RenderWindow *optionsWindow;
  sf::Font font;
};

#endif