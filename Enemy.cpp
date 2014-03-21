#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0), moveDistance(0), currentDirection(Up)  {
	shape.move(xpos, ypos);
	leftDistance = 0;
}

void Enemy::moveIterate(sf::Time& t) { // dodać niewychodzenie ich za ekran

	sf::Vector2f pos = shape.getPosition();

	bool bad = false;

	if (pos.x < 0) { //bad=true;
//		std::cout << "Mam zły obiekt na pozycji"<< pos.x << " " << pos.y << std::endl;
		pos.x = 0;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Right;
//		return;
	}
	if (pos.x > (CONF_screenWidth-64)) {bad=true;

		std::cout << "Mam zły obiekt na pozycji"<< pos.x << " " << pos.y << std::endl;
		pos.x = CONF_screenWidth-64;
		shape.setPosition(pos.x, pos.y); // minus ileśtam (?) // było 64

		currentDirection = Left;
//		return;
	}
	if (pos.y < 0) {//bad=true;
//		std::cout << "Mam zły obiekt na pozycji"<< pos.x << " " << pos.y << std::endl;
//		std::cout << "Korekta" << rand() << std::endl;
		pos.y = 0;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Down;
//		return;
	}
	if (pos.y > CONF_screenHeight*CONF_enemyDownLimit) {//bad=true;
//		std::cout << "Mam zły obiekt na pozycji"<< pos.x << " " << pos.y << std::endl;
		pos.y = CONF_screenHeight*CONF_enemyDownLimit;
		shape.setPosition(pos.x, pos.y);
		currentDirection = Up;
//		return;
	}

	if (bad) {
		std::cout << "Poprawiono " << pos.x << " " << pos.y << std::endl;
		bad = false;
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

	//shape.setPosition(10, 10);
}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}
