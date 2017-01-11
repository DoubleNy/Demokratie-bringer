#pragma once
#include <SFML/Graphics.hpp>


void attack( sf::RectangleShape &fire, sf::RectangleShape player, sf::RectangleShape enemy, int case0, int &timer);
void check(bool &st1, bool &st2, bool &st3, bool &st4, int &timer, int &eHealth, sf::RectangleShape &fire,
	sf::RectangleShape &enemy, sf::RenderWindow &window);

void make_explosion(sf::RenderWindow &window, sf::Sprite explosion[], int exp);