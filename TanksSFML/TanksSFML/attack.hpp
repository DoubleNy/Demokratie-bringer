#pragma once
#include <SFML/Graphics.hpp>


void attack( sf::RectangleShape &fire, sf::RectangleShape player, sf::RectangleShape enemy, int case0);
void check(bool &st1, bool &st2, bool &st3, bool &st4, int &eHealth, sf::RectangleShape &fire,
	sf::RectangleShape &enemy, sf::RenderWindow &window);