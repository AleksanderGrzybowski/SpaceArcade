#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>
#include <exception>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "Ship.h"
#include "config.h"
#include "NormalMissile.h"
#include "PowerMissile.h"
#include "MissileFactory.h"
#include "Enemy.h"
#include "NormalEnemy.h"
#include "HardEnemy.h"
#include "EnemyFactory.h"
#include "Direction.h"
#include "Line.h"
#include "PointsCounter.h"

class GameOverException {};

class Game {
public:
	sf::RenderWindow window;
	sf::Clock clock;

	Ship ship;
	std::vector<Missile*> missiles;
	std::vector<Enemy*> enemies;
	Line line;
	PointsCounter pc;

	Game();

	bool loop();
	void mainloop() { while (loop()); }
	void addMissile();
	void addEnemy();
	void recalc();
	bool isCollision(sf::Vector2f mpos, sf::Vector2f epos, int msize, int esize); // pociski są kwadratami!!!
	void reset();
	void gameOver();
	~Game();
};

#endif /* GAME_H_ */
