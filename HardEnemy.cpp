#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	sf::Texture t;
	t.loadFromFile("Sprites/HardEnemy.png"); // na razie bez animacji
	tf.add(t);
	sprite.setTexture(tf.getFlip());
	sprite.move(xpos, ypos);
	health = getMaxHealth();
}
