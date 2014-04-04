#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	tf.add(std::vector<std::string> {"Sprites/HardEnemy.png"});
	sprite.setTexture(tf.getFlip());
	sprite.setPosition(xpos, ypos);
	health = getMaxHealth();
}
