#include "Line.h"

Line::Line() {
	sf::Texture texture;
	texture.loadFromFile("Sprites/Line.png", sf::IntRect(0, 0, CONF_screenWidth, CONF_lineHeight));
	texture.setRepeated(true);
	tf.add(texture);
	//setTexture(texture);
	setPosition(0,  CONF_screenHeight*(1-CONF_shipUpLimit));
}
