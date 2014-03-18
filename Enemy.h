#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Enemy {
public:
	sf::CircleShape shape;

	Enemy(double xpos, double ypos);

	sf::CircleShape getShape() { return shape; }
	void moveIterate(sf::Time& t);
	sf::Vector2f getPosition() { return shape.getPosition(); }

	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
