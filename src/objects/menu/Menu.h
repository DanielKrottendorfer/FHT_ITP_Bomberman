#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "..\..\engine\GameEngine.h"
#include "..\..\Bomberman.h"
#include "dialog\Dialog.h"
#include "Options.h"
#include "Help.h"

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
  Menu(float width, float height);
  ~Menu();

  void draw(sf::RenderWindow &window);
  void moveUp();
  void moveDown();
  int getPressedItem() { return selectedItemIndex; }

  void setMusic();
  void battleMusic();
  void menuMusic();
  void handleEventListener(sf::Event, sf::RenderWindow *);
  sf::Music menMusic;
  sf::Music battlMusic;

private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text menu[MAX_NUMBER_OF_ITEMS];
  sf::Texture menuBackgroundTexture;
  sf::Sprite menuBackgroundSprite;
  Dialog *popupNewGame;
  Options *menuOption;
  Help *menuHelp;
  bool isPopupCreated = false;
  bool hasMenuFocus = true;

  void startGame(sf::RenderWindow *menuWindow, int numberOfPlayers);
};
