#include "HardEnemy.h"

HardEnemy::HardEnemy(double xpos, double ypos) : Enemy(xpos,ypos) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/HardEnemy.png");
	shape.setTexture(*texture);

	shape.move(xpos, ypos);
	health = getMaxHealth();
}
