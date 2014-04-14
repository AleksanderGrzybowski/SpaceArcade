#include "PointsCounter.h"

PointsCounter::PointsCounter() : pointsCount(0) {
	setPosition(0, 0);
}

std::string PointsCounter::getString() {
	return std::string("Punkty: ") + std::to_string(pointsCount);
}
