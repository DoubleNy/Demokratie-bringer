#pragma once
#include <SFML/Graphics.hpp>


void attack(sf::RectangleShape &fire, sf::RectangleShape player, sf::RectangleShape enemy, int angle, int &timer, float &cx, float &cy, float dx, float dy);
void check(bool &st1, bool &st2, bool &st3, bool &st4, int &timer, int &eHealth, int &seHealth, sf::RectangleShape &fire,
	sf::RectangleShape &enemy, sf::RectangleShape &enemyTwo, sf::RenderWindow &window, float dx, float dy, int angle);

void make_explosion(sf::RenderWindow &window, sf::Sprite explosion[], int exp);