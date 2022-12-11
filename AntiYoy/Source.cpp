#include <iostream>
#include "Maincore.h"




int main() {
	MainCore Engine = MainCore();
	while (Engine.gamestatus) {
		for (unsigned short int i = 0; i < 2; i++) {
			Engine.players[i]->movestatus = true;
			while (Engine.players[i]->movestatus) {
				/*Engine.GraphicsCore.render();
				string a = Engine.GraphicsCore.events();
				if (a == 'move') {
					Engine.moveprocess();
				}
				if (a == 'buy') {
					Engine.buyprocess();
				}
				if (a == 'end') {
					Engine.players[i].movestatus == false;
				}*/
			}
		}
		/*Engine.proccessing();*/
	}
	return 0;
}