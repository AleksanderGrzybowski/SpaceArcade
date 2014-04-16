#include "TextObject.h"

TextObject::TextObject() {
	if (!fileExists("Fonts/Arial.ttf")) throw FileNotFoundException("Fonts/Arial.ttf");
	font.loadFromFile("Fonts/Arial.ttf");

	xpos = ypos = 0;
}

void TextObject::draw(sf::RenderWindow& window) {
	sf::Text text;
	text.setFont(font);
	text.setString(getString());
	text.setPosition(xpos, ypos);
	text.setCharacterSize(getFontSize());
	text.setColor(getColor());

	window.draw(text);
}
