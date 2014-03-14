#include "Ship.h"



Ship::Ship() : shape(shipSize, 1000) {
	shape.setFillColor(shipColor);
	shape.setPosition(screenWidth/2.0, screenHeight-2*shipSize);
}


void Ship::move(bool b, sf::Time& t) {
	shape.move( (b ? 1 : -1)*shipSpeed*t.asMilliseconds(), 0);
}

void Ship::setPosition(double x, double y) {
	shape.setPosition(x, y);

}
