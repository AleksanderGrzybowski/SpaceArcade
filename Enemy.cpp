#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), currentDirection(Up)  {
	shape.move(xpos, ypos);
	leftDistance = 0;
}

void Enemy::moveIterate(sf::Time& t) {

	sf::Vector2f pos = shape.getPosition();


	if (pos.x < 0) {
		pos.x = 0;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Right;
	}
	if (pos.x > (CONF_screenWidth-64)) {
		pos.x = CONF_screenWidth-64;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Left;
	}
	if (pos.y < 0) {
		pos.y = 0;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Down;
	}
	if (pos.y > CONF_screenHeight*CONF_enemyDownLimit) {
		pos.y = CONF_screenHeight*CONF_enemyDownLimit;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Up;
	}


	if (leftDistance > 0) {
		double toMove = moveDistance*getSpeed()*t.asMilliseconds()/50.0; // export
		leftDistance -= toMove;

		switch (currentDirection) {
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
