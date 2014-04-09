#ifndef MOVING_H_
#define MOVING_H_

#include <iostream>
#include <SFML/Window.hpp>

class Moving {
public:
	virtual void moveIterate(sf::Time& t) = 0;
	virtual ~Moving() {}
};

#endif /* MOVING_H_ */
