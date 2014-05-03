#include "PointsCounter.h"

PointsCounter::PointsCounter() : TextObject(0, 0, 20, sf::Color::Red), pointsCount(0) {
	updateString();
}
