#include "PowerMissile.h"

PowerMissile::PowerMissile(double xpos, double ypos) {
	r = sf::CircleShape(getSize(), 1000);
	r.move(xpos, ypos);
	r.setFillColor(getColor());
}

sf::Clock PowerMissile::missileLimitClock;
