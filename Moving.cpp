#include "Moving.h"
void Moving::moveIterate(sf::Time& t) {
	double toMove = getSpeed()*t.asMilliseconds()/CONF_globalEnemySpeedFactor;

	if (getDirection() == Down) move(0, toMove);
	else move(0, -toMove);
}
