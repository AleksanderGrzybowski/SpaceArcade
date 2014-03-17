#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Ship.h"
#include "config.h"
#include "NormalMissile.h"
#include "Enemy.h"
#include "Direction.h"

class Game {
public:
	sf::RenderWindow window;
	Ship ship;

	sf::Clock clock;
	sf::Clock missileLimitClock;

	std::vector<Missile*> missiles;
	std::vector<Enemy*> enemies;

	Game();
	void loop();
	void addMissile();
	void addEnemy();
	void recalc();

};

#endif /* GAME_H_ */
