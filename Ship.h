#ifndef SHIP_H_
#define SHIP_H_

#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Drawable.h"

class Ship : public Drawable {
public:
	Ship();

	void move(Direction d, const sf::Time& t); // ona nie jest przesłonięta, bo inne parametry
	void draw(sf::RenderWindow& window);
	int getSize() const { return 1337; }

private:
//	TextureFlipper tf;
	sf::Clock animationSpeedClock;
};

#endif /* SHIP_H_ */
