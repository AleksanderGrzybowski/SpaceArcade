#include <iostream>
#include "Game.h"
#include "Random.h"

int main() {
	//for (int i = 0; i < 100; ++i) std::cout << "Proba " << i << " " << Random::tryChance(100) << std::endl;

	try {
		Game().mainloop();
	} catch (std::exception& e) {
		std::cout << "Blad" << std::endl;
	}

}
