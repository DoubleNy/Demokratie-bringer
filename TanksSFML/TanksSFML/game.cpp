#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.cpp"
#include <time.h>
#include "maps.h"
#include "keyboard.h"
#include "objects.hpp"

void game() {

	// Creare fereastra de joc, dimensiune 924 x 704
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");
	// Creare jucator
	sf::RectangleShape player(sf::Vector2f(80.0f, 65.0f));
	// Creare dusman
	sf::RectangleShape enemy(sf::Vector2f(80.0f, 65.0f));
	//Pozitie de start pentru jucator
	player.setPosition(-8.0, 0.0);
	//Pozitie de start pentru dusman
	enemy.setPosition(860, 600);
	sf::Texture texture;
	texture.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	sf::Texture texture2;
	texture2.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	int x = 0, a = 79, b = 63;
	int x0 = 70;
	//directia dusmanului ,  -1 = nord, 1 = sud
	int change = -1;
	player.setTexture(&texture);
	enemy.setTexture(&texture2);
	// Daca harta are probleme, e eroare.
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 29, 22)) {
		std::cout << "Un fel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	//
	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//
	sf::Clock clock;
	sf::Time time;
	window.setFramerateLimit(30);
	//Loop-ul principal;
	
	while (window.isOpen()) {
		//eveniment pentru inchiderea ferestrei
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else
				if (KeyEsc())
					window.close();
		}	
			if (KeyUp()) {
				x = 68;	a = 79; b = 63; // niste numere calculate cu precizie pentru a decupa partea necesara a tankului din poza cu ... tankuri . (?)
				//Daca pe axa y ne aflam intr-o pozitie cu y > 0 , continuam sa ne deplasam spre origine, altfel nu.
				if (player.getPosition().y < 0 || obstacleUp(player.getPosition().x, player.getPosition().y))
					player.move(0, 0);
				else
					player.move(0.0, -10.0);
			}
			else
				if (KeyDown()) {
					x = 0;	a = 79; b = 63; // aceleasi numere;
					//Daca pe axa y ne afla intr-o pozitie cu y < window.Size().y , continuam sa ne deplasam spre margine, altfel nu.
					if (player.getPosition().y > window.getSize().y - 70 || obstacleDown(player.getPosition().x, player.getPosition().y))
						player.move(0, 0);
					else
						player.move(0.0, 10.0);
				}
				else
					if (KeyLeft()) {
						x = 3 * 69.4; a = 78; b = 62;
						//Daca pe axa x ne aflam intr-o pozitie cu x > 0 ...sau nu intilnim un obstacol , continuam sa ne deplasam spre origine, altfel nu.
						if (player.getPosition().x < 0 || obstacleRight(player.getPosition().x, player.getPosition().y))
							player.move(0, 0);
						else
							player.move(-10.0, 0.0);
					}
					else
						if (KeyRight()) {
							x = 2 * 68; a = 79; b = 63;
							//Daca pe axa x ne aflam intr-o pozitie cu x < window.getSize().x ...sau nu intilnim un obstacol , continuam sa ne deplasam spre margine, altfel nu.
							if ((player.getPosition().x >= window.getSize().x - 70) || obstacleLeft(player.getPosition().x, player.getPosition().y))
								player.move(0, 0);
							else
								player.move(10.0, 0.0);
						}

			//Coordonare cu primul dusman in map1
			//Daca se paleste de perete, se intoarce 
			if (!intersect(player.getPosition().x, player.getPosition().y, 25, enemy.getPosition().x, enemy.getPosition().y, 25)) {
				if (change == -1 && enemy.getPosition().y - 10 > 0) {
					enemy.move(0.0, -10.0);
					x0 = 70;
				}
				else change = 1;
				if (change == 1 && enemy.getPosition().y + 50 < window.getSize().y) {
					enemy.move(0.0, 10.0);
					x0 = 0;
				}
				else change = -1;
			}
		//<---------------------------------------------
		//Decupam bucatile necesare de tank
		player.setTextureRect(sf::IntRect(x, 0, a, b));
		enemy.setTextureRect(sf::IntRect(x0, 0, 78, 63));
		//curatim fereastra
		window.clear();
		//std::cout << player.getPosition().x << std::endl;
		//Desenam harta
		window.draw(map);
		//Desenam jucatorul
		window.draw(enemy);
		//Desenam dusmanul
		window.draw(player);
		//Ii afisam pe toti
		window.display();
		//std::cout << player.getSize().x << ' ' << player.getSize().y << ' ' << std::endl << enemy.getSize().x << ' ' << enemy.getSize().y << std::endl;
		//if (intersect(player.getPosition().x, player.getPosition().y, 70, enemy.getPosition().x, enemy.getPosition().y, 70))
		//	std::cout << "YES" << std::endl;
		//
		/*
		
			time = clock.getElapsedTime();
			std::cout << 1.0f / time.asSeconds() << std::endl;
			clock.restart().asSeconds();
		// 
			*/
	}
}
