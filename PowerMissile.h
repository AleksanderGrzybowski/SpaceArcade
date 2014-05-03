#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile {
public:

	PowerMissile(int shipx, int shipy);

	static bool canBeSent();
	static void restartClock();

	// PowerMissileIndicator wymaga tego public
	static const int timeLimit;
	static sf::Clock missileLimitClock;
};


#endif /* MISSILE_H_ */
