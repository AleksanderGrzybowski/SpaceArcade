#include "PowerMissileIndicator.h"

PowerMissileIndicator::PowerMissileIndicator() : rect(sf::Vector2f(100, 20)) {
	setPosition(0, 30);
}

// W zależności od stosunku czasów: tego, który upłynął i limitu wystrzeleń,
// ustawiamy odpowiednio jaskrawy kolor prostokąta
void PowerMissileIndicator::update() {
	// kolor do którego dążymy: metallic mint	#37FDFC
	sf::Color col;

	double factor = ((double)PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds()) / ((double)PowerMissile::timeLimit);
	if (factor > 1.0) factor = 1.0;

	col.r = factor * 0x37; // skalowanie
	col.g = factor * 0xfd;
	col.b = factor * 0xfc;

	rect.setFillColor(sf::Color(col));
}
