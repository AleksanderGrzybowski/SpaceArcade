#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include "Drawable.h"

class Enemy : public Drawable {
public:
	//sf::Sprite sprite;
	TextureFlipper tf;

	int health;

	Enemy(double xpos, double ypos);

	void moveIterate(sf::Time& t);
	void setPosition(int x, int y) { sprite.setPosition(x, y); }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
//	void draw(sf::RenderWindow& window) {
//		window.draw(sprite);
//	}

	// przesłaniane w potomnych
	virtual double getSpeed() = 0;
	virtual int getSize() = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;
	virtual int getPoints() = 0;

	bool isAlive() { return health > 0; }
	void damage(int damage);

	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
