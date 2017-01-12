#pragma once
#include <SFML\Graphics.hpp>
bool obstacleLeft(int, int);
bool obstacleRight(int, int);
bool obstacleUp(int, int);
bool obstacleDown(int, int);
bool intersect(int, int, int, int, int, int);
void loadExplosion(sf::Sprite explosion[]);