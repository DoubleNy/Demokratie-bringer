
#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(int nbr, sf::RenderWindow &window, int language);
	void MoveUp(int);
	void MoveDown(int);
	int GetPressedItem() { return selectedItemIndex; }
	int GetPressedItem2() { return selectedItemIndex2; }
	int GetPressedItem3() { return selectedItemIndex3; }

public:
	int selectedItemIndex;
	int selectedItemIndex2;
	int selectedItemIndex3;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text play[MAX_NUMBER_OF_ITEMS];
	sf::Text options[MAX_NUMBER_OF_ITEMS];

};