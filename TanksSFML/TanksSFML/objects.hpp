#pragma once
#include <SFML\Graphics.hpp>
extern  int firstLeft ;
extern  int firstDown;
extern  int secondLeft;
extern  int secondUp;
extern int firstRight;
extern int secondRight;

bool obstacleLeft(int, int);
bool obstacleRight(int, int);
bool obstacleUp(int, int);
bool obstacleDown(int, int);
bool intersect(int, int, int, int, int, int);
void loadExplosion(sf::Sprite explosion[]);
