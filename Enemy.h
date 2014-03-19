#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Enemy {
public:
	sf::RectangleShape shape;
	int health;
	double moveDistance;
	double leftDistance;
	int currentDirection; // zamienić na enum

	Enemy(double xpos, double ypos);

	sf::RectangleShape getShape() { return shape; }
	void moveIterate(sf::Time& t);
	sf::Vector2f getPosition() { return shape.getPosition(); }

	virtual double getSpeed() { return 0.1;} // coś wymyślić
	virtual int getSize()  = 0;
	virtual sf::Color getColor() = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;

	bool isAlive() { return health > 0; }
	void damage(int damage);
	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
