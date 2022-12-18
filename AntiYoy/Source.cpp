#include <iostream>
#include "Maincore.h"
#include <SFML/Graphics.hpp>

void drawhex(int x, int y, sf::RenderWindow* window, sf::ConvexShape* arr) {
	sf::ConvexShape* hex;
	hex = arr;
	hex->setPointCount(6);
	int a = 20;
	float startx = 100 + 3 * a * x / 2;
	float starty = 100 + x % 2 * a * sqrt(3) / 2 + sqrt(3) * a * y;
	hex->setPoint(0, sf::Vector2f(startx, starty));
	hex->setPoint(1, sf::Vector2f(startx + a / 2, starty - a * sqrt(3) / 2));
	hex->setPoint(2, sf::Vector2f(startx + a * 3 / 2, starty - a * sqrt(3) / 2));
	hex->setPoint(3, sf::Vector2f(startx + 2 * a, starty));
	hex->setPoint(4, sf::Vector2f(startx + a * 3 / 2, starty + a * sqrt(3) / 2));
	hex->setPoint(5, sf::Vector2f(startx + a / 2, starty + a * sqrt(3) / 2));
	hex->setFillColor(sf::Color(255, 0, 0));
	hex->setOutlineThickness(1.f);
	hex->setOutlineColor(sf::Color(100, 150, 100));
}

void main() {
	MainCore Engine = MainCore();
	//sf::Clock clc;
	//while(Engine.GraphicsCore.window->isOpen()){
	//	while (Engine.gamestatus) {
	//		for (unsigned short int i = 0; i < 2; i++) {
	//			Engine.players[i]->movestatus = true;
	//			while (Engine.players[i]->movestatus) {
	//				/*Engine.GraphicsCore.update();*/
	//			}
	//		}
	//		/*Engine.processing();*/
	//	}
	//}


	int map_size = 20;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
	sf::RenderWindow* pointer_win = &window;
	sf::Clock clc;
	sf::Event event;
	sf::ConvexShape array[20][20];
	sf::ConvexShape* arr[20][20];
	bool gamestatus = true;
	while(window.isOpen()){
		while (gamestatus) {
			for (unsigned short int player_num = 0; player_num < 2; player_num++) {
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Escape)
							window.close();
					}

					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.mouseButton.button == sf::Mouse::Left) {
							sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window.getPosition();
							for (int i = 0; i < map_size; i++) {
								for (int j = 0; j < map_size; j++) {
									if (((mouse_pos.x - Engine.Map[i][j].centr[0]) * (mouse_pos.x - Engine.Map[i][j].centr[0]) + (mouse_pos.y - Engine.Map[i][j].centr[1]) * (mouse_pos.y - Engine.Map[i][j].centr[1])) <= 196) {
										std::cout << i << j << '\n';
										bool flag_cell = true;
										while (flag_cell) {
											if (Engine.Map[i][j].entity_status == true) {
												std::cout << "BFS";
												/*!!!!!!!!!!!!!!!!!!!!

												BFS

												!!!!!!!!!!!!!!!!!!!!!!!!!!*/
											}
											else {
												while (window.pollEvent(event)) {
													if (event.type == sf::Event::Closed)
														window.close();
													if (event.type == sf::Event::KeyPressed) {
														if (event.key.code == sf::Keyboard::Escape)
															flag_cell = false;
													}

													if (event.type == sf::Event::MouseButtonPressed) {
														sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window.getPosition();
														if (((mouse_pos.x - Engine.Map[i][j].centr[0]) * (mouse_pos.x - Engine.Map[i][j].centr[0]) + (mouse_pos.y - Engine.Map[i][j].centr[1]) * (mouse_pos.y - Engine.Map[i][j].centr[1])) <= 196) {
															if (Engine.players[player_num]->money >= 10) {
																Engine.players[player_num]->money -= 10;
																std::cout << "create" << i << j << '\n';
																/*!!!!!!!!!!!!!!!!

																CREATE AN ENTITY

																!!!!!!!!!!!!!!!!!!!!*/
																flag_cell = false;
															}
														}
													}
												}
											}
										}
									}
								}
							}


						}
					}

				}
				window.clear();
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						arr[i][j] = &array[i][j];
					}
				}
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						drawhex(i, j, pointer_win, arr[i][j]);
						window.draw(array[i][j]);
					}
				}
				window.display();
			}
		}
	}
}