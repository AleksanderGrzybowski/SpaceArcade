#include "Ship.h"

Ship::Ship() : shape(CONF_shipSize/2, 1000) {
	shape.setFillColor(CONF_shipColor);

	shape.setPosition(CONF_screenWidth/2.0 - CONF_shipSize/2, CONF_screenHeight-CONF_shipSize);
}


void Ship::move(Direction b, const sf::Time& t) {
	sf::Vector2f pos = shape.getPosition();

	double xdistance = 0;
	double ydistance = 0;

	switch(b) {
	case Left:
		xdistance = -CONF_shipSpeed*t.asMilliseconds();
		break;
	case Right:
		xdistance = +CONF_shipSpeed*t.asMilliseconds();
		break;
	case Up:
		ydistance = -CONF_shipSpeed*t.asMilliseconds();
		break;
	case Down:
		ydistance = CONF_shipSpeed*t.asMilliseconds();
		break;
	}

	if (! (( (pos.x + xdistance) <= -CONF_shipSize/2) || ((pos.x + xdistance) >= (CONF_screenWidth-CONF_shipSize/2))) )
		shape.move(xdistance, 0);

	if (! (( (pos.y + ydistance) >= (CONF_screenHeight-CONF_shipSize)) || ((pos.y + ydistance) <= (CONF_screenHeight*(1-CONF_shipUpLimit)))) )
		shape.move(0, ydistance);


}


