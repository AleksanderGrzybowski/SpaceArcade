#include "Line.h"

Line::Line() {
	// Musimy tutaj oporządzić teksturę, bo wycinamy z niej prostokąt szeroki jak ekran
	// Dlatego też automatyczne wczytywanie tekstury z getSpritesString tu nie zadziała
	sf::Texture texture;
	texture.loadFromFile("Sprites/Line.png", sf::IntRect(0, 0, CONF_screenWidth, CONF_lineHeight));
	texture.setRepeated(true);
	tf.add(texture); // uwaga, czy to jest bezpieczne pamięciowo?
	setPosition(0,  CONF_screenHeight*(1-CONF_shipUpLimit));
}
