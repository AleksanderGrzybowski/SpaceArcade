#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), currentDirection(Up)  {
	shape.move(xpos, ypos);
	leftDistance = 0;
}

void Enemy::moveIterate(sf::Time& t) { // dodać niewychodzenie ich za ekran
	if (leftDistance > 0) {
		double toMove = moveDistance*getSpeed()*t.asMilliseconds()/50.0;
		leftDistance -= toMove;

		switch (currentDirection) { // na enum
		case Right:
			shape.move(toMove, 0);
			break;
		case Left:
			shape.move(-toMove, 0);
			break;
		case Down:
			shape.move(0, toMove);
			break;
		case Up:
			shape.move(0, -toMove);
		}
	} else {
		moveDistance = rand() % 100;
		currentDirection = (Direction)(rand() % 4);
		leftDistance = moveDistance;
	}
}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}
