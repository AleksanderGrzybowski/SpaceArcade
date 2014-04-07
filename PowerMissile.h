#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile {
public:

	static sf::Clock missileLimitClock;
	static const int timeLimit;

	PowerMissile(int shipx, int shipy);

	static bool canBeSent();

	std::vector<std::string> getSpritesString() {
		return std::vector<std::string> {"Sprites/PowerMissileA.png", "Sprites/PowerMissileB.png"};
	}
	int getDamage() { return 20; }
	double getSpeed() { return 0.5; }
	int getSize() { return 24; }
};

#endif /* MISSILE_H_ */
