#include <iostream>
#include "Maincore.h"


int main() {
	MainCore Engine = MainCore();
	while (Engine.gamestatus) {
		for (unsigned short int i = 0; i < 2; i++) {
			Engine.players[i].movestatus = 1;
			while (Engine.players[i].movestatus) {
				/*Need to write an algorythm of playing game*/
			}
		}
	}
	return 0;
}