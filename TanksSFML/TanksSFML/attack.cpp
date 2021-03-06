#include "attack.hpp"
#include "objects.hpp"
#include "game.h"
#include <iostream>
#include <math.h>
//float DEGTORAD = 0.017453f;

void attack( sf::RectangleShape &fire, sf::RectangleShape player, sf::RectangleShape enemy,   int angle,  int &timer, float &cx, float &cy, float dx, float dy) {
	if (timer == 0) {
		timer = 20;
		float pp = 0.017453f;
		int unghi = angle;
		if (angle < 0) {
			unghi = 360 + angle;
		}
		//std::cout << unghi << std::endl;
		//if(unghi > 270 && unghi < 360)
			//fire.setPosition(player.getPosition().x - cos(angle*pp) * 60, player.getPosition().y - sin(angle*pp) * 40);
		//else

		if(unghi > 60 && unghi < 180)
			fire.setPosition(player.getPosition().x - cos(angle*pp) - 10 , player.getPosition().y - sin(angle*pp));
		else
			fire.setPosition(player.getPosition().x - cos(angle*pp) , player.getPosition().y - sin(angle*pp) );
		//cx -= dx * 10;
		//cy -= dy * 10;
	}
}


void check(bool &st1, bool &st2, bool &st3, bool &st4, int  &timer, int &eHealth, int &seHealth,  sf::RectangleShape &fire, sf::RectangleShape &enemy, sf::RectangleShape &enemyTwo,  sf::RenderWindow &window, float dx, float dy, int angle) {
	float pp = 0.017453f;
	int unghi = angle;
	if (angle < 0) {
		unghi = 360 + angle;
	}
	if ((st1 && !st2 && !st3 && !st4)) {
		//timer = 20;
		timer = std::max(0, timer - 1);
		fire.setPosition(fire.getPosition().x - cos(angle*pp)*10, fire.getPosition().y - sin(angle*pp) *10);
		//fire.move(0, -15);
		window.draw(fire);
		if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
		 ((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
				 (fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
					 (fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
						 (fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
							 (((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
								 (unghi > 0 && unghi < 180 && obstacleUp(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
									 (unghi > 180 && unghi < 360 && obstacleDown(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) || (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
			st1 = 0;
			if (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
				eHealth -= 1;
			if (eHealth < 0)
				eHealth = 0;
		}
		std::cout << "111->>>>>>>" << seHealth << std::endl;
		if (seHealth >= 1) {

			if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
				((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
				(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
				(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
				(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
				(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
				(unghi > 0 && unghi < 180 && obstacleUp(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
				(unghi > 180 && unghi < 360 && obstacleDown(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) || (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
				st1 = 0;
				if (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
					seHealth -= 1;
				if (seHealth < 0)
					seHealth = 0;
			}
		}
	}
	else
		if ((st2 && !st1 && !st3 && !st4)) {
			//timer = 20;
			timer = std::max(0, timer - 1);
			fire.setPosition(fire.getPosition().x - cos(angle*pp) * 10, fire.getPosition().y - sin(angle*pp) * 10);
			window.draw(fire);
			if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
				((unghi > 90 && unghi < 270 && obstacleLeft(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
				(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
				(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
				(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
				(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
				(unghi > 0 && unghi < 180 && obstacleUp(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
				(unghi > 180 && unghi < 360 && obstacleDown(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))|| (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
				st2 = 0;
				if (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
					eHealth -= 1;
				if (eHealth < 0)
					eHealth = 0;
			}
			if (seHealth >= 1) {

				if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
					((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
					(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
					(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
					(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
					(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
					(unghi > 0 && unghi < 180 && obstacleUp(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
					(unghi > 180 && unghi < 360 && obstacleDown(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) || (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
					st1 = 0;
					if (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
						seHealth -= 1;
					if (seHealth < 0)
						seHealth = 0;
				}
			}
		}
		else
			if ((st3 && !st1 && !st2 && !st4)) {
				//timer = 20;
				timer = std::max(0, timer - 1);
				fire.setPosition(fire.getPosition().x - cos(angle*pp) * 10, fire.getPosition().y - sin(angle*pp) * 10);
				window.draw(fire);
				if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
					((unghi > 90 && unghi < 270 && obstacleLeft(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
					(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
					(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
					(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
					(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
					(unghi > 0 && unghi < 180 && obstacleUp(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
					(unghi > 180 && unghi < 360 && obstacleDown(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))|| (fire.getPosition().x < 10) || (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
					st3 = 0;
					if (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
						eHealth -= 1;
					if (eHealth < 0)
						eHealth = 0;
				}
				if (seHealth >=1) {

					if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
						((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
						(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
						(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
						(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
						(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
						(unghi > 0 && unghi < 180 && obstacleUp(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
						(unghi > 180 && unghi < 360 && obstacleDown(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) || (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
						st1 = 0;
						if (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
							seHealth -= 1;
						if (seHealth < 0)
							seHealth = 0;
					}
				}
			}
			else
				if ((st4 && !st1 && !st2 && !st3)) {
					//timer = 20;
					timer = std::max(0, timer - 1);
					fire.setPosition(fire.getPosition().x - cos(angle*pp) * 10, fire.getPosition().y - sin(angle*pp) * 10);
					window.draw(fire);
					if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
						((unghi > 90 && unghi < 270 && obstacleLeft(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
						(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
						(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
						(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
						(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
						(unghi > 0 && unghi < 180 && obstacleUp(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
						(unghi > 180 && unghi < 360 && obstacleDown(mpcur,fire.getPosition().x, fire.getPosition().y, choosedMap))|| (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))) {
						st4 = 0;
						if (intersect(enemy.getPosition().x, enemy.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20)){
							eHealth -= 1;
							st4 = 0;
						}

						if (eHealth < 0)
							eHealth = 0;
					}
					if (seHealth >= 1) {

						if (((fire.getPosition().y < 50 && unghi < 180 && unghi > 0)) ||
							((unghi > 90 && unghi < 270 && obstacleLeft(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap))) ||
							(fire.getPosition().x < 50 && ((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90))) ||
							(fire.getPosition().x > window.getSize().x - 50 && unghi > 90 && unghi < 270) ||
							(fire.getPosition().y > window.getSize().y - 50 && unghi > 180 && unghi < 360) ||
							(((unghi > 270 && unghi < 360) || (unghi > 1 && unghi < 90)) && obstacleRight(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
							(unghi > 0 && unghi < 180 && obstacleUp(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) ||
							(unghi > 180 && unghi < 360 && obstacleDown(mpcur, fire.getPosition().x, fire.getPosition().y, choosedMap)) || (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 25, fire.getPosition().x, fire.getPosition().y, 20))) {
							st1 = 0;
							if (intersect(enemyTwo.getPosition().x, enemyTwo.getPosition().y, 40, fire.getPosition().x, fire.getPosition().y, 20))
								seHealth -= 1;
							if (seHealth < 0)
								seHealth = 0;
						}
					}
				}
}


void make_explosion(sf::RenderWindow &window, sf::Sprite explosion[], int exp) {
	//std::cout << "->" << 25 - (exp / 2) << std::endl;
	window.draw(explosion[25 - (exp / 2) ]);
} 