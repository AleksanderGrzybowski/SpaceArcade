#include "Missile.h"

Missile::Missile() {}

void Missile::moveIterate(sf::Time& t) {
	sf::Vector2f actPos = getPosition();

	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	setPosition(actPos.x, actPos.y);
}

void Missile::draw(sf::RenderWindow& window) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > CONF_animationSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	Drawable::draw(window);
}

void Missile::initialize(int shipx, int shipy) {
	tf.add(getSpritesString());
	setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	move(xpos, ypos);
}
