#include "PowerMissile.h"

PowerMissile::PowerMissile(int shipx, int shipy) {
//	sf::Texture t;
//	t.loadFromFile("Sprites/PowerMissileA.png");
//	tf.add(t);
//	t.loadFromFile("Sprites/PowerMissileB.png");
//	tf.add(t);

	tf.add(std::vector<std::string> {"Sprites/PowerMissileA.png", "Sprites/PowerMissileB.png"});
	shape.setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	shape.move(xpos, ypos);
}

bool PowerMissile::canBeSent() {
	return (PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > PowerMissile::timeLimit;
}

sf::Clock PowerMissile::missileLimitClock;
const int PowerMissile::timeLimit = 1000;
