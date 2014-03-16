#include "Ship.h"

Ship::Ship() : shape(shipSize, 1000) {
	shape.setFillColor(shipColor);
	shape.setPosition(screenWidth/2.0, screenHeight-2*shipSize);
}


void Ship::move(Direction b, const sf::Time& t) {
	sf::Vector2f pos = shape.getPosition();

	float distance = (b ? 1 : -1)*shipSpeed*t.asMilliseconds();
	if (! ((pos.x + distance) <= 0) || ((pos.x + distance) >= screenWidth))
		shape.move(distance, 0);


}


