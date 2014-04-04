#include "NormalMissile.h"

NormalMissile::NormalMissile(int shipx, int shipy) {
	tf.add(std::vector<std::string> {"Sprites/NormalMissileA.png", "Sprites/NormalMissileB.png"});
	shape.setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0);
	double ypos = shipy;
	shape.move(xpos, ypos);
}

bool NormalMissile::canBeSent() {
	return (NormalMissile::missileLimitClock).getElapsedTime().asMilliseconds() > NormalMissile::timeLimit;
}

sf::Clock NormalMissile::missileLimitClock;

const int NormalMissile::timeLimit = 100; // ms
