#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Drawable.h"
#include "TextObject.h"

class PointsCounter : public TextObject {
public:

	int pointsCount;

	PointsCounter();

	void add(int n) { pointsCount += n; updateString(); }
	void reset() { pointsCount = 0; updateString(); }
	void updateString() {
		str = std::string("Punkty: ") + std::to_string(pointsCount);
	}
//	int getFontSize() { return 20; }
//	sf::Color getColor() { return sf::Color::White; }

private:
	//std::string getString(); // impl
};

#endif /* POINTSCOUNTER_H_ */
