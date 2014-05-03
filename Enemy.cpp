#include "Enemy.h"

Enemy::Enemy(int xpos, int ypos, std::vector<std::string> spritesString, int size,
		int animationSpeed, double speed, int health, int pointsReceived) :
		Moving(xpos, ypos, spritesString, size, animationSpeed, speed, Down), health(health), pointsReceived(pointsReceived) {
//	tf.add(spritesString);
//	setTexture(tf.getFlip());
//	setPosition(xpos, ypos);
//	health = 100; // TODO

//	std::cout << "Tworzę enemy na pozycji" << xpos << " " << ypos << std::endl;
}

void Enemy::damage(int damage) {
	health -= damage;
}

