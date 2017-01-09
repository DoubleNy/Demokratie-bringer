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
#include "getStart.hpp"

//using namespace std;
void game() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");	// Creare fereastra de joc, dimensiune 924 x 704 FINALLY?
	sf::RenderWindow details(sf::VideoMode(924, 100), "Details"); // Creare fereastra cu detalii din joc
	sf::RectangleShape player(sf::Vector2f(80.0f, 65.0f)); // Creare jucator

	sf::RectangleShape heartOne(sf::Vector2f(50, 35)); // Inima
	sf::RectangleShape exploded(sf::Vector2f(80, 80)); // explozie
	sf::RectangleShape enemy(sf::Vector2f(80.0f, 65.0f)); // creare dusman
	sf::RectangleShape fire(sf::Vector2f(20, 20)); // foc 
	sf::RectangleShape fire1(sf::Vector2f(20, 20));

	player.setPosition(-8.0, 0.0); // setare pozitie de start pentru jucator
	enemy.setPosition(860, 600); // setare pozitie de start pentru inamic
	details.setPosition(sf::Vector2i(500, 50)); // setare pozitie pentru fereastra details.

	sf::Texture heart;                 //  Incarcare imagine inima 
	heart.loadFromFile("heart.png");
	heartOne.setTexture(&heart);

	sf::Texture texture; // Incarcare imagine inamic,jucator
	texture.loadFromFile("tank.png");
	player.setTexture(&texture);
	enemy.setTexture(&texture);

	sf::Texture firetext; // Incarcare imagine foc
	firetext.loadFromFile("fire.png");
	fire.setTexture(&firetext);
	fire1.setTexture(&firetext);

	sf::Texture expl;  // Incarcare imagine explozie
	expl.loadFromFile("exploded.png");
	exploded.setTexture(&expl);

	// Incarcare harta, daca harta are probleme, e eroare.
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 29, 22)) {
		std::cout << "Un fel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	if (!map1.load("tileset.png", sf::Vector2u(32, 32), level0, 29, 22)){
		std::cout << "Altfel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	//
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){
		std::cout << "O eroare cu fontul ... " << std::endl;
		std::cin.get();
		return;
	}
	//

	sf::Text playerHealth; // textul din fereastra details.
		playerHealth.setFont(font);
		playerHealth.setString("100");
		playerHealth.setCharacterSize(20);
		playerHealth.setFillColor(sf::Color::White);
		playerHealth.setStyle(sf::Text::Bold);
		playerHealth.setPosition(500, 0);

	sf::Text enemyHealth;
		enemyHealth.setFont(font);
		enemyHealth.setString("100");
		enemyHealth.setCharacterSize(20);
		enemyHealth.setFillColor(sf::Color::White);
		enemyHealth.setStyle(sf::Text::Bold);
		enemyHealth.setPosition(800, 0);

	sf::Text playerName;
		playerName.setFont(font);
		playerName.setString("PLAYER:");
		playerName.setCharacterSize(20);
		playerName.setFillColor(sf::Color::White);
		playerName.setStyle(sf::Text::Bold);
		playerName.setPosition(400, 0);

	sf::Text enemyName;
		enemyName.setFont(font);
		enemyName.setString("ENEMY:");
		enemyName.setCharacterSize(20);
		enemyName.setFillColor(sf::Color::White);
		enemyName.setStyle(sf::Text::Bold);
		enemyName.setPosition(700, 0);

	sf::Text text;
		text.setFont(font);
		text.setString("30 ");
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold);
	//
	sf::Text Win;
		Win.setFont(font);
		Win.setString("YOU WON !!!");
		Win.setCharacterSize(70);
		Win.setFillColor(sf::Color::White);
		Win.setStyle(sf::Text::Bold);	
	sf::Text fps;
		fps.setFont(font);
		fps.setString("FPS");
		fps.setCharacterSize(20);
		fps.setFillColor(sf::Color::White);
		fps.setStyle(sf::Text::Bold);
		fps.setPosition(40, 0);
		
	sf::Image icon;
	if (!icon.loadFromFile("icon.png")) {
		std::cout << "Probleme cu iconita";
		return;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	int cnt = 0;
	int pHealth = 100;
	int eHealth = 100;
	int nextMove = 1;
	int x = 0;
	int a = 79;
	int b = 63;
	int x0 = 70;
	int exp = 0;
	int playerLifes = 3;
	int enemyLifes = 3;
	int case0 = 0, cs0 = 0;
	bool  setted1 = 0, st1 = 0;
	bool  setted2 = 0, st2 = 0;
	bool  setted3 = 0, st3 = 0;
	bool  setted4 = 0, st4 = 0;
	std::string str;
	int fp;
	int ripPlayer = 0;
	sf::Clock clock;
	sf::Time time;
	window.setFramerateLimit(30);//fixare limita fps		
	//Loop-ul principal;
	choosedMap = 1;
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
		while (details.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				details.close();
		}
		if (choosedMap == 0) {
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
			//
			if (!cnt) {
				nextMove = next(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y);
				cnt = 20;
			}
			else
				cnt--;
			if (nextMove == 1) // 1 == UP
				if (enemy.getPosition().y < 40 || obstacleUp(enemy.getPosition().x, enemy.getPosition().y))
					enemy.move(0, 0);
				else {
					cs0 = 0;
					enemy.move(0.0, -6.0);
					x0 = 70;
				}
				if (nextMove == 2) // 2 == DOWN
					if (enemy.getPosition().y > window.getSize().y - 100 || obstacleDown(enemy.getPosition().x, enemy.getPosition().y))
						enemy.move(0, 0);
					else {
						cs0 = 1;
						enemy.move(0.0, 6.0);
						x0 = 0;
					}
					if (nextMove == 3) // 3 == LEFT
						if (enemy.getPosition().x < 40 || obstacleRight(enemy.getPosition().x, enemy.getPosition().y))
							enemy.move(0, 0);
						else {
							cs0 = 2;
							enemy.move(-6, 0);
							x0 = 3 * 69;
						}
						if (nextMove == 4) // 4 == GUESS
							if ((enemy.getPosition().x >= window.getSize().x - 100) || obstacleLeft(enemy.getPosition().x, enemy.getPosition().y))
								enemy.move(0, 0);
							else {
								cs0 = 3;
								enemy.move(6, 0);
								x0 = 2 * 69.5;
							}
							//Decupam bucatile necesare de tank
							player.setTextureRect(sf::IntRect(x, 0, a, b));
							enemy.setTextureRect(sf::IntRect(x0, 0, 78, 63));
							//
							int pressed = 0;
							if (Space())
								pressed = 1;
							//
							window.clear(); // curatire fereastra
							details.clear(); // 
							//de aici pana "acolo" e o chestie legata de proiectilul player-ului
							if (!ripPlayer)
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
							//acolo
							//
							if (!exp)
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
							if (choosedMap == 0)
								window.draw(map); //desenam harta
							else if (choosedMap == 1)
								window.draw(map1);
							if (!exp)
								window.draw(enemy);
							window.draw(player); // desenam jucatorul
							check(setted1, setted2, setted3, setted4, eHealth, fire, enemy, window); //trage jucatorul
							check(st1, st2, st3, st4, pHealth, fire1, player, window); // trage inamicul

							//adica desenez alea 3 inimi de sus pentru player
							if (playerLifes == 3) {
								heartOne.setPosition(340, 0);
								details.draw(heartOne);
								heartOne.setPosition(300, 0);
								details.draw(heartOne);
								heartOne.setPosition(260, 0);
								details.draw(heartOne);
							}
							else
								// 2..
								if (playerLifes == 2) {
									heartOne.setPosition(340, 0);
									details.draw(heartOne);
									heartOne.setPosition(300, 0);
									details.draw(heartOne);
								}
								else
									//1..
									if (playerLifes == 1) {
										heartOne.setPosition(340, 0);
										details.draw(heartOne);
									}
							// same here
							if (enemyLifes == 3) {
								heartOne.setPosition(640, 0);
								details.draw(heartOne);
								heartOne.setPosition(600, 0);
								details.draw(heartOne);
								heartOne.setPosition(560, 0);
								details.draw(heartOne);
							}
							else
								if (enemyLifes == 2) {
									heartOne.setPosition(640, 0);
									details.draw(heartOne);
									heartOne.setPosition(600, 0);
									details.draw(heartOne);
								}
								else
									if (enemyLifes == 1) {
										heartOne.setPosition(640, 0);
										details.draw(heartOne);
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
							details.display();
							//daca inamicul e mort definitiv
							if (eHealth <= 0 && enemyLifes == 1) {
								Win.setPosition(300, 300);
								window.clear();
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
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
							//daca inamicul  e mort , dar mai are o viata
							else if (eHealth <= 0 && enemyLifes > 1) {
								eHealth = 100;
								enemyLifes--;
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								exploded.setPosition(enemy.getPosition().x, enemy.getPosition().y);
								exp = 50;
								enemy.setPosition(860, 600);
								window.draw(player);
								window.draw(exploded);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							if (pHealth <= 0 && playerLifes == 1) {
								Win.setString("You Lost !!!");
								Win.setPosition(300, 300);
								window.clear();
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
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
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								exploded.setPosition(player.getPosition().x, player.getPosition().y);
								ripPlayer = 50;
								player.setPosition(-8, 0);
								window.draw(exploded);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							if (!displayed) {
								if (exp) {
									exp--;
									window.draw(exploded);
								}
								if (ripPlayer) {
									ripPlayer--;
									window.draw(exploded);
								}
								window.display();
							}
		} else 
		/* BOGDAN OUATU WORKSPACE*/
		if (choosedMap == 1) {
			if (KeyUp()) {
				case0 = 0;
				x = 68;	a = 79; b = 63; // niste numere calculate cu precizie pentru a decupa partea necesara a tankului din poza cu ... tankuri . (?)
										//Daca pe axa y ne aflam intr-o pozitie cu y > 0 , continuam sa ne deplasam spre origine, altfel nu.
				if (player.getPosition().y < 0)
					player.move(0, 0);
				else
					player.move(0.0, -10.0);
			}
			else
				if (KeyDown()) {
					case0 = 1;
					x = 0;	a = 79; b = 63; // aceleasi numere;
											//Daca pe axa y ne afla intr-o pozitie cu y < window.Size().y , continuam sa ne deplasam spre margine, altfel nu.
					if (player.getPosition().y > window.getSize().y - 70)
						player.move(0, 0);
					else
						player.move(0.0, 10.0);
				}
				else
					if (KeyLeft()) {
						case0 = 2;
						x = 3 * 69.4; a = 78; b = 62;
						//Daca pe axa x ne aflam intr-o pozitie cu x > 0 ...sau nu intilnim un obstacol , continuam sa ne deplasam spre origine, altfel nu.
						if (player.getPosition().x < 0 )
							player.move(0, 0);
						else
							player.move(-10.0, 0.0);
					}
					else
						if (KeyRight()) {
							case0 = 3;
							x = 2 * 68; a = 79; b = 63;
							//Daca pe axa x ne aflam intr-o pozitie cu x < window.getSize().x ...sau nu intilnim un obstacol , continuam sa ne deplasam spre margine, altfel nu.
							if ((player.getPosition().x >= window.getSize().x - 70) )
								player.move(0, 0);
							else
								player.move(10.0, 0.0);
						}
			//
			if (!cnt) {
				nextMove = next(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y);
				cnt = 20;
			}
			else
				cnt--;
			if (nextMove == 1) // 1 == UP
				if (enemy.getPosition().y < 40 || obstacleUp(enemy.getPosition().x, enemy.getPosition().y))
					enemy.move(0, 0);
				else {
					cs0 = 0;
					enemy.move(0.0, -6.0);
					x0 = 70;
				}
				if (nextMove == 2) // 2 == DOWN
					if (enemy.getPosition().y > window.getSize().y - 100 || obstacleDown(enemy.getPosition().x, enemy.getPosition().y))
						enemy.move(0, 0);
					else {
						cs0 = 1;
						enemy.move(0.0, 6.0);
						x0 = 0;
					}
					if (nextMove == 3) // 3 == LEFT
						if (enemy.getPosition().x < 40 || obstacleRight(enemy.getPosition().x, enemy.getPosition().y))
							enemy.move(0, 0);
						else {
							cs0 = 2;
							enemy.move(-6, 0);
							x0 = 3 * 69;
						}
						if (nextMove == 4) // 4 == GUESS
							if ((enemy.getPosition().x >= window.getSize().x - 100) || obstacleLeft(enemy.getPosition().x, enemy.getPosition().y))
								enemy.move(0, 0);
							else {
								cs0 = 3;
								enemy.move(6, 0);
								x0 = 2 * 69.5;
							}
							//Decupam bucatile necesare de tank
							player.setTextureRect(sf::IntRect(x, 0, a, b));
							enemy.setTextureRect(sf::IntRect(x0, 0, 78, 63));
							//
							int pressed = 0;
							if (Space())
								pressed = 1;
							//
							window.clear(); // curatire fereastra
							details.clear(); // 
											 //de aici pana "acolo" e o chestie legata de proiectilul player-ului
							if (!ripPlayer)
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
							//acolo
							//
							if (!exp)
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
							if (choosedMap == 0)
								window.draw(map); //desenam harta
							else if (choosedMap == 1)
								window.draw(map1);
							if (!exp)
								window.draw(enemy);
							window.draw(player); // desenam jucatorul
							check(setted1, setted2, setted3, setted4, eHealth, fire, enemy, window); //trage jucatorul
							check(st1, st2, st3, st4, pHealth, fire1, player, window); // trage inamicul

																					   //adica desenez alea 3 inimi de sus pentru player
							if (playerLifes == 3) {
								heartOne.setPosition(340, 0);
								details.draw(heartOne);
								heartOne.setPosition(300, 0);
								details.draw(heartOne);
								heartOne.setPosition(260, 0);
								details.draw(heartOne);
							}
							else
								// 2..
								if (playerLifes == 2) {
									heartOne.setPosition(340, 0);
									details.draw(heartOne);
									heartOne.setPosition(300, 0);
									details.draw(heartOne);
								}
								else
									//1..
									if (playerLifes == 1) {
										heartOne.setPosition(340, 0);
										details.draw(heartOne);
									}
							// same here
							if (enemyLifes == 3) {
								heartOne.setPosition(640, 0);
								details.draw(heartOne);
								heartOne.setPosition(600, 0);
								details.draw(heartOne);
								heartOne.setPosition(560, 0);
								details.draw(heartOne);
							}
							else
								if (enemyLifes == 2) {
									heartOne.setPosition(640, 0);
									details.draw(heartOne);
									heartOne.setPosition(600, 0);
									details.draw(heartOne);
								}
								else
									if (enemyLifes == 1) {
										heartOne.setPosition(640, 0);
										details.draw(heartOne);
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
							details.display();
							//daca inamicul e mort definitiv
							if (eHealth <= 0 && enemyLifes == 1) {
								Win.setPosition(300, 300);
								window.clear();
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
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
							//daca inamicul  e mort , dar mai are o viata
							else if (eHealth <= 0 && enemyLifes > 1) {
								eHealth = 100;
								enemyLifes--;
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								exploded.setPosition(enemy.getPosition().x, enemy.getPosition().y);
								exp = 50;
								enemy.setPosition(860, 600);
								window.draw(player);
								window.draw(exploded);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							if (pHealth <= 0 && playerLifes == 1) {
								Win.setString("You Lost !!!");
								Win.setPosition(300, 300);
								window.clear();
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
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
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								exploded.setPosition(player.getPosition().x, player.getPosition().y);
								ripPlayer = 50;
								player.setPosition(-8, 0);
								window.draw(exploded);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							if (!displayed) {
								if (exp) {
									exp--;
									window.draw(exploded);
								}
								if (ripPlayer) {
									ripPlayer--;
									window.draw(exploded);
								}
								window.display();
							}
		}
	}
}
