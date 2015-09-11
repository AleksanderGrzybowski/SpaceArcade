#include "Ship.h"

Ship::Ship(double speed) : Drawable(CONF_screenWidth/2.0 - CONF_shipSize/2, CONF_screenHeight-CONF_shipSize,
		{"Sprites/spaceshipA.png", "Sprites/spaceshipB.png"}, CONF_shipSize, 100), speed(speed)
{}

void Ship::move(Direction b, const sf::Time& t) {
	sf::Vector2f pos = sprite.getPosition();

	double xdistance = 0;
	double ydistance = 0;

	switch(b) {
	case Left:
		xdistance = -speed*t.asMilliseconds();
		break;
	case Right:
		xdistance = +speed*t.asMilliseconds();
		break;
	case Up:
		ydistance = -speed*t.asMilliseconds();
		break;
	case Down:
		ydistance = +speed*t.asMilliseconds();
		break;
	}

	// Statek może wyjść na boki max 50%, do góry i dołu 0%
	// Uwaga: pozycja statku to lewy górny róg jego prostokąta
	if (! (( (pos.x + xdistance) <= -CONF_shipSize/2) || ((pos.x + xdistance) >= (CONF_screenWidth-CONF_shipSize/2))) )
		sprite.move(xdistance, 0);

	if (! (( (pos.y + ydistance) >= (CONF_screenHeight-CONF_shipSize)) || ((pos.y + ydistance) <= (CONF_screenHeight*(1-CONF_shipUpLimit)))) )
		sprite.move(0, ydistance);
}
