#include "getStart.hpp"
#include "SFML\Audio.hpp"
#include "menu.h"
#include <algorithm>    // std::max

int choosedMap;
bool multiplayer = 0;

int start() {
	sf::Music switchEffect;
	if (!switchEffect.openFromFile("switch.ogg")) {
		std::cout << "Eroare" << std::endl;
		return 0;
	}
	sf::RenderWindow window(sf::VideoMode(924, 704), "Are you ready for tanks ?");
	sf::RectangleShape romanian(sf::Vector2f(70, 50));
	sf::RectangleShape english(sf::Vector2f(70, 50));
	sf::RectangleShape russian(sf::Vector2f(70, 50));
	sf::Texture image;
	sf::Texture image1;
	sf::Texture image2;
	sf::Font fnt;
	fnt.loadFromFile("arial.ttf");
	image.loadFromFile("romanian.png");
		romanian.setTexture(&image);
		romanian.setPosition(650, 10);
	image1.loadFromFile("russian.png");
		russian.setTexture(&image1);
		russian.setPosition(750, 10);
	image2.loadFromFile("english.png");
		english.setTexture(&image2);
		english.setPosition(850, 10);
	sf::Texture txt;
	sf::Text modch;
	modch.setFont(fnt);
	modch.setCharacterSize(20);
	sf::Texture language;
	sf::RectangleShape wallpaper(sf::Vector2f(924.0f, 704.0f));
	if (!txt.loadFromFile("wall.png")) {
			std::cout << "Eroare cu wall-ul" << std::endl;
			std::cin.get();
			return 0;
	}
	//label down;
	//
	switchEffect.setPitch(3);
	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//
	bool musicIsPlaying = 0;
	int lang = 2;
	int CHmenu = 0;
	wallpaper.setTexture(&txt);
	Menu meniu(window.getSize().x, window.getSize().y);
	while (window.isOpen()) {
		if (multiplayer)
				modch.setString("Multiplayer mode");
			else
				modch.setString("Single mode");
			modch.setFillColor(sf::Color::White);
			modch.setPosition(700, 630);
			window.draw(modch);
			sf::Event event;
			if (1) {
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (position.x >= 650 && position.x <= 650 + 70 && position.y <= 60 && position.y >= 10) {
					std::cout << "here" << std::endl;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						lang = 0;
					}
				}
				if (position.x >= 750 && position.x <= 750 + 70 && position.y <= 60 && position.y >= 10) {
					std::cout << "here" << std::endl;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						lang = 1;
					}
				}
				if (position.x >= 850 && position.x <= 850 + 70 && position.y <= 60 && position.y >= 10) {
					std::cout << "here" << std::endl;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						lang = 2;
					}
				}
			}
			while (window.pollEvent(event)) {
					switch (event.type) {
							case sf::Event::KeyReleased:
									switch (event.key.code) {
											case sf::Keyboard::Up:
													if(CHmenu != 0)
														switchEffect.play();
														CHmenu = std::max(0, CHmenu - 1);
														meniu.MoveUp(0);
													break;
											case sf::Keyboard::Down:
													if(CHmenu != 2)
														switchEffect.play();
														CHmenu = std::min(2, CHmenu + 1);
														meniu.MoveDown(0);
													break;
											case sf::Keyboard::Return:
														switch (meniu.GetPressedItem()) {
															case 0:
																std::cout << " Play button has been pressed" << std::endl;
																	//
																				while (window.isOpen()) {
																					if (multiplayer)
																						modch.setString("Multiplayer mode");
																					else
																						modch.setString("Single mode");
																					sf::Event event;
																					while (window.pollEvent(event)) {
																						switch (event.type) {
																						case sf::Event::KeyReleased:
																							switch (event.key.code) {
																							case sf::Keyboard::Up:
																								if (CHmenu != 0)
																									switchEffect.play();
																								CHmenu = std::max(0, CHmenu - 1);
																								meniu.MoveUp(1);
																								break;
																							case sf::Keyboard::Down:
																								if (CHmenu != 2)
																									switchEffect.play();
																								CHmenu = std::min(2, CHmenu + 1);
																								meniu.MoveDown(1);
																								break;
																							case sf::Keyboard::Return:
																								switch (meniu.GetPressedItem2()) {
																								case 0:
																									std::cout << "LEVEL I" << std::endl;
																									choosedMap = 0;
																									window.close();
																									game();
																									break;
																								case 1:
																									std::cout << "LEVEL II" << std::endl;
																									choosedMap = 1;
																									window.close();
																									game();
																									break;
																								case 2:
																									std::cout << "LEVEL III" << std::endl;
																									choosedMap = 2;
																									window.close();
																									game();
																									break;
																								}
																								break;
																							}//sqitch(event.key)
																							break;
																						case sf::Event::Closed:
																							window.close();
																							break;
																						} // switch(event.type)
																					} // while(pollEvent)
																					window.clear();
																					window.draw(wallpaper);
																					meniu.draw(1, window, lang);
																					window.draw(modch);
																					window.display();
																				}
																	//
															break;
															case 1:
																std::cout << "Option button has been pressed" << std::endl;
																	//
																			while (window.isOpen()) {
																				if (multiplayer)
																					modch.setString("Multiplayer mode");
																				else
																					modch.setString("Single mode");
																				sf::Event event;
																				while (window.pollEvent(event)) {
																					switch (event.type) {
																					case sf::Event::KeyReleased:
																						switch (event.key.code) {
																						case sf::Keyboard::Up:
																							if (CHmenu != 0)
																								switchEffect.play();
																							CHmenu = std::max(0, CHmenu - 1);
																							meniu.MoveUp(2);
																							break;
																						case sf::Keyboard::Down:
																							if (CHmenu != 2)
																								switchEffect.play();
																							CHmenu = std::min(2, CHmenu + 1);
																							meniu.MoveDown(2);
																							break;
																						case sf::Keyboard::Return:
																							switch (meniu.GetPressedItem3()) {
																							case 0:
																								std::cout << "Tanks" << std::endl;
																	
																								break;
																							case 1:
																								std::cout << "Game Mode" << std::endl;
																								//
																								while (window.isOpen()) {
																									if (multiplayer)
																										modch.setString("Multiplayer mode");
																									else
																										modch.setString("Single mode");
																									sf::Event event;
																									while (window.pollEvent(event)) {
																										switch (event.type) {
																										case sf::Event::KeyReleased:
																											switch (event.key.code) {
																											case sf::Keyboard::Up:
																												if (CHmenu != 0)
																													switchEffect.play();
																												CHmenu = std::max(0, CHmenu - 1);
																												meniu.MoveUp(3);
																												break;
																											case sf::Keyboard::Down:
																												if (CHmenu != 2)
																													switchEffect.play();
																												CHmenu = std::min(2, CHmenu + 1);
																												meniu.MoveDown(3);
																												break;
																											case sf::Keyboard::Return:
																												switch (meniu.GetPressedItem4()) {
																												case 0:
																													std::cout << "Multiplayer" << std::endl;
																													multiplayer = 1;
																													break;
																												case 1:
																													std::cout << "Computer" << std::endl;
																													multiplayer = 0;
																													break;
																												case 2:
																													std::cout << "Back" << std::endl;
																													//window.close();
																													goto down1;
																													break;
																												}
																												break;
																											}//sqitch(event.key)
																											break;
																										case sf::Event::Closed:
																											window.close();
																											break;
																										} // switch(event.type)
																									} // while(pollEvent)
																									window.clear();
																									window.draw(wallpaper);
																									meniu.draw(3, window, lang);
																									window.draw(modch);
																									window.display();
																								}
																								//
																								down1:
																								break;
																							case 2:
																								std::cout << "Back" << std::endl;
																								//window.close();
																								goto down;
																								break;
																							}
																							break;
																						}//sqitch(event.key)
																						break;
																					case sf::Event::Closed:
																						window.close();
																						break;
																					} // switch(event.type)
																				} // while(pollEvent)
																				window.clear();
																				window.draw(wallpaper);
																				meniu.draw(2, window, lang);
																				window.draw(modch);
																				window.display();
																			}
																	//
																down:
																break;
															case 2:
																window.close();
																break;
														}
														break;
									}//sqitch(event.key)
									break;
		 						case sf::Event::Closed:
										window.close();
										break;
				} // switch(event.type)
		} // while(pollEvent)
		window.clear();
		window.draw(wallpaper);
		window.draw(romanian);
		window.draw(russian);
		window.draw(english);
		meniu.draw(0, window, lang);
		window.draw(modch);
		window.display();
	}
	return(0);
}