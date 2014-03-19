#ifndef NORMALENEMY_H_
#define NORMALENEMY_H_

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class NormalEnemy : public Enemy {
public:
	NormalEnemy(double xpos, double ypos);

	double getSpeed() { return 0.2; }
	int getSize() { return 30; }
	sf::Color getColor() { return sf::Color::Blue; }
	int getMaxHealth() { return 10; }
	double getDamageCoeff() { return 1; }
};

#endif /* ENEMY_H_ */
