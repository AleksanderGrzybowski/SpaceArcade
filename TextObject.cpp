#include "TextObject.h"

/* Zahardkodowanie nazwy czcionki nie jest problemem,
 * bo po co więcej?
 */
TextObject::TextObject() {
	if (!fileExists("Fonts/Arial.ttf")) throw FileNotFoundException("Fonts/Arial.ttf");
	font.loadFromFile("Fonts/Arial.ttf");

	xpos = ypos = 0;
}

/* Za każdym razem tworzenie nowego obiektu sf::Text,
 * można go przenieść do klasy
 */
void TextObject::draw(sf::RenderWindow& window) {
	sf::Text text;
	text.setFont(font);
	text.setString(getString());
	text.setPosition(xpos, ypos);
	text.setCharacterSize(getFontSize());
	text.setColor(getColor());

	window.draw(text); // nie Drawable::draw() !
}
