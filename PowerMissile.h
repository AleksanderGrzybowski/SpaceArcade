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

//	int getDamage() const { return 20; }
//	double getSpeed() const { return 0.5; }
//	int getSize() const { return 24; }

	static const int timeLimit;
	static sf::Clock missileLimitClock;

private:
//	const std::vector<std::string> getSpritesString() const {
//		return std::vector<std::string> {"Sprites/PowerMissileA.png", "Sprites/PowerMissileB.png"};
//	}
};


#endif /* MISSILE_H_ */
