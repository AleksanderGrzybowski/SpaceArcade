
#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : shape(20, 1000) {
	shape.move(xpos, ypos);
}


void Enemy::moveIterate(sf::Time& t) {
	int dir = rand() % 4;
	if (dir == 0) {
		shape.move(0.2*t.asMilliseconds(), 0);
	}
	if (dir == 1) {
		shape.move(-0.2*t.asMilliseconds(), 0);
	}
	if (dir == 2) {
		shape.move(0, 0.2*t.asMilliseconds());
	}
	if (dir == 0) {
		shape.move(0, -0.2*t.asMilliseconds());
	}
}
