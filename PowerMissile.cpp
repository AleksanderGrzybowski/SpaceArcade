#include "PowerMissile.h"

PowerMissile::PowerMissile(const sf::Vector2f& shipPos) {
	texture.loadFromFile("Sprites/NormalMissile.png");
	shape.setTexture(texture);

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipPos.y;
	shape.move(xpos, ypos);
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
