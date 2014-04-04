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
