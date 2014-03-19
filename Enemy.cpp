#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : shape(CONF_enemySize, 1000), health(0) {
	shape.move(xpos, ypos);


}


void Enemy::moveIterate(sf::Time& t) {
	int dir = rand() % 4;
	int dis = rand() % CONF_movementRandomFactor;

	switch (dir) {
	case 0:
		shape.move(dis*CONF_enemySpeed*t.asMilliseconds(), 0);
		break;
	case 1:
		shape.move(-dis*CONF_enemySpeed*t.asMilliseconds(), 0);
		break;
	case 2:
		shape.move(0, dis*CONF_enemySpeed*t.asMilliseconds());
		break;
	case 3:
		shape.move(0, -dis*CONF_enemySpeed*t.asMilliseconds());
	}
}
