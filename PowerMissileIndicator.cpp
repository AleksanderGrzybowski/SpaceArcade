#include "PowerMissileIndicator.h"

PowerMissileIndicator::PowerMissileIndicator() : rect(sf::Vector2f(100, 20)) {
	setPosition(0, 30);
}

void PowerMissileIndicator::update() {
	// kolor do którego dążymy: metallic mint	#37FDFC
	double r, g, b;
	if (PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) {
		r = 0x37; g = 0xfd; b = 0xfc;
	}
	else {
		double factor = ((double)PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds()) / ((double)PowerMissile::timeLimit);
		r = factor * 0x37;
		g = factor * 0xfd;
		b = factor * 0xfc;
	}

	rect.setFillColor(sf::Color(r, g, b));
}
