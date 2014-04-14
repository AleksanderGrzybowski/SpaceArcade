#include "TextObject.h"

TextObject::TextObject() {
	if (!font.loadFromFile("Fonts/Arial.ttf")) { // should never happen
		std::cerr << "Nie idzie czcionki załadować" << std::endl;
		throw std::exception();
	}
	xpos = ypos = 0;
}

void TextObject::draw(sf::RenderWindow& window) {
	sf::Text text;
	text.setFont(font);
	text.setString(getString());
	text.setPosition(xpos, ypos);
	text.setCharacterSize(getFontSize());
	text.setColor(sf::Color::White);

	window.draw(text);
}
