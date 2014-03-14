
#ifndef GAME_H_
#define GAME_H_

using namespace std; // niezalecane, trudno
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ship.h"
#include "config.h"
#include "Missile.h"
#include "Enemy.h"

class Game {
public:
	sf::RenderWindow window;
	Ship ship;

	sf::Clock clock;
	sf::Clock missileLimitClock;

	vector<Missile*> missiles;
	vector<Enemy*> enemies;

	Game();
	void loop();
	void addMissile();
	void addEnemy();
	void recalc();

};

#endif /* GAME_H_ */
