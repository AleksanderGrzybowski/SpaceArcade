#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Drawable.h"
#include "TextObject.h"

class PointsCounter : public TextObject {
public:
	PointsCounter();

	void add(int n) { pointsCount += n; updateString(); }
	void reset() { pointsCount = 0; updateString(); }
	void updateString() {
		str = std::string("Punkty: ") + std::to_string(pointsCount);
	}

private:
	int pointsCount;
};

#endif /* POINTSCOUNTER_H_ */
