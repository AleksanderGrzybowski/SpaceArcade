#include "Missile.h"

Missile::Missile() {}

void Missile::initialize(int shipx, int shipy) {
	tf.add(getSpritesString());
	setTexture(tf.getFlip());

	double xpos = shipx + CONF_shipSize/2 - (getSize()/2.0); // środek pocisku na środku statku
	double ypos = shipy;
	move(xpos, ypos);
}
