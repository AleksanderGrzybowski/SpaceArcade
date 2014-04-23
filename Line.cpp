#include "Line.h"

Line::Line() {
	// Musimy tutaj oporządzić teksturę, bo wycinamy z niej prostokąt szeroki jak ekran
	// Z każdej tekstury w getSpritesString() wycinamy prostokąt

	for (const std::string& s: getSpritesString()) {
		sf::Texture texture;
		texture.loadFromFile(s, sf::IntRect(0, 0, CONF_screenWidth, CONF_lineHeight));
		texture.setRepeated(true);
		tf.add(texture); // uwaga, czy to jest bezpieczne pamięciowo? Ponoć tak - dopisek.
	}

	setPosition(0,  CONF_screenHeight*(1-CONF_shipUpLimit));
}
