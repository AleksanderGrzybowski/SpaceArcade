#ifndef ENEMYFACTORY_H_
#define ENEMYFACTORY_H_

#include "Enemy.h"
#include "NormalEnemy.h"
#include "HardEnemy.h"
#include "Random.h"

/* Ta klasa służy wyłącznie do tworzenia losowych przeciwników.
 * W całym programie nie zastosowano wzorca Factory,
 * bo nie było to przydatne ani dobre.
 */
class EnemyFactory {
public:
	static Enemy* getRandomEnemy(int xpos, int ypos);
};

#endif /* ENEMYFACTORY_H_ */
