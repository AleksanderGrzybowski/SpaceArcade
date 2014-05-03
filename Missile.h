#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "TextureFlipper.h"
#include "Drawable.h"
#include "Moving.h"
#include "Direction.h"

class Missile : public Moving {
public:
	Missile(int shipx, int shipy, std::vector<std::string> spritesString, int size, int animationSpeed, double speed, int damage);

	//virtual int getSize() const = 0;

	//virtual double getSpeed() const = 0;
	virtual int getDamage() { return damage; }
	//Direction getDirection() const { return Up; }
	//int getAnimationSpeed() const { return 100; }

	virtual ~Missile() {}

protected:
	//virtual std::vector<std::string> getSpritesString() const = 0;
	//void initialize(int shipx, int shipy);
	int damage;

};

#endif /* MISSILE_H_ */
