
#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {
	shape = sf::CircleShape(getSize(), 1000);
	shape.move(xpos, ypos);
	shape.setFillColor(getColor());
	health = getMaxHealth();
}

