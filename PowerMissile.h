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

	int getDamage() const { return 20; }
	double getSpeed() const { return 0.5; }
	int getSize() const { return 24; }

private:
	std::vector<std::string> getSpritesString() const {
		return std::vector<std::string> {"Sprites/PowerMissileA.png", "Sprites/PowerMissileB.png"};
	}
	static const int timeLimit;
};


#endif /* MISSILE_H_ */
