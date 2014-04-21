#ifndef NORMALENEMY_H_
#define NORMALENEMY_H_

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "config.h"

class NormalEnemy : public Enemy {
public:
	NormalEnemy(double xpos, double ypos);

	double getSpeed() const { return 0.2; }
	int getSize() const { return CONF_enemySize; }
	int getMaxHealth() const { return 10; }
	double getDamageCoeff() const { return 1; }
	int getPoints() const { return 1; }

private:
	std::vector<std::string> getSpritesString() const {
		return std::vector<std::string> {"Sprites/NormalEnemy.png"};
	}
};

#endif /* ENEMY_H_ */
