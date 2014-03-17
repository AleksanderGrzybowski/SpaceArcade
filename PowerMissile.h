#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile { // z niej można by wywodzić pozostałe
public:


	PowerMissile(double xpos, double ypos);
	virtual double getSpeed() { return CONF_missileSpeed*2; }

};

#endif /* MISSILE_H_ */
