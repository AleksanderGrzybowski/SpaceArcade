#ifndef SHIP_H_
#define SHIP_H_

#include "config.h"
#include "Direction.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Ship {
public:
	sf::Sprite shape;
	sf::Texture texture;

	Ship();
	void move(Direction d, const sf::Time& t);
	const sf::Vector2f& getPosition() { return shape.getPosition(); }

	operator sf::Sprite&() { return shape; }
};

#endif /* SHIP_H_ */
