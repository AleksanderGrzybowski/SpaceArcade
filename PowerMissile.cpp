#include "PowerMissile.h"

PowerMissile::PowerMissile(const sf::Vector2f& shipPos) {
	sf::Texture t;
	t.loadFromFile("Sprites/PowerMissileA.png");
	tf.add(t);
	t.loadFromFile("Sprites/PowerMissileB.png");
	tf.add(t);
	shape.setTexture(tf.getFlip());

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipPos.y;
	shape.move(xpos, ypos);
}

bool PowerMissile::canBeSent() {
	return (PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > PowerMissile::timeLimit;
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
