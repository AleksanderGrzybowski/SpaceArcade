/*
 * HardEnemy.h
 *
 *  Created on: 17-03-2014
 *      Author: kelog
 */

#ifndef HARDENEMY_H_
#define HARDENEMY_H_

#include "Enemy.h"

class HardEnemy: public Enemy {
public:
	HardEnemy(double xpos, double ypos);

	void damage(int damage);
};

#endif /* HARDENEMY_H_ */
