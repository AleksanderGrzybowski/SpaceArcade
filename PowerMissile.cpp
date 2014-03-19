#include "PowerMissile.h"

PowerMissile::PowerMissile(const sf::Vector2f& shipPos) {
	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2);
	double ypos = shipPos.y;
	r = sf::CircleShape(getSize(), 1000);
	r.move(xpos, ypos);
	r.setFillColor(getColor());
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
