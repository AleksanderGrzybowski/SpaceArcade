#include "Missile.h"

Missile::Missile() {}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = r.getPosition();
	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	r.setPosition(actPos);
}
