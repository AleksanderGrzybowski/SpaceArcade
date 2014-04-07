#include "Ship.h"

Ship::Ship() {
	tf.add(std::vector<std::string> {"Sprites/spaceshipA.png", "Sprites/spaceshipB.png"});

	sprite.setTexture(tf.getFlip());
	sprite.setPosition(CONF_screenWidth/2.0 - CONF_shipSize/2, CONF_screenHeight-CONF_shipSize);
}

void Ship::move(Direction b, const sf::Time& t) {
	sf::Vector2f pos = sprite.getPosition();

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
		sprite.move(xdistance, 0);

	if (! (( (pos.y + ydistance) >= (CONF_screenHeight-CONF_shipSize)) || ((pos.y + ydistance) <= (CONF_screenHeight*(1-CONF_shipUpLimit)))) )
		sprite.move(0, ydistance);
}

void Ship::draw(sf::RenderWindow& window) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > CONF_animationSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	Drawable::draw(window);
}
