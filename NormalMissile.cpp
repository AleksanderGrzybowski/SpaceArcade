#include "NormalMissile.h"

NormalMissile::NormalMissile(int shipx, int shipy) {
	initialize(shipx, shipy); // ala wirtualny konstruktor
}

bool NormalMissile::canBeSent() {
	return (NormalMissile::missileLimitClock).getElapsedTime().asMilliseconds() > NormalMissile::timeLimit;
}

sf::Clock NormalMissile::missileLimitClock;
const int NormalMissile::timeLimit = 100; // ms
