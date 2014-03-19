#include <iostream>
#include "Game.h"

int main() {
	try {
		Game().mainloop();
	} catch (std::exception& e) {
		std::cout << "Blad" << std::endl;
	}
}
