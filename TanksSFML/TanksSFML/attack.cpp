#include "attack.hpp"
#include "objects.hpp"
#include "game.h"

void attack( sf::RectangleShape &fire, sf::RectangleShape player, sf::RectangleShape enemy,   int case0) {
	if (case0 == 0) 
		fire.setPosition( player.getPosition().x + 31 , player.getPosition().y - 12);
	if (case0 == 1)
		fire.setPosition(player.getPosition().x + 31, player.getPosition().y +30);
	if (case0 == 2)
		fire.setPosition(player.getPosition().x, player.getPosition().y + 20 );
	if(case0 == 3)
		fire.setPosition(player.getPosition().x + 51, player.getPosition().y + 20);
}

/*
void check(bool &st1, bool &st2, bool &st3, bool &st4, int &eHealth, sf::RectangleShape &fire, sf::RectangleShape &enemy) {
	if (st1 && !st2 && !st3 && !st4) {
		fire.move(0, -15);
		window.draw(fire);
		if (fire.getPosition().y < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20)
			|| obstacleUp(fire.getPosition().x, fire.getPosition().y)) {
			st1 = 0;
			if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
				eHealth -= 10;
		}
	}
	else
		if (st2 && !st1 && !st3 && !st4) {
			fire.move(0, 15);
			window.draw(fire);
			if (fire.getPosition().y > window.getSize().y - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20)
				|| obstacleDown(fire.getPosition().x, fire.getPosition().y - 40)) {
				st2 = 0;
				if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
					eHealth -= 10;
			}
		}
		else
			if (st3 && !st1 && !st2 && !st4) {
				fire.move(-15, 0);
				window.draw(fire);
				if (fire.getPosition().x < 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) ||
					obstacleLeft(fire.getPosition().x - 90, fire.getPosition().y)) {
					st3 = 0;
					if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
						eHealth -= 10;
				}
			}
			else
				if (st4 && !st1 && !st2 && !st3) {
					fire.move(15, 0);
					window.draw(fire);
					if (fire.getPosition().x > window.getSize().x - 10 || intersect(enemy.getPosition().x, enemy.getPosition().y, 10, fire.getPosition().x, fire.getPosition().y, 20) ||
						obstacleRight(fire.getPosition().x + 50, fire.getPosition().y)) {
						st4 = 0;
						if (intersect(enemy.getPosition().x, enemy.getPosition().y, 20, fire.getPosition().x, fire.getPosition().y, 20))
							eHealth -= 10;
					}
				}

} */