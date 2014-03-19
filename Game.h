#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp> // może redundant?
#include <iostream>
#include <vector>
#include "Ship.h"
#include "config.h"
#include "NormalMissile.h"
#include "PowerMissile.h"
#include "Enemy.h"
#include "NormalEnemy.h"
#include "HardEnemy.h"
#include "Direction.h"

class Game {
public:
	sf::RenderWindow window;
	Ship ship;

	sf::Clock clock;
	sf::Clock missileLimitClock; // będą różne missile z różnymi czasami limitu, przerobić to

	std::vector<Missile*> missiles;
	std::vector<Enemy*> enemies;

	int pointCount;
	sf::Font font;

	Game();
	bool loop();
	void mainloop() { while (loop()); }
	void addMissile();
	void addEnemy();
	void recalc();
	bool checkCollision(sf::Vector2f mpos, sf::Vector2f epos, int msize, int esize); // pociski są kwadratami!!!

};

#endif /* GAME_H_ */
