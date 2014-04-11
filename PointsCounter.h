#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Drawable.h"

class PointsCounter : public Drawable {
public:

	int pointsCount;
	sf::Font font;

	PointsCounter();

	void add(int n) { pointsCount += n; }
	void draw(sf::RenderWindow& window);
	void reset() { pointsCount = 0; }
	int getSize() const { return 1337; }
};

#endif /* POINTSCOUNTER_H_ */
