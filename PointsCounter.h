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

	void add(int n) { pointsCount += n; }
	void reset() { pointsCount = 0; }
	int getFontSize() { return 20; }

private:
	std::string getString(); // impl
};

#endif /* POINTSCOUNTER_H_ */
