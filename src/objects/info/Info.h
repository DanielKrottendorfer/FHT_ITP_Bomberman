#include <SFML/Graphics.hpp>
#include <iostream>

class Info
{
public:
  Info();
  ~Info();
  void draw(sf::RenderWindow *window);
  void reset();
  void setNumberOfPlayers(int* numOfP);

private:
  sf::Font font;
  sf::Text gameInfos[3];
  sf::Clock clock;
  int mins = 0;
  int* numberOfPlayers = 0;
};
