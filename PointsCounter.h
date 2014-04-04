#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
class PointsCounter {
public:
	int pointsCount;
	sf::Font font;


	PointsCounter();

	void add(int n) { pointsCount += n; }
	void draw(sf::RenderWindow& window);
};

#endif /* POINTSCOUNTER_H_ */
