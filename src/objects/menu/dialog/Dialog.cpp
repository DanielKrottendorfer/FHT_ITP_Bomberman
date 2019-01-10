#include "Dialog.h"

Dialog::Dialog(sf::Vector2f size, sf::Vector2f position)
{
	// Dialog for startgame popup
	if (!font.loadFromFile("res/fonts/reem.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
	createFrame(size, position);
	createButtons(size, position);
	createTitle(size, position);
	createButtonsText(size, position);
	std::cout << "Created new dialog" << std::endl;
}

/**
 *	Dialog for end game (phase before return to main menu) 
 */
Dialog::Dialog(sf::Vector2f position)
{
	if (!font.loadFromFile("res/fonts/reem.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
	createFrame(sf::Vector2f(370, 140), position);

	endGameDialog.setFont(font);
	endGameDialog.setString("\t\t\t\t\t\tGame over!\nPress SPACE for Main Menu");
	endGameDialog.setFillColor(sf::Color::White);
	endGameDialog.setCharacterSize(28);
	sf::FloatRect textRect1 = endGameDialog.getLocalBounds();
	endGameDialog.setOrigin(textRect1.left + textRect1.width / 2.0f,
							 textRect1.top + textRect1.height / 2.0f);
	endGameDialog.setPosition(position.x + 370 / 2, position.y + 70);

	isOnceCreated = true;
	std::cout << "Created new dialog" << std::endl;
}

void Dialog::createFrame(sf::Vector2f size, sf::Vector2f position)
{
	dialogFrame.setSize(size);
	dialogFrame.setOutlineColor(sf::Color::Red);
	dialogFrame.setFillColor(sf::Color::Black);
	dialogFrame.setOutlineThickness(3);
	dialogFrame.setPosition(position);
}

void Dialog::createButtons(sf::Vector2f size, sf::Vector2f position)
{
	sf::Vector2f startPosition(position.x + 25, position.y + 75);
	sf::Color bgColor(219, 219, 219);
	dialogButtons[0].setSize(sf::Vector2f(size.x - 50, 50));
	dialogButtons[0].setPosition(startPosition);
	dialogButtons[0].setFillColor(bgColor);
	dialogButtons[0].setOutlineColor(sf::Color::Red);
	dialogButtons[0].setOutlineThickness(3);

	dialogButtons[1].setSize(sf::Vector2f(size.x - 50, 50));
	startPosition.y += 75;
	dialogButtons[1].setPosition(startPosition);
	dialogButtons[1].setFillColor(bgColor);
	dialogButtons[1].setOutlineColor(sf::Color::Black);
	dialogButtons[1].setOutlineThickness(3);

	dialogButtons[2].setSize(sf::Vector2f(size.x - 50, 50));
	startPosition.y += 75;
	dialogButtons[2].setPosition(startPosition);
	dialogButtons[2].setFillColor(bgColor);
	dialogButtons[2].setOutlineColor(sf::Color::Black);
	dialogButtons[2].setOutlineThickness(3);

	dialogButtons[3].setSize(sf::Vector2f(size.x - size.x / 2 - 50, 50));
	startPosition.y += 75;
	startPosition.x += size.x - size.x / 2;
	dialogButtons[3].setPosition(startPosition);
	dialogButtons[3].setFillColor(bgColor);
	dialogButtons[3].setOutlineColor(sf::Color::Black);
	dialogButtons[3].setOutlineThickness(3);
}

void Dialog::createTitle(sf::Vector2f size, sf::Vector2f position)
{
	dialogTitle.setFont(font);
	dialogTitle.setString("Choose game mode");
	dialogTitle.setFillColor(sf::Color::Red);
	dialogTitle.setCharacterSize(32);
	sf::FloatRect textRect = dialogTitle.getLocalBounds();
	dialogTitle.setOrigin(textRect.left + textRect.width / 2.0f,
						  textRect.top + textRect.height / 2.0f);
	dialogTitle.setPosition(position.x + size.x / 2, position.y + 35);
}

void Dialog::createButtonsText(sf::Vector2f size, sf::Vector2f position)
{
	buttonsText[0].setFont(font);
	buttonsText[0].setString("Two players");
	buttonsText[0].setFillColor(sf::Color::Black);
	buttonsText[0].setCharacterSize(28);
	sf::FloatRect textRect1 = buttonsText[0].getLocalBounds();
	buttonsText[0].setOrigin(textRect1.left + textRect1.width / 2.0f,
							 textRect1.top + textRect1.height / 2.0f);
	buttonsText[0].setPosition(position.x + size.x / 2, position.y + 100);

	buttonsText[1].setFont(font);
	buttonsText[1].setString("Three players");
	buttonsText[1].setFillColor(sf::Color::Black);
	buttonsText[1].setCharacterSize(28);
	sf::FloatRect textRect2 = buttonsText[1].getLocalBounds();
	buttonsText[1].setOrigin(textRect2.left + textRect2.width / 2.0f,
							 textRect2.top + textRect2.height / 2.0f);
	buttonsText[1].setPosition(position.x + size.x / 2, position.y + 175);

	buttonsText[2].setFont(font);
	buttonsText[2].setString("Four players");
	buttonsText[2].setFillColor(sf::Color::Black);
	buttonsText[2].setCharacterSize(28);
	sf::FloatRect textRect3 = buttonsText[2].getLocalBounds();
	buttonsText[2].setOrigin(textRect3.left + textRect3.width / 2.0f,
							 textRect3.top + textRect3.height / 2.0f);
	buttonsText[2].setPosition(position.x + size.x / 2, position.y + 250);

	buttonsText[3].setFont(font);
	buttonsText[3].setString("Cancel");
	buttonsText[3].setFillColor(sf::Color::Black);
	buttonsText[3].setCharacterSize(28);
	sf::FloatRect textRect4 = buttonsText[3].getLocalBounds();
	buttonsText[3].setOrigin(textRect4.left + textRect4.width / 2.0f,
							 textRect4.top + textRect4.height / 2.0f);
	buttonsText[3].setPosition(position.x + size.x / 2 + 85, position.y + 325);
}

sf::RectangleShape Dialog::drawFrame()
{
	return dialogFrame;
}

sf::RectangleShape *Dialog::drawButtons()
{
	return dialogButtons;
}

sf::Text Dialog::drawDialogTitle()
{
	return dialogTitle;
}

sf::Text *Dialog::drawButtonsText()
{
	return buttonsText;
}

void Dialog::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		dialogButtons[selectedItemIndex].setOutlineColor(sf::Color::Black);
		selectedItemIndex--;
		dialogButtons[selectedItemIndex].setOutlineColor(sf::Color::Red);
	}
}

void Dialog::moveDown()
{
	if (selectedItemIndex + 1 < POPUP_DIALOG_BUTTONS_NUM)
	{
		dialogButtons[selectedItemIndex].setOutlineColor(sf::Color::Black);
		selectedItemIndex++;
		dialogButtons[selectedItemIndex].setOutlineColor(sf::Color::Red);
	}
}

Dialog::~Dialog()
{
}
