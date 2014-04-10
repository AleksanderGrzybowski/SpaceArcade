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
	virtual ~Moving() {}
	virtual double getSpeed() = 0;
	virtual Direction getDirection() = 0;
};

#endif /* MOVING_H_ */
