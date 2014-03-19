#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile { // z niej można by wywodzić pozostałe
public:
	static sf::Clock missileLimitClock;
	NormalMissile(const sf::Vector2f& shipPos);

	int getDamage() { return 1; }
	double getSpeed() { return 0.2; }
	int getSize() { return 20; }
	sf::Color getColor() { return sf::Color::Blue; }
};


#endif /* MISSILE_H_ */
