#ifndef MISSILEINDICATOR_H_
#define MISSILEINDICATOR_H_

#include <SFML/Graphics.hpp>
#include "PowerMissile.h"

class PowerMissileIndicator {
public:

	sf::RectangleShape rect;
	PowerMissileIndicator() : rect(sf::Vector2f(100, 20)) {

		rect.setFillColor(sf::Color(128, 128, 128));
	}

	void draw(sf::RenderWindow& window) {
		rect.setPosition(100, 100);
		window.draw(rect);
	}

	void update() {
		double col;
		if (PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) col = 255;
		else {
			col = ((double)PowerMissile::missileLimitClock.getElapsedTime().asMilliseconds()) / ((double)PowerMissile::timeLimit);
			col *= 256;
		}
		rect.setFillColor(sf::Color(col, col, col));
		std::cout << col << std::endl;
	}
	virtual ~PowerMissileIndicator() {}
};

#endif /* MISSILEINDICATOR_H_ */
