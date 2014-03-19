#ifndef SHIP_H_
#define SHIP_H_

#include "config.h"
#include "Direction.h"
#include <iostream>

class Ship {
public:
	//sf::RectangleShape shape; // potem sprite
	sf::Sprite shape;

	Ship();
	void move(Direction d, const sf::Time& t);
	const sf::Vector2f& getPosition() { return shape.getPosition(); }
	sf::Sprite& getShape() { return shape; }

};

#endif /* SHIP_H_ */
