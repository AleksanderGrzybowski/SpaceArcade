#include "NormalMissile.h"

NormalMissile::NormalMissile(int shipx, int shipy)
	: Missile(shipx, shipy, {"Sprites/NormalMissileAA.png", "Sprites/NormalMissileBB.png"})
{}

bool NormalMissile::canBeSent() {
	return (NormalMissile::missileLimitClock).getElapsedTime().asMilliseconds() > NormalMissile::timeLimit;
}

void NormalMissile::restartClock() {
	missileLimitClock.restart();
}


sf::Clock NormalMissile::missileLimitClock;
const int NormalMissile::timeLimit = 100; // ms
