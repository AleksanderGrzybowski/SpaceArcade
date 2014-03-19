#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {
	shape = sf::RectangleShape(sf::Vector2f(getSize(), getSize()));
	shape.move(xpos, ypos);
	shape.setFillColor(getColor());
	health = getMaxHealth();
}
