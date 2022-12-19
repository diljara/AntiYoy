#include <iostream>
#include "Maincore.h"
#include <SFML/Graphics.hpp>
#include "Button.h"


void draw_endbutt(sf::RenderWindow* window) {
	sf::CircleShape endbutt(50.f);

	endbutt.setFillColor(sf::Color(255, 0, 0));
	sf::CircleShape* pont = &endbutt;
	endbutt.setPosition(sf::Vector2f(800.f, 800.f));
	window->draw(endbutt);
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
	Engine.fill_adj_list();
	bool gamestatus = true;
	while(window.isOpen()){
		while (gamestatus) {
			Button pl_num(sf::Vector2f(800.f, 100.f), &window, "1");
			Button pl0_mon(sf::Vector2f(800.f, 200.f), &window, "2");
			Button pl1_mon(sf::Vector2f(800.f, 300.f), &window, "3");
			Button* buttons[3] = { &pl_num, &pl0_mon, &pl1_mon };
			for (unsigned short int player_num = 0; player_num < 2; player_num++) {
				pl_num.change_txt("player_num : " + std::to_string(player_num));
				pl0_mon.change_txt("player_1: " + std::to_string(Engine.players[0]->money));
				pl1_mon.change_txt("player_2 : " + std::to_string(Engine.players[1]->money));
				while (Engine.players[player_num]->movestatus) {
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
								if ((mouse_pos.x - 860) * (mouse_pos.x - 860) + (mouse_pos.y - 890) * (mouse_pos.y - 890) < 1000) {
									Engine.players[player_num]->movestatus = false;

								}
								else {
									for (int i = 0; i < map_size; i++) {
										for (int j = 0; j < map_size; j++) {

											if (((mouse_pos.x - Engine.Map[i][j].centr[0]) * (mouse_pos.x - Engine.Map[i][j].centr[0]) + (mouse_pos.y - Engine.Map[i][j].centr[1]) * (mouse_pos.y - Engine.Map[i][j].centr[1])) <= 300 && Engine.Map[i][j].player_status == player_num + 1) {
												Engine.Map[i][j].color = sf::Color(0, 255, 0);
												
												Engine.Map[i][j].draw(pointer_win, arr[i][j]);
												window.draw(array[i][j]);
												
												
											
												window.display();
												
												bool flag_cell = true;
												while (flag_cell) {
													if (Engine.Map[i][j].entity_status == true) {
														std::cout << "BFS";
														/*!!!!!!!!!!!!!!!!!!!!

														BFS

														!!!!!!!!!!!!!!!!!!!!!!!!!!*/

														Engine.draw_way(&Engine.Map[i][j], &window);
														
														window.display();
														/*std::vector<Cell*> way_array = Engine.entity_steps(&Engine.Map[i][j]);*/
														while(true){}
														flag_cell = false;
													}
													else {
														while (window.pollEvent(event)) {
															if (event.type == sf::Event::Closed)
																window.close();
															if (event.type == sf::Event::KeyPressed) {
																if (event.key.code == sf::Keyboard::Escape) {
																	flag_cell = false;
																	Engine.Map[i][j].color = Engine.players[player_num]->color;
																}
															}

															if (event.type == sf::Event::MouseButtonPressed) {
																sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window.getPosition();
																if (((mouse_pos.x - Engine.Map[i][j].centr[0]) * (mouse_pos.x - Engine.Map[i][j].centr[0]) + (mouse_pos.y - Engine.Map[i][j].centr[1]) * (mouse_pos.y - Engine.Map[i][j].centr[1])) <= 300) {
																	if (Engine.players[player_num]->money >= 10) {
																		Engine.players[player_num]->money -= 10;
																		std::cout << "create" << i << j << '\n';
																		Engine.Map[i][j].color = sf::Color(0, 255, 255);
																		/*!!!!!!!!!!!!!!!!
																		

																		CREATE AN ENTITY

																		!!!!!!!!!!!!!!!!!!!!*/
																		Engine.createEnt(i, j, player_num);
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

					}
					window.clear();
					for (int i = 0; i < map_size; i++) {
						for (int j = 0; j < map_size; j++) {
							arr[i][j] = &array[i][j];
						}
					}
					for (auto button : buttons) {
						button->render();
					}
					for (int i = 0; i < map_size; i++) {
						for (int j = 0; j < map_size; j++) {
							Engine.Map[i][j].draw(pointer_win, arr[i][j]);
							window.draw(array[i][j]);
						}
					}
					draw_endbutt(&window);
					window.display();
				}
			}
			Engine.processing();
		}
	}
}