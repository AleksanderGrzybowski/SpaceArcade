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
#include "Random.h"
#include "Bonus.h"
#include "SimpleBonus.h"
#include "GameOverText.h"
#include "PowerMissileIndicator.h"
class GameOverException {};

class Game {
public:
	Game();

	void mainloop() { while (loop()); }

	~Game();

private:
	sf::RenderWindow window;
	sf::Clock gameSpeedClock; // resetowany po każdym przebiegu pętli
	sf::Clock masterClock; // działa od początku gry


	Ship ship;
	std::vector<Missile*> missiles;
	std::vector<Enemy*> enemies;
	std::vector<Bonus*> bonuses;
	Line line;
	PowerMissileIndicator mind;
	PointsCounter pc;

	bool loop();
	void addEnemy();
	void addBonus();
	void recalc();

	static bool isCollision(sf::Vector2f mpos, sf::Vector2f epos, int msize, int esize); // pociski są kwadratami!!!

	void reset();
	void gameOver();
};

#endif /* GAME_H_ */
