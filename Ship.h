#ifndef SHIP_H_
#define SHIP_H_

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include "Drawable.h"

/* Statek. Implementuje Drawable, ale nie używa moveIterate,
 * ma swoje własne move sterowane klawiaturą.
 */
class Ship : public Drawable {
public:
	Ship(double speed);

	void move(Direction d, const sf::Time& t); // inne parametry! nie wersja z Drawable

private:
	double speed;
};

#endif /* SHIP_H_ */
