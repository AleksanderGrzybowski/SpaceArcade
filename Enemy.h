#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Direction.h"

class Enemy {
public:
	sf::Sprite shape;
	int health;
	double moveDistance;
	double leftDistance; // pozostały
	Direction currentDirection;

	Enemy(double xpos, double ypos);

	operator sf::Sprite&() { return shape; }
	void moveIterate(sf::Time& t);
	sf::Vector2f getPosition() { return shape.getPosition(); }

	virtual double getSpeed() { return 0.1;} // coś wymyślić
	virtual int getSize()  = 0;
//	virtual sf::Color getColor() = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;

	bool isAlive() { return health > 0; }
	void damage(int damage);
	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
