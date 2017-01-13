#include "objects.hpp"
#include <iostream>
#include <math.h>
#include "maps.h"

int firstLeft = 276;
int firstDown = 276;
int secondLeft = 450;
int secondUp = 430;
int xx, yy;
bool obstacleLeft(int x, int y){
	
	for (int i = 0; i < 22 * 29; i++)
	{

		if (level[i] == 120 || level[i] == 121 || level[i] == 136 || level[i] == 137 || level[i] == 70 || level[i] == 71 || level[i] == 55 || level[i] == 86 || level[i] == 87 || level[i] == 18 || level[i] == 19 || level[i] == 114 || level[i] == 115 || level[i] == 130 || level[i] == 131)
		{
			xx = i % 29*32;
			yy = i / 29*32;
			
		}
		if (x<xx&&y>yy&&y<yy + 40&&x+40>xx)
			return(1);
		
	}
	return 0;
}
 int firstRight = 420; 
 int secondRight = 620;
bool obstacleRight(int x, int y) {
	for (int i = 0; i < 22 * 29; i++)
	{

		if (level[i] == 120 || level[i] == 121 || level[i] == 136 || level[i] == 137 || level[i] == 70 || level[i] == 71 || level[i] == 55 || level[i] == 86 || level[i] == 87 || level[i] == 18 || level[i] == 19 || level[i] == 114 || level[i] == 115 || level[i] == 130 || level[i] == 131)
		{
			xx = i % 29 * 32;
			yy = i / 29 * 32;

		}
		if (x>xx+32&&y>yy&&y<yy + 40&&x-42<xx+32)
			return(1);

	}
	return 0;
}
bool obstacleUp(int x, int y) {
	for (int i = 0; i < 22 * 29; i++)
	{

		if (level[i] == 120 || level[i] == 121 || level[i] == 136 || level[i] == 137 || level[i] == 70 || level[i] == 71 || level[i] == 55 || level[i] == 86 || level[i] == 87 || level[i] == 18 || level[i] == 19 || level[i] == 114 || level[i] == 115 || level[i] == 130 || level[i] == 131)
		{
			xx = i % 29 * 32;
			yy = i / 29 * 32;

		}
		if (y<yy && x>xx&&x<xx + 40 && y+50>yy)
			return(1);

	}
	return 0;
}
bool obstacleDown(int x, int y) {
	for (int i = 0; i < 22 * 29; i++)
	{

		if (level[i] == 120 || level[i] == 121 || level[i] == 136 || level[i] == 137 || level[i] == 70 || level[i] == 71 || level[i] == 55 || level[i] == 86 || level[i] == 87 || level[i] == 18 || level[i] == 19 || level[i] == 114 || level[i] == 115 || level[i] == 130 || level[i] == 131)
		{
			xx = i % 29 * 32;
			yy = i / 29 * 32;

		}
		if (y>yy+32 && x>xx&&x<xx + 40 && y - 45<yy+32)
			return(1);

	}
	return 0;
}
bool intersect(int x0, int y0, int r0, int x1, int y1, int r1) {
	if(sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) <= r0 + r1)
		return(1);
	return(0);
}

void loadExplosion(sf::Sprite explosion[]) {

}

