#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile { // z niej można by wywodzić pozostałe
public:
	static sf::Clock missileLimitClock;
	NormalMissile(double xpos, double ypos);

	virtual Missile* newMissile(double xpos, double ypos) {
		return new NormalMissile(xpos, ypos);
	}
};


#endif /* MISSILE_H_ */
