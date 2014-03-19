#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Missile {
public:
	sf::RectangleShape r;

	Missile();

	void moveIterate(const sf::Time& t);
	sf::Shape& getShape() { return r; }
	sf::Vector2f getPosition() { return r.getPosition(); }

	virtual double getSpeed() = 0;
	virtual int getDamage() = 0;
	virtual int getSize() = 0;
	virtual sf::Color getColor() = 0;

	virtual ~Missile() {}
};

#endif /* MISSILE_H_ */
