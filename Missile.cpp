#include "Missile.h"

Missile::Missile() {}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = shape.getPosition();

	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	shape.setPosition(actPos);
}

void Missile::draw(sf::RenderWindow& window) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > CONF_animationSpeed) {
		shape.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(shape);
}

void Missile::initialize(int shipx, int shipy) {
	tf.add(getSpritesString());
	shape.setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	shape.move(xpos, ypos);
}
