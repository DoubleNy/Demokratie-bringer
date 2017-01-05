#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.cpp"
#include <time.h>
#include "maps.h"
#include "keyboard.h"
#include "objects.hpp"
#include "attack.hpp"

void game() {

	// Creare fereastra de joc, dimensiune 924 x 704 FINALLY?
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");
	// Creare jucator
	sf::RectangleShape player(sf::Vector2f(80.0f, 65.0f));
	// Creare dusman
	sf::RectangleShape enemy(sf::Vector2f(80.0f, 65.0f));
	sf::RectangleShape fire(sf::Vector2f(20, 20));
	//Pozitie de start pentru jucator
	player.setPosition(-8.0, 0.0);
	//Pozitie de start pentru dusman
	enemy.setPosition(860, 600);
	sf::Texture texture;
	sf::Texture firetext;
	firetext.loadFromFile("fire.png");
	texture.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	sf::Texture texture2;
	texture2.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	int x = 0, a = 79, b = 63;
	int x0 = 70;
	//directia dusmanului ,  -1 = nord, 1 = sud
	int change = -1;
	fire.setTexture(&firetext);
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
	bool  setted1 = 0;
	bool  setted2 = 0;
	bool  setted3 = 0;
	bool  setted4 = 0;

	window.setFramerateLimit(30);
	//Loop-ul principal;
	int case0 = 0;
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
				case0 = 0;
				x = 68;	a = 79; b = 63; // niste numere calculate cu precizie pentru a decupa partea necesara a tankului din poza cu ... tankuri . (?)
				//Daca pe axa y ne aflam intr-o pozitie cu y > 0 , continuam sa ne deplasam spre origine, altfel nu.
				if (player.getPosition().y < 0 || obstacleUp(player.getPosition().x, player.getPosition().y))
					player.move(0, 0);
				else
					player.move(0.0, -10.0);
			}
			else
				if (KeyDown()) {
					case0 = 1;
					x = 0;	a = 79; b = 63; // aceleasi numere;
					//Daca pe axa y ne afla intr-o pozitie cu y < window.Size().y , continuam sa ne deplasam spre margine, altfel nu.
					if (player.getPosition().y > window.getSize().y - 70 || obstacleDown(player.getPosition().x, player.getPosition().y))
						player.move(0, 0);
					else
						player.move(0.0, 10.0);
				}
				else
					if (KeyLeft()) {
						case0 = 2;
						x = 3 * 69.4; a = 78; b = 62;
						//Daca pe axa x ne aflam intr-o pozitie cu x > 0 ...sau nu intilnim un obstacol , continuam sa ne deplasam spre origine, altfel nu.
						if (player.getPosition().x < 0 || obstacleRight(player.getPosition().x, player.getPosition().y))
							player.move(0, 0);
						else
							player.move(-10.0, 0.0);
					}
					else
						if (KeyRight()) {
							case0 = 3;
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
		int pressed = 0;
		if (Space() ) {
			//std::cout << "Pressed" << std::endl;
			pressed = 1;
		}
		window.clear();
		//std::cout << player.getPosition().x << std::endl;
		//Desenam harta
		window.draw(map);
		//Desenam jucatorul
		window.draw(enemy);
		//Desenam dusmanul
		window.draw(player);
		//window.draw(fire);
		if (pressed && !setted1 && !setted2 && !setted3 && !setted4) {
			attack(fire, player, enemy, case0);
			if (case0 == 0 && !setted2 && !setted3 && !setted4)
				setted1 = 1;
			if (case0 == 1 && !setted1 && !setted3 && !setted4)
				setted2 = 1;
			if (case0 == 2 && !setted1 && !setted2 && !setted4)
				setted3 = 1;
			if (case0 == 3 && !setted1 && !setted2 && !setted3)
				setted4 = 1;
			
		}
		//Ii afisam pe toti
		if (setted1 && !setted2 && !setted3 && !setted4) {
			fire.move(0, -15);
			window.draw(fire);
			if (fire.getPosition().y < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20) || obstacleUp(fire.getPosition().x, fire.getPosition().y))
				setted1 = 0;
		}  else
		if (setted2 && !setted1 && !setted3 && !setted4) {
				fire.move(0, 15);
				window.draw(fire);
				if (fire.getPosition().y > window.getSize().y - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20) || obstacleDown(fire.getPosition().x, fire.getPosition().y - 40))
					setted2 = 0;
		}  else
		if (setted3 && !setted1 && !setted2 && !setted4) {
			fire.move(-15, 0);
			window.draw(fire);
			if (fire.getPosition().x < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) || obstacleLeft(fire.getPosition().x - 90, fire.getPosition().y))
				setted3 = 0;
		} else
		if (setted4 && !setted1 && !setted2 && !setted3) {
			fire.move(15, 0);
			window.draw(fire);
			if (fire.getPosition().x > window.getSize().x - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) || obstacleRight(fire.getPosition().x + 50, fire.getPosition().y))
				setted4 = 0;
		}

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
