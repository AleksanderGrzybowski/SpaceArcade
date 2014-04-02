#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/NormalEnemy.png");
	sprite.setTexture(*texture);

	sprite.move(xpos, ypos);
	health = getMaxHealth();
}
