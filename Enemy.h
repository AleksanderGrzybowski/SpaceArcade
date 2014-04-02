#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
class Enemy {
public:
	sf::Sprite sprite;
	TextureFlipper tf;

	int health;
	double moveDistance;
	double leftDistance; // pozostały
	Direction currentDirection;

	Enemy(double xpos, double ypos);

	void moveIterate(sf::Time& t);
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void draw(sf::RenderWindow& window) { window.draw(sprite); }

	virtual double getSpeed() { return CONF_enemySpeed;}
	virtual int getSize()  = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;

	bool isAlive() { return health > 0; }
	void damage(int damage);

	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
