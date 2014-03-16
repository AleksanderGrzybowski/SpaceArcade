#ifndef SHIP_H_
#define SHIP_H_

#include "config.h"
#include "Direction.h"


class Ship {
public:
	sf::CircleShape shape; // potem sprite

	Ship();
	void move(Direction d, const sf::Time& t);
	const sf::Vector2f& getPosition() { return shape.getPosition(); }
	sf::Shape& getShape() { return shape; }

};

#endif /* SHIP_H_ */
