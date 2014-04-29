#include "Missile.h"

Missile::Missile(int shipx, int shipy, std::vector<std::string> spritesString) {
	tf.add(spritesString);
	setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (CONF_missileSize/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	move(xpos, ypos);
}

