#ifndef SHIP_H_
#define SHIP_H_

//#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include "Drawable.h"

class Ship : public Drawable {
public:
	Ship();

	void move(Direction d, const sf::Time& t); // inne parametry! nie impl. z Drawable
	int getSize() const { return 1337; }
	int getAnimationSpeed() const { return 100; }
};

#endif /* SHIP_H_ */
