#ifndef MISSILEINDICATOR_H_
#define MISSILEINDICATOR_H_

#include <SFML/Graphics.hpp>
#include "PowerMissile.h"

class PowerMissileIndicator {
public:

	PowerMissileIndicator();

	void setPosition(int xpos, int ypos) {
		rect.setPosition(xpos, ypos);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(rect);
	}

	void update();

	virtual ~PowerMissileIndicator() {}

private:
	sf::RectangleShape rect;
};

#endif /* MISSILEINDICATOR_H_ */
