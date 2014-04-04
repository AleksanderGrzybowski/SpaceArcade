#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile {
public:
	static sf::Clock missileLimitClock;
	static sf::Clock animationSpeedClock;
	static const int timeLimit;

	NormalMissile(int shipx, int shipy);

	static bool canBeSent();
	int getDamage() { return 5; }
	double getSpeed() { return 0.5; }
	int getSize() { return 24; }
};

#endif /* MISSILE_H_ */
