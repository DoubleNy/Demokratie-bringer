#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL.h>
class Graphics;

//Clasa Game
class Game {
public: 
	Game();
	~Game();
private: 
	void gameLoop(bool quit, SDL_Event event);
	void draw(Graphics &graphcis);
	void update(float elapsedTime);
//	Sprite _player;
};

#endif // !GAME_H
