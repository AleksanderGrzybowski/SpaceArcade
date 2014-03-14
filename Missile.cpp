#include "Missile.h"

Missile::Missile(double xpos, double ypos) : r(sf::Vector2f(10, 10)) {
	r.setPosition(xpos, ypos);
	r.setFillColor(sf::Color::Red);
}

void Missile::moveIterate(sf::Time& t) {
	sf::Vector2f actPos = r.getPosition();
	// tylko w górę
	actPos.y -= 0.2 * t.asMilliseconds();
	r.setPosition(actPos);
}
