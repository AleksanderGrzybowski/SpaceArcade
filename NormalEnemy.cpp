#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/NormalEnemy.png");
	shape.setTexture(*texture);

	//shape = sf::RectangleShape(sf::Vector2f(getSize(), getSize()));
	shape.move(xpos, ypos);
	//shape.setFillColor(getColor());
	health = getMaxHealth();
}
