/*
 * Missile.cpp
 *
 *  Created on: 17-03-2014
 *      Author: kelog
 */

#include "Missile.h"

Missile::Missile(double xpos, double ypos) : r(CONF_missileSize/2, 10) {
	r.setPosition(xpos, ypos);
	r.setFillColor(sf::Color::Red);
}

void Missile::moveIterate(const sf::Time& t) {
	sf::Vector2f actPos = r.getPosition();
	// tylko w górę
	actPos.y -= getSpeed() * t.asMilliseconds();
	r.setPosition(actPos);
}
