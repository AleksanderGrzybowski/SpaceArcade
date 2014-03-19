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

	double getSpeed() { return 0.3; }
	int getSize() { return 50; }
	sf::Color getColor() { return sf::Color::Red; }
	int getMaxHealth() { return 20; }
	double getDamageCoeff() { return 0.5; }
};

#endif /* HARDENEMY_H_ */
