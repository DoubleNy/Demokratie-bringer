#include "getStart.hpp"
int start() {
	sf::RenderWindow window(sf::VideoMode(924, 704), "Are you ready for tanks ?");
	sf::Texture txt;
	sf::RectangleShape wallpaper(sf::Vector2f(924.0f, 704.0f));
	if (!txt.loadFromFile("wall.jpg")) {
		std::cout << "Eroare cu wall-ul" << std::endl;
		std::cin.get();
		return 0;
	}
	//
	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//
	wallpaper.setTexture(&txt);
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem()) {
					case 0:
						std::cout << " Play button has been pressed" << std::endl;
						window.close();
						game();
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(wallpaper);
		menu.draw(window);
		window.display();
	}
	return(0);
}