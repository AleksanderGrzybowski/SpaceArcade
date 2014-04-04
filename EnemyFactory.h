#ifndef ENEMYFACTORY_H_
#define ENEMYFACTORY_H_

#include "Enemy.h"
#include "NormalEnemy.h"
#include "HardEnemy.h"
class EnemyFactory {
public:
	static Enemy* getRandomEnemy(int xpos, int ypos);
};

#endif /* ENEMYFACTORY_H_ */
