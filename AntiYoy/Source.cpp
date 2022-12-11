#include <iostream>
#include "Maincore.h"




int main() {
	MainCore Engine = MainCore();
	while (Engine.gamestatus) {
		for (unsigned short int i = 0; i < 2; i++) {
			Engine.players[i].movestatus = true;
			while (Engine.players[i].movestatus) {
				/*if (Engine.GraphicsCore.events() == 'move') {
					Engine.GraphicsCore.moveprocess();
				}
				if (Engine.GraphicsCore.events() == 'buy') {
					Engine.GraphicsCore.buyprocess();
				}
				if (Engine.GraphicsCore.events() == 'end') {
					Engine.players[i].movestatus == false;
				}*/
			}
		}
		/*Engine.proccessing();*/
	}
	return 0;
}