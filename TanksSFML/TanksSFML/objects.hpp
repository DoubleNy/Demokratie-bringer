#pragma once
#include <SFML\Graphics.hpp>
extern  int firstLeft ;
extern  int firstDown;
extern  int secondLeft;
extern  int secondUp;
extern int firstRight;
extern int secondRight;

bool obstacleLeft(int level[], int, int, int choosedMap);
bool obstacleRight(int level[], int, int, int choosedMap);
bool obstacleUp(int level[], int, int, int choosedMap);
bool obstacleDown(int level[], int, int, int choosedMap);
bool intersect(int, int, int, int, int, int);
void loadExplosion(sf::Sprite explosion[]);
