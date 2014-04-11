#include "Enemy.h"

Enemy::Enemy() : health(0) {}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}

void Enemy::initialize(int xpos, int ypos) {
	tf.add(getSpritesString());
	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
	health = getMaxHealth();
}
