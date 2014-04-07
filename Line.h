#ifndef LINE_H_
#define LINE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Drawable.h"

class Line : public Drawable {
public:
	//sf::RectangleShape shape;
	sf::Texture texture;

	Line();

	//sf::Vector2f getPosition() { return shape.getPosition(); }
	//void draw(sf::RenderWindow& window) { window.draw(shape); }
};

#endif /* LINE_H_ */
