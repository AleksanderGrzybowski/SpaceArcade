#ifndef HARDENEMY_H_
#define HARDENEMY_H_

#include "Enemy.h"

class HardEnemy: public Enemy {
public:
	HardEnemy(double xpos, double ypos);

	double getSpeed() const { return 0.1; }
	int getSize() const { return CONF_enemySize; }
	int getMaxHealth() const { return 20; }
	double getDamageCoeff() const { return 0.5; }
	int getPoints() const { return 5; }

private:
	const std::vector<std::string> getSpritesString() const {
		return std::vector<std::string> {"Sprites/HardEnemy_.png"};
	}
};

#endif /* HARDENEMY_H_ */
