#include "Ship.h"



Ship::Ship() : shape(shipSize, 1000) {
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(screenWidth/2.0, screenHeight-2*shipSize);
}

void Ship::move(double x, double y) {
	shape.move(x, y);
}

void Ship::move(bool b, sf::Time& t) {
	shape.move( (b ? 1 : -1)*0.2*t.asMilliseconds(), 0);
}

void Ship::setPosition(double x, double y) {
	shape.setPosition(x, y);

}
