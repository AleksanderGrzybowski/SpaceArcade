/*
 * HardEnemy.cpp
 *
 *  Created on: 17-03-2014
 *      Author: kelog
 */

#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	health = 20;
}

void HardEnemy::damage(int damage) {
	health -= damage;
}
