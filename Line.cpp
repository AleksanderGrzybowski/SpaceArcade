#include "Line.h"

Line::Line() /*: shape(sf::Vector2f(CONF_screenWidth, CONF_lineHeight))*/ {
//	shape.setPosition(0,  CONF_screenHeight*(1-CONF_shipUpLimit));
//	shape.setFillColor(sf::Color::Yellow);

	texture.loadFromFile("Sprites/Line.png", sf::IntRect(0, 0, CONF_screenWidth, CONF_lineHeight));
	texture.setRepeated(true);
	setTexture(texture);
	setPosition(0,  CONF_screenHeight*(1-CONF_shipUpLimit));
}
