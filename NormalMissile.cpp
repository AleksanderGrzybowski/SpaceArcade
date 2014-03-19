#include "NormalMissile.h"

NormalMissile::NormalMissile(const sf::Vector2f& shipPos) {
	texture.loadFromFile("Sprites/NormalMissile.png");
	shape.setTexture(texture);

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0);
	double ypos = shipPos.y;
	shape.move(xpos, ypos);
}

sf::Clock NormalMissile::missileLimitClock;
const int NormalMissile::timeLimit = 300; // ms
