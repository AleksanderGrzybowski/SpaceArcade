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
	TextureFlipper tf;
	int health;

	Enemy();
	virtual void initialize(int xpos, int ypos);
	void moveIterate(sf::Time& t);

	// przesłaniane w potomnych
	virtual double getSpeed() = 0;
	virtual int getSize() = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;
	virtual int getPoints() = 0;

	bool isAlive() { return health > 0; }
	void damage(int damage);
	virtual std::vector<std::string> getSpritesString() = 0;

	virtual ~Enemy() {}
};

#endif /* ENEMY_H_ */
