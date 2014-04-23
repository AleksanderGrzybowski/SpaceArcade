#include "PowerMissile.h"

PowerMissile::PowerMissile(int shipx, int shipy) {
	initialize(shipx, shipy); // ala wirtualny konstruktor
}

bool PowerMissile::canBeSent() {
	return (PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > PowerMissile::timeLimit;
}

void PowerMissile::restartClock() {
	missileLimitClock.restart();
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
