#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include "Drawable.h"
#include "Moving.h"
#include "Direction.h"

class Enemy : public Moving {
public:
	Enemy();
	virtual void moveIterate(sf::Time& t);

	// przesłaniane w potomnych
	virtual double getSpeed() = 0;
	virtual int getSize() = 0;
	virtual int getMaxHealth() = 0;
	virtual double getDamageCoeff() = 0;
	virtual int getPoints() = 0;
	Direction getDirection() { return Down; }

	bool isAlive() { return health > 0; }
	void damage(int damage);

	virtual ~Enemy() {}

protected:
	virtual std::vector<std::string> getSpritesString() = 0;
	virtual void initialize(int xpos, int ypos);
private:
	TextureFlipper tf;
	int health;
};

#endif /* ENEMY_H_ */
