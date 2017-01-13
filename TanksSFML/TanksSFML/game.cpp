#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.cpp"
#include <time.h>
#include "maps.h"
#include <algorithm>
#include "keyboard.h"
#include "objects.hpp"
#include "attack.hpp"
#include <string>
#include "AI.hpp"
#include "getStart.hpp"
#include "SFML\Audio.hpp"
#include "vars.hpp"
int choosedTankplayer = 0;
int choosedTankenemy = 1;
int choosedTanksenemy = 2;
int mpcur[29*22];
//using namespace std;
float DEGTORAD = 0.017453f;
void game() {
	srand(time(NULL));
	sf::Music music;
	sf::Music moving;
	sf::Music shot;	
	int exp = 0;
	int exp1 = 0;
	std::string str;
	sf::Clock clock;
	sf::Time time;
	shot.openFromFile("shot.ogg");
	moving.openFromFile("moving.ogg");
	music.openFromFile("explosionsound.ogg");
	music.setPitch(1.5);
	sf::RenderWindow window(sf::VideoMode(924, 704), "Tanks ");	// Creare fereastra de joc, dimensiune 924 x 704 FINALLY?
	sf::RenderWindow details(sf::VideoMode(924, 100), "Details"); // Creare fereastra cu detalii din joc
	sf::RectangleShape player(sf::Vector2f(80, 75)); // Creare jucator
	sf::RectangleShape heartOne(sf::Vector2f(50, 35)); // Inima
	sf::RectangleShape exploded(sf::Vector2f(80, 80)); // explozie
	sf::RectangleShape enemy(sf::Vector2f(80, 75)); // creare dusman
	sf::RectangleShape enemyTwo(sf::Vector2f(80, 75)); // creare dusman
	sf::RectangleShape fire(sf::Vector2f(20, 20)); // foc 
	sf::RectangleShape fire1(sf::Vector2f(20, 20));
	sf::RectangleShape fire2(sf::Vector2f(20, 20));
	sf::RectangleShape colisionMap[638];
	sf::Sprite explosion[26];
	enemy.setPosition(Ecx, Ecy);
	enemy.setRotation(Eangle);
	enemy.setOrigin(80 / 2, 75 / 2);
	//


	sf::RectangleShape pwOneShot(sf::Vector2f(32, 32));
	sf::RectangleShape pwSpeed(sf::Vector2f(32, 32));
	sf::RectangleShape pwUp(sf::Vector2f(32, 32));
	
		
		sf::Texture pwOneShotT;
	pwOneShotT.loadFromFile("oneShot.png");
	pwOneShot.setTexture(&pwOneShotT);
	
		sf::Texture pwSpeedT;
	pwSpeedT.loadFromFile("speed.png");
	pwSpeed.setTexture(&pwSpeedT);
	
		sf::Texture pwUpT;
	pwUpT.loadFromFile("heart.png");
	pwUp.setTexture(&pwUpT);
	
		pwUp.setPosition(100, 100);
	pwSpeed.setPosition(401, 300);
	pwOneShot.setPosition(300, 300);

	int pwT = 300;

	enemyTwo.setPosition(Secx, Secy);
	enemyTwo.setRotation(Seangle);
	enemyTwo.setOrigin(80 / 2, 75 / 2);
	//
	TileMap map;
	TileMap map1;
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
	
	player.setPosition(30, 30); // setare pozitie de start pentru jucator
	details.setPosition(sf::Vector2i(500, 50)); // setare pozitie pentru fereastra details.

	sf::Texture heart;                 //  Incarcare imagine inima 
	heart.loadFromFile("heart.png");
	heartOne.setTexture(&heart);

//load tanks	
	sf::Texture texture; // Incarcare imagine inamic,jucator
		sf::Texture tnk1;
		tnk1.loadFromFile("tank1.png");
		player.setTexture(&tnk1);
		player.setOrigin(80 / 2, 60 / 2);

		sf::Texture tnk2;
		tnk2.loadFromFile("tank2.png");
		sf::Texture tnk3;
		tnk3.loadFromFile("tank3.png");
		enemyTwo.setTexture(&tnk1);
		if (choosedTankplayer == 1)
			player.setTexture(&tnk2);
		if (choosedTankplayer == 2)
			player.setTexture(&tnk3);	
		if (choosedTankenemy == 1)
			enemy.setTexture(&tnk2);
		if (choosedTankenemy == 2)
			enemy.setTexture(&tnk3);
		if(choosedTanksenemy == 1)
			enemyTwo.setTexture(&tnk2);
		if (choosedTanksenemy == 2)
			enemyTwo.setTexture(&tnk3);
		
//!load tanks

//load fire
	sf::Texture firetext; // Incarcare imagine foc
	firetext.loadFromFile("fire.png");
	fire.setTexture(&firetext);
	fire1.setTexture(&firetext);
	fire2.setTexture(&firetext);
	sf::Texture expl;  // Incarcare imagine explozie
	expl.loadFromFile("exploded.png");
	exploded.setTexture(&expl);
//!load fire

	// Incarcare harta, daca harta are probleme, e eroare.
/*	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 29, 22)) {
		std::cout << "Un fel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}
	if (!map1.load("tileset.png", sf::Vector2u(32, 32), level0, 29, 22)) {
		std::cout << "Altfel de eroare!!" << std::endl;
		std::cin.get();
		return;
	}*/
	//
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "O eroare cu fontul ... " << std::endl;
		std::cin.get();
		return;
	}
	//

//load texts
	sf::Text playerHealth; // textul din fereastra details.
	playerHealth.setFont(font);
	playerHealth.setString("100");
	playerHealth.setCharacterSize(20);
	playerHealth.setFillColor(sf::Color::White);
	playerHealth.setStyle(sf::Text::Bold);
	playerHealth.setPosition(460, 0);

	sf::Text enemyHealth;
	enemyHealth.setFont(font);
	enemyHealth.setString("100");
	enemyHealth.setCharacterSize(20);
	enemyHealth.setFillColor(sf::Color::White);
	enemyHealth.setStyle(sf::Text::Bold);
	enemyHealth.setPosition(800, 0);

	sf::Text enemyTwoHealth;
	enemyTwoHealth.setFont(font);
	enemyTwoHealth.setString("100");
	enemyTwoHealth.setCharacterSize(20);
	enemyTwoHealth.setFillColor(sf::Color::White);
	enemyTwoHealth.setStyle(sf::Text::Bold);
	enemyTwoHealth.setPosition(500, 50);

	sf::Text playerName;
	playerName.setFont(font);
	playerName.setString("PLAYER:");
	playerName.setCharacterSize(20);
	playerName.setFillColor(sf::Color::White);
	playerName.setStyle(sf::Text::Bold);
	playerName.setPosition(360, 0);

	sf::Text enemyName;
	enemyName.setFont(font);
	enemyName.setString("ENEMY:");
	enemyName.setCharacterSize(20);
	enemyName.setFillColor(sf::Color::White);
	enemyName.setStyle(sf::Text::Bold);
	enemyName.setPosition(700, 0);

	sf::Text enemyTwoName;
	enemyTwoName.setFont(font);
	enemyTwoName.setString("ENEMY Two:");
	enemyTwoName.setCharacterSize(20);
	enemyTwoName.setFillColor(sf::Color::White);
	enemyTwoName.setStyle(sf::Text::Bold);
	enemyTwoName.setPosition(370, 50);
//sadasdasdsdsadsad
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
//!load texts

	sf::Image icon;
	if (!icon.loadFromFile("icon.png")) {
		std::cout << "Probleme cu iconita";
		return;
   }
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setFramerateLimit(30);//fixare limita fps		
	//Loop-ul principal;
	moving.setLoop(1);
	moving.play();
	if (choosedMap == 0) {
		if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 29, 22)) {
			std::cout << "Un fel de eroare!!" << std::endl;
			std::cin.get();
			return;
		}
		for (int i = 0; i < 29 * 22; i++)
			mpcur[i] = level[i];
	}
	if (choosedMap == 1) {
		if (!map.load("tileset.png", sf::Vector2u(32, 32), level0, 29, 22)) {
			std::cout << "Un fel de eroare!!" << std::endl;
			std::cin.get();
			return;
		}
		for (int i = 0; i < 29 * 22; i++)
			mpcur[i] = level0[i];
	} 
	if (choosedMap == 2) {
		if (!map.load("tileset.png", sf::Vector2u(32, 32), level1, 29, 22)) {
			std::cout << "Un fel de eroare!!" << std::endl;
			std::cin.get();
			return;
		}
		for (int i = 0; i < 29 * 22; i++)
			mpcur[i] = level1[i];
	}
	while (window.isOpen()) {
		thrust = false;
		Ethrust = false;
		Sethrust = false;
		ja = 0;
		ja2 = 0;
		ja3 = 0;
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
// management powerUpsuri
		pwT--;
		playerSpeed--;
		enemySpeed--;
		playerOneShot--;
		enemyOneShot--;
		if (pwT == 0) {
			pwT = 500;
			int q = rand() % 5;
			
				int i = rand() % (29 * 22);
			while (level[i] == 120 || level[i] == 121 || level[i] == 136 || level[i] == 137 || level[i] == 70 || level[i] == 71 || level[i] == 55 || level[i] == 86 || level[i] == 87 || level[i] == 18 || level[i] == 19 || level[i] == 114 || level[i] == 115 || level[i] == 130 || level[i] == 131)
				 {
				{
					i = rand() % (29 * 22);
					}
				}
			if (q == 0)
				 pwUp.setPosition(i % 29 * 32, i / 29 * 32);
			else if (q == 1)
				 pwOneShot.setPosition(i % 29 * 32, i / 29 * 32);
			else
				 pwSpeed.setPosition(i % 29 * 32, i / 29 * 32);
			
		}
		if (player.getGlobalBounds().intersects(pwSpeed.getGlobalBounds()))
			 {
			playerSpeed = 200;
			pwSpeed.setPosition(-100, -100);
			}
		if (player.getGlobalBounds().intersects(pwUp.getGlobalBounds()))
			 {
			pHealth += 2;
			if (pHealth > 100)
				 pHealth = 100;
			pwUp.setPosition(-100, -100);
			}
		if (player.getGlobalBounds().intersects(pwOneShot.getGlobalBounds()))
			 {
			playerOneShot = 200;
			pwOneShot.setPosition(-100, -100);
			std::cout << "ONE OPORTUNITY";
			}
		if (enemy.getGlobalBounds().intersects(pwSpeed.getGlobalBounds()))
			 {
			enemySpeed = 200;
			pwSpeed.setPosition(-100, -100);
			}
		if (player.getGlobalBounds().intersects(pwUp.getGlobalBounds()))
			 {
			eHealth += 2;
			if (eHealth>100)
				 eHealth = 100;
			pwUp.setPosition(-100, -100);
			}
		if (player.getGlobalBounds().intersects(pwOneShot.getGlobalBounds()))
			 {
			enemyOneShot = 200;
			pwOneShot.setPosition(-100, -100);
			}
		if (enemy.getGlobalBounds().intersects(fire.getGlobalBounds()) && playerOneShot > 0)
			 eHealth = 0;
		if (player.getGlobalBounds().intersects(fire.getGlobalBounds()) && enemyOneShot > 0)
			 pHealth = 0;

//------------------PLAYER'S MOVEMENTS-------------------------------------------------------------------------------------------------------------------------------------
		if (1) {
			if (KeyUp()) {
				ja = 1;
				case0 = 0;
				int unghi = angle;
				if (angle < 0) {
					unghi = 360 + angle;
				}
				if ((player.getPosition().y < 50 && unghi < 180 && unghi > 0));
				else
					 if ((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, player.getPosition().x, player.getPosition().y, choosedMap)));
				else
					 if (player.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)));
				else
					 if (player.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270);
				else
					 if (player.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360);
				else
					 if (((unghi > 270 && unghi < 360) || (unghi >= 0 && unghi < 90)) && obstacleRight(mpcur, player.getPosition().x, player.getPosition().y, choosedMap)); else
					 if (unghi > 0 && unghi < 180 && obstacleUp(mpcur, player.getPosition().x, player.getPosition().y, choosedMap));
				else
					 if (unghi > 180 && unghi < 360 && obstacleDown(mpcur, player.getPosition().x, player.getPosition().y, choosedMap));
				else
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
					if ((player.getPosition().y < 50 && unghi > 180 && unghi < 360)); else
						if ((((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleLeft(mpcur, player.getPosition().x, player.getPosition().y, choosedMap))); else
							if (player.getPosition().x < 50 && unghi > 90 && unghi < 270); else
								if (player.getPosition().x > window.getSize().x - 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))); else
									if (player.getPosition().y > window.getSize().y - 50 && unghi > 0 && unghi < 180); else
										if (unghi > 90 && unghi < 270 && obstacleRight(mpcur, player.getPosition().x, player.getPosition().y, choosedMap)); else
											if (unghi > 180 && unghi < 360 && obstacleUp(mpcur, player.getPosition().x, player.getPosition().y, choosedMap)); else
												if (unghi > 0 && unghi < 180 && obstacleDown(mpcur, player.getPosition().x, player.getPosition().y, choosedMap)); else
													thrust = true;
				}
				//else
					if (KeyLeft()) {
						ja = 1;
						case0 = 2;
						angle -= 3;
						angle %= 361;
					}
					else
						if (KeyRight()) {
							ja = 1;
							case0 = 3;
							angle += 3;
							angle %= 361;
						}
			//
		if(!ripPlayer){
			if (thrust) {
					dx += cos(angle*DEGTORAD) * 20; //*0.2;
					dy += sin(angle*DEGTORAD) * 20;//*0.2;
			}

			int maxSpeed = 3;
			float speed = sqrt(dx*dx + dy*dy);
			if (speed > maxSpeed) {
				if(playerSpeed > 0)
					maxSpeed *= 2;
				dx *= maxSpeed / speed;
				dy *= maxSpeed / speed;
			}
			if(case0 == 0 && thrust)
				cx -= dx , cy -= dy;
			if (case0 == 1 && thrust)
				cx += dx, cy += dy;
			player.setPosition( cx, cy);
			player.setRotation(angle + 90);
		}
//---------------------!PLAYER'S MOVEMENTS----------------------------------------------------------------------------------------------------------------------------------
			if (!ja)
				moving.setVolume(10);
			else
				moving.setVolume(20);

//-----------------------------------------------------------------------------
//if (multiplayer = 0 && choosedMap == 1) {
//}
//-----------------------------------------------------------------------------

//DACA ESTE SINGLR
if(multiplayer == 0){
			if (!cnt) {
				nextMove = next(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y, Eangle, enemy);
				cnt = 20;
			}
			else
				cnt--;

//-----------------------ENEMY'S MOVEMENTS---------------------------------------------------------------------------------------------------------------------------------------------------
			if (nextMove == 1) // 1 == UP
				if (enemy.getPosition().y < 40 || obstacleUp(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
					enemy.move(0, 0);
				else {
					if (distance(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
						{
						enemy.setRotation(180);
						Eangle = 180;
						cs0 = 0;
						enemy.move(0.0, 0.0);}
					else{
						enemy.setRotation(180);
						Eangle = 180;
						cs0 = 0;
						enemy.move(0.0, -2.0);
					}			
			}
			if (nextMove == 2) // 2 == DOWN
				if (enemy.getPosition().y > window.getSize().y - 100 || obstacleDown(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
						enemy.move(0, 0);
				else {
					if (distance(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
						{
						enemy.setRotation(0);
						Eangle = 0;
						cs0 = 1;
						enemy.move(0.0, 0.0);
					}
					else { 
							enemy.setRotation(0);
							Eangle = 0;
							cs0 = 1;
							enemy.move(0.0, 2.0);
					}				
				}
			if (nextMove == 3) // 3 == LEFT
				if (enemy.getPosition().x < 40 || obstacleRight(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
						enemy.move(0, 0);
				else {
					if (distance(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
						{
						cs0 = 2;
						enemy.setRotation(90);
						Eangle = 90;
						enemy.move(0, 0);
					}
						else {
								cs0 = 2;
								enemy.setRotation(90);
								Eangle = 90;
								enemy.move(-2, 0);
						}				
				}
			if (nextMove == 4) // 4 == GUESS
				if ((enemy.getPosition().x >= window.getSize().x - 100) || obstacleLeft(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
						enemy.move(0, 0);
					else {
					if (distance(enemy.getPosition().x, enemy.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
							{
						enemy.setRotation(270);
						Eangle = 270;
						cs0 = 3;
						enemy.move(0, 0);
					}
						else {
							enemy.setRotation(270);
							Eangle = 270;
							cs0 = 3;
							enemy.move(2, 0);
						}
					}
}
//if(MULTIPLAYER)
else {
								if (KeyW()) {
									ja2 = 1;
									cs0 = 0;
									int unghi = Eangle;
									if (Eangle < 0) {
										unghi = 360 + Eangle;
									}
									//std::cout << unghi << std::endl;
									//Daca pe axa y ne aflam intr-o pozitie cu y > 0 , continuam sa ne deplasam spre origine, altfel nu.
									if ((enemy.getPosition().y < 50 && unghi < 180 && unghi > 0)); else
										if ((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))); else
											if (enemy.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))); else
												if (enemy.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270); else
													if (enemy.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360); else
														if (((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
															if (unghi > 0 && unghi < 180 && obstacleUp(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
																if (unghi > 180 && unghi < 360 && obstacleDown(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
																	Ethrust = true;
								}
								else
									if (KeyS()) {
										ja2 = 1;
										cs0 = 1;
										int unghi = angle;
										if (Eangle < 0) {
											unghi = 360 + Eangle;
										}
										//std::cout << unghi << std::endl;
										//Daca pe axa y ne afla intr-o pozitie cu y < window.Size().y , continuam sa ne deplasam spre margine, altfel nu.
										if ((enemy.getPosition().y < 50 && unghi > 180 && unghi < 360)); else
											if ((((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleLeft(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))); else
												if (enemy.getPosition().x < 50 && unghi > 90 && unghi < 270); else
													if (enemy.getPosition().x > window.getSize().x - 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))); else
														if (enemy.getPosition().y > window.getSize().y - 50 && unghi > 0 && unghi < 180); else
															if (unghi > 90 && unghi < 270 && obstacleRight(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
																if (unghi > 180 && unghi < 360 && obstacleUp(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
																	if (unghi > 0 && unghi < 180 && obstacleDown(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap)); else
																		Ethrust = true;
									}
									else
										if (KeyA()) {
											ja2 = 1;
											cs0 = 2;
											Eangle -= 3;
											Eangle %= 361;
											//player.rotate(-5);
											//x = 3 * 69.4; a = 78; b = 62;
											//Daca pe axa x ne aflam intr-o pozitie cu x > 0 ...sau nu intilnim un obstacol , continuam sa ne deplasam spre origine, altfel nu.
											if (enemy.getPosition().x < 0 || obstacleRight(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
												enemy.move(0, 0);
											else;
											//player.move(-4.0, 0.0);
										}
										else
											if (KeyD()) {
												ja2 = 1;
												cs0 = 3;
												Eangle += 3;
												Eangle %= 361;
												//player.rotate(5);
												//x = 2 * 68; a = 79; b = 63;
												//Daca pe axa x ne aflam intr-o pozitie cu x < window.getSize().x ...sau nu intilnim un obstacol , continuam sa ne deplasam spre margine, altfel nu.
												if ((enemy.getPosition().x >= window.getSize().x - 70) || obstacleLeft(mpcur, enemy.getPosition().x, enemy.getPosition().y, choosedMap))
													enemy.move(0, 0);
												else;
												//player.move(4.0, 0.0);
											}
								//
								if (!exp) {
									if (Ethrust) {
										Edx += cos(Eangle*DEGTORAD) * 20; //*0.2;
										Edy += sin(Eangle*DEGTORAD) * 20;//*0.2;
									}

									int EmaxSpeed = 3;
									float Espeed = sqrt(Edx*Edx + Edy*Edy);
									if (Espeed > EmaxSpeed) {
										if (enemySpeed > 0)
											EmaxSpeed *= 2;
										Edx *= EmaxSpeed / Espeed;
										Edy *= EmaxSpeed / Espeed;
									}
									if (cs0 == 0 && Ethrust)
										Ecx -= Edx, Ecy -= Edy;
									if (cs0 == 1 && Ethrust)
										Ecx += Edx, Ecy += Edy;
									enemy.setPosition(Ecx, Ecy);
									enemy.setRotation(Eangle + 90);
								}
								//---------------------!ENEMYY2'S MOVEMENTS----------------------------------------------------------------------------------------------------------------------------------
								if (!ja2)
									moving.setVolume(10);
								else
									moving.setVolume(20);
}
							int pressed = 0;
							if (Space())
								pressed = 1;
							int prsd = 0;
							if (KeyQ()) {
								prsd = 1;
							}
//------------------(!)ENEMY'S-MOVEMENTS-----------------------------------------------------------------------------------------------------------------------
//(!)DACA ESTE SINGLE
							window.clear(); // curatire fereastra
							details.clear(); // 
							//de aici pana "acolo" e o chestie legata de proiectilul player-ului
							if (!ripPlayer)
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
if(multiplayer){
							if (!exp)
								if (prsd && !st1 && !st2 && !st3 && !st4) {
									shot.setVolume(60);
									shot.play();
									attack(fire1, enemy, player, Eangle, timerFireEnemy, Ecx, Ecy, Edx, Edy);
									ung2 = Eangle;
									if (cs0 == 0 && !st2 && !st3 && !st4)
										st1 = 1;
									if (cs0 == 1 && !st1 && !st3 && !st4)
										st2 = 1;
									if (cs0 == 2 && !st1 && !st2 && !st4)
										st3 = 1;
									if (cs0 == 3 && !st1 && !st2 && !st3)
										st4 = 1;
								}
}
else {
						if (!exp)
							if (!st1 && !st2 && !st3 && !st4) {
								//shot.setVolume(60);
								//shot.play();
								attack(fire1, enemy, player, Eangle, timerFireEnemy, Ecx, Ecy, Edx, Edy);
								ung2 = Eangle-90;
								if (cs0 == 0 && !st2 && !st3 && !st4)
									st1 = 1;
								if (cs0 == 1 && !st1 && !st3 && !st4)
									st2 = 1;
								if (cs0 == 2 && !st1 && !st2 && !st4)
									st3 = 1;
								if (cs0 == 3 && !st1 && !st2 && !st3)
									st4 = 1;
							}


}
							window.draw(map); //desenam harta


//erwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww4rewrewrwerwerewwwwwwww
// A LOT OF BUGS WITH ENEMY TWO

//ENEMYTWO----------------------------------							
if(multiplayer == 0 && choosedMap == 1){
	//window.draw(enemyTwo);
	int nextMove1;
	if (!cnt2) {
		nextMove1 = next(enemyTwo.getPosition().x, enemyTwo.getPosition().y, player.getPosition().x, player.getPosition().y, Seangle, enemyTwo);
		cnt2 = 20;
	}
	else
		cnt2--;
	//std::cout << nextMove1 << std::endl;
	if(fromstart)
		nextMove1 = 2;
	//-----------------------ENEMY'S MOVEMENTS---------------------------------------------------------------------------------------------------------------------------------------------------
	if (nextMove1 == 1) // 1 == UP
		if (enemyTwo.getPosition().y < 40 || obstacleUp(mpcur, enemyTwo.getPosition().x, enemyTwo.getPosition().y, choosedMap))
			enemyTwo.move(0, 0);
		else {
			if (distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, player.getPosition().x, player.getPosition().y) < 150 || 
				distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, enemy.getPosition().x, enemy.getPosition().y) < 150)
			{
				enemyTwo.setRotation(180);
				Seangle = 180;
				cs01 = 0;
				enemyTwo.move(0.0, 0.0);
			}
			else {
				enemyTwo.setRotation(180);
				Seangle = 180;
				cs01 = 0;
				enemyTwo.move(0.0, -2.0);
			}
		}
		if (nextMove1 == 2) // 2 == DOWN
			if (enemyTwo.getPosition().y > window.getSize().y - 100 || obstacleDown(mpcur, enemyTwo.getPosition().x, enemyTwo.getPosition().y, choosedMap) ||
				distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, enemy.getPosition().x, enemy.getPosition().y) < 150)
				enemyTwo.move(0, 0);
			else {
				if (distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
				{
					enemyTwo.setRotation(0);
					Seangle = 0;
					cs01 = 1;
					enemyTwo.move(0.0, 0.0);
				}
				else {
					enemyTwo.setRotation(0);
					Seangle = 0;
					cs01 = 1;
					enemyTwo.move(0.0, 2.0);
				}
			}
			if (nextMove1 == 3) // 3 == LEFT
				if (enemyTwo.getPosition().x < 40 || obstacleRight(mpcur, enemyTwo.getPosition().x, enemyTwo.getPosition().y, choosedMap) ||
					distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, enemy.getPosition().x, enemy.getPosition().y) < 150)
					enemyTwo.move(0, 0);
				else {
					if (distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
					{
						cs01 = 2;
						enemyTwo.setRotation(90);
						Seangle = 90;
						enemyTwo.move(0, 0);
					}
					else {
						cs01 = 2;
						enemyTwo.setRotation(90);
						Seangle = 90;
						enemyTwo.move(-2, 0);
					}
				}
				if (nextMove1 == 4) // 4 == GUESS
					if ((enemyTwo.getPosition().x >= window.getSize().x - 100) || obstacleLeft(mpcur, enemyTwo.getPosition().x, enemyTwo.getPosition().y, choosedMap) ||
						distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, enemy.getPosition().x, enemy.getPosition().y) < 150)
						enemyTwo.move(0, 0);
					else {
						if (distance(enemyTwo.getPosition().x, enemyTwo.getPosition().y, player.getPosition().x, player.getPosition().y) < 150)
						{
							enemyTwo.setRotation(270);
							Seangle = 270;
							cs01 = 3;
							enemyTwo.move(0, 0);
						}
						else {
							enemyTwo.setRotation(270);
							Seangle = 270;
							cs01 = 3;
							enemyTwo.move(2, 0);
						}
					}
					if (!exp1)
						if (!s1 && !s2 && !s3 && !s4) {
							//shot.setVolume(60);
							//shot.play();
							attack(fire2, enemyTwo, player, Seangle, timerFireEnemy, Secx, Secy, Sedx, Sedy);
							ung3 = Seangle-90;
							if (cs01 == 0 && !s2 && !s3 && !s4)
								s1 = 1;
							if (cs01 == 1 && !s1 && !s3 && !s4)
								s2 = 1;
							if (cs01 == 2 && !s1 && !s2 && !s4)
								s3 = 1;
							if (cs01 == 3 && !s1 && !s2 && !s3)
								s4 = 1;
					}
		if(!exp1 && enemyTwolifes > 0)
			window.draw(enemyTwo);
		if (timerFireSenemy)
			timerFireSenemy--;
		fromstart = std::max(fromstart-1, 0);
		std::cout << "DSADAS" << fromstart << std::endl;
		if(fromstart <= 0 && !mort)
			check(s1, s2, s3, s4, timerFireSenemy, pHealth, ppr , fire2, player,enemyTwo, window, Sedx, Sedy, ung3); // trage inamicul
		//std::cout << enemyTwolifes << std::endl;
		if (enemyTwolifes == 5) {
			std::cout << "DSADADADS" << std::endl;
			heartOne.setPosition(140, 50);
			details.draw(heartOne);
			heartOne.setPosition(180, 50);
			details.draw(heartOne);
			heartOne.setPosition(300, 50);
			details.draw(heartOne);
			heartOne.setPosition(260, 50);
			details.draw(heartOne);
			heartOne.setPosition(220, 50);
			details.draw(heartOne);
		}
		else
			if (enemyTwolifes == 4) {
				heartOne.setPosition(180, 50);
				details.draw(heartOne);
				heartOne.setPosition(300, 50);
				details.draw(heartOne);
				heartOne.setPosition(260, 50);
				details.draw(heartOne);
				heartOne.setPosition(220, 50);
				details.draw(heartOne);
			}
			else
				if (enemyTwolifes == 3) {
					heartOne.setPosition(300, 50);
					details.draw(heartOne);
					heartOne.setPosition(260, 50);
					details.draw(heartOne);
					heartOne.setPosition(220, 50);
					details.draw(heartOne);
				}
				else
					// 2..
					if (enemyTwolifes == 2) {
						heartOne.setPosition(300, 50);
						details.draw(heartOne);
						heartOne.setPosition(260, 50);
						details.draw(heartOne);
					}
					else
						//1..
						if (enemyTwolifes == 1) {
							heartOne.setPosition(300, 50);
							details.draw(heartOne);
						}
						details.draw(enemyTwoName);
						details.draw(enemyTwoHealth);
}  // SOME BUGSSSSSSSSSSS
//()()()ENEMYTWO--------------------ENEMYTWO--------------------ENEMYTWO--------------------ENEMYTWO--------------------
							if (!exp && enemyLifes > 0) // exp = true daca enemy e mort
								window.draw(enemy);
							if (playerLifes <= 1 && pHealth <= 0);
							else if(!ripPlayer) // ripPlayer e true daca player-ul e mort
							window.draw(player); // desenam jucatorul
							window.draw(pwUp);
							window.draw(pwSpeed);
							if (timerFirePlayer)
									timerFirePlayer--;
							if (timerFireEnemy)
									timerFireEnemy--;
							check(setted1, setted2, setted3, setted4,timerFirePlayer, eHealth, seHealth, fire, enemy, enemyTwo, window, dx ,dy, ung); //trage jucatorul
							if(!mort)
								check(st1, st2, st3, st4, timerFireEnemy, pHealth, ppr, fire1, player, enemyTwo, window, Edx, Edy, ung2); // trage inamicul
							else
									mort--;
							if (exp1) {
									if(exp1 == 50)
										music.play();
									make_explosion(window, explosion, exp1);
									exp1--;
							}
							if (exp) { // enemy emort
									if (exp == 50) // abia a murit si simulam explosia
										music.play();
									make_explosion(window, explosion, exp);
									exp--;
							}
							if (ripPlayer) { // player-ul e mort
								if (ripPlayer == 50) // abia a murit si simulam explozia
									music.play();
								make_explosion(window, explosion, ripPlayer);
								ripPlayer--;
							}
//------------------------VIATILE-JUCATORILOR--------------------------------------------------------------------------------------------------------------------------
						
							if (playerLifes == 5) {
								heartOne.setPosition(140, 0);
								details.draw(heartOne);
								heartOne.setPosition(180, 0);
								details.draw(heartOne);
								heartOne.setPosition(300, 0);
								details.draw(heartOne);
								heartOne.setPosition(260, 0);
								details.draw(heartOne);
								heartOne.setPosition(220, 0);
								details.draw(heartOne);
							} else
							if (playerLifes == 4) {
								heartOne.setPosition(180, 0);
								details.draw(heartOne);
								heartOne.setPosition(300, 0);
								details.draw(heartOne);
								heartOne.setPosition(260, 0);
								details.draw(heartOne);
								heartOne.setPosition(220, 0);
								details.draw(heartOne);
							}else
							if (playerLifes == 3) {
								heartOne.setPosition(300, 0);
								details.draw(heartOne);
								heartOne.setPosition(260, 0);
								details.draw(heartOne);
								heartOne.setPosition(220, 0);
								details.draw(heartOne);
							}
							else
								// 2..
								if (playerLifes == 2) {
									heartOne.setPosition(300, 0);
									details.draw(heartOne);
									heartOne.setPosition(260, 0);
									details.draw(heartOne);
								}
								else
									//1..
									if (playerLifes == 1) {
										heartOne.setPosition(300, 0);
										details.draw(heartOne);
									}
							// same here
							if (enemyLifes == 5) {
								heartOne.setPosition(480, 0);
								details.draw(heartOne);
								heartOne.setPosition(520, 0);
								details.draw(heartOne);
								heartOne.setPosition(640, 0);
								details.draw(heartOne);
								heartOne.setPosition(600, 0);
								details.draw(heartOne);
								heartOne.setPosition(560, 0);
								details.draw(heartOne);
							}
							else
								if (enemyLifes == 4) {
									heartOne.setPosition(520, 0);
									details.draw(heartOne);
									heartOne.setPosition(640, 0);
									details.draw(heartOne);
									heartOne.setPosition(600, 0);
									details.draw(heartOne);
									heartOne.setPosition(560, 0);
									details.draw(heartOne);
								}
								else
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
//----------------------(!)VIETILE JUCATORILOR-----------------------------------------------------------------------------------------------------------------
							bool displayed = 0; // este sau nu afisat curentul display
							//chestii ce tin de fps
								time = clock.getElapsedTime();
								fp = 1.0f / time.asSeconds();
								clock.restart().asSeconds(); 	
							// 
							std::string h;
							//afisare viata enemy
								h = std::to_string(eHealth);
								enemyHealth.setString(h);
							//(!)
								h = std::to_string(seHealth);
								enemyTwoHealth.setString(h);
							//afisare viata player
								h = std::to_string(pHealth);
								playerHealth.setString(h);
							//(!)
							//afisareFPS
								str = std::to_string(fp);
								text.setString(str);
								details.draw(text);							
								details.draw(fps);
								details.draw(playerName);
								details.draw(enemyName);
								details.draw(playerHealth);

								details.draw(enemyHealth);
								details.display();
							//a(1)
							//daca inamicul e mort definitiv
							//
								
								if (seHealth <= 0 && enemyTwolifes == 1 ) {
									std::cout << "!111111" << std::endl;
									window.clear();
									enemyTwolifes--;
									window.draw(map); //desenam hart;
									window.draw(player);
									exp1 = 50;
									for (int i = 1; i <= 25; i++)
										explosion[i].setPosition(enemyTwo.getPosition().x - 30, enemyTwo.getPosition().y - 30);
									window.display();
									displayed = 1;
								}
								//daca inamicul  e mort , dar mai are o viata
								else if (seHealth <= 0 && enemyTwolifes > 1) {
									std::cout << "!1111222211" << std::endl;
									seHealth = 1;
									enemyTwolifes--;
									window.draw(map); //desenam harta
									for (int i = 1; i <= 25; i++)
										explosion[i].setPosition(enemyTwo.getPosition().x - 30, enemyTwo.getPosition().y - 30);
									exp1 = 50;
									Secx = 740; Secy = 70; Sedx = 0; Sedy = 0; Seangle = 90;
									enemyTwo.setPosition(Secx, Secy);
									window.draw(player);
									//window.draw(enemy);
									window.display();
									displayed = 1;
								}
								else if (enemyTwolifes == 0 && !exp1 && enemyLifes == 0) {
									std::cout << "!11113211" << std::endl;
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
								} else if ( choosedMap != 1 && !exp && enemyLifes == 0) {
									std::cout << "!11113211" << std::endl;
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
							// 
							if (eHealth <= 0 && enemyLifes == 1) {
										window.clear();
										enemyLifes--;
										window.draw(map); //desenam hart;
										window.draw(player);
										exp = 50;
										for(int i = 1; i<=25; i++)
												explosion[i].setPosition(enemy.getPosition().x - 30, enemy.getPosition().y - 30);
												window.display();
												displayed = 1;
							}
							//daca inamicul  e mort , dar mai are o viata
							else if (eHealth <= 0 && enemyLifes > 1) {
											eHealth = 1;
											enemyLifes--;
											window.draw(map); //desenam harta
											for (int i = 1; i <= 25; i++)
													explosion[i].setPosition(enemy.getPosition().x - 30, enemy.getPosition().y - 30);
													exp = 50;
													Ecx=830;Ecy=620;Edx=0;Edy=0;Eangle=90;
													enemy.setPosition(Ecx, Ecy);
													window.draw(player);
													window.draw(enemy);
													window.display();
													displayed = 1;
						} 
						//PLAYER
						if (pHealth <= 0 && playerLifes == 1) {
											window.clear();
											playerLifes--;
											window.draw(map); //desenam harta
											window.draw(enemy);
											ripPlayer = 50;
											mort = 100;
											for (int i = 1; i <= 25; i++)
														explosion[i].setPosition(player.getPosition().x - 30, player.getPosition().y - 30);
											window.display();
											displayed = 1;
						}
						else if (pHealth <= 0 && playerLifes> 1) {
											pHealth = 1;
											playerLifes--;
											window.draw(map); //desenam harta
											for (int i = 1; i <= 25; i++)
													explosion[i].setPosition(player.getPosition().x - 30, player.getPosition().y - 30);
											ripPlayer = 50;
											mort = 100;
											player.setPosition(30, 30);
											cx=cy=30;dx=dy=0;angle=-90;ung=0;
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
					if (!displayed)
									window.display();
		} 
}
}