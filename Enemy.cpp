#include "Enemy.h"

Enemy::Enemy(double xpos, double ypos) : health(0) {
	sprite.move(xpos, ypos);
}

void Enemy::moveIterate(sf::Time& t) {
	double toMove = getSpeed()*t.asMilliseconds()/CONF_globalEnemySpeedFactor;
	sprite.move(0, toMove);
}
void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}
