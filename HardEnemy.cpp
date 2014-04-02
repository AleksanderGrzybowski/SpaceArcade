#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/HardEnemy.png");
	sprite.setTexture(*texture);

	sprite.move(xpos, ypos);
	health = getMaxHealth();
}
