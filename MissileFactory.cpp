#include "MissileFactory.h"

Missile* MissileFactory::getRandomMissile(sf::Vector2f shipPos) {
	if (rand() % 2) return new NormalMissile(shipPos);
	else return new PowerMissile(shipPos);

}
