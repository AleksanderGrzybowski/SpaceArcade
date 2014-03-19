#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile { // z niej można by wywodzić pozostałe
public:

	static sf::Clock missileLimitClock;

	PowerMissile(double xpos, double ypos);
	virtual double getSpeed() { return CONF_missileSpeed; } // tu może być * 2

	virtual Missile* newMissile(double xpos, double ypos) {
		return new PowerMissile(xpos, ypos);
	}

	int getDamage() { return 2; }

};


#endif /* MISSILE_H_ */
