#include "PowerMissileIndicator.h"

PowerMissileIndicator::PowerMissileIndicator() : rect(sf::Vector2f(100, 20)) {
	setPosition(0, 30);
}

void PowerMissileIndicator::update() {
	// kolor do którego dążymy: metallic mint	#37FDFC
	//double r, g, b;
	sf::Color col;

	if (PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) {
		col.r = 0x37; col.g = 0xfd; col.b = 0xfc;
	}
	else {
		double factor = ((double)PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds()) / ((double)PowerMissile::timeLimit);
		col.r = factor * 0x37; // skalowanie
		col.g = factor * 0xfd;
		col.b = factor * 0xfc;
	}

	rect.setFillColor(sf::Color(col));
}
