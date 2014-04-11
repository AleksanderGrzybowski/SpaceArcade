#ifndef SIMPLEBONUS_H_
#define SIMPLEBONUS_H_

#include "Bonus.h"

class SimpleBonus : public Bonus {
public:
	SimpleBonus(double xpos, double ypos);
	double getSpeed() const { return 2*CONF_enemySpeed; }
	int getSize() const { return 32; }
	int getPoints() const { return 100; }

private:
	std::vector<std::string> getSpritesString() const {
		return std::vector<std::string> {"Sprites/SimpleBonus.png"};
	}
};

#endif /* SIMPLEBONUS_H_ */
