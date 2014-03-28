#include "PowerMissile.h"

PowerMissile::PowerMissile(const sf::Vector2f& shipPos) {
	textureA.loadFromFile("Sprites/PowerMissile.png");
	textureB.loadFromFile("Sprites/PowerMissile.png");
	shape.setTexture(textureA);

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipPos.y;
	shape.move(xpos, ypos);
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
