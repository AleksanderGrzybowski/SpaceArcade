#ifndef HARDENEMY_H_
#define HARDENEMY_H_

#include "Enemy.h"

class HardEnemy: public Enemy {
public:
	HardEnemy(double xpos, double ypos);

	double getSpeed() { return 0.9*CONF_enemySpeed; }
	int getSize() { return 64; }
	int getMaxHealth() { return 20; }
	double getDamageCoeff() { return 0.5; }
	int getPoints() { return 5; }


private:
	std::vector<std::string> getSpritesString() {
		return std::vector<std::string> {"Sprites/HardEnemy.png"};
	}
};

#endif /* HARDENEMY_H_ */
