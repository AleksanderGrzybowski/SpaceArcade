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

	Moving(int xpos, int ypos, const std::vector<std::string>& spritesString, int size, int animationSpeed, double speed, Direction dir)
	: Drawable(xpos, ypos, spritesString, size, animationSpeed), speed(speed), dir(dir)
	{}

	virtual void moveIterate(const sf::Time& t);

	virtual ~Moving() {}

protected:
	const double speed;
	const Direction dir;
};

#endif /* MOVING_H_ */
