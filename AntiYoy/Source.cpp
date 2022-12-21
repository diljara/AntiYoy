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
	bool flag_step;
	Engine.fill_adj_list();
	bool gamestatus = true;
	while(window.isOpen()){
		while (gamestatus) {
			Button pl_num(sf::Vector2f(800.f, 100.f), &window, "1");
			Button pl0_mon(sf::Vector2f(800.f, 200.f), &window, "2");
			Button pl1_mon(sf::Vector2f(800.f, 300.f), &window, "3");
			Button* buttons[3] = { &pl_num, &pl0_mon, &pl1_mon };
			for (unsigned short int player_num = 0; player_num < 2; player_num++) {
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
												Engine.Map[i][j].draw_point(&window);
												window.display();
												
												bool flag_cell = true;
												while (flag_cell) {
													if (Engine.Map[i][j].entity_status == true && Engine.Map[i][j].entity_pointer->move_status == 1) {
														while (window.pollEvent(event)) {
															if (event.type == sf::Event::Closed)
																window.close();
															if (event.type == sf::Event::KeyPressed) {
																if (event.key.code == sf::Keyboard::Escape) {
																	flag_cell = false;
																}
															}
															Engine.Map[i][j].entity_pointer->move_status = 0;
															/*!!!!!!!!!!!!!!!!!!!!

															BFS

															!!!!!!!!!!!!!!!!!!!!!!!!!!*/

															Engine.draw_way(&Engine.Map[i][j], &window);
														
															window.display();
															flag_step = 1;
															while (flag_step) {
																while (window.pollEvent(event)) {
																	if (event.type == sf::Event::Closed)
																		window.close();
																	if (event.type == sf::Event::KeyPressed) {
																		if (event.key.code == sf::Keyboard::Escape) {
																			flag_step = false;
																			Engine.Map[i][j].color = Engine.players[player_num]->color;
																		}
																	}

																	if (event.type == sf::Event::MouseButtonPressed) {
																		if (event.mouseButton.button == sf::Mouse::Left) {
																			for (int counter3 = 0; counter3 < Engine.entity_steps(&Engine.Map[i][j]).size(); counter3++) {
																				if (Engine.get_x(&window) == Engine.entity_steps(&Engine.Map[i][j])[counter3]->map_coord[0] && Engine.get_y(&window) == Engine.entity_steps(&Engine.Map[i][j])[counter3]->map_coord[1]) {
																					Cell* nextstep = Engine.entity_steps(&Engine.Map[i][j])[counter3];
																					Entity* ent_cell = nextstep->entity_pointer;
																					if (nextstep->entity_status == 1) {
																						for (int counter4 = 0; counter4 < Engine.Entities.size(); counter4++) {
																							if (Engine.Entities[counter4] == ent_cell) {
																								Engine.Entities[counter4] = Engine.Entities[Engine.Entities.size() - 1];
																								Engine.ent[counter4] = Engine.ent[Engine.Entities.size() - 1];
																								Engine.ent.pop_back();
																								Engine.Entities.pop_back();
																							}
																						}
																					}
																					nextstep->color = Engine.players[player_num]->color;
																					nextstep->player_status = player_num + 1;
																					nextstep->entity_status = 1;
																					nextstep->entity_pointer = Engine.Map[i][j].entity_pointer;
																					Engine.Map[i][j].entity_pointer = nullptr;
																					Engine.Map[i][j].entity_status = 0;
																					nextstep->entity_pointer->map_coord[0] = nextstep->map_coord[0];
																					nextstep->entity_pointer->map_coord[1] = nextstep->map_coord[1];
																					flag_step = false;
																					break;
																				}
																			}
																		}
																	}



																}
															}
														}
														flag_cell = false;
													}
													if(Engine.Map[i][j].entity_status != true) {
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
					pl_num.change_txt("player_num : " + std::to_string(player_num));
					pl0_mon.change_txt("player_1: " + std::to_string(Engine.players[0]->money));
					pl1_mon.change_txt("player_2 : " + std::to_string(Engine.players[1]->money));
					window.clear();
					for (auto button : buttons) {
						button->render();
					}
					for (int i = 0; i < map_size; i++) {
						for (int j = 0; j < map_size; j++) {
							Engine.Map[i][j].draw(pointer_win);
						}
					}
					draw_endbutt(&window);
					window.display();
				}
			}
			Engine.processing(&window);
		}
	}
}