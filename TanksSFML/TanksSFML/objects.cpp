#include "objects.hpp"
#include <iostream>
#include <math.h>
const int firstLeft = 276;
const int firstDown = 276;
const int secondLeft = 450;
const int secondUp = 430;
bool obstacleLeft(int x, int y){
	if (x >= firstLeft &&  x <= firstLeft + 20 && y <= firstDown)
		return(1);
	if (x >= secondLeft && x <= secondLeft + 20 && y > secondUp)
		return(1);
	return(0);
}
const int firstRight = 420; 
const int secondRight = 620;
bool obstacleRight(int x, int y) {
	if (x <= firstRight && x >= firstRight - 20 && y <= firstDown)
		return(1);
	if (x <= secondRight  && x >= secondRight - 20 && y >= secondUp)
		return(1);
	return(0);
}
bool obstacleUp(int x, int y) {
	if (x >= firstLeft + 10 && x <= firstLeft + 100 && y <= firstDown + 60)
		return(1);
	return(0);
}
bool obstacleDown(int x, int y) {
	if (x >= secondLeft + 10 && x <= secondLeft + 100 && y > secondUp)
		return (1);
	return(0);
}
bool intersect(int x0, int y0, int r0, int x1, int y1, int r1) {
	if(sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) <= r0 + r1)
		return(1);
	return(0);
}