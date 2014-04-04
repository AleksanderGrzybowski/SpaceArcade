#include "EnemyFactory.h"

Enemy* EnemyFactory::getRandomEnemy(int xpos, int ypos) {
	if (rand() % 2) return new NormalEnemy(xpos, ypos);
	else return new HardEnemy(xpos, ypos);
}
