#include "Enemy.h"

Enemy::Enemy(int xpos, int ypos, std::vector<std::string> spritesString) : health(0), Moving(spritesString) {
//	tf.add(spritesString);
//	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
	health = 100; // TODO
}

void Enemy::damage(int damage) {
	health -= damage*getDamageCoeff();
}

