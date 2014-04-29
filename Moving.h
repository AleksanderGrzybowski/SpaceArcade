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

	Moving(std::vector<std::string> spritesString) : Drawable(spritesString) {}

	virtual void moveIterate(sf::Time& t);
	virtual double getSpeed() const = 0;
	virtual Direction getDirection() const = 0;

	virtual ~Moving() {}
};

#endif /* MOVING_H_ */
