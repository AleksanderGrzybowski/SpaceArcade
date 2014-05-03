#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile {
public:
	static sf::Clock missileLimitClock;
	static sf::Clock animationSpeedClock;

	NormalMissile(int shipx, int shipy);

	static void restartClock();

	static bool canBeSent();
//	int getDamage() const { return 5; }
//	double getSpeed() const { return 0.5; }
//	int getSize() const { return 20; }

private:
//	const std::vector<std::string> getSpritesString() const {
//		return std::vector<std::string> {"Sprites/NormalMissileAA.png", "Sprites/NormalMissileBB.png"};
//	}
	static const int timeLimit;
};

#endif /* MISSILE_H_ */
