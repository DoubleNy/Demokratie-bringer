#include "attack.hpp"

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