#include "Missile.h"

Missile::Missile() {}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = shape.getPosition();

	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	shape.setPosition(actPos);
}
