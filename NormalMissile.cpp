#include "NormalMissile.h"

NormalMissile::NormalMissile(const sf::Vector2f& shipPos) {
	textureA.loadFromFile("Sprites/NormalMissileA.png");
	textureB.loadFromFile("Sprites/NormalMissileB.png");
	shape.setTexture(textureA);
	shape.setTexture(textureB);

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0);
	double ypos = shipPos.y;
	shape.move(xpos, ypos);
}

sf::Clock NormalMissile::missileLimitClock;

const int NormalMissile::timeLimit = 100; // ms
