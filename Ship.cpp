#include "Ship.h"

Ship::Ship() : shape(CONF_shipSize/2, 1000) {
	shape.setFillColor(CONF_shipColor);

	shape.setPosition(CONF_screenWidth/2.0 - CONF_shipSize/2, CONF_screenHeight-CONF_shipSize);
}


void Ship::move(Direction b, const sf::Time& t) {
	sf::Vector2f pos = shape.getPosition();

	float distance = (b ? 1 : -1)*CONF_shipSpeed*t.asMilliseconds();
	if (! (( (pos.x + distance) <= -CONF_shipSize/2) || ((pos.x + distance) >= (CONF_screenWidth-CONF_shipSize/2))) ) {
		shape.move(distance, 0);
	}

}


