#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Drawable.h"
#include "FileNotFoundException.h"
#include "fileExists.h"
#include <string>

/* Obiekt tekstowy. Nie Drawable bo nie ma sprite.
 */
class TextObject {
public:

	TextObject(int xpos, int ypos, int fontSize, sf::Color color, const std::string& str = "");

	void draw(sf::RenderWindow& window);
	virtual ~TextObject() {}

protected:
	std::string str;

private:
	sf::Font font;
	sf::Text text;
	int xpos, ypos;
	int fontSize;
	sf::Color color;
};

#endif /* TEXTOBJECT_H_ */
