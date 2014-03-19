#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Enemy {
public:
	sf::CircleShape shape;
	int health;

	Enemy(double xpos, double ypos);

	sf::CircleShape getShape() { return shape; }
	void moveIterate(sf::Time& t);
	sf::Vector2f getPosition() { return shape.getPosition(); }

	virtual double getSpeed() { return 0.1;} // coś wymyślić
	virtual int getSize()  = 0;
	virtual sf::Color getColor() = 0;
	virtual int getMaxHealth() = 0;

	bool isAlive() { return health > 0; }
	virtual void damage(int damage) = 0;
	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
