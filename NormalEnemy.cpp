
#include "NormalEnemy.h"

NormalEnemy::NormalEnemy(double xpos, double ypos) : Enemy(xpos, ypos) {
	shape.setFillColor(sf::Color::Blue);
	health = 10;
}

void NormalEnemy::damage(int damage) {
	health -= damage; // dobrać stałe lepiej
}
