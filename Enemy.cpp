#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), currentDirection(0)  {
	shape.move(xpos, ypos);
	leftDistance = 0;
}


void Enemy::moveIterate(sf::Time& t) {
//	int dir = rand() % 4;
//	int dis = rand() % CONF_movementRandomFactor;
//
//	switch (dir) {
//	case 0:
//		shape.move(dis*getSpeed()*t.asMilliseconds(), 0);
//		break;
//	case 1:
//		shape.move(-dis*getSpeed()*t.asMilliseconds(), 0);
//		break;
//	case 2:
//		shape.move(0, dis*getSpeed()*t.asMilliseconds());
//		break;
//	case 3:
//		shape.move(0, -dis*getSpeed()*t.asMilliseconds());
//	}

	if (leftDistance > 0) {
		double toMove = moveDistance*getSpeed()*t.asMilliseconds()/50.0;
		leftDistance -= toMove;
		switch (currentDirection) {
		case 0:
			shape.move(toMove, 0);
			break;
		case 1:
			shape.move(-toMove, 0);
			break;
		case 2:
			shape.move(0, toMove);
			break;
		case 3:
			shape.move(0, -toMove);
		}
	} else {
		moveDistance = rand() % 100;
		currentDirection = rand() % 4;
		leftDistance = moveDistance;
	}


}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}
