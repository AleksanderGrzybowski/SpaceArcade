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
	TextureFlipper tf;
	sf::Clock animationSpeedClock;

	Ship();

	void move(Direction d, const sf::Time& t);
	void draw(sf::RenderWindow& window);
};

#endif /* SHIP_H_ */
