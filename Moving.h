#ifndef MOVING_H_
#define MOVING_H_

#include <iostream>
#include <SFML/Window.hpp>
#include "Drawable.h"
#include "Direction.h"
#include "config.h"

/* Klasa określająca obiekt poruszający się sam (iterate!)
 * Ship nie wykorzystuje nic z poniższych,
 * bo rusza nim gracz a nie algorytm
 */
class Moving : public Drawable {
public:

	Moving(int xpos, int ypos, std::vector<std::string> spritesString, int size, int animationSpeed, double speed, Direction dir)
	: Drawable(xpos, ypos, spritesString, size, animationSpeed), speed(speed), dir(dir) {
		//std::cout << "Tworzę " << speed << " " << rand() <<  std::endl;
	}

	virtual void moveIterate(sf::Time& t);
//	virtual double getSpeed() const = 0;
//	virtual Direction getDirection() const = 0;

	virtual ~Moving() {}

protected:
	double speed;
	Direction dir;
};

#endif /* MOVING_H_ */
