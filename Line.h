#ifndef LINE_H_
#define LINE_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Line {
public:
	sf::RectangleShape shape;

	Line();

	sf::Vector2f getPosition() { return shape.getPosition(); }
	void draw(sf::RenderWindow& window) { window.draw(shape); }
};

#endif /* LINE_H_ */
