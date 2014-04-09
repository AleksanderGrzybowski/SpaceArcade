#include "Bonus.h"

void Bonus::moveIterate(sf::Time& t) {
	double toMove = getSpeed()*t.asMilliseconds()/CONF_globalEnemySpeedFactor;
	move(0, toMove);
}

void Bonus::initialize(int xpos, int ypos) {
	tf.add(getSpritesString());
	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
}
