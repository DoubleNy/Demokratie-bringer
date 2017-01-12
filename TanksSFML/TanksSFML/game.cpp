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
#include "SFML\Audio.hpp"
#include "vars.hpp"
int choosedTank = 0;
//using namespace std;
float DEGTORAD = 0.017453f;

void game() {
	srand(time(NULL));
	sf::Music music;
	sf::Music moving;
	sf::Music shot;
	shot.openFromFile("shot.ogg");
	moving.openFromFile("moving.ogg");
	music.openFromFile("explosionsound.ogg");
	music.setPitch(1.5);
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");	// Creare fereastra de joc, dimensiune 924 x 704 FINALLY?
	sf::RenderWindow details(sf::VideoMode(924, 100), "Details"); // Creare fereastra cu detalii din joc
	sf::RectangleShape player(sf::Vector2f(80, 75)); // Creare jucator

	sf::RectangleShape heartOne(sf::Vector2f(50, 35)); // Inima
	sf::RectangleShape exploded(sf::Vector2f(80, 80)); // explozie
	sf::RectangleShape enemy(sf::Vector2f(80.0f, 65.0f)); // creare dusman
	sf::RectangleShape fire(sf::Vector2f(20, 20)); // foc 
	sf::RectangleShape fire1(sf::Vector2f(20, 20));
	sf::Sprite explosion[26];
	//if (1) {
	sf::Texture txt1;
	txt1.loadFromFile("1.png");
	explosion[1].setTexture(txt1);

	sf::Texture txt2;
	txt2.loadFromFile("2.png");
	explosion[2].setTexture(txt2);

	sf::Texture txt3;
	txt3.loadFromFile("3.png");
	explosion[3].setTexture(txt3);

	sf::Texture txt4;
	txt4.loadFromFile("4.png");
	explosion[4].setTexture(txt4);

	sf::Texture txt5;
	txt5.loadFromFile("5.png");
	explosion[5].setTexture(txt5);

	sf::Texture txt6;
	txt6.loadFromFile("6.png");
	explosion[6].setTexture(txt6);

	sf::Texture txt7;
	txt7.loadFromFile("7.png");
	explosion[7].setTexture(txt7);

	sf::Texture txt8;
	txt8.loadFromFile("8.png");
	explosion[8].setTexture(txt8);

	sf::Texture txt9;
	txt9.loadFromFile("9.png");
	explosion[9].setTexture(txt9);

	sf::Texture txt10;
	txt10.loadFromFile("10.png");
	explosion[10].setTexture(txt10);

	sf::Texture txt11;
	txt11.loadFromFile("11.png");
	explosion[11].setTexture(txt11);

	sf::Texture txt12;
	txt12.loadFromFile("12.png");
	explosion[12].setTexture(txt12);

	sf::Texture txt13;
	txt13.loadFromFile("13.png");
	explosion[13].setTexture(txt13);

	sf::Texture txt14;
	txt14.loadFromFile("14.png");
	explosion[14].setTexture(txt14);

	sf::Texture txt15;
	txt15.loadFromFile("15.png");
	explosion[15].setTexture(txt15);

	sf::Texture txt16;
	txt16.loadFromFile("16.png");
	explosion[16].setTexture(txt16);

	sf::Texture txt17;
	txt17.loadFromFile("17.png");
	explosion[17].setTexture(txt17);

	sf::Texture txt18;
	txt18.loadFromFile("18.png");
	explosion[18].setTexture(txt18);

	sf::Texture txt19;
	txt19.loadFromFile("19.png");
	explosion[19].setTexture(txt19);

	sf::Texture txt20;
	txt20.loadFromFile("20.png");
	explosion[20].setTexture(txt20);

	sf::Texture txt21;
	txt21.loadFromFile("21.png");
	explosion[21].setTexture(txt21);

	sf::Texture txt22;
	txt22.loadFromFile("22.png");
	explosion[22].setTexture(txt22);

	sf::Texture txt23;
	txt23.loadFromFile("23.png");
	explosion[23].setTexture(txt23);

	sf::Texture txt24;
	txt24.loadFromFile("24.png");
	explosion[24].setTexture(txt24);

	sf::Texture txt25;
	txt25.loadFromFile("25.png");
	explosion[25].setTexture(txt25);
	//loadExplosion(explosion);
	//}
	player.setPosition(30, 30); // setare pozitie de start pentru jucator
	enemy.setPosition(860, 600); // setare pozitie de start pentru inamic
	details.setPosition(sf::Vector2i(500, 50)); // setare pozitie pentru fereastra details.

	sf::Texture heart;                 //  Incarcare imagine inima 
	heart.loadFromFile("heart.png");
	heartOne.setTexture(&heart);
	//sf::Sprite bag;
	sf::Texture texture; // Incarcare imagine inamic,jucator
	//if (choosedTank == 0) {
		sf::Texture tnk1;
		tnk1.loadFromFile("tank1.png");
		player.setTexture(&tnk1);
		
		sf::Texture tnk2;
		tnk2.loadFromFile("tank2.png");

		sf::Texture tnk3;
		tnk3.loadFromFile("tank3.png");
		
	//}
		if (choosedTank == 1)
			player.setTexture(&tnk2);
		if (choosedTank == 2)
			player.setTexture(&tnk3);

	texture.loadFromFile("tank.png");
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
	if (!map1.load("tileset.png", sf::Vector2u(32, 32), level0, 29, 22)) {
		std::cout << "Altfel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	//
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
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
	player.setOrigin(80 / 2, 60 / 2);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		int exp = 0;
		std::string str;
		sf::Clock clock;
		sf::Time time;
	window.setFramerateLimit(30);//fixare limita fps		
	//Loop-ul principal;
	moving.setLoop(1);
	moving.play();
	while (window.isOpen()) {
		thrust = false;
		ja = 0;
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
				ja = 1;
				case0 = 0;
				int unghi = angle;
				if (angle < 0) {
					unghi = 360 + angle;
				}
				std::cout << unghi << std::endl;
				//Daca pe axa y ne aflam intr-o pozitie cu y > 0 , continuam sa ne deplasam spre origine, altfel nu.
				if ((player.getPosition().y < 50 && unghi < 180 && unghi > 0)); else
					if ((unghi > 90 && unghi < 270 && obstacleLeft(player.getPosition().x, player.getPosition().y))); else
						if (player.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))); else
							if (player.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270); else
								if (player.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360); else
									if (((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(player.getPosition().x, player.getPosition().y)); else
										if (unghi > 0 && unghi < 180 && obstacleUp(player.getPosition().x, player.getPosition().y)); else
											if (unghi > 180 && unghi < 360 && obstacleDown(player.getPosition().x, player.getPosition().y));else
					thrust = true;
			}
			else
				if (KeyDown()) {
					ja = 1;
					case0 = 1;
					int unghi = angle;
					if (angle < 0) {
						unghi = 360 + angle;
					}
					std::cout << unghi << std::endl;
					//Daca pe axa y ne afla intr-o pozitie cu y < window.Size().y , continuam sa ne deplasam spre margine, altfel nu.
					if ((player.getPosition().y < 50 && unghi > 180 && unghi < 360)); else
						if ((((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleLeft(player.getPosition().x, player.getPosition().y))); else
							if (player.getPosition().x < 50 && unghi > 90 && unghi < 270); else
								if (player.getPosition().x > window.getSize().x - 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))); else
									if (player.getPosition().y > window.getSize().y - 50 && unghi > 0 && unghi < 180); else
										if (unghi > 90 && unghi < 270 && obstacleRight(player.getPosition().x, player.getPosition().y)); else
											if (unghi > 180 && unghi < 360 && obstacleUp(player.getPosition().x, player.getPosition().y)); else
												if (unghi > 0 && unghi < 180 && obstacleDown(player.getPosition().x, player.getPosition().y)); else
													thrust = true;
				}
				else
					if (KeyLeft()) {
						ja = 1;
						case0 = 2;
						angle -= 3;
						angle %= 361;
						//player.rotate(-5);
						//x = 3 * 69.4; a = 78; b = 62;
						//Daca pe axa x ne aflam intr-o pozitie cu x > 0 ...sau nu intilnim un obstacol , continuam sa ne deplasam spre origine, altfel nu.
						if (player.getPosition().x < 0 || obstacleRight(player.getPosition().x, player.getPosition().y))
							player.move(0, 0);
						else;
							//player.move(-4.0, 0.0);
					}
					else
						if (KeyRight()) {
							ja = 1;
							case0 = 3;
							angle += 3;
							angle %= 361;
							//player.rotate(5);
							//x = 2 * 68; a = 79; b = 63;
							//Daca pe axa x ne aflam intr-o pozitie cu x < window.getSize().x ...sau nu intilnim un obstacol , continuam sa ne deplasam spre margine, altfel nu.
							if ((player.getPosition().x >= window.getSize().x - 70) || obstacleLeft(player.getPosition().x, player.getPosition().y))
								player.move(0, 0);
							else;
								//player.move(4.0, 0.0);
						}
			//

			if (thrust) {
					dx += cos(angle*DEGTORAD) * 20; //*0.2;
					dy += sin(angle*DEGTORAD) * 20;//*0.2;
			}

			int maxSpeed = 2;
			float speed = sqrt(dx*dx + dy*dy);
			if (speed > maxSpeed) {
				dx *= maxSpeed / speed;
				dy *= maxSpeed / speed;
			}
			if(case0 == 0 && thrust)
				cx -= dx , cy -= dy;
			if (case0 == 1 && thrust)
				cx += dx, cy += dy;
			player.setPosition( cx, cy);
			player.setRotation(angle + 90);
			//x += dx;
			//y += dy;



			//std::cout << player.getRotation() << std::endl;
			if (!ja)
				moving.setVolume(10);
			else
				moving.setVolume(20);
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
					enemy.move(0.0, -2.0);
					x0 = 70;
				}
				if (nextMove == 2) // 2 == DOWN
					if (enemy.getPosition().y > window.getSize().y - 100 || obstacleDown(enemy.getPosition().x, enemy.getPosition().y))
						enemy.move(0, 0);
					else {
						cs0 = 1;
						enemy.move(0.0, 2.0);
						x0 = 0;
					}
					if (nextMove == 3) // 3 == LEFT
						if (enemy.getPosition().x < 40 || obstacleRight(enemy.getPosition().x, enemy.getPosition().y))
							enemy.move(0, 0);
						else {
							cs0 = 2;
							enemy.move(-2, 0);
							x0 = 3 * 70;
						}
						if (nextMove == 4) // 4 == GUESS
							if ((enemy.getPosition().x >= window.getSize().x - 100) || obstacleLeft(enemy.getPosition().x, enemy.getPosition().y))
								enemy.move(0, 0);
							else {
								cs0 = 3;
								enemy.move(2, 0);
								x0 = 2 * 69;
							}
							//Decupam bucatile necesare de tank
							//player.setTextureRect(sf::IntRect(x, 0, a, b));
							if(cs0 == 2)
							enemy.setTextureRect(sf::IntRect(x0, 0, 78, 63));
							else
							enemy.setTextureRect(sf::IntRect(x0, 0, 78, 63));
							//
							int pressed = 0;
							if (Space())
								pressed = 1;
							//
							window.clear(); // curatire fereastra
							details.clear(); // 
							//de aici pana "acolo" e o chestie legata de proiectilul player-ului
							if (!ripPlayer && !timerFirePlayer)
								if (pressed && !setted1 && !setted2 && !setted3 && !setted4) {
									shot.setVolume(60);
									shot.play();
									attack(fire, player, enemy, angle, timerFirePlayer, cx, cy, dx, dy);
									ung = angle;
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
							if (!exp && !timerFireEnemy)
								if (!st1 && !st2 && !st3 && !st4) {
									attack(fire1, enemy, player, cs0, timerFireEnemy, cx, cy, dx, dy);
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
							if (playerLifes <= 1 && pHealth <= 0);
							else
							window.draw(player); // desenam jucatorul
							if (timerFirePlayer)
								timerFirePlayer--;
							if (timerFireEnemy)
								timerFireEnemy--;
							//std::cout << timerFirePlayer << std::endl;
						//	if(!timerFirePlayer)
							check(setted1, setted2, setted3, setted4,timerFirePlayer, eHealth, fire, enemy, window, dx ,dy, ung); //trage jucatorul
						//	if(!timerFireEnemy)
							check(st1, st2, st3, st4, timerFireEnemy, pHealth, fire1, player, window, dx, dy, angle); // trage inamicul
							//window.draw(explosion[2]);
							//adica desenez alea 3 inimi de sus pentru player
						//	window.draw(bag);
							if (exp) {
								if (exp == 50)
									music.play();
								make_explosion(window, explosion, exp);
								exp--;
							}
							if (ripPlayer) {
								if (ripPlayer == 50)
									music.play();
								make_explosion(window, explosion, ripPlayer);
								ripPlayer--;
							}

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
								window.clear();
								enemyLifes--;
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								window.draw(player);
								exp = 50;
								for(int i = 1; i<=25; i++)
									explosion[i].setPosition(enemy.getPosition().x, enemy.getPosition().y);
								//window.draw(exploded);
								window.display();
								displayed = 1;
								//while (window.isOpen())
								//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
								//		window.close();
								//		details.close();
								//	}
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
								for (int i = 1; i <= 25; i++)
									explosion[i].setPosition(enemy.getPosition().x, enemy.getPosition().y);
								exp = 50;
								enemy.setPosition(860, 600);
								window.draw(player);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							else if (enemyLifes == 0 && !exp) {
								Win.setPosition(300, 300);
								window.draw(Win);
								window.display();
								displayed = 1;
								sf::Event event;
								while(window.isOpen())
								if (window.pollEvent(event))
									if (event.type == sf::Event::Closed)
										window.close(), details.close();
									else
										if (KeyEsc())
											window.close(), details.close();
							}
							if (pHealth <= 0 && playerLifes == 1) {
								window.clear();
								playerLifes--;
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								window.draw(enemy);
								ripPlayer = 50;
								for (int i = 1; i <= 25; i++)
									explosion[i].setPosition(player.getPosition().x, player.getPosition().y);
								window.display();
								displayed = 1;
							}
							else if (pHealth <= 0 && playerLifes> 1) {
								pHealth = 100;
								playerLifes--;
								if (choosedMap == 0)
									window.draw(map); //desenam harta
								else if (choosedMap == 1)
									window.draw(map1);
								//window.draw(map);
								for (int i = 1; i <= 25; i++)
									explosion[i].setPosition(player.getPosition().x, player.getPosition().y);
								ripPlayer = 50;
								player.setPosition(-8, 0);
								window.draw(enemy);
								window.display();
								displayed = 1;
							}
							else if (playerLifes <= 0 && !ripPlayer) {
						     		Win.setString("You Lost !!!");
									Win.setPosition(300, 300);
									window.draw(Win);
									window.display();
									displayed = 1;
									sf::Event event;
									while (window.isOpen())
										if (window.pollEvent(event))
											if (event.type == sf::Event::Closed)
												window.close(), details.close();
											else
												if (KeyEsc())
													window.close(), details.close();
							}
							if (!displayed) {
								//if (exp) {
								//	exp--;
									//window.draw(exploded);
								//}
								//if (ripPlayer) {
								//	ripPlayer--;
									//window.draw(exploded);
							//	}
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
			if (!cnt && !exp) {
				nextMove = next(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y);
				cnt = 20;
			}
			else
				cnt--;
			if (!exp) {
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
							if (!ripPlayer && !timerFirePlayer)
								if (pressed && !setted1 && !setted2 && !setted3 && !setted4) {
									attack(fire, player, enemy, case0, timerFirePlayer, cx, cy, dx, dy);
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
							if (!exp && !timerFireEnemy)
								if (!st1 && !st2 && !st3 && !st4) {
									attack(fire1, enemy, player, cs0, timerFireEnemy, cx, cy, dx, dy);
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
							check(setted1, setted2, setted3, setted4,timerFirePlayer, eHealth, fire, enemy, window, dx, dy,  angle); //trage jucatorul
							check(st1, st2, st3, st4, timerFireEnemy, pHealth, fire1, player, window, dx, dy,  angle); // trage inamicul

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
								//window.draw(exploded);
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
