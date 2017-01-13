#pragma once
#include <stdlib.h>  
//using namespace std;
#include <SFML\Graphics.hpp>

int distance(int x1, int y1, int x2, int y2);

int next(int ex, int ey, int px, int py,  int &angle, sf::RectangleShape &enemy);