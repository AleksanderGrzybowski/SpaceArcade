#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile {
public:

	static sf::Clock missileLimitClock;

	PowerMissile(int shipx, int shipy);

	static bool canBeSent();

	int getDamage() { return 20; }
	double getSpeed() { return 200; }
	int getSize() { return 24; }

private:
	std::vector<std::string> getSpritesString() {
		return std::vector<std::string> {"Sprites/PowerMissileA.png", "Sprites/PowerMissileB.png"};
	}
	static const int timeLimit;
};


#endif /* MISSILE_H_ */
