#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), leftDistance(0), currentDirection((Direction)(rand() % 4))  {
	sprite.move(xpos, ypos);
}

void Enemy::moveIterate(sf::Time& t) {

	sf::Vector2f pos = getPosition();

	if (pos.x < 0) {
		pos.x = 0;
		sprite.setPosition(pos.x, pos.y);
		currentDirection = Right;
	}
	if (pos.x > (CONF_screenWidth-64)) {
		pos.x = CONF_screenWidth-64;
		sprite.setPosition(pos.x, pos.y);
		currentDirection = Left;
	}
	if (pos.y < 0) {
		pos.y = 0;
		sprite.setPosition(pos.x, pos.y);
		currentDirection = Down;
	}
	if (pos.y > CONF_screenHeight*CONF_enemyDownLimit) {
		pos.y = CONF_screenHeight*CONF_enemyDownLimit;
		sprite.setPosition(pos.x, pos.y);
		currentDirection = Up;
	}


	if (leftDistance > 0) {
		double toMove = moveDistance*getSpeed()*t.asMilliseconds()/CONF_globalEnemySpeedFactor;
		leftDistance -= toMove;

		switch (currentDirection) {
		case Right:
			sprite.move(toMove, 0);
			break;
		case Left:
			sprite.move(-toMove, 0);
			break;
		case Down:
			sprite.move(0, toMove);
			break;
		case Up:
			sprite.move(0, -toMove);
		}
	} else {
		moveDistance = rand() % 100;
		currentDirection = (Direction)(rand() % 4);
		leftDistance = moveDistance; // obie równe sobie
	}
}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}
