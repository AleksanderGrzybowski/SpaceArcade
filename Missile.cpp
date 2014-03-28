#include "Missile.h"


Missile::Missile() {}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = shape.getPosition();

	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	shape.setPosition(actPos);
}

void Missile::draw(sf::RenderWindow& window) {
	//if ((PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > 100) {
		animationSpeedClock.restart();
		if (currentTexture) {
			shape.setTexture(textureA);
		} else {
			shape.setTexture(textureB);
		}
		currentTexture = !currentTexture;
	}
	window.draw(shape);
}
