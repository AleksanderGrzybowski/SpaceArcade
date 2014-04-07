#include "Missile.h"

Missile::Missile() {}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = sprite.getPosition();

	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	sprite.setPosition(actPos);
}

void Missile::draw(sf::RenderWindow& window) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > CONF_animationSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(sprite);
}

void Missile::initialize(int shipx, int shipy) {
	tf.add(getSpritesString());
	sprite.setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	sprite.move(xpos, ypos);
}
