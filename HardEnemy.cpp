/*
 * HardEnemy.cpp
 *
 *  Created on: 17-03-2014
 *      Author: kelog
 */

#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	shape = sf::CircleShape(getSize(), 1000);
	shape.move(xpos, ypos);
	shape.setFillColor(getColor());
	health = getMaxHealth();
}

void HardEnemy::damage(int damage) {
	health -= damage;
}
