
#ifndef GAME_H_
#define GAME_H_

using namespace std; // niezalecane, trudno
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "config.h"


class Game {
public:
	sf::RenderWindow window;
	Ship ship;
	sf::Clock clock;

	Game();
	void loop();

};

#endif /* GAME_H_ */
