/*
 * Missile.h
 *
 *  Created on: 17-03-2014
 *      Author: kelog
 */

#ifndef MISSILE_H_
#define MISSILE_H_
#include <SFML/Graphics.hpp>
#include "config.h"

class Missile { // z niej można by wywodzić pozostałe
public:
	sf::CircleShape r;

	Missile(double xpos, double ypos);

	void moveIterate(const sf::Time& t);

	sf::Shape& getShape() { return r; }
	sf::Vector2f getPosition() { return r.getPosition(); }
	virtual double getSpeed() { return CONF_missileSpeed; }

	virtual ~Missile() {}
};

#endif /* MISSILE_H_ */
