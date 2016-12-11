#include "MainWindow.h"
#include "Game.h"
#include <iostream>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::Draw(int posx, int posy) {
	gfx.PutPixel(posx, posy, 250, 250, 0);
	gfx.PutPixel(posx, posy + 1, 250, 250, 0);
	gfx.PutPixel(posx, posy + 2, 250, 250, 0);
	gfx.PutPixel(posx - 4, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx - 3, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx - 2, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx + 2, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx + 3, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx + 4, posy + 5, 250, 250, 0);
	gfx.PutPixel(posx, posy + 8, 250, 250, 0);
	gfx.PutPixel(posx, posy + 9, 250, 250, 0);
	gfx.PutPixel(posx, posy + 10, 250, 250, 0);
}
void Game::ComposeFrame()
{
	//if (condition) {
	bool up = 0, down = 0, left = 0, right = 0;
	//int posx, posy = 400;
	Draw(posx, posy);
	//while (true) {
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			posy -= 40;
			if (posy < 11)
				posy = 589;
			Draw(posx, posy);
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			posy += 20;
			if (posy > 589)
				posy = 11;
			Draw(posx, posy);
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			posx -= 20;
			if (posx < 5)
				posx = 794;
			Draw(posx, posy);
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			posx += 20;
			if (posx > 794)
				posx = 5;
			Draw(posx, posy);
		}
	//    	std::cin.get();
//	}
}
