#include "AI.hpp"
#include <math.h>
#include <iostream>
#include "objects.hpp"
int distance(int x1,int y1, int x2, int y2) {
		return sqrt(  ( (x1 - x2) * (x1 - x2)  ) + ( (y1 - y2) * (y1 - y2) )  );
}
int next(int ex, int ey, int px, int py,  int &angle,  sf::RectangleShape &enemy) {
	std::cout << px << ' ' << py << ' ' << ex << ' ' << ey << std::endl;
	if ((py >= ey - 20 && py <= ey + 20) ){
		return(0);
	}
	if (px >= ex - 20 && px <= ex + 20) {
		if(py > ey)
			enemy.setRotation(0), angle = 0;
		else
			enemy.setRotation(180), angle = 180;
			return(0);
	}
	if (px < ex && py < ey && ex > firstRight && ey > firstDown + 100)
		return(1);
	if (px < ex && py > ey) {
		return(2);
		//enemy.rotate(180);
	}
	if (px < ex && enemy.getPosition().x > 40)
		return(3);
	if(px > ex && enemy.getPosition().x < 800)
		return(4);
	return(-1);
}