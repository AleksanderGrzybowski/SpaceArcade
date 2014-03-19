#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/NormalEnemy.png");
	shape.setTexture(*texture);

	shape.move(xpos, ypos);
	health = getMaxHealth();
}
