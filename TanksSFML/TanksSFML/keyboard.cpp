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
bool KeyW() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
}
bool KeyS() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S));
}
bool KeyA() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
}
bool KeyD() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D));
}
bool KeyQ() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q));
}
bool KeyEsc() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape));
}
bool Space() {
	return(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space));
}