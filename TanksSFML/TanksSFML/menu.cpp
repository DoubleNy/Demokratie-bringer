#include "Menu.h"
#include <iostream>
#include <string>

Menu::Menu(float width, float height){
	if (!font.loadFromFile("governor.ttf")){
			std::cout << "O eroare cu fontul ... " << std::endl;
			std::cin.get();
			return;
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Play");
	menu[0].setCharacterSize(100);
	menu[0].setPosition(sf::Vector2f(width / 2 - 90, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setCharacterSize(100);
	menu[1].setPosition(sf::Vector2f(width / 2 - 160, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(100);
	menu[2].setPosition(sf::Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));



	play[0].setFont(font);
	play[0].setFillColor(sf::Color::Black);
	play[0].setString("Level I");
	play[0].setCharacterSize(100);
	play[0].setPosition(sf::Vector2f(325, 100));

	play[1].setFont(font);
	play[1].setFillColor(sf::Color::White);
	play[1].setString("Level II");
	play[1].setCharacterSize(100);
	play[1].setPosition(sf::Vector2f(310, 250));

	play[2].setFont(font);
	play[2].setFillColor(sf::Color::White);
	play[2].setString("Level III");
	play[2].setCharacterSize(100);
	play[2].setPosition(sf::Vector2f(295, 400));

	options[0].setFont(font);
	options[0].setFillColor(sf::Color::Black);
	options[0].setString("Choose Tank");
	options[0].setCharacterSize(100);
	options[0].setPosition(sf::Vector2f(200, 100));

	options[1].setFont(font);
	options[1].setFillColor(sf::Color::White);
	options[1].setString("Game Mode");
	options[1].setCharacterSize(100);
	options[1].setPosition(sf::Vector2f(200, 250));

	options[2].setFont(font);
	options[2].setFillColor(sf::Color::White);
	options[2].setString("Back");
	options[2].setCharacterSize(100);
	options[2].setPosition(sf::Vector2f(360, 400));

	mode[0].setFont(font);
	mode[0].setFillColor(sf::Color::Black);
	mode[0].setString("Multiplayer");
	mode[0].setCharacterSize(100);
	mode[0].setPosition(sf::Vector2f(200, 100));

	mode[1].setFont(font);
	mode[1].setFillColor(sf::Color::White);
	mode[1].setString("Single");
	mode[1].setCharacterSize(100);
	mode[1].setPosition(sf::Vector2f(300, 250));

	mode[2].setFont(font);
	mode[2].setFillColor(sf::Color::White);
	mode[2].setString("Back");
	mode[2].setCharacterSize(100);
	mode[2].setPosition(sf::Vector2f(350, 400));

	selectedItemIndex = 0;
	selectedItemIndex2 = 0;
	selectedItemIndex3 = 0;
	selectedItemIndex4 = 0;
}
Menu::~Menu(){
}
void Menu::draw(int nbr, sf::RenderWindow &window, int language){
	int width = window.getSize().x;
	int height = window.getSize().y;
	if (language == 0) {
		menu[0].setString(L"Joacă");
		menu[1].setString(L"Opțiuni");
		menu[2].setString(L"Ieșire");
		menu[0].setPosition(sf::Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		menu[1].setPosition(sf::Vector2f(width / 2 - 160, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		menu[2].setPosition(sf::Vector2f(width / 2 - 110, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		play[0].setString(L"Nivelul I");
		play[1].setString(L"Nivelul II");
		play[2].setString(L"Nivelul III");
		//
		options[0].setString(L"Alege Tankul");
		options[1].setString(L"Alege modul");
		options[2].setString(L"Înapoi");
		options[0].setPosition(sf::Vector2f(width / 2 - 270, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		options[1].setPosition(sf::Vector2f(width / 2 - 250, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		options[2].setPosition(sf::Vector2f(width / 2 - 110, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		mode[0].setString(L"Cu un prieten");
		mode[1].setString(L"Singur");
		mode[2].setString(L"Înapoi");
		mode[0].setPosition(sf::Vector2f(width / 2 - 270, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		mode[1].setPosition(sf::Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		mode[2].setPosition(sf::Vector2f(width / 2 - 110, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
	}
	if (language == 1) {
		menu[0].setString(L"Играть");
		menu[1].setString(L"Настройки");
		menu[2].setString(L"Выити");
		menu[0].setPosition(sf::Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		menu[1].setPosition(sf::Vector2f(width / 2 - 200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		menu[2].setPosition(sf::Vector2f(width / 2 - 110, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		play[0].setString(L"Уровень I");
		play[1].setString(L"Уровень II");
		play[2].setString(L"Уровень III");
		play[0].setPosition(sf::Vector2f(width / 2 - 190, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		play[1].setPosition(sf::Vector2f(width / 2 - 200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		play[2].setPosition(sf::Vector2f(width / 2 - 190, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		options[0].setString(L"Выбрать танк");
		options[1].setString(L"Выбрать режим");
		options[2].setString(L"Назад");
		options[0].setPosition(sf::Vector2f(width / 2 - 300, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		options[1].setPosition(sf::Vector2f(width / 2 - 350, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		options[2].setPosition(sf::Vector2f(width / 2 - 120, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		mode[0].setString(L"С другом");
		mode[1].setString(L"Одиночка");
		mode[2].setString(L"Назад");
		mode[0].setPosition(sf::Vector2f(width / 2 - 170, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		mode[1].setPosition(sf::Vector2f(width / 2 - 200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		mode[2].setPosition(sf::Vector2f(width / 2 - 130, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
}
	if (language == 2) {
		menu[0].setString(L"Play");
		menu[1].setString(L"Options");
		menu[2].setString(L"Exit");
		menu[0].setPosition(sf::Vector2f(width / 2 - 90, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 - 80));
		menu[1].setPosition(sf::Vector2f(width / 2 - 160, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 80));
		menu[2].setPosition(sf::Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 - 80));
		//
		play[0].setString(L"Level I");
		play[1].setString(L"Level II");
		play[2].setString(L"Level III");
		play[0].setPosition(sf::Vector2f(325, 100));
		play[1].setPosition(sf::Vector2f(310, 250));
		play[2].setPosition(sf::Vector2f(295, 400));
		//
		options[0].setString(L"Choose Tank");
		options[1].setString(L"Game Mode");
		options[2].setString(L"Back");
		options[0].setPosition(sf::Vector2f(200, 100));
		options[1].setPosition(sf::Vector2f(200, 250));
		options[2].setPosition(sf::Vector2f(360, 400));
		//
		mode[0].setString(L"Multiplayer");
		mode[1].setString(L"Single");
		mode[2].setString(L"Back");
		mode[0].setPosition(sf::Vector2f(200, 100));
		mode[1].setPosition(sf::Vector2f(300, 250));
		mode[2].setPosition(sf::Vector2f(350, 400));
	}
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		if (nbr == 0)
			window.draw(menu[i]);
		if(nbr == 1)
			window.draw(play[i]);
		if (nbr == 2)
			window.draw(options[i]);
		if(nbr == 3)
			window.draw(mode[i]);
	}
}

void Menu::MoveUp(int nbr){
	if(nbr == 0)
	if (selectedItemIndex - 1 >= 0){
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
	if(nbr == 1){
		if (selectedItemIndex2 - 1 >= 0) {
			play[selectedItemIndex2].setFillColor(sf::Color::White);
			selectedItemIndex2--;
			play[selectedItemIndex2].setFillColor(sf::Color::Black);
		}
	}
	if (nbr == 2) {
		if (selectedItemIndex3 - 1 >= 0) {
			options[selectedItemIndex3].setFillColor(sf::Color::White);
			selectedItemIndex3--;
			options[selectedItemIndex3].setFillColor(sf::Color::Black);
		}
	}
	if (nbr == 3) {
		if (selectedItemIndex4 - 1 >= 0) {
			mode[selectedItemIndex4].setFillColor(sf::Color::White);
			selectedItemIndex4--;
			mode[selectedItemIndex4].setFillColor(sf::Color::Black);
		}
	}
}

void Menu::MoveDown(int nbr){
	if(nbr == 0)
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
	if(nbr == 1){
		if (selectedItemIndex2 + 1 < MAX_NUMBER_OF_ITEMS) {
			play[selectedItemIndex2].setFillColor(sf::Color::White);
			selectedItemIndex2++;
			play[selectedItemIndex2].setFillColor(sf::Color::Black);
		}
	}
	if (nbr == 2) {
		if (selectedItemIndex3 + 1 < MAX_NUMBER_OF_ITEMS) {
			options[selectedItemIndex3].setFillColor(sf::Color::White);
			selectedItemIndex3++;
			options[selectedItemIndex3].setFillColor(sf::Color::Black);
		}
	}
	if (nbr == 3) {
		if (selectedItemIndex4 + 1 < MAX_NUMBER_OF_ITEMS) {
			mode[selectedItemIndex4].setFillColor(sf::Color::White);
			selectedItemIndex4++;
			mode[selectedItemIndex4].setFillColor(sf::Color::Black);
		}
	}
}