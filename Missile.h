#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Missile {
public:
	sf::Sprite shape;
	sf::Texture texture;

	Missile();

	void moveIterate(const sf::Time& t);
	operator sf::Sprite&() { return shape; }
	sf::Vector2f getPosition() { return shape.getPosition(); }

	virtual double getSpeed() = 0;
	virtual int getDamage() = 0;
	virtual int getSize() = 0;

	virtual ~Missile() {}
};

#endif /* MISSILE_H_ */
