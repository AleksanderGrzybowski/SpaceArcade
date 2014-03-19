#include "NormalMissile.h"

NormalMissile::NormalMissile(const sf::Vector2f& shipPos) {
	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0);
	double ypos = shipPos.y;
	r = sf::CircleShape(getSize(), 1000);
	r.move(xpos, ypos);
	r.setFillColor(getColor());
}

sf::Clock NormalMissile::missileLimitClock;
const int NormalMissile::timeLimit = 300; // ms
