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
	Ship();

	void move(Direction d, const sf::Time& t); // inne parametry! nie impl. z Drawable
	int getSize() const { return 1337; }
	int getAnimationSpeed() const { return 100; }
	const double getSpeed() const { return 0.4; }

protected:
	std::vector<std::string> getSpritesString() const {
		return {"Sprites/spaceshipA.png", "Sprites/spaceshipB.png"};
	}
};

#endif /* SHIP_H_ */
