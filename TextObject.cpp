#include "TextObject.h"

/* Zahardkodowanie nazwy czcionki nie jest problemem,
 * bo po co więcej?
 */
TextObject::TextObject(int xpos, int ypos, int fontSize, sf::Color color)
	: xpos(xpos), ypos(ypos), fontSize(fontSize), color(color) {

	if (!fileExists("Fonts/Arial.ttf")) throw FileNotFoundException("Fonts/Arial.ttf");
	font.loadFromFile("Fonts/Arial.ttf");
	str = "---"; // niezainicjalizowany łańcuch
}


void TextObject::draw(sf::RenderWindow& window) {
	text.setFont(font);
	text.setString(str);
	text.setPosition(xpos, ypos);
	text.setCharacterSize(fontSize);
	text.setColor(color);

	window.draw(text);
}
