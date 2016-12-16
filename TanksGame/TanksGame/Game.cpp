#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Graphics.h"
#include <algorithm>
//adaugam limita de FPS la joc; 
namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
//Constructorul pentru clasa Game;
SDL_Event event;
Game::Game() {
	bool quit = false;
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	gameLoop(quit,  event);
} 
//Destructorul pentru clasa Game;;
Game::~Game() {
	IMG_Quit();
	SDL_Quit();
}
//Clasa Game
void Game::gameLoop(bool quit, SDL_Event event) {
	SDL_Window * window = SDL_CreateWindow("Tanks",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 840, 680, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("tank.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
//	SDL_Rect srcrect = { 15, 15, 68, 60 };
	int cur = 70;
	int pos = 0;
	int x = 41, y = 41;
	SDL_Rect dstrect = { x, y, 70, 60 };

	while (!quit){
		Uint32 ticks = SDL_GetTicks();
		Uint32 seconds = ticks / 1000;
		Uint32 sprite = seconds % 4;
		//SDL_WaitEvent(&event);
			
		while (SDL_PollEvent(&event) != NULL)
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_UP: {
					y -= 10;
					pos = cur * 1;
					break;
				}
				case SDLK_DOWN: {
					y += 10;
					pos = cur * 0;
					break;
				}
				case SDLK_RIGHT: {
					x += 10;
					pos = cur * 2;
					break;
				}
					//case SDL_Scancode(SDLK_LEFT):
				case  SDLK_LEFT: {
					x -= 10;
					pos = cur * 3;
					break;
				}
				default:
					break;
				}
			}
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_Rect  srcrect = { pos, 0, 70, 60 };
		SDL_Rect dstrect = { x, y, 70, 64 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		//	SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
void Game::draw(Graphics &graphics) {
}
void Game::update(float elapsedTime) {
}
//
