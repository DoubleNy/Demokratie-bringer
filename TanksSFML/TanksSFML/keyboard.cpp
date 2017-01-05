#include "keyboard.h"

bool KeyUp() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
}
bool KeyDown() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
}
bool KeyLeft() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));
}
bool KeyRight() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right));
}
bool KeyEsc() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape));
}
bool Space() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space));
}