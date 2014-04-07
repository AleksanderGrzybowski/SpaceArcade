#include "MissileFactory.h"

Missile* MissileFactory::getRandomMissile(int shipx, int shipy) {
	if (rand() % 2) return new NormalMissile(shipx, shipy);
	else return new PowerMissile(shipx, shipy);
}
