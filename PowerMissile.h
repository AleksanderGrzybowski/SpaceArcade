#ifndef POWERMISSILE_H_
#define POWERMISSILE_H_
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class PowerMissile : public Missile {
public:

	static sf::Clock missileLimitClock;
	static const int timeLimit;
	PowerMissile(const sf::Vector2f& shipPos);

	int getDamage() { return 2; }
	double getSpeed() { return 0.5; }
	sf::Color getColor() { return sf::Color::Red; }
	int getSize() { return 30; }

};


#endif /* MISSILE_H_ */
