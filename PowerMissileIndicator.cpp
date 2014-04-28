#include "PowerMissileIndicator.h"

PowerMissileIndicator::PowerMissileIndicator() : rect(sf::Vector2f(100, 20)) {
	setPosition(0, 30);
}

void PowerMissileIndicator::update() {
	double col;
	if (PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) col = 255;
	else {
		col = ((double)PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds()) / ((double)PowerMissile::timeLimit);
		col *= 256;
	}

	rect.setFillColor(sf::Color(col, col, col));
}
