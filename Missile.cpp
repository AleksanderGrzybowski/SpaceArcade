#include "Missile.h"

Missile::Missile(int shipx, int shipy, std::vector<std::string> spritesString, int size, int animationSpeed, double speed, int damage)
	: Moving(shipx + CONF_shipSize/2 - (CONF_missileSize/2.0),    shipy, spritesString, size, animationSpeed, speed, Up), damage(damage) {
//	tf.add(spritesString);
//	setTexture(tf.getFlip());

//	double xpos = shipx + CONF_shipSize/2 - (CONF_missileSize/2.0); // środek pocisku na środku statku
//	double ypos = shipy;
//	move(xpos, ypos); // drawable::drawable już to chyba robi
}

