#ifndef NORMALENEMY_H_
#define NORMALENEMY_H_

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class NormalEnemy : public Enemy {
public:
	NormalEnemy(double xpos, double ypos);

	virtual void damage(int damage);
};

#endif /* ENEMY_H_ */
