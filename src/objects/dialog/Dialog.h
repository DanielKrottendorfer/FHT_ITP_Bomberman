#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#ifndef SRC_OBJECTS_DIALOG_DIALOG_H_
#define SRC_OBJECTS_DIALOG_DIALOG_H_

#define POPUP_DIALOG_BUTTONS_NUMBER 5

class Dialog
{
public:
	Dialog(sf::Vector2f, sf::Vector2f);
	virtual ~Dialog();

	int const POPUP_DIALOG_BUTTONS_NUM = POPUP_DIALOG_BUTTONS_NUMBER;
	int selectedItemIndex = 0;

	sf::RectangleShape drawFrame();
	sf::RectangleShape *drawButtons();
	sf::Text drawDialogTitle();
	sf::Text *drawButtonsText();

	void moveUp();
	void moveDown();
	int getSelectedIndex() { return selectedItemIndex; }

private:
	sf::Font font;
	sf::RectangleShape dialogFrame;
	sf::RectangleShape dialogButtons[POPUP_DIALOG_BUTTONS_NUMBER];
	sf::Text dialogTitle;
	sf::Text buttonsText[POPUP_DIALOG_BUTTONS_NUMBER];

	void createFrame(sf::Vector2f size, sf::Vector2f position);
	void createButtons(sf::Vector2f size, sf::Vector2f position);
	void createTitle(sf::Vector2f size, sf::Vector2f position);
	void createButtonsText(sf::Vector2f size, sf::Vector2f position);
};

#endif /* SRC_OBJECTS_MENU_DIALOG_H_ */
