#include "NormalMissile.h"

NormalMissile::NormalMissile(const sf::Vector2f& shipPos) {
	//missiles.push_back(new NormalMissile(shipPos.x + CONF_shipSize/2 - (CONF_missileSize/2), shipPos.y));
	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2);
	double ypos = shipPos.y;
	r = sf::CircleShape(getSize(), 1000);
	r.move(xpos, ypos);
	r.setFillColor(getColor());
}

sf::Clock NormalMissile::missileLimitClock;
