#ifndef MOVING_H_
#define MOVING_H_

#include <iostream>
#include <SFML/Window.hpp>
#include "Drawable.h"
#include "Direction.h"
#include "config.h"

class Moving : public Drawable {
public:
	virtual void moveIterate(sf::Time& t);
	virtual double getSpeed() const = 0;
	virtual Direction getDirection() const = 0;

	virtual ~Moving() {}
};

#endif /* MOVING_H_ */
