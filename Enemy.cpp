#include "Enemy.h"

Enemy::Enemy() : health(0) {}

//void Enemy::moveIterate(sf::Time& t) {
//	double toMove = getSpeed()*t.asMilliseconds()/CONF_globalEnemySpeedFactor;
//	move(0, toMove);
//}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}

void Enemy::initialize(int xpos, int ypos) {
	std::cout << "enemy init" << std::endl;
	tf.add(getSpritesString());
	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
	health = getMaxHealth();
}
