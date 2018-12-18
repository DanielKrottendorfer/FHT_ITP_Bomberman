#include "Info.h"
#include <sstream>

Info::Info()
{
  if (!font.loadFromFile("res/fonts/reem.ttf"))
  {
    std::cout << "Error loading font for Info" << std::endl;
  }

  //std::cout << seconds;

  gameInfos[0].setFont(font);
  gameInfos[0].setCharacterSize(42);
  gameInfos[0].setFillColor(sf::Color::White);
  gameInfos[0].setString("Bomberman++");
  gameInfos[0].setPosition(975, 40);

  gameInfos[1].setFont(font);
  gameInfos[1].setCharacterSize(32);
  gameInfos[1].setFillColor(sf::Color::White);
  gameInfos[1].setString("Players Alive:   1");
  gameInfos[1].setPosition(980, 120);

  gameInfos[2].setFont(font);
  gameInfos[2].setCharacterSize(32);
  gameInfos[2].setFillColor(sf::Color::White);
  gameInfos[2].setPosition(980, 152);
}

Info::~Info()
{
}

void Info::draw(sf::RenderWindow *window)
{

  sf::Time time = clock.getElapsedTime();
  float seconds = time.asSeconds();

  // rounding
  seconds = ((int)(seconds * 100 + .5) / 100.0);

  if (seconds > 59)
  {
    mins++;
    clock.restart();
  }

  // Convert float / int to string
  std::ostringstream ss;
  ss << seconds;
  std::string sss(ss.str());

  std::ostringstream minss;
  minss << mins;
  std::string minsss(minss.str());

  //std::cout << elapsedTime << std::endl;
  gameInfos[2].setString(minsss + " min " + sss + " sec");

  for (int i = 0; i < 3; i++)
  {
    window->draw(gameInfos[i]);
  }
}

void Info::reset()
{
  clock.restart();
}
