#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.cpp"
#include <time.h>
#include "maps.h"
#include "keyboard.h"
#include "objects.hpp"
#include "attack.hpp"
#include <string>
#include "AI.hpp"
//using namespace std;
void game() {
	srand(time(NULL));
	// Creare fereastra de joc, dimensiune 924 x 704 FINALLY?
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");
	sf::RenderWindow details(sf::VideoMode(924, 100), "Details");
	// Creare jucator
	sf::RectangleShape player(sf::Vector2f(80.0f, 65.0f));
	sf::RectangleShape heartOne(sf::Vector2f(50, 35));
	sf::RectangleShape heartTwo(sf::Vector2f(50, 35));
	sf::RectangleShape exploded(sf::Vector2f(80, 80));
	// Creare dusman
	sf::RectangleShape enemy(sf::Vector2f(80.0f, 65.0f));
	sf::RectangleShape fire(sf::Vector2f(20, 20));
	sf::RectangleShape fire1(sf::Vector2f(20, 20));

	//Pozitie de start pentru jucator
	player.setPosition(-8.0, 0.0);
	//Pozitie de start pentru dusman
	details.setPosition(sf::Vector2i(500, 50));
	enemy.setPosition(860, 600);
	sf::Texture heart;
	heart.loadFromFile("heart.png");
	sf::Texture texture;
	sf::Texture firetext;
	sf::Texture expl; 
	firetext.loadFromFile("fire.png");
	expl.loadFromFile("exploded.png");
	exploded.setTexture(&expl);
	texture.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	sf::Texture texture2;
	texture2.loadFromFile("tank.png"/*, sf::IntRect(0, 0, 80, 65)*/);
	heartOne.setTexture(&heart);
	heartTwo.setTexture(&heart);

	int x = 0, a = 79, b = 63;
	int x0 = 70;
	//directia dusmanului ,  -1 = nord, 1 = sud
	int change = -1;
	fire.setTexture(&firetext);
	fire1.setTexture(&firetext);
	player.setTexture(&texture);
	enemy.setTexture(&texture2);
	// Daca harta are probleme, e eroare.
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 29, 22)) {
		std::cout << "Un fel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	//
	sf::Text playerHealth;
	sf::Text enemyHealth;
	sf::Text playerName;
	sf::Text enemyName;
	//


	sf::Image icon;
	sf::Text text;
	sf::Text Win;
	//sf::Text Lst;
	sf::Text fps;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "O eroare cu fontul ... " << std::endl;
		std::cin.get();
		return;
	}
	Win.setFont(font);
	Win.setString("YOU WON !!!");
	Win.setCharacterSize(70);
	Win.setFillColor(sf::Color::White);
	Win.setStyle(sf::Text::Bold);
	/*
	LOSE.setFont(font);
	LOSE.setString("YOU LOST !!!");
	LOSE.setCharacterSize(70);
	LOSE.setFillColor(sf::Color::White);
	LOSE.setStyle(sf::Text::Bold);
	*/
	playerHealth.setFont(font);
	playerHealth.setString("100");
	playerHealth.setCharacterSize(20);
	playerHealth.setFillColor(sf::Color::White);
	playerHealth.setStyle(sf::Text::Bold);

	enemyHealth.setFont(font);
	enemyHealth.setString("100");
	enemyHealth.setCharacterSize(20);
	enemyHealth.setFillColor(sf::Color::White);
	enemyHealth.setStyle(sf::Text::Bold);

	playerName.setFont(font);
	playerName.setString("PLAYER:");
	playerName.setCharacterSize(20);
	playerName.setFillColor(sf::Color::White);
	playerName.setStyle(sf::Text::Bold);

	enemyName.setFont(font);
	enemyName.setString("ENEMY:");
	enemyName.setCharacterSize(20);
	enemyName.setFillColor(sf::Color::White);
	enemyName.setStyle(sf::Text::Bold);

	text.setFont(font);
	text.setString("30 ");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	fps.setFont(font);
	fps.setString("FPS");
	fps.setCharacterSize(20);
	fps.setFillColor(sf::Color::White);
	fps.setStyle(sf::Text::Bold);
	fps.setPosition(40, 0);

	//
	playerName.setPosition(400, 0);
	playerHealth.setPosition(500, 0);
	enemyName.setPosition(700, 0);
	enemyHealth.setPosition(800, 0);
	int pHealth = 100, eHealth = 100;
	icon.loadFromFile("icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//
	sf::Clock clock;
	sf::Time time;
	bool  setted1 = 0, st1 = 0;
	bool  setted2 = 0, st2 = 0;
	bool  setted3 = 0, st3 = 0;
	bool  setted4 = 0, st4 = 0;
	int exp = 0;
	int playerLifes = 3;
	int enemyLifes = 3;
	window.setFramerateLimit(30);
	//Loop-ul principal;
	int case0 = 0, cs0 = 0;
	while (window.isOpen()) {
		//eveniment pentru inchiderea ferestrei
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close(), details.close();
			else
				if (KeyEsc())
					window.close(), details.close();
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
		std::string nextMove = next(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y);
		std::cout << nextMove << std::endl;
		//if (!intersect(player.getPosition().x, player.getPosition().y, 25, enemy.getPosition().x, enemy.getPosition().y, 25)) {
		if (nextMove == "up")
		if (enemy.getPosition().y < 40 || obstacleUp(enemy.getPosition().x, enemy.getPosition().y))
				enemy.move(0, 0);
			else{
				cs0 = 0;
				enemy.move(0.0, -6.0);
				x0 = 70;
			}
		if (nextMove == "down") 
		if (enemy.getPosition().y > window.getSize().y - 100 || obstacleDown(enemy.getPosition().x, enemy.getPosition().y))
			enemy.move(0, 0);
		else{
			cs0 = 1;
				enemy.move(0.0, 6.0);
				x0 = 0;
		}
		if (nextMove == "left")
		if (enemy.getPosition().x < 40 || obstacleRight(enemy.getPosition().x, enemy.getPosition().y))
			enemy.move(0, 0);
		else{
			cs0 = 2;
			enemy.move(-6, 0);
			x0 = 3 * 69;
		}
		if (nextMove == "right")
		if ((enemy.getPosition().x >= window.getSize().x - 100) || obstacleLeft(enemy.getPosition().x, enemy.getPosition().y))
			enemy.move(0, 0);
		else{
			cs0 = 3;
			enemy.move(6, 0);	
			x0 = 2 * 69.5;
		}
		
			//}
			
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
		details.clear();
		//std::cout << player.getPosition().x << std::endl;
		
		//window.draw(fire);
		/***/
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

		//
		if (!st1 && !st2 && !st3 && !st4) {
			attack(fire1, enemy, player, cs0);
			if (cs0 == 0 && !st2 && !st3 && !st4)
				st1 = 1;
			if (cs0 == 1 && !st1 && !st3 && !st4)
				st2 = 1;
			if (cs0 == 2 && !st1 && !st2 && !st4)
				st3 = 1;
			if (cs0 == 3 && !st1 && !st2 && !st3)
				st4 = 1;
		}

		//Ii afisam pe toti
		//Desenam harta
		window.draw(map);
		//Desenam jucatorul
		//if (eHealth > 0)
		if(!exp)
			window.draw(enemy);
		//else {
	//		exploded.setPosition(enemy.getPosition().x, enemy.getPosition().y);
//			window.draw(exploded);
//		}
		//Desenam dusmanul
		window.draw(player);
		//check(setted1, setted2, setted3, setted4, eHealth, fire, enemy);
		if (setted1 && !setted2 && !setted3 && !setted4) {
			fire.move(0, -15);
			window.draw(fire);
			if (fire.getPosition().y < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20)
				|| obstacleUp(fire.getPosition().x, fire.getPosition().y)) {
				setted1 = 0;
				if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
					eHealth -= 10;
			}
		}
		else
			if (setted2 && !setted1 && !setted3 && !setted4) {
				fire.move(0, 15);
				window.draw(fire);
				if (fire.getPosition().y > window.getSize().y - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20)
					|| obstacleDown(fire.getPosition().x, fire.getPosition().y - 40)) {
					setted2 = 0;
					if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
						eHealth -= 10;
				}
			}
			else
				if (setted3 && !setted1 && !setted2 && !setted4) {
					fire.move(-15, 0);
					window.draw(fire);
					if (fire.getPosition().x < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) ||
						obstacleLeft(fire.getPosition().x - 90, fire.getPosition().y)) {
						setted3 = 0;
						if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
							eHealth -= 10;
					}
				}
				else
					if (setted4 && !setted1 && !setted2 && !setted3) {
						fire.move(15, 0);
						window.draw(fire);
						if (fire.getPosition().x > window.getSize().x - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) ||
							obstacleRight(fire.getPosition().x + 50, fire.getPosition().y)) {
							setted4 = 0;
							if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
								eHealth -= 10;
						}
					}
		///trage inamic
		if (!exp) {
			if (st1 && !st2 && !st3 && !st4) {
				fire1.move(0, -15);
				window.draw(fire1);
				if (fire1.getPosition().y < 10 || intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20)
					|| obstacleUp(fire1.getPosition().x, fire1.getPosition().y)) {
					st1 = 0;
					if (intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20))
						pHealth -= 10;
				}
			}
			else
				if (st2 && !st1 && !st3 && !st4) {
					fire1.move(0, 15);
					window.draw(fire1);
					if (fire1.getPosition().y > window.getSize().y - 10 || intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20)
						|| obstacleDown(fire1.getPosition().x, fire1.getPosition().y - 40)) {
						st2 = 0;
						if (intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20))
							pHealth -= 10;
					}
				}
				else
					if (st3 && !st1 && !st2 && !st4) {
						fire1.move(-15, 0);
						window.draw(fire1);
						if (fire1.getPosition().x < 10 || intersect(player.getPosition().x, player.getPosition().y, 10, fire1.getPosition().x, fire1.getPosition().y, 20) ||
							obstacleLeft(fire1.getPosition().x - 90, fire1.getPosition().y)) {
							st3 = 0;
							if (intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20))
								pHealth -= 10;
						}
					}
					else
						if (st4 && !st1 && !st2 && !st3) {
							fire1.move(15, 0);
							window.draw(fire1);
							if (fire1.getPosition().x > window.getSize().x - 10 || intersect(player.getPosition().x, player.getPosition().y, 10, fire1.getPosition().x, fire1.getPosition().y, 20) ||
								obstacleRight(fire.getPosition().x + 50, fire.getPosition().y)) {
								st4 = 0;
								if (intersect(player.getPosition().x, player.getPosition().y, 20, fire1.getPosition().x, fire1.getPosition().y, 20))
									pHealth -= 10;
							}
						}
			//
		}
		std::string str; 
		int fp;
		//window.draw(exploded);
		//window.draw(blur);
		//std::cout << player.getSize().x << ' ' << player.getSize().y << ' ' << std::endl << enemy.getSize().x << ' ' << enemy.getSize().y << std::endl;
		//if (intersect(player.getPosition().x, player.getPosition().y, 70, enemy.getPosition().x, enemy.getPosition().y, 70))
		//	std::cout << "YES" << std::endl;
		//

		//

		if (playerLifes == 3) {
			heartOne.setPosition(340, 0);
			details.draw(heartOne);
			heartOne.setPosition(300, 0);
			details.draw(heartOne);
			heartOne.setPosition(260, 0);
			details.draw(heartOne);
		} else 
		if (playerLifes == 2) {
			heartOne.setPosition(340, 0);
			details.draw(heartOne);	
			heartOne.setPosition(300, 0);
			details.draw(heartOne);
		}else 
		if (playerLifes == 1) {
			heartOne.setPosition(340, 0);
			details.draw(heartOne);
		}
		
		if (enemyLifes == 3) {
			heartTwo.setPosition(640, 0);
			details.draw(heartTwo);
			heartTwo.setPosition(600, 0);
			details.draw(heartTwo);
			heartTwo.setPosition(560, 0);
			details.draw(heartTwo);
		}else
		if (enemyLifes == 2) {
			heartTwo.setPosition(640, 0);
			details.draw(heartTwo);
			heartTwo.setPosition(600, 0);
			details.draw(heartTwo);
		}else 
		if (enemyLifes == 1) {
			heartTwo.setPosition(640, 0);
			details.draw(heartTwo);
		}
	
		bool displayed = 0;
			time = clock.getElapsedTime();
			fp = 1.0f / time.asSeconds();
			clock.restart().asSeconds(); 		// 
			str = std::to_string(fp);
			std::string h;
			h = std::to_string(eHealth);
			enemyHealth.setString(h);
			h = std::to_string(pHealth);
			playerHealth.setString(h);
			text.setString(str);
			details.draw(text);
			details.draw(fps);
			details.draw(playerName);
			details.draw(enemyName);
			details.draw(playerHealth);
			details.draw(enemyHealth);
			//details.draw(heartOne);
			//details.draw(heartTwo);
			details.display();
			if (eHealth <= 0 && enemyLifes == 1) {
				Win.setPosition(300,300);
				window.clear();
				window.draw(map);
				window.draw(player);
				exploded.setPosition(enemy.getPosition().x, enemy.getPosition().y);
				window.draw(exploded);
				window.draw(Win);
				window.display();
				while (window.isOpen())
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
						window.close();
						details.close();
					}

			}
			else if (eHealth <= 0 && enemyLifes > 1) {
				eHealth = 100;
				enemyLifes--;
				//window.clear();
				window.draw(map);
				exploded.setPosition(enemy.getPosition().x, enemy.getPosition().y);
				exp = 50;
				enemy.setPosition(860, 600);
				window.draw(player);
				window.draw(exploded);
				window.draw(enemy);
				//window.display();
				displayed = 1;
			} 
			if (pHealth <= 0 && playerLifes == 1) {
				Win.setString("You Lost !!!");
				Win.setPosition(300, 300);
				window.clear();
				window.draw(map);
				window.draw(enemy);
				exploded.setPosition(player.getPosition().x, player.getPosition().y);
				window.draw(exploded);
				window.draw(Win);
				window.display();
				while (window.isOpen())
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
						window.close();
						details.close();
					}
			}
			else if (pHealth <= 0) {
				pHealth = 100;
				playerLifes--;
			}
			if (!displayed) {
				if (exp) {
					exp--;
					window.draw(exploded);
				}
				window.display();
			}
			/***/
	}
}
