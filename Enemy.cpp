#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), currentDirection(Up)  {
	shape.move(xpos, ypos);
	leftDistance = 0;
}

void Enemy::moveIterate(sf::Time& t) { // dodać niewychodzenie ich za ekran

	sf::Vector2f pos = shape.getPosition();

	if (pos.x < 0) {
		shape.setPosition(0, pos.y);
		currentDirection = Right;
		return;
	}
	if ((pos.x-64) > CONF_screenWidth) {
		std::cout << "Korekta" << rand() << std::endl;
		shape.setPosition(CONF_screenWidth-64, pos.y); // minus ileśtam (?)
		currentDirection = Left;
		return;
	}
	if (pos.y < 0) {
		shape.setPosition(pos.x, 0);
		currentDirection = Down;
		return;
	}
	if (pos.y > CONF_screenHeight*CONF_enemyDownLimit) {
		shape.setPosition(pos.x, CONF_screenHeight*CONF_enemyDownLimit);
		currentDirection = Up;
		return;
	}

	if (leftDistance > 0) {
		double toMove = moveDistance*getSpeed()*t.asMilliseconds()/50.0; // export
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
