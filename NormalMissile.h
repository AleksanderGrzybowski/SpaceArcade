#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile { // z niej można by wywodzić pozostałe
public:
	static sf::Clock missileLimitClock;
	static const int timeLimit;

	NormalMissile(const sf::Vector2f& shipPos);

	int getDamage() { return 5; }
	double getSpeed() { return 0.5; }
	int getSize() { return 5; }
	sf::Color getColor() { return sf::Color::Red; }
};


#endif /* MISSILE_H_ */
