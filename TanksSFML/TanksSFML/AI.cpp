#include "AI.hpp"
#include <math.h>
#include <iostream>

int distance(int x1,int y1, int x2, int y2) {
	return sqrt(  ( (x1 - x2) * (x1 - x2)  ) + ( (y1 - y2) * (y1 - y2) )  );
}

int next(int ex, int ey, int px, int py) {
	std::cout << px << ' ' << py << ' ' << ex << ' ' << ey << std::endl;
	int ans = rand() % 4 + 1;
	return(ans);
	/*
	//bug
	if (ans == 1)
		return("up");
	if (ans == 2)
		return("down");
	if (ans == 3)
		return("left");
	if (ans == 4)
		return("right");
	*/
}
