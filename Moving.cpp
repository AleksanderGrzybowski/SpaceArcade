#include "Moving.h"

/* Główna metoda do iteracyjnego poruszania obiektów */
void Moving::moveIterate(sf::Time& t) {
	double toMove = getSpeed()*t.asMilliseconds();

	switch (getDirection()) {
	case Up:
		move(0, -toMove);
		break;
	case Down:
		move(0, toMove);
		break;
	case Left:
		move(-toMove, 0);
		break;
	case Right:
		move(toMove, 0);
		break;
	}

}
